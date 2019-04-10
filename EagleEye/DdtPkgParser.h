#pragma once

#include "EeCommon.h"
#include "PcapPkgParser.h"
#include "StrucDDT.h"
#include "StrucDDTLUT.h"

QDataStream& operator>>(QDataStream& dataStream, DDTUdpHeader_t& ddtUdpHeader);
QDataStream& operator>>(QDataStream& dataStream, DDTUdpHeaderCA_t& ddtUdpHeaderCA);
QDataStream& operator>>(QDataStream& dataStream, ult_ct_hdr_t& ddtUlHeader);

class DdtPkgParser :public PcapPkgParser
{
public:
	DdtPkgParser(DataManager *dm);
	~DdtPkgParser();

	void checkFileSanity(void) override;

	bool parsePayload(CompLoc &headerLoc, CompLoc &payloadLoc) override;

private:
	bool isValidDdtPkg(quint8 ddtType);

	quint16 getDdtTypePos();

	bool parseULT(CompLoc &headerLoc, CompLoc &payloadLoc);

	bool parseDLT(CompLoc &headerLoc, CompLoc &payloadLoc);

	bool isValidDLTPacket(const DDTUdpHeader_t &hdr);

	bool isValidULTPacket(const ult_ct_hdr_t &hdr);

	bool parseDLTblock00(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock01(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock02(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock03(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock04(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock05(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock06(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock07(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock08(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock09(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock10(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock11(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock12(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock13(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock14(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool parseDLTblock15(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc);

	bool isFdd() const
	{
		return TECH_TYPE_FDD == techType;
	}
private:
	quint8 techType{ TECH_TYPE_NA };
};

