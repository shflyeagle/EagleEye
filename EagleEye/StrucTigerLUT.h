#pragma once

#include "StrucLUT.h"

#define TT_ID_0x507			0x507
#define TT_ID_0x917			0x917
#define TT_ID_0x801			0x801
#define TT_ID_0x80A			0x80A

class StrucTigerLUT
{
public:
	static void init();
};


inline quint16 EE_BE_GetPkgIdFromTTPackageHeader(char* buf)
{
	quint16 u16_val = EE_BE_GetQUINT16(buf);

	return (u16_val & 0xFFF0) >> 4;
}