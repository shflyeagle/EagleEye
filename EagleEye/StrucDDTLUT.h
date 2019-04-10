#pragma once

#include "EeCommon.h"
#include "StrucLUT.h"

enum
{
	DDT_TYPE_DSP_SOC_FDD			= 0x14,
	DDT_TYPE_DSP_SOC_TDD			= 0x16,
	DDT_TYPE_DSP_METRO_FDD			= 0x18,
	DDT_TYPE_DSP_BCEM_FDD			= 0x1C,
	DDT_TYPE_DSP_BCEM_TDD			= 0x1F,
	DDT_TYPE_ULT_SOC_FDD			= 0x15,
	DDT_TYPE_ULT_SOC_TDD			= 0x17,
	DDT_TYPE_ULT_METRO_FDD			= 0x19,
	DDT_TYPE_ULT_BCEM_FDD			= 0x1D,
	DDT_TYPE_ULT_BCEM_TDD			= 0x1E,
	DDT_TYPE_DLT_BCEM_FDD_TDD		= 0x2B,
	DDT_TYPE_DLT_BCEM_TDD_INTERNAL  = 0x2F,
	DDT_TYPE_DLT_ECEM				= 0x2A,
	DDT_TYPE_PDCP					= 0x3A,
};

enum
{
	DDT_VER_ULT_BCEM_TDD_V4			= 4,
	DDT_VER_ULT_BCEM_TDD_V5,
	DDT_VER_ULT_BCEM_TDD_V6,
	DDT_VER_ULT_BCEM_TDD_V7,

	DDT_VER_DLT_BCEM_FDD_TDD_V10	= 10,
	DDT_VER_DLT_BCEM_FDD_TDD_V11,
	DDT_VER_DLT_BCEM_FDD_TDD_V12,
	DDT_VER_DLT_BCEM_FDD_TDD_V13,

	DDT_VER_ULT_BCEM_FDD_V16		= 16,
	DDT_VER_ULT_BCEM_FDD_V17,
	DDT_VER_ULT_BCEM_FDD_V18,
	DDT_VER_ULT_BCEM_FDD_V19,
};

enum
{
	DDT_UE_SETUP_TYPE_0 = 0,
	DDT_UE_SETUP_TYPE_1 = 1,
	DDT_UE_SETUP_TYPE_2 = 2,
	DDT_UE_SETUP_TYPE_3 = 3,
	DDT_UE_SETUP_TYPE_NA,
};

enum
{
	DDT_RB_DEL_TYPE_0 = 0,
	DDT_RB_DEL_TYPE_1 = 1,
	DDT_RB_DEL_TYPE_2 = 2,
	DDT_RB_DEL_TYPE_NA,
};

#define DDT_LTE_CT_DOWNLINK     0
#define DDT_LTE_CT_UPLINK       1

#define DDT_LTE_RRC_CT_CCCH     0
#define DDT_LTE_RRC_CT_SRB1     1
#define DDT_LTE_RRC_CT_SRB2     2
#define DDT_LTE_RRC_CT_PCCH     3

#define DDT_LTE_RRC_CT_RLC_MODE_UM_5B   1
#define DDT_LTE_RRC_CT_RLC_MODE_UM_10B  3
#define DDT_LTE_RRC_CT_RLC_MODE_AM      2


#define DDT_LTE_RLC_AM_PDU      0
#define DDT_LTE_RLC_AM_RF_PDU   1

#define DDT_LTE_RLC_AM_PDU_DC_DATA      1
#define DDT_LTE_RLC_AM_PDU_DC_CONTROL   0

#define DDT_LTE_RLC_AM_POLL_NO       0
#define DDT_LTE_RLC_AM_POLL_YES      1

#define DDT_LTE_RLC_FI_FL           0
#define DDT_LTE_RLC_FI_FNL          1
#define DDT_LTE_RLC_FI_NFL          2
#define DDT_LTE_RLC_FI_NFNL         3

