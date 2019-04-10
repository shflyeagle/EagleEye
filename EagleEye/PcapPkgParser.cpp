#include "EeCommon.h"
#include "PcapPkgParser.h"
#include "DataManager.h"
#include "PkgPageCommand.h"
#include "PkgPageThread.h"


PcapPkgParser::PcapPkgParser(DataManager *dm) :
AbstractPkgParser(dm)
{
}

PcapPkgParser::~PcapPkgParser()
{
}

void PcapPkgParser::checkFileSanity(void)
{
	EELOG_TRACE("Enter PcapPkgParser::checkFileSanity");

	QDataStream ds(&qFile);
	QByteArray data;
	data.reserve(EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V6);

	int readSize = ds.readRawData(data.data(), EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V6);
	if (-1 == readSize && 
		readSize != EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V6)
	{
		QString exeinfo = QObject::tr("PcapPkgParser::checkFileSanity | failed to read. actual size (%1), expected size(%2)")
			.arg(readSize).arg(EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V6);
		throw EeException(exeinfo);
	}

	quint32 pcapFileMagic = EE_LE_GetMagicFromPcapFileHeader(data.data());
	if (pcapFileMagic != PCAP_FILE_MAGIC)
	{
		QString exeinfo = QObject::tr("PcapPkgParser::checkFileSanity | wrong file format with magic(%1)")
			.arg(pcapFileMagic);
		throw EeException(exeinfo);
	}
	
	quint16 ethProc = EE_BE_GetEthProFromEthIPUDPHdr(data.data());
	if (EE_VAL_ETH_PROC_IP_V4 == ethProc)
	{
		ethIPUDPHdrVer = EE_VAL_ETH_IP_VER_V4;
	}
	else if (EE_VAL_ETH_PROC_IP_V6 == ethProc)
	{
		ethIPUDPHdrVer = EE_VAL_ETH_IP_VER_V6;
	}
	else
	{
		ethIPUDPHdrVer = EE_VAL_ETH_IP_VER_NULL;
	}

	EELOG_INFO("PcapPkgParser::checkFileSanity|ethProc (" << ethProc << ")");

	EELOG_TRACE("Leave PcapPkgParser::checkFileSanity");
}

void PcapPkgParser::pagesLoad(void)
{
	EELOG_TRACE("Enter PcapPkgParser::pagesLoad");

	bool rc = true;
	QString exeInfo;
	int readSize = -1;

	int filesize = qFile.size();

	EELOG_DEBUG("PcapPkgParser::pagesLoad|filesize (" << filesize << ")");

	QDataStream ds(&qFile);
	QByteArray data;
	data.reserve(EE_MAX_SIZE_IN_BYTE_PER_PAGE);

	//skip pcap file header;
	quint32 curPos = EE_SIZE_PCAP_FILE_HEADER;
	quint32 curPagePos = 0;
	while (curPos < filesize)
	{
		if (-1 == ds.device()->seek(curPos))
		{
			exeInfo = QObject::tr("PcapPkgParser::pagesLoad|failed to seek(%1)").arg(curPos);
			rc = false;
			break;
		}

		readSize = ds.readRawData(data.data(), EE_MAX_SIZE_IN_BYTE_PER_PAGE);
		if (-1 == readSize)
		{
			exeInfo = QObject::tr("PcapPkgParser::pagesLoad|failed to read(%1)").arg(readSize);
			rc = false;
			break;
		}

		PkgPage pkgPage;
		pkgPage.startPos = curPos;
		quint16 capLen = 0;
		curPagePos = 0;		
		while((curPagePos < readSize) && 
			(curPagePos + EE_SIZE_PCAP_PKT_HEADER) <= readSize)
		{			
			capLen = EE_LE_GetCapLenFromPcapPktHdr(data.data() + curPagePos);

			curPagePos += (capLen + EE_SIZE_PCAP_PKT_HEADER);

			++pkgNum;
		}

		if (curPagePos > readSize)
		{
			curPagePos -= (capLen + EE_SIZE_PCAP_PKT_HEADER);
			--pkgNum;
		}

		curPos += curPagePos;
		pkgPage.endPos = curPos;

		dm->pageContainer.pkgPageList.push_back(pkgPage);

		QString pageInfo = QObject::tr("page %1(%2 - %3)")
			.arg(dm->pageContainer.pkgPageList.size())
			.arg(pkgPage.startPos)
			.arg(pkgPage.endPos);

		EELOG_DEBUG("PcapPkgParser::pagesLoad|"<< pageInfo.toStdString().c_str());
	}

	if (!rc)
	{
		throw EeException(exeInfo);
	}

	EELOG_TRACE("Leave PcapPkgParser::pagesLoad");	
}

void PcapPkgParser::parseFile(void)
{
	EELOG_TRACE("PcapPkgParser::parseFile");
	
	QString exeInfo;
	bool rc = true;
	int fileSize = qFile.size();

	QTime loadingTime;
	loadingTime.start();

	dm->dataProcessingState.totalKBSize = fileSize;

	QProgressDialog progress("Loading file...", 
							 "Stop",
							 0,
							 dm->pageContainer.pkgPageList.size(),
							 dm->parent);
	progress.setAutoClose(true);
	progress.setWindowModality(Qt::WindowModal);
	progress.setValue(0);

	quint16 pageIdx;
	for (pageIdx = 0; pageIdx < dm->pageContainer.pkgPageList.size(); ++pageIdx)
	{
		PkgPage page = dm->pageContainer.pkgPageList[pageIdx];
		PkgPageRequest req(pageIdx, page.startPos, page.endPos - page.startPos);
		dm->pkgPageThread->putCommand(new LoadPkgPageCommand(dm->pkgPageThread.get(), req));
		dm->pkgPageRawData = dm->pkgPageThread->switchBuf(pageIdx);

		dm->pageContainer.curPkgPage = pageIdx;
		dm->pageContainer.pkgPageList[pageIdx].startPkgNo = dm->pageContainer.totalPkg;


		quint32 dataLen = dm->pkgPageRawData->size();
		quint32 curBytePos = 0;
		quint32 pcapPayloadLen = 0;
		rc = true;	
		while (rc &&
			   curBytePos < dataLen)
		{
			if (curBytePos + EE_SIZE_PCAP_PKT_HEADER >= fileSize)
			{
				exeInfo = QObject::tr("PcapPkgParser::parseFile|faild to read PCAP pkt header %1:%2 (%3)")
					.arg(curBytePos)
					.arg(EE_SIZE_PCAP_PKT_HEADER).arg(fileSize);
				rc = false;
				break;
			}

			CompLoc pcapHdrLoc;
			pcapHdrLoc.pos = curBytePos;
			pcapHdrLoc.len = EE_SIZE_PCAP_PKT_HEADER;

			//pcap packet header
			curBytePos += pcapHdrLoc.len;

			dm->dataProcessingState.loadedKBSize = page.startPos + curBytePos;			

			quint16 capLen = EE_LE_GetCapLenFromPcapPktHdr(dm->pkgPageRawData->data() + pcapHdrLoc.pos);
			if (capLen > EE_MAX_SIZE_IN_BYTE_PCAP_PACKET)
			{
				exeInfo = QObject::tr("PcapPkgParser::parseFile|detected long PCAP pkt payload %1:%2")
					.arg(capLen)
					.arg(EE_MAX_SIZE_IN_BYTE_PCAP_PACKET);
				rc = false;
				break;
			}

			pcapPayloadLen = capLen;

			//pcap packet payload
			//skip ip/upd header if necessary
			curBytePos += getSizeOfEthIPUDPHdr();
			pcapPayloadLen -= getSizeOfEthIPUDPHdr();

			CompLoc pcapPayloadLoc;
			pcapPayloadLoc.pos = curBytePos;
			pcapPayloadLoc.len = pcapPayloadLen;

			if (curBytePos + pcapPayloadLoc.len > fileSize)
			{
				exeInfo = QObject::tr("PcapPkgParser::parseFile|file is corrupted.  %1:%2 (%3)")
					.arg(curBytePos).arg(pcapPayloadLoc.len).arg(fileSize);
				rc = false;
				break;
			}
			curBytePos += pcapPayloadLoc.len;

			parsedPkgNum++;

			if (false == parsePayload(pcapHdrLoc, pcapPayloadLoc))
			{
				exeInfo = errorStr;
				rc = false;
				break;
			}
		}

		dm->pageContainer.pkgPageList[pageIdx].endPkgNo = 
			dm->pageContainer.totalPkg - 1;

		dm->resizePkgPageSize(pageIdx);
		dm->dataProcessingState.elapsedTime = loadingTime.elapsed();

		if (!rc)
		{
			break;
		}
		
		progress.setValue(pageIdx + 1);
		if (progress.wasCanceled())
		{
			exeInfo = "PcapPkgParser::parseFile|parse is canceled by operator";
			rc = false;
			break;
		}
	}

	progress.close();

	dm->dataProcessingState.packets = dm->pageContainer.totalPkg;
	dm->dataProcessingState.filteredPackets = dm->pageContainer.totalPkgIdx;	

	//need several seconds , opt ???
	quint32 idx = 0;
	for (idx = 0; idx < dm->pageContainer.totalPkg; ++idx)
	{
		dm->insertPkgIdxPkgIdPair(idx, idx);		
	}

	EELOG_INFO("PcapPkgParser::parseFile|parsed payload num(" 
		<< parsedPkgNum << "), parsed pkg num(" 
		<< dm->pageContainer.totalPkg << ")");

	EELOG_TRACE("Leave PcapPkgParser::parseFile");

	if (!rc)
	{		
		throw EeException(exeInfo);		
	}
}

unsigned PcapPkgParser::getSizeOfEthIPUDPHdr(void)
{
	if (ethIPUDPHdrVer == EE_VAL_ETH_IP_VER_V4)
	{
		return EE_SIZE_ETH_IP_UDP_HEADER_V4;
	}
	else if (ethIPUDPHdrVer == EE_VAL_ETH_IP_VER_V6)
	{
		return EE_SIZE_ETH_IP_UDP_HEADER_V6;
	}
	else
	{
		return EE_SIZE_ETH_IP_UDP_HEADER_NULL;
	}
}