#include "DataManager.h"
#include "PkgPageCommand.h"
#include "PkgPageThread.h"
#include "TigerPkgParser.h"
#include "EeYacc.h"
#include "PkgDecoder.h"
#include "StrucLUT.h"
#include "EeProfile.h"
#include "StrucTree.h"

DataManager::DataManager(QWidget *parent)
{
	this->parent = parent;
	pkgPageThread = std::shared_ptr<PkgPageThread>(nullptr);
	pkgDecoderMng = std::shared_ptr<PkgDecoderMng>(nullptr);
	pkgVisitorMng = std::shared_ptr<PkgVisitorMng>(nullptr);
}

DataManager::~DataManager()
{
	clear();
}

void DataManager::clear()
{
	EELOG_TRACE("Enter DataManager::clear");

	fileName.clear();

	EELOG_TRACE("DataManager::clear|map4PkgIdxPage2PkgIdx2PkgIdVec (" 
		<< map4PkgIdxPage2PkgIdx2PkgIdVec.size() 
		<< ") begin");
	quint32 pageIdx;
	for (pageIdx = 0; pageIdx < map4PkgIdxPage2PkgIdx2PkgIdVec.size(); ++pageIdx)
	{
		delete map4PkgIdxPage2PkgIdx2PkgIdVec[pageIdx];
	}
	map4PkgIdxPage2PkgIdx2PkgIdVec.clear();
	EELOG_TRACE("DataManager::clear|map4PkgIdxPage2PkgIdx2PkgIdVec end");

	EELOG_TRACE("DataManager::clear|map4PkgPage2PkgId2PkgLocVec (" 
		<< map4PkgPage2PkgId2PkgLocVec.size() 
		<< ") begin");
	for (pageIdx = 0; pageIdx < map4PkgPage2PkgId2PkgLocVec.size(); ++pageIdx)
	{
		delete map4PkgPage2PkgId2PkgLocVec[pageIdx];		
	}
	map4PkgPage2PkgId2PkgLocVec.clear();
	EELOG_TRACE("DataManager::clear|map4PkgPage2PkgId2PkgLocVec end");

	pageContainer.rst();
	pkgPageRawData = nullptr;

	DataProcessingState initps;
	dataProcessingState = initps;

	pkgPageThread.reset();

	isFilterOnceDone = false;

	EELOG_TRACE("Leave DataManager::clear");
}

void DataManager::loadPackets(const QString& fileName)
{
	EELOG_TRACE("Enter DataManager::loadPackets");

	this->fileName = fileName;

	try
	{
		pkgPageThread = std::make_shared<PkgPageThread>(fileName);
	}
	catch (...)
	{
		EELOG_WARN("DataManager::DataManage|failed to new/start PkgPageThread!");
	}

	std::shared_ptr<AbstractPkgParser> parser(getPacketParser());
	if (parser.get() != nullptr)
	{
		parser->parse();
	}
	else
	{
		EELOG_WARN("DataManager::loadPackets|failed to getPacketParser");
	}

	check2Paging();

	EELOG_TRACE("Leave DataManager::loadPackets");
}

unsigned DataManager::getPkgIdByPkgIdx(unsigned pkgIdx)
{
	unsigned globalPkgIdx = 
		pageContainer.tabIdxPageList[pageContainer.curTabIdxPage].firstIdx + pkgIdx;
	if (globalPkgIdx >= pageContainer.totalPkgIdx)
	{
		QString exeinfo = QObject::tr("globalPkgIdx(%1) >= self.pageContainer.totalPkgIdx(%2)")
			.arg(globalPkgIdx)
			.arg(pageContainer.totalPkgIdx);
		EELOG_FATAL("DataManager::getPkgIdByPkgIdx|" << exeinfo.toStdString().c_str());
		//throw EeException(exeinfo);
		Q_ASSERT(globalPkgIdx < pageContainer.totalPkgIdx);

		return 0;
	}
	else
	{
		if (globalPkgIdx >= pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].firstPkgIdx &&
			globalPkgIdx <= pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].lastPkgIdx)
		{
			//do nothing
		}
		else if (globalPkgIdx < pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].firstPkgIdx &&
			globalPkgIdx >= pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage - 1].firstPkgIdx)
		{
			--pageContainer.curPkgIdxPage;
		}
		else if (globalPkgIdx > pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].lastPkgIdx &&
			globalPkgIdx <= pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage + 1].lastPkgIdx)
		{
			++pageContainer.curPkgIdxPage;
		}
		else
		{			
			for (quint16 pageIdx = 0; pageIdx < pageContainer.pkgIdxPageList.size(); ++pageIdx)
			{
				if (globalPkgIdx >= pageContainer.pkgIdxPageList[pageIdx].firstPkgIdx &&
					globalPkgIdx <= pageContainer.pkgIdxPageList[pageIdx].lastPkgIdx)
				{
					pageContainer.curPkgIdxPage = pageIdx;
					break;
				}
			}
		}

		//Q_ASSERT(((pageContainer.curPkgIdxPage >= 0) &&
		//	(pageContainer.curPkgIdxPage < pageContainer.pkgIdxPageList.size())));		

		unsigned localPkgIdx = getLocalPkgIdx(globalPkgIdx);

		return (*(map4PkgIdxPage2PkgIdx2PkgIdVec[pageContainer.curPkgIdxPage])).at(localPkgIdx);		
	}
}

