#include "TigerPkgParser.h"
#include "DataManager.h"
#include "StrucTigerLUT.h"


TigerPkgParser::TigerPkgParser(DataManager *dm):
PcapPkgParser(dm)
{
}

TigerPkgParser::~TigerPkgParser()
{
}

bool TigerPkgParser::parsePayload(CompLoc &headerLoc, CompLoc &payloadLoc)
{
	char *bufPtr = dm->pkgPageRawData->data();
	quint8 uldlid = EE_BE_GetULDLIdFromTTPayloadHeader(bufPtr + payloadLoc.pos);
	if (!isValidTigerPkg(uldlid))
	{
		EELOG_WARN("TigerPkgParser::parsePayload|invalid pkg with Tag (" << uldlid << ")");
		return true;
	}

	PkgLoc pkgLocComm;
	pkgLocComm.timePos = headerLoc.pos;
	pkgLocComm.headerPos = payloadLoc.pos;
	pkgLocComm.headerLen = EE_SIZE_TIGER_PAYLOAD_HEADER;
	Q_ASSERT(pkgLocComm.headerLen <= 0xFF);

	quint32 pkgPos = payloadLoc.pos + pkgLocComm.headerLen;

	quint8 pkgNum = EE_BE_GetPkgNumFromTTPayloadHeader(bufPtr + pkgLocComm.headerPos);
	quint8 pkgNo = 0;
	for (pkgNo = 0; pkgNo < pkgNum; ++pkgNo)
	{
		quint8 pkgLen = EE_BE_GetPkgLenFromTTPackageHeader(bufPtr + pkgPos);
		quint16 pkgId = EE_BE_GetPkgIdFromTTPackageHeader(bufPtr + pkgPos);

		PkgLoc pkgLoc;		
		pkgLoc.timePos = pkgLocComm.timePos;
		pkgLoc.headerPos = pkgLocComm.headerPos;
		pkgLoc.headerLen = pkgLocComm.headerLen;
		pkgLoc.payloadPos = pkgPos;
		pkgLoc.payloadLen = pkgLen + EE_SIZE_TIGER_PACKAGE_HEADER;
		pkgLoc.misc = pkgId;		

		dm->insertPkgLoc(pkgLoc);

		pkgPos += pkgLoc.payloadLen;
	}

	return true;
}