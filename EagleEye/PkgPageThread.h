#pragma once

#include "EeCommon.h"
#include "PkgPageCommand.h"

class PkgPageThread: public QThread
{
private:
	enum
	{
		PKG_PAGE_BUF_FLIP = 0,
		PKG_PAGE_BUF_FLOP = 1,
		PKG_PAGE_BUF_NUM = 2
	};

	enum
	{
		PKG_PAGE_BUF_STATE_DIRTY = 0,
		PKG_PAGE_BUF_STATE_CLEAN = 1,
		PKG_PAGE_BUF_STATE_USING = 2
	};

	class PkgPageBuf
	{
	public:
		PkgPageBuf()
		{
			buf.reserve(EE_MAX_SIZE_IN_BYTE_PER_PAGE);
		}

		void rst()
		{
			no = -1;
			state = PKG_PAGE_BUF_STATE_DIRTY;
			buf.clear();
		}

	public:
		int no{ -1 };
		unsigned state{ PKG_PAGE_BUF_STATE_DIRTY };
		QByteArray buf;
	};

public:
	PkgPageThread(const QString& fileName);
	virtual ~PkgPageThread();

	void putCommand(PkgPageCommand *cmd);

	void loadPage(const PkgPageRequest& req);

	void cancelPage(const PkgPageRequest& req);

	QByteArray* switchBuf(quint16 pageIdx);

protected:
	void run() override;

	bool load(quint8 toUsedBufIdx, const PkgPageRequest& req);

private:
	QQueue<PkgPageCommand *> cmdQueue;

	QWaitCondition queCond;
	QMutex queMutex;

	QWaitCondition bufCond;
	QMutex bufMutex;

	PkgPageBuf buf[PKG_PAGE_BUF_NUM];

	quint8 usingBufIdx{ PKG_PAGE_BUF_FLIP };
	quint8 isRunning{true};
	QFile qFile;
};