PkgLoc *DataManager::getPkgLocByPkgIdx(unsigned pkgIdx)
{
	unsigned pkgId = getPkgIdByPkgIdx(pkgIdx);

	return getPkgLocByPkgId(pkgId);
}

PkgLoc *DataManager::getPkgLocByPkgId(unsigned pkgId)
{
	if (pkgId >= pageContainer.totalPkg)
	{
		QString exeinfo = QObject::tr("pkgId(%1) >= pageContainer.totalPkg(%2)")
			.arg(pkgId)
			.arg(pageContainer.totalPkg);
		EELOG_FATAL("DataManager::getPkgLocByPkgId|" << exeinfo.toStdString().c_str());
		//throw EeException(exeinfo);
		Q_ASSERT(pkgId < pageContainer.totalPkg);
		return nullptr;
	}
	else
	{
		unsigned totalPkgNo = pageContainer.pkgPageList[pageContainer.curPkgPage].totalPkgNo;
		unsigned startPkgNo = pageContainer.pkgPageList[pageContainer.curPkgPage].startPkgNo;
		unsigned endPkgNo = pageContainer.pkgPageList[pageContainer.curPkgPage].endPkgNo;
		unsigned midPkgNo = (startPkgNo + endPkgNo) >> 1;
		int  nextPkgPage = pageContainer.curPkgPage;
		bool isPkgPageSwitch = false;

		if (totalPkgNo > 0 && pkgId >= startPkgNo && pkgId <= endPkgNo)
		{
			if (false == pageContainer.isPkgPageSwitchSend)
			{
				if (pkgId < midPkgNo && pageContainer.curPkgPage > 0)
				{
					nextPkgPage = pageContainer.curPkgPage - 1;
				}
				else if (pkgId > midPkgNo &&
					pageContainer.curPkgPage < pageContainer.pkgPageList.size() - 1)
				{
					nextPkgPage = pageContainer.curPkgPage + 1;
				}
				else
				{
					//no need to pre-load pkg page to speed up page load
				}
			}
		}
		else
		{
			size_t pkgPageIdx;
			for (pkgPageIdx = 0; pkgPageIdx < pageContainer.pkgPageList.size(); ++pkgPageIdx)
			{
				if (pageContainer.pkgPageList[pkgPageIdx].totalPkgNo > 0 &&
					pkgId >= pageContainer.pkgPageList[pkgPageIdx].startPkgNo &&
					pkgId <= pageContainer.pkgPageList[pkgPageIdx].endPkgNo)
				{
					nextPkgPage = pkgPageIdx;
					break;
				}
			}

			Q_ASSERT((nextPkgPage) < (pageContainer.pkgPageList.size()));

			isPkgPageSwitch = true;
		}

		if (nextPkgPage != pageContainer.curPkgPage)
		{
			QString info = QObject::tr("page switch from %1 to %2 with conditions (%3, %4 - %5 - %6 - %7 - %8)")
				.arg(pageContainer.curPkgPage)
				.arg(nextPkgPage)
				.arg(isPkgPageSwitch)
				.arg(pkgId)
				.arg(startPkgNo)
				.arg(midPkgNo)
				.arg(endPkgNo)
				.arg(totalPkgNo);
			EELOG_INFO("DataManager::getPkgLocByPkgId|" << info.toStdString().c_str());			

			PkgPageRequest req(
				nextPkgPage,
				pageContainer.pkgPageList[nextPkgPage].startPos,
				pageContainer.pkgPageList[nextPkgPage].endPos - pageContainer.pkgPageList[nextPkgPage].startPos);
			pkgPageThread->putCommand(new LoadPkgPageCommand(pkgPageThread.get(), req));

			pageContainer.isPkgPageSwitchSend = true;

			if (isPkgPageSwitch)
			{
				pkgPageRawData = pkgPageThread->switchBuf(nextPkgPage);
				pageContainer.curPkgPage = nextPkgPage;
				pageContainer.isPkgPageSwitchSend = false;
			}
		}
	
		quint32 localPkgIdIdx = 
			pkgId - pageContainer.pkgPageList[pageContainer.curPkgPage].startPkgNo;
		return &((*(map4PkgPage2PkgId2PkgLocVec[pageContainer.curPkgPage]))[localPkgIdIdx]);
	}
}

