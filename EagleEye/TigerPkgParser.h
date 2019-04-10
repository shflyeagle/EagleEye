#pragma once

#include "EeCommon.h"
#include "PcapPkgParser.h"


class TigerPkgParser :public PcapPkgParser
{
public:
	TigerPkgParser(DataManager *dm);
	~TigerPkgParser();

	bool parsePayload(CompLoc &headerLoc, CompLoc &payloadLoc) override;
};

