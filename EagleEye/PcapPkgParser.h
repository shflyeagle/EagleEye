#pragma once

#include "AbstractPkgParser.h"

class PcapPkgParser :public AbstractPkgParser
{
public:
	PcapPkgParser(DataManager *dm);
	~PcapPkgParser();

protected:
	void checkFileSanity(void) override;

	void pagesLoad(void) override;

	void parseFile(void) override;

	unsigned getSizeOfEthIPUDPHdr(void);

protected:
	unsigned ethIPUDPHdrVer{ EE_VAL_ETH_IP_VER_V4 };
};