unsigned DataManager::getCurTabPagePkgCount(void)
{
	return pageContainer.tabIdxPageList[pageContainer.curTabIdxPage].idxCnt;	
}


QByteArray DataManager::getTime(unsigned pkgIdx)
{
	int pkgId = getPkgIdByPkgIdx(pkgIdx);

	PkgLoc* pkgLoc = getPkgLocByPkgId(pkgId);

	return getTime(pkgLoc);
}

QByteArray DataManager::getTime(const PkgLoc* pkgLoc)
{
	return QByteArray(pkgPageRawData->data() +
		pkgLoc->timePos, EE_SIZE_TIME_VAL);
}

unsigned DataManager::getDecoderId(unsigned pkgIdx)
{
	int pkgId = getPkgIdByPkgIdx(pkgIdx);

	PkgLoc* pkgLoc = getPkgLocByPkgId(pkgId);

	return getDecoderId(pkgLoc);
}


QByteArray DataManager::getDecoderCxt(unsigned pkgIdx)
{
	int pkgId = getPkgIdByPkgIdx(pkgIdx);

	PkgLoc* pkgLoc = getPkgLocByPkgId(pkgId);

	return getDecoderCxt(pkgLoc);
}

QString DataManager::getFilterExpression4Export(quint32 decodeId, const StrucTree* st)
{
	EELOG_WARN("DataManager::getFilterExpression4Export");
	return QString();
}

unsigned DataManager::getDecoderId(const PkgLoc* pkgLoc)
{
	EELOG_WARN("DataManager::getDecoderId");
	return 0;
}

QByteArray DataManager::getDecoderCxt(const PkgLoc* pkgLoc)
{
	EELOG_WARN("DataManager::getDecoderCxt");
	return QByteArray();
}

QByteArray DataManager::getDecoderCxt4Filter(const PkgLoc* pkgLoc)
{
	EELOG_WARN("DataManager::getDecoderCxt4Filter");
	return QByteArray();
}