///DLT BLOCK
#define DDT_ID_BLOCK0000		    0x0000
#define DDT_ID_BLOCK0001		    0x0001
#define DDT_ID_BLOCK0002		    0x0002
#define DDT_ID_BLOCK0003		    0x0003
#define DDT_ID_BLOCK0004		    0x0004
#define DDT_ID_BLOCK0005		    0x0005
#define DDT_ID_BLOCK0006		    0x0006
#define DDT_ID_BLOCK0007		    0x0007
#define DDT_ID_BLOCK0008		    0x0008
#define DDT_ID_BLOCK0009		    0x0009
#define DDT_ID_BLOCK000A		    0x000A
#define DDT_ID_BLOCK000B		    0x000B
#define DDT_ID_BLOCK0010		    0x0010
#define DDT_ID_BLOCK0011		    0x0011

#define DDT_ID_BLOCK0100		    0x0100
#define DDT_ID_BLOCK0101		    0x0101

#define DDT_ID_BLOCK0200		    0x0200
#define DDT_ID_BLOCK0201		    0x0201
#define DDT_ID_BLOCK0202		    0x0202

#define DDT_ID_BLOCK0300		    0x0300
#define DDT_ID_BLOCK0301		    0x0301

#define DDT_ID_BLOCK0400		    0x0400
#define DDT_ID_BLOCK0401		    0x0401
#define DDT_ID_BLOCK0402		    0x0402
#define DDT_ID_BLOCK0403		    0x0403

#define DDT_ID_BLOCK0500		    0x0500
#define DDT_ID_BLOCK0501		    0x0501
#define DDT_ID_BLOCK0510		    0x0510
#define DDT_ID_BLOCK0511		    0x0511
#define DDT_ID_BLOCK0512		    0x0512
#define DDT_ID_BLOCK0513		    0x0513
#define DDT_ID_BLOCK0514		    0x0514
#define DDT_ID_BLOCK0515		    0x0515

#define DDT_ID_BLOCK0600		    0x0600

#define DDT_ID_BLOCK0700		    0x0700
#define DDT_ID_BLOCK0701		    0x0701

#define DDT_ID_BLOCK0800		    0x0800

#define DDT_ID_BLOCK0900		    0x0900
#define DDT_ID_BLOCK0901		    0x0901

#define DDT_ID_BLOCK0A00		    0x0A00

#define DDT_ID_BLOCK0B00		    0x0B00
#define DDT_ID_BLOCK0B01		    0x0B01

#define DDT_ID_BLOCK0C00		    0x0C00
#define DDT_ID_BLOCK0C01		    0x0C01

#define DDT_ID_BLOCK0F00		    0x0F00
#define DDT_ID_BLOCK0F01		    0x0F01
#define DDT_ID_BLOCK0F02		    0x0F02

#define DDT_ID_UdpHeader_t					0x1600
#define DDT_ID_UdpHeaderCA_t				0x1601
#define DDT_ID_UdpHeaderCATM_162_t			0x1602
#define DDT_ID_UdpHeaderCATM_171_t			0x1603
#define DDT_ID_DDT_t						0x1604
#define DDT_ID_UDPHEADER					STRUC_ID(DDT_TYPE_DLT_BCEM_FDD_TDD, DDT_VER_DLT_BCEM_FDD_TDD_V10, DDT_ID_UdpHeader_t)
#define DDT_ID_UDPHEADERCA					STRUC_ID(DDT_TYPE_DLT_BCEM_FDD_TDD, DDT_VER_DLT_BCEM_FDD_TDD_V10, DDT_ID_UdpHeaderCA_t)
#define DDT_ID_UDPHEADERCATM_LR162			STRUC_ID(DDT_TYPE_DLT_BCEM_FDD_TDD, DDT_VER_DLT_BCEM_FDD_TDD_V10, DDT_ID_UdpHeaderCATM_162_t)
#define DDT_ID_UDPHEADERCATM_LR171			STRUC_ID(DDT_TYPE_DLT_BCEM_FDD_TDD, DDT_VER_DLT_BCEM_FDD_TDD_V10, DDT_ID_UdpHeaderCATM_171_t)
#define DDT_ID_DDT							STRUC_ID(DDT_TYPE_DLT_BCEM_FDD_TDD, DDT_VER_DLT_BCEM_FDD_TDD_V10, DDT_ID_DDT_t)


///ULT BLOCK
//msg2
#define DDT_ID_BLOCK1800		    0x1800
#define DDT_ID_BLOCK1801			0x1801
#define DDT_ID_BLOCK180A		    0x180A
#define DDT_ID_BLOCK180B			0x180B

//phich
#define DDT_ID_BLOCK1900		    0x1900

//sps
#define DDT_ID_BLOCK1A00		    0x1A00
#define DDT_ID_BLOCK1A01		    0x1A01

//RFNS
#define DDT_ID_BLOCK1B00		    0x1B00

//measurement
#define DDT_ID_BLOCK1C00		    0x1C00

//counter
#define DDT_ID_BLOCK1D00		    0x1D00

//misc
#define DDT_ID_BLOCK1E00		    0x1E00

//reserved for legacy
#define DDT_ID_BLOCK1F00		    0x1F00
#define DDT_ID_BLOCK2000		    0x2000
#define DDT_ID_BLOCK2100		    0x2100
#define DDT_ID_BLOCK2200		    0x2200
#define DDT_ID_BLOCK2300		    0x2300
#define DDT_ID_BLOCK2400		    0x2400

//catm
#define DDT_ID_BLOCK2500		    0x2500
#define DDT_ID_BLOCK2501		    0x2501
#define DDT_ID_BLOCK2502		    0x2502
#define DDT_ID_BLOCK2503		    0x2503

#define DDT_ID_BLOCK2600		    0x2600
#define DDT_ID_BLOCK2700		    0x2700

//DCI
#define DDT_DCI_BLOCK_BEGIN			    0x2800
#define DDT_ID_pdcch_pkt_hdr_t			DDT_DCI_BLOCK_BEGIN
#define DDT_ID_pdcch_pkt_hdr_dummy_t	0x2801
#define DDT_ID_mpdcch_pkt_hdr_t			0x2802
#define DDT_ID_mpdcch_pkt_hdr_dummy_t	0x2803
#define DDT_ID_pdcch_pkt_hdr			STRUC_ID(DDT_TYPE_ULT_BCEM_FDD, DDT_VER_ULT_BCEM_FDD_V16, DDT_ID_pdcch_pkt_hdr_t)
#define DDT_ID_pdcch_pkt_hdr_dummy		STRUC_ID(DDT_TYPE_ULT_BCEM_FDD, DDT_VER_ULT_BCEM_FDD_V16, DDT_ID_pdcch_pkt_hdr_dummy_t)
#define DDT_ID_mpdcch_pkt_hdr			STRUC_ID(DDT_TYPE_ULT_BCEM_FDD, DDT_VER_ULT_BCEM_FDD_V16, DDT_ID_mpdcch_pkt_hdr_t)
#define DDT_ID_mpdcch_pkt_hdr_dummy		STRUC_ID(DDT_TYPE_ULT_BCEM_FDD, DDT_VER_ULT_BCEM_FDD_V16, DDT_ID_mpdcch_pkt_hdr_dummy_t)

#define DDT_ID_BLOCK280A		    0x280A
#define DDT_ID_BLOCK280B		    0x280B
#define DDT_ID_BLOCK280C		    0x280C
#define DDT_ID_BLOCK280D		    0x280D
#define DDT_ID_BLOCK280E			0x280E
#define DDT_ID_BLOCK280F		    0x280F
#define DDT_ID_BLOCK2810		    0x2810
#define DDT_ID_BLOCK2811		    0x2811
#define DDT_ID_BLOCK2812		    0x2812
#define DDT_ID_BLOCK2813		    0x2813
#define DDT_ID_BLOCK2814		    0x2814
#define DDT_ID_BLOCK2815		    0x2815
#define DDT_ID_BLOCK2816		    0x2816
#define DDT_ID_BLOCK2817		    0x2817
#define DDT_ID_BLOCK2818		    0x2818
#define DDT_ID_BLOCK2819		    0x2819
#define DDT_ID_BLOCK281A		    0x281A
#define DDT_ID_BLOCK281B		    0x281B
#define DDT_ID_BLOCK281C		    0x281C
#define DDT_ID_BLOCK281D		    0x281D
#define DDT_ID_BLOCK281E		    0x281E
#define DDT_ID_BLOCK281F		    0x281F
#define DDT_ID_BLOCK2820		    0x2820
#define DDT_ID_BLOCK2821		    0x2821
#define DDT_ID_BLOCK2822		    0x2822
#define DDT_ID_BLOCK2823		    0x2823
#define DDT_ID_BLOCK2824		    0x2824
#define DDT_ID_BLOCK2825		    0x2825
#define DDT_ID_BLOCK2826		    0x2826
#define DDT_ID_BLOCK2827		    0x2827

#define DDT_ID_BLOCK2840		    0x2840
#define DDT_ID_BLOCK2841		    0x2841
#define DDT_ID_BLOCK2842		    0x2842
#define DDT_ID_BLOCK2843		    0x2843
#define DDT_DCI_BLOCK_END			DDT_ID_BLOCK2843

//uls call trace
#define DDT_ID_BLOCK3000		    0x3000
#define DDT_ID_ult_ct_hdr_t			0x3001
#define DDT_ID_ult_ct_hdr			STRUC_ID(DDT_TYPE_ULT_BCEM_FDD, DDT_VER_ULT_BCEM_FDD_V16, DDT_ID_ult_ct_hdr_t)


#define DDT_ID_BLOCKINVALID		    0xFFFF


#define DDT_DLT_BLOCK_MAX			0x0F


#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_5MHZ   25
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_10MHZ  27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_15MHZ  27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_CA_UE_SPEC_SPACE_15MHZ 28
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_20MHZ  28
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_CA_UE_SPEC_SPACE_20MHZ 29
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_5MHZ   27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_10MHZ  31
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_15MHZ  33
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_20MHZ  39
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_5MHZ  25
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_10MHZ 27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_15MHZ 27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_CA_UE_SPEC_SPACE_15MHZ 28
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_20MHZ 28
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_CA_UE_SPEC_SPACE_20MHZ 29
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1C_10MHZ 13
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1C_15MHZ 14
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1C_20MHZ 15
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_5MHZ   39
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_10MHZ  43
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_15MHZ  45
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_20MHZ  51
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_5MHZ  36
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_10MHZ 41
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_15MHZ 42
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_20MHZ 48
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_5MHZ_4TX     42
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_10MHZ_4TX    46
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_15MHZ_4TX    48
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_20MHZ_4TX    54
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_5MHZ_4TX    38
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_10MHZ_4TX   42
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_15MHZ_4TX   45
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_20MHZ_4TX   50

#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_5MHZ_TDD     27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_10MHZ_TDD    29
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_15MHZ_TDD    30
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT0_20MHZ_TDD    31
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_5MHZ_TDD     30
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_10MHZ_TDD    34
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_15MHZ_TDD    36
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1_20MHZ_TDD    42
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_5MHZ_TDD    27
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_10MHZ_TDD   29
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_15MHZ_TDD   30
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT1A_20MHZ_TDD   31
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_5MHZ_TDD     42
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_10MHZ_TDD    46
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_15MHZ_TDD    48
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_20MHZ_TDD    54
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_5MHZ_TDD    39
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_10MHZ_TDD   43
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_15MHZ_TDD   45
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_20MHZ_TDD   51
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2B_5MHZ_TDD    39
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2B_10MHZ_TDD   43
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2B_15MHZ_TDD   45
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2B_20MHZ_TDD   51
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2C_10MHZ_TDD   45
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2C_15MHZ_TDD   47
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2C_20MHZ_TDD   53
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_10MHZ_4TX_TDD   45
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_15MHZ_4TX_TDD   47
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2A_20MHZ_4TX_TDD   53
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_10MHZ_4TX_TDD    49
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_15MHZ_4TX_TDD    51
#define ULS_L1_DCI_TRANSPORT_BLK_SIZE_FORMAT2_20MHZ_4TX_TDD    57


#define RES_MPDCCH_DCI_FORMAT_FLAG_FORMAT6_0A_DIFF 0
#define RES_MPDCCH_DCI_FORMAT_FLAG_FORMAT6_1A_DIFF 1
#define RES_MPDCCH_DCI_FORMAT_FLAG_FORMAT6_2_DIFF		 0
#define RES_MPDCCH_DCI_FORMAT_FLAG_FORMAT6_2_PAGING_DIFF 1
#define RES_MPDCCH_N_BITS_DCI_FORMAT6_0A_10MHZ_FDD 29
#define RES_MPDCCH_N_BITS_DCI_FORMAT6_1A_10MHZ_FDD 29
#define RES_MPDCCH_N_BITS_DCI_FORMAT6_2_10MHZ_FDD  12

#define T_CRNTI_UL_PRACH_CONFIG_CATM    0x0000    // Cat-M - 179183
#define T_CRNTI_UL_PRACH_POWER_FIRST    0x0001
#define T_CRNTI_UL_PRACH_POWER_SECOND   0x0002
#define T_CRNTI_PREAMBLE_ID             0x0003
#define T_CRNTI_UL_PRACH_POWER_CATM     0x0004    // Cat-M - 179183
#define T_CRNTI_PREAMBLE_ID_CATM        0x0005    // Cat-M - 179183
#define T_CRNTI_MSG2_INVALID            0xFFFF

typedef enum
{
	TECH_TYPE_FDD = 0,
	TECH_TYPE_TDD,
	TECH_TYPE_NA,
}TechType_t;

typedef enum
{
	DDT_DCI_FORMAT0 = 0,
	DDT_DCI_FORMAT1A = 1,
	DDT_DCI_FORMATNA = 2,
}DciFormatFlag_t;

class DciIdentify
{
public:
	DciIdentify(quint16 dciId, quint16 dciFlag = DDT_DCI_FORMATNA)
	{			
		this->dciId = dciId;
		this->dciFlag = dciFlag;
	}
	quint16 dciId;
	quint16 dciFlag;

};

#define DDT_DCI_KEY(techType, bw, antTx) (techType << 16 | bw << 8 | antTx)
#define DDT_DCI_KEY_FDD_05MHZ_2X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_05, EE_ANT_2TX)
#define DDT_DCI_KEY_FDD_10MHZ_2X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_10, EE_ANT_2TX)
#define DDT_DCI_KEY_FDD_15MHZ_2X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_15, EE_ANT_2TX)
#define DDT_DCI_KEY_FDD_20MHZ_2X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_20, EE_ANT_2TX)
#define DDT_DCI_KEY_FDD_05MHZ_4X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_05, EE_ANT_4TX)
#define DDT_DCI_KEY_FDD_10MHZ_4X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_10, EE_ANT_4TX)
#define DDT_DCI_KEY_FDD_15MHZ_4X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_15, EE_ANT_4TX)
#define DDT_DCI_KEY_FDD_20MHZ_4X		DDT_DCI_KEY(TECH_TYPE_FDD, EE_BANDWIDTH_20, EE_ANT_4TX)
#define DDT_DCI_KEY_TDD_05MHZ_2X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_05, EE_ANT_2TX)
#define DDT_DCI_KEY_TDD_10MHZ_2X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_10, EE_ANT_2TX)
#define DDT_DCI_KEY_TDD_15MHZ_2X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_15, EE_ANT_2TX)
#define DDT_DCI_KEY_TDD_20MHZ_2X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_20, EE_ANT_2TX)
#define DDT_DCI_KEY_TDD_05MHZ_4X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_05, EE_ANT_4TX)
#define DDT_DCI_KEY_TDD_10MHZ_4X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_10, EE_ANT_4TX)
#define DDT_DCI_KEY_TDD_15MHZ_4X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_15, EE_ANT_4TX)
#define DDT_DCI_KEY_TDD_20MHZ_4X		DDT_DCI_KEY(TECH_TYPE_TDD, EE_BANDWIDTH_20, EE_ANT_4TX)

class StrucDDTLUT
{
public:
	static void init();

	static void initStrucLut();

	static void initDciLut();

	static QMap<quint32, QMap<quint16, DciIdentify> > dciLUT;

	static const QMap<quint16, DciIdentify> * curDciLut;

	static void setCurDciLut();

	static const QMap<quint16, DciIdentify> * getCurDciLut();

	static quint16 getDciId(quint16 tbs, quint16 dciFlag);

	static bool isDCIBlock(quint32 sid);

	static QString getDCIFormat(quint32 sid);
};

#define DDT_GET_DCI_ID(tbs, dciFlag) StrucDDTLUT::getDciId(tbs, dciFlag)
#define DDT_IS_DCI_BLOCK(sid)  StrucDDTLUT::isDCIBlock(sid)
#define DDT_GET_DCI_FORMAT(sid) StrucDDTLUT::getDCIFormat(sid)