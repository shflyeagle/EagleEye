#include "EeCommon.h"
#include "PkgPageThread.h"

PkgPageThread::PkgPageThread(const QString& fileName) :
qFile(fileName)
{
	start();
}

PkgPageThread::~PkgPageThread()
{
	EELOG_TRACE("Enter PkgPageThread::~PkgPageThread");
	{
		QMutexLocker locker(&queMutex);
		while (!cmdQueue.isEmpty())
		{
			delete cmdQueue.dequeue();
		}

		PkgPageRequest req;
		cmdQueue.enqueue(new CancelPkgPageCommand(this, req));
		queCond.wakeOne();
	}

	if (qFile.isOpen())
	{
		qFile.close();
	}

	EELOG_TRACE("Wait To Leave PkgPageThread::~PkgPageThread");

	wait();

	EELOG_TRACE("Leave PkgPageThread::~PkgPageThread");
}

void PkgPageThread::putCommand(PkgPageCommand *cmd)
{
	EELOG_DEBUG("PkgPageThread::putCommand (" 
		<< cmd->getPageReq().dump().toStdString().c_str() 
		<< ")");

	QMutexLocker locker(&queMutex);
	cmdQueue.enqueue(cmd);
	queCond.wakeOne();
}

void PkgPageThread::loadPage(const PkgPageRequest& req)
{
	EELOG_TRACE("Enter PkgPageThread::loadPage");
	
	EELOG_DEBUG("loadPage (" << req.dump().toStdString().c_str() << ")");

	quint8 toUsedBufIdx;
	{
		QMutexLocker locker(&bufMutex);

		toUsedBufIdx = (usingBufIdx + 1) & 1;

		if (buf[toUsedBufIdx].no == req.no &&
			PKG_PAGE_BUF_STATE_CLEAN == buf[toUsedBufIdx].state)
		{
			EELOG_DEBUG("Page (" << req.dump().toStdString().c_str() << ") already loaded");
			EELOG_TRACE("Leave PkgPageThread::loadPage");
			return;
		}

		buf[toUsedBufIdx].no = req.no;
		buf[toUsedBufIdx].state = PKG_PAGE_BUF_STATE_DIRTY;
	}

	if (!load(toUsedBufIdx, req))
	{
		bufCond.wakeOne();
		EELOG_TRACE("Leave PkgPageThread::loadPage");
		return;
	}

	{
		QMutexLocker locker(&bufMutex);

		buf[toUsedBufIdx].no = req.no;
		buf[toUsedBufIdx].state = PKG_PAGE_BUF_STATE_CLEAN;

		bufCond.wakeOne();
	}

	EELOG_TRACE("Leave PkgPageThread::loadPage");

}

bool PkgPageThread::load(quint8 toUsedBufIdx, const PkgPageRequest& req)
{
	if(!qFile.isOpen())
	{
		bool rc = qFile.open(QIODevice::ReadOnly);
		if (false == rc)
		{
			EELOG_WARN("PkgPageThread::load|failed to open file (" 
				<< qFile.fileName().toStdString().c_str() 
				<< ")");
			return false;
		}
	}

	QDataStream inDs(&qFile);
	if(!(inDs.device()->seek(req.pos)))
	{
		EELOG_WARN("PkgPageThread::load|failed to seek pos (" 
			<< req.pos 
			<< ")");	
		return false;
	}

	int readSize = inDs.readRawData(buf[toUsedBufIdx].buf.data(), req.len);
	if(readSize != req.len)
	{
		EELOG_WARN("PkgPageThread::load|failed to read (" 
			<< readSize 
			<< " - " 
			<< req.len 
			<< ")");			
		return false;
	}
	buf[toUsedBufIdx].buf.resize(readSize);

	EELOG_DEBUG("PkgPageThread::load|successfully loaded page (" 
		<< req.dump().toStdString().c_str() 
		<< ") )");

	return true;

}

void PkgPageThread::cancelPage(const PkgPageRequest& req)
{
	EELOG_TRACE("Enter PkgPageThread::cancelPage");

	Q_UNUSED(req);

	isRunning = false;

	EELOG_TRACE("Leave PkgPageThread::cancelPage");
}

QByteArray* PkgPageThread::switchBuf(quint16 pageIdx)
{	
	EELOG_TRACE("Enter PkgPageThread::switchBuf");

	quint8 toUsedBufIdx;	
	while (1)
	{
		QMutexLocker locker(&bufMutex);

		toUsedBufIdx = (usingBufIdx + 1) & 1;

		if (pageIdx == buf[toUsedBufIdx].no &&
			PKG_PAGE_BUF_STATE_CLEAN == buf[toUsedBufIdx].state)
		{			
			usingBufIdx = toUsedBufIdx;
			break;
		}
		else
		{
			if (pageIdx != buf[toUsedBufIdx].no)
			{
				EELOG_INFO("PkgPageThread::switchBuf|waiting page (" 
					<< pageIdx 
					<< ") to be loaded ......");				
			}

			bufCond.wait(&bufMutex);			
		}
	} 

	EELOG_TRACE("Leave PkgPageThread::switchBuf");
	return &(buf[toUsedBufIdx].buf);
}

void PkgPageThread::run()
{
	EELOG_TRACE("Enter PkgPageThread::run");

	PkgPageCommand *cmd = nullptr;
	while(isRunning)
	{
		{
			QMutexLocker locker(&queMutex);

			if (cmdQueue.isEmpty())
			{
				queCond.wait(&queMutex);
			}

			cmd = cmdQueue.dequeue();
		}

		cmd->execute();		

		delete cmd;
	}

	EELOG_TRACE("Leave PkgPageThread::run");
}