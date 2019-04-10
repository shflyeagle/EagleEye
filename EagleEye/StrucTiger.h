#pragma once 

#include "EeCommon.h"

#pragma pack(1)

typedef struct{
	quint8 uldlid;
	quint8 filler0;
	quint8 version;
	quint8 cell_id;
	quint8 packet_seq;
	quint8 record_number;
	quint16 pci;
	quint8 filler1;
}TTUdpHeader_t;

typedef struct{
	quint16 traceid:12;
	quint16 type:2;
	quint16 overflow_ind:1;
	quint16 filler0:1;
	quint8 length;
}TTHeader_t;

/////////////////////////////////////
/// TT507
/////////////////////////////////////
typedef struct{
	quint16 ueid:10;
	quint16 sync_state:5;
	quint16 fdfs:1;
	quint16 sfn:12;
	quint16 subframe:4;
	qint16 se_corr;
	qint16 average_wb_sinr_srs_db;
	qint16 wb_combined_srs_db_from_dsp;
}TT507Payload_v0_t;

typedef struct{
	TTUdpHeader_t ttUdpHeader;
	TTHeader_t ttHeader;
}TTHdr_t;

typedef struct{
	TTHdr_t ttHdr;
	TT507Payload_v0_t tt507Payload;
}TT507_v0_t;