void DataManager::filter()
{
	EELOG_TRACE("Enter DataManager::filter");

	if (Q_NULLPTR == EeYacc::yaccTree.get())
	{
		if (pageContainer.totalPkgIdx == pageContainer.totalPkg)
		{
			EELOG_TRACE("Leave DataManager::filter (do nothing)");
			return;
		}
	}

	QTime filterringTime;
	filterringTime.start();

	clearPkgIdxPages();

	if (Q_NULLPTR == EeYacc::yaccTree.get())
	{			
		for (quint32 pkgId = 0; pkgId < pageContainer.totalPkg; ++pkgId)
		{
			updatePkgIdxPkgIdPair(pkgId, pkgId);
		}	

		check2Paging();

		dataProcessingState.elapsedTime = filterringTime.elapsed();
		dataProcessingState.filteredPackets = pageContainer.totalPkgIdx;

		EELOG_TRACE("Leave DataManager::filter (loaded all packets)");
		return;
	}

	bool isCancelledByOpr = false;

	QProgressDialog progress("Filtering packet...", "Stop",
		0, dataProcessingState.packets, parent);
	progress.setAutoClose(true);
	progress.setWindowModality(Qt::WindowModal);

	PkgLoc *pkgLoc = Q_NULLPTR;
	if (isFilterOnceDone)
	{
		quint32 curPkgId = 0;
		for (quint16 pageIdx = 0; pageIdx < pageContainer.pkgPageList.size(); ++pageIdx)
		{
			PkgId2PkgLocVec* pkgId2PkgLocVec = map4PkgPage2PkgId2PkgLocVec[pageIdx];
			quint32 size = pageContainer.pkgPageList[pageIdx].totalPkgNo;
			for (quint32 pkgIdIdx = 0; pkgIdIdx < size; ++pkgIdIdx)
			{
				if (0 == (pkgIdIdx & 0xFFF))
				{
					progress.setValue(curPkgId);
				}				

				const PkgLoc& pkgLoc = (*pkgId2PkgLocVec).at(pkgIdIdx);
				quint32 rc = EeYacc::compute("", pkgLoc.fk);
				if (rc)
				{
					updatePkgIdxPkgIdPair(pageContainer.totalPkgIdx, curPkgId);
				}

				++curPkgId;
			}			
		}

		check2Paging();

		dataProcessingState.elapsedTime = filterringTime.elapsed();
		dataProcessingState.filteredPackets = pageContainer.totalPkgIdx;

		EELOG_TRACE("Leave DataManager::filter (once done)");

		return;
	}

	for (quint32 pkgId = 0; pkgId < pageContainer.totalPkg; ++pkgId)
	{
		if (0 == (pkgId & 0xFFF))
		{
			progress.setValue(pkgId);
			if (progress.wasCanceled())
			{
				isCancelledByOpr = true;
				break;
			}
		}

		pkgLoc = getPkgLocByPkgId(pkgId);
		quint32 decoderId = getDecoderId(pkgLoc);
		//if (false == pkgLoc->fk[MAX_NUM_FILTER_KW - 1])
		{
			PkgDecoder* decoder = getPkgDecoderMng()->getDecoder(decoderId);
			if (Q_NULLPTR == decoder)
			{
				continue;
			}

			const QByteArray& b = getDecoderCxt4Filter(pkgLoc);
			decoder->decode(b, pkgLoc, true);
			if (Q_NULLPTR == decoder->getStrucTree())
			{
				continue;
			}
		}
		
		//QString strucId = QString("%1").arg(decoderId);
		quint32 rc = EeYacc::compute("", pkgLoc->fk);
		if (rc)
		{
			updatePkgIdxPkgIdPair(pageContainer.totalPkgIdx, pkgId);
		}

		dataProcessingState.filteredPackets = pageContainer.totalPkgIdx;
		dataProcessingState.elapsedTime = filterringTime.elapsed();
	}

	if (false == isFilterOnceDone && 
		false == isCancelledByOpr)
	{
		isFilterOnceDone = true;
	}

	check2Paging();

	dataProcessingState.filteredPackets = pageContainer.totalPkgIdx;
	dataProcessingState.elapsedTime = filterringTime.elapsed();

	EELOG_TRACE("Leave DataManager::filter");
}

void DataManager::fetchPkgIdxs(quint32 decodeId, QVector<quint32> * const pkgIdxVec)
{
	EELOG_TRACE("Enter DataManager::fetchPkgIdxs");

	for (quint32 pkgIdx = 0; pkgIdx < pageContainer.totalPkgIdx; ++pkgIdx)
	{
		if (decodeId == getDecoderId(pkgIdx))
		{
			pkgIdxVec->append(pkgIdx);
		}
	}
	
	EELOG_TRACE("Leave DataManager::fetchPkgIdxs");
}

std::shared_ptr<AbstractPkgParser> DataManager::getPacketParser(void)
{
	return std::shared_ptr<AbstractPkgParser>(nullptr);
}

void DataManager::insertPkgIdxPkgIdPair(unsigned pkgIdx, unsigned pkgId)
{
	bool isBeyondMaxSize = pageContainer.curPkgIdxPage != -1 && 
		pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].totalPkgIdx 
		>= EE_MAX_SIZE_PKG_IDX_PER_PAGE;
	if (isBeyondMaxSize || 0 == map4PkgIdxPage2PkgIdx2PkgIdVec.size())
	{
		++pageContainer.curPkgIdxPage;
		map4PkgIdxPage2PkgIdx2PkgIdVec.insert(pageContainer.curPkgIdxPage, 
			new PkgIdx2PkgIdVec(EE_MAX_SIZE_PKG_IDX_PER_PAGE));

		PkgIdxPage pkgIdxPage;
		pkgIdxPage.firstPkgIdx = pkgIdx;
		pageContainer.pkgIdxPageList.push_back(pkgIdxPage);
	}	

	quint32 localPkgIdx = 
		pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].totalPkgIdx;
	(*(map4PkgIdxPage2PkgIdx2PkgIdVec[pageContainer.curPkgIdxPage]))[localPkgIdx] = pkgId;

	pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].lastPkgIdx = pkgIdx;
	++pageContainer.totalPkgIdx;
	++pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].totalPkgIdx;
}

void DataManager::updatePkgIdxPkgIdPair(unsigned pkgIdx, unsigned pkgId)
{
	bool isNeedNewPage = (-1 == pageContainer.curPkgIdxPage) || 
						  (pageContainer.curPkgIdxPage != -1 && 
						   pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].totalPkgIdx 
						   >= EE_MAX_SIZE_PKG_IDX_PER_PAGE);
	if (isNeedNewPage)
	{
		++pageContainer.curPkgIdxPage;

		PkgIdxPage pkgIdxPage;
		pkgIdxPage.firstPkgIdx = pkgIdx;
		pageContainer.pkgIdxPageList.push_back(pkgIdxPage);
	}

	quint32 localPkgIdx =
		pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].totalPkgIdx;
	(*(map4PkgIdxPage2PkgIdx2PkgIdVec[pageContainer.curPkgIdxPage]))[localPkgIdx] = pkgId;

	++pageContainer.totalPkgIdx;
	++pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].totalPkgIdx;
	pageContainer.pkgIdxPageList[pageContainer.curPkgIdxPage].lastPkgIdx = pkgIdx;
}


void DataManager::insertPkgLoc(const PkgLoc &pkgLoc)
{
	if (!map4PkgPage2PkgId2PkgLocVec.contains(pageContainer.curPkgPage))
	{
		map4PkgPage2PkgId2PkgLocVec.insert(pageContainer.curPkgPage, 
			new PkgId2PkgLocVec(EE_MAX_SIZE_PKG_LOC_PER_PAGE));
	}

	if (EP_FEATURE_DISABLED(STRUC_N(pkgLoc.misc)))
	{
		return;
	}

	quint32 localPkgLocIdx = pageContainer.pkgPageList[pageContainer.curPkgPage].totalPkgNo;
	(*(map4PkgPage2PkgId2PkgLocVec[pageContainer.curPkgPage]))[localPkgLocIdx] = pkgLoc;
	++pageContainer.totalPkg;
	++pageContainer.pkgPageList[pageContainer.curPkgPage].totalPkgNo;
}

void DataManager::check2Paging()
{
	pageContainer.rstTabIdxPage();

	quint16 tabIdxPageNum = 
		(pageContainer.totalPkgIdx + QT_TABMODEL_MAX_COUNT_MINUS_1) / QT_TABMODEL_MAX_COUNT;	
	if (tabIdxPageNum > 0)
	{
		quint16 pageIdx;
		for (pageIdx = 0; pageIdx < tabIdxPageNum; ++pageIdx)
		{
			TabIdxPage tabIdxPage;
			tabIdxPage.firstIdx = pageIdx * QT_TABMODEL_MAX_COUNT;
			tabIdxPage.idxCnt = QT_TABMODEL_MAX_COUNT;
			if (pageIdx == (tabIdxPageNum - 1))
			{
				tabIdxPage.idxCnt =
					pageContainer.totalPkgIdx - tabIdxPage.firstIdx;
			}

			pageContainer.tabIdxPageList.push_back(tabIdxPage);			
		}
	}
	else
	{	
		pageContainer.tabIdxPageList.push_back(TabIdxPage());
	}

	pageContainer.curPkgIdxPage = 0;
	pageContainer.curTabIdxPage = 0;

	updateDataProcessingState();
}


void DataManager::updateDataProcessingState()
{
	dataProcessingState.curPageNo =
		pageContainer.curTabIdxPage;
	dataProcessingState.totalPageNum =
		pageContainer.tabIdxPageList.size();
	dataProcessingState.curPageFilteredPackets =
		pageContainer.tabIdxPageList[pageContainer.curTabIdxPage].idxCnt;
	dataProcessingState.filteredPackets = pageContainer.totalPkgIdx;
}

PkgDecoderMng *DataManager::getPkgDecoderMng() const
{
	return pkgDecoderMng.get();
}

PkgVisitorMng *DataManager::getPkgVisitorMng() const
{
	return pkgVisitorMng.get();
}

QString DataManager::getPacketStatus() const
{
	return QString("Packet: %1 ; Displayed: %2/%3 ; Page: %4/%5 ; Load Time : %6").
		arg(dataProcessingState.packets).
		arg(dataProcessingState.curPageFilteredPackets).
		arg(dataProcessingState.filteredPackets).
		arg(dataProcessingState.curPageNo + 1).
		arg(dataProcessingState.totalPageNum).
		arg(dataProcessingState.elapsedTime);
}

bool DataManager::isFirstPage() const
{
	return (0 == pageContainer.curTabIdxPage);
}

bool DataManager::isLastPage() const
{
	return ((pageContainer.tabIdxPageList.size() - 1) 
		== pageContainer.curTabIdxPage);
}

bool DataManager::check2FetchPreviousPage()
{
	bool isSwitchPage = false;
	quint16 curPage = pageContainer.curTabIdxPage;
	if (curPage > 0)
	{
		--pageContainer.curTabIdxPage;
		isSwitchPage = true;

		updateDataProcessingState();

		EELOG_INFO("DataManager::check2FetchNextPage|switch page from "
			<< curPage
			<< " to "
			<< pageContainer.curTabIdxPage);
	}

	return isSwitchPage;
}

bool DataManager::check2FetchNextPage()
{
	bool isSwitchPage = false;
	quint16 curPage = pageContainer.curTabIdxPage;
	if (curPage < (pageContainer.tabIdxPageList.size() - 1))
	{
		++pageContainer.curTabIdxPage;
		isSwitchPage = true;

		updateDataProcessingState();

		EELOG_INFO("DataManager::check2FetchNextPage|switch page from " 
			<< curPage 
			<< " to " 
			<< pageContainer.curTabIdxPage);
	}

	return isSwitchPage;
}

void DataManager::clearPkgIdxPages()
{
	pageContainer.rstPkgIdxPage();
}

unsigned DataManager::getLocalPkgIdx(unsigned glocalPkgIdx)
{
	return glocalPkgIdx - 
		pageContainer.curPkgIdxPage * EE_MAX_SIZE_PKG_IDX_PER_PAGE;
}

void DataManager::resizePkgPageSize(int pageIdx)
{
	if (pageIdx >= 0 && 
		map4PkgPage2PkgId2PkgLocVec.size() > pageIdx)
	{
		EELOG_INFO("DataManager::resizePkgPageSize|PkgPage ("
			<< pageIdx
			<< ") totalPkgNo ("
			<< pageContainer.pkgPageList[pageIdx].totalPkgNo
			<< ") startPkgNo ("
			<< pageContainer.pkgPageList[pageIdx].startPkgNo
			<< ") endPkgNo ("
			<< pageContainer.pkgPageList[pageIdx].endPkgNo
			<< ") size (" 
			<< map4PkgPage2PkgId2PkgLocVec[pageIdx]->size() 
			<< ")");

		Q_ASSERT((map4PkgPage2PkgId2PkgLocVec[pageIdx]->size() >= 
			pageContainer.pkgPageList[pageIdx].totalPkgNo));

		map4PkgPage2PkgId2PkgLocVec[pageIdx]->resize(
			pageContainer.pkgPageList[pageIdx].totalPkgNo + 1);	

		map4PkgPage2PkgId2PkgLocVec[pageIdx]->squeeze();
	}
}

void DataManager::checkPkgIdxPageSize(int pageIdx)
{
	if (pageIdx > 0)
	{		
		EELOG_INFO("DataManager::checkPkgIdxPageSize|pkgIdxPage ("
			<< pageIdx
			<< ") totalPkgIdx ("
			<< pageContainer.pkgIdxPageList[pageIdx].totalPkgIdx
			<< ") firstPkgIdx (" 
			<< pageContainer.pkgIdxPageList[pageIdx].firstPkgIdx 
			<< ") lastPkgIdx (" 
			<< pageContainer.pkgIdxPageList[pageIdx].lastPkgIdx 
			<< ")");

		Q_ASSERT((pageContainer.pkgIdxPageList[pageIdx].totalPkgIdx) ==
			(pageContainer.pkgIdxPageList[pageIdx].lastPkgIdx -
			pageContainer.pkgIdxPageList[pageIdx].firstPkgIdx + 1));
	}
}

