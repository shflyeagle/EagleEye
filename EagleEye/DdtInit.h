#pragma once

#include "EeCommon.h"
#include "EeLexSymbol.h"
#include "StrucDdtLUT.h"
#include "StrucTreeManager.h"
#include "DdtDataManager.h"
#include "StrucLUT.h"

#define DDT_INIT_LUT()\
do{\
	StrucDDTLUT::init(); \
} while (0);

#define DDT_INIT_DM()\
do{\
	dm = std::shared_ptr<DdtDataManager>(new DdtDataManager(this)); \
} while (0);

#define DDT_INIT()\
do{\
	DDT_INIT_LUT()\
	SLUT_COMM_INIT()\
	DDT_INIT_DM()\
} while (0);
