#pragma once

#include <QtEndian>
#include <QtGlobal>
#define MAX_SIZE_STRUC_POOL_VEC					0xFFFF
#define MAX_NUM_STRUC_POOL						10
#define MAX_NUM_FILTER_KW						6
#define EE_MAX_SIZE_IN_BYTE_PER_PAGE			30 * 1024 * 1024
#define EE_MAX_NUM_RECENT_FILES					5
#define EE_MAX_SIZE_IN_BYTE_PCAP_PACKET			3000
#define EE_MAX_SIZE_PKG_IDX_PER_PAGE			40000
#define EE_MAX_SIZE_PKG_LOC_PER_PAGE			(EE_MAX_SIZE_IN_BYTE_PER_PAGE >> 2)

#define BYTE_ALIGN_4B(x)  (((quint16)(x) + 3) & ~(0x03))

#define STRUC_ID(t, v, n)		((t << 24) | (v << 16) | (n))
#define STRUC_T(id)				(id >> 24)
#define STRUC_V(id)				((id >> 16) & 0x00FF)
#define STRUC_N(id)				(id & 0xFFFF)
#define STRUC_TV(id)			(id >> 16)

#define INVALID_U16				0xFFFF
#define EE_MAX_STRUC_TV			0x1F

enum
{
	EE_STRUC_TYPE_TIGER,
	EE_STRUC_TYPE_DDT,
	EE_STRUC_TYPE_TTI,
};

typedef enum
{
	EE_BANDWIDTH_05 = 0,
	EE_BANDWIDTH_10,
	EE_BANDWIDTH_15,
	EE_BANDWIDTH_20,
	EE_BANDWIDTH_NA,
}BandWidth_t;

typedef enum
{
	EE_ANT_2TX = 0,
	EE_ANT_4TX,
	EE_ANT_NA,
}AntTx_t;

#define EE_RRC_SD_DOWNLINK     0
#define EE_RRC_SD_UPLINK       1

#define EE_RRC_CT_CCCH     0
#define EE_RRC_CT_SRB1     1
#define EE_RRC_CT_SRB2     2
#define EE_RRC_CT_PCCH     3

#define QSTR2CSTR(qstr)	qstr.toStdString().c_str()
#define PTR_CVT_Any2ConstUchar(src)	static_cast<const uchar*>((void*)(src))

inline qint8 EE_BE_GetQINT8(char *src)
{
	return qFromBigEndian<qint8>(PTR_CVT_Any2ConstUchar(src));
}

inline quint8 EE_BE_GetQUINT8(char *src)
{
	return qFromBigEndian<quint8>(PTR_CVT_Any2ConstUchar(src));
}

inline qint16 EE_BE_GetQINT16(char *src)
{
	return qFromBigEndian<qint16>(PTR_CVT_Any2ConstUchar(src));
}

inline quint16 EE_BE_GetQUINT16(char *src)
{
	return qFromBigEndian<quint16>(PTR_CVT_Any2ConstUchar(src));
}

inline qint32 EE_BE_GetQINT32(char *src)
{
	return qFromBigEndian<qint32>(PTR_CVT_Any2ConstUchar(src));
}

inline quint32 EE_BE_GetQUINT32(char *src)
{
	return qFromBigEndian<quint32>(PTR_CVT_Any2ConstUchar(src));
}

inline qint8 EE_LE_GetQINT8(char *src)
{
	return qFromLittleEndian<qint8>(PTR_CVT_Any2ConstUchar(src));
}

inline quint8 EE_LE_GetQUINT8(char *src)
{
	return qFromLittleEndian<quint8>(PTR_CVT_Any2ConstUchar(src));
}

inline qint16 EE_LE_GetQINT16(char *src)
{
	return qFromLittleEndian<qint16>(PTR_CVT_Any2ConstUchar(src));
}

inline quint16 EE_LE_GetQUINT16(char *src)
{
	return qFromLittleEndian<quint16>(PTR_CVT_Any2ConstUchar(src));
}

inline qint32 EE_LE_GetQINT32(char *src)
{
	return qFromLittleEndian<qint32>(PTR_CVT_Any2ConstUchar(src));
}

inline quint32 EE_LE_GetQUINT32(char *src)
{
	return qFromLittleEndian<quint32>(PTR_CVT_Any2ConstUchar(src));
}
