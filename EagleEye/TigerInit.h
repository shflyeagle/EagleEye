#pragma once

#include "EeCommon.h"
#include "EeLexSymbol.h"
#include "StrucTigerLUT.h"
#include "StrucTreeManager.h"
#include "TigerDataManager.h"
#include "StrucLUT.h"

#define TIGER_INIT_LUT()\
do{\
	StrucTigerLUT::init(); \
} while (0);

#define TIGER_INIT_DM()\
do{\
	dm = std::shared_ptr<TigerDataManager>(new TigerDataManager(this));\
} while (0);

#define TIGER_INIT()\
do{\
	TIGER_INIT_LUT()\
	SLUT_COMM_INIT()\
	TIGER_INIT_DM()\
} while (0);
