#pragma once 

#include "EeCommon.h"

#pragma pack(1)

/////////////////////DLT/////////////////////
typedef struct{
}DDT_t;

typedef struct{
	quint8 traceType;
	quint8 cemCellId;
	quint8 traceVersion;
	quint8 lteCellIndex;
	quint16 sfn : 12;
	quint16 subFrameNumber : 4;
	quint16 cpuOccupancy;
}DDTUdpHeader_t;

typedef struct{
	DDTUdpHeader_t ddtUdpHeader;
	quint32 cellEngineId;
	quint32 associatedCellEngineId[7];
	quint8 associatedLteCellIdList[8];
}DDTUdpHeaderCA_t;

typedef struct{
	DDTUdpHeader_t ddtUdpHeader;
	quint32 isUeCatMSupportEnabled : 1;
	quint32 isMibRepetitionsEnabledForCatM : 1;
	quint32 downlinkSubframeBitmapLCTypeCatM : 1;
	quint32 pci : 9;
	quint32 dLMpdcchNarrowbandNumberCatM : 4;
	quint32 simNarrowbandNumberCatM : 4;
	quint32 startSymbolLCCatM : 4;
	quint32 nbCeLevelCatM : 4;
	quint32 reserved1 : 4;
	quint32 mibContainer : 24;
	quint32 downlinkSubframeBitmapLC40bitsMSBCatM : 8;
	quint32 downlinkSubframeBitmapLC40bitsLSBCatM_or_10bitsCatM;
	quint32 uplinkSubframeBitmapLC10bitsCatM : 10;
	quint32 reserved2 : 2;
	quint32 numberOfPucchRepetitionsMsg4Level0CatM : 4;
	quint32 maxNumberOfPuschRepetitionsCatM : 4;
	quint32 maxNumberOfPdschRepetitionsModeACatM : 4;
	quint32 maxNumberOfPdschRepetitionsModeBCatM : 4;
	quint32 maxNumberOfPagingMpdcchRepetitionsCatM : 4;
	quint32 modificationPeriodCoeffCatM : 3;
	quint32 defaultPagingCycleCatM : 2;
	quint32 nBCatM : 3;
	quint32 siHoppingConfigCommon : 1;
	quint32 reserved3 : 11;
	quint32 sib1LengthCatM : 12;
	quint32 sib1TbsNbRetransIdCatM : 8;
	quint32 nbOfSibItemScheduledCatM : 4;
	quint32 siWindowLengthCatM : 3;
	quint32 siRepetitionPatternCatM : 2;
	quint32 reserved4 : 1;
	quint32 sibBitmapSum : 14;
	quint8 siPeriodicity_NBIdx[8];
	quint32 reserved5[2];
}DDTUdpHeaderCATM_162_t;

typedef struct{
	DDTUdpHeader_t ddtUdpHeader;
	quint32 isUeCatMSupportEnabled : 1;
	quint32 isMibRepetitionsEnabledForCatM : 1;
	quint32 downlinkSubframeBitmapLCTypeCatM : 1;
	quint32 pci : 9;
	quint32 dLMpdcchNarrowbandNumberCatM : 4;
	quint32 simNarrowbandNumberCatM : 4;
	quint32 startSymbolLCCatM : 4;
	quint32 nbCeLevelCatM : 4;
	quint32 reserved1 : 4;
	quint32 mibContainer : 24;
	quint32 downlinkSubframeBitmapLC40bitsMSBCatM : 8;
	quint32 downlinkSubframeBitmapLC40bitsLSBCatM_or_10bitsCatM;
	quint32 uplinkSubframeBitmapLC10bitsCatM : 10;
	quint32 reserved2 : 2;
	quint32 numberOfPucchRepetitionsMsg4Level0CatM : 4;
	quint32 maxNumberOfPuschRepetitionsCatM : 4;
	quint32 maxNumberOfPdschRepetitionsModeACatM : 4;
	quint32 maxNumberOfPdschRepetitionsModeBCatM : 4;
	quint32 maxNumberOfPagingMpdcchRepetitionsCatM : 4;
	quint32 modificationPeriodCoeffCatM : 3;
	quint32 defaultPagingCycleCatM : 2;
	quint32 nBCatM : 3;
	quint32 siHoppingConfigCommon : 1;
	quint32 isCELevel1EnabledCatM : 1;
	quint32 numberOfPucchRepetitionsMsg4Level1CatM : 4;
	quint32 reserved3 : 6;
	quint32 sib1LengthCatM : 12;
	quint32 sib1TbsNbRetransIdCatM : 8;
	quint32 nbOfSibItemScheduledCatM : 4;
	quint32 siWindowLengthCatM : 3;
	quint32 siRepetitionPatternCatM : 2;
	quint32 reserved4 : 1;
	quint32 sibBitmapSum : 14;
	quint8 siPeriodicity_NBIdx[8];
	quint32 pucchNumRepetitionCatM_received_in_last_ue_config : 4;
	quint32 maxNumberOfMpdcchRepetitionCatM_received_in_last_ue_config : 4;
	quint32 reserved5 : 24;
	quint32 reserved6;
}DDTUdpHeaderCATM_171_t;

/////////////////////BLOCK0
typedef struct{
	quint8 blockId;
	quint8 nbOfAddUe;
	quint8 nbOfDelUeorReportUe;
	quint8 TAG_ForNewLen;
	quint16 length;
}B0000_v10_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}FDD_B0000_v10_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}FDD_B0000_v11_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}FDD_B0000_v12_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}FDD_B0000_v13_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}TDD_B0000_v10_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}TDD_B0000_v11_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}TDD_B0000_v12_t;

typedef struct{
	B0000_v10_t cplaneHdr;
}TDD_B0000_v13_t;

typedef struct{
	quint16 ueId;
	quint16 rnti;
	quint8 bearerNumber;
	quint8 setupFlag;
}B0001_v10_t;

typedef struct{
	B0001_v10_t addBearerHdr;
}FDD_B0001_v10_t;

typedef struct{
	B0001_v10_t addBearerHdr;
}TDD_B0001_v10_t;

typedef struct{
	quint32 traceKey;
	quint16 ueId;
	quint16 rnti;
	quint8 bearerNumber;
	quint8 setupFlag;
}B0001_v11_t;

typedef struct{
	B0001_v11_t addBearerHdr;
}FDD_B0001_v11_t;
typedef struct{
	B0001_v11_t addBearerHdr;
}FDD_B0001_v12_t;
typedef struct{
	B0001_v11_t addBearerHdr;
}FDD_B0001_v13_t;

typedef struct{
	B0001_v11_t addBearerHdr;
}TDD_B0001_v11_t;
typedef struct{
	B0001_v11_t addBearerHdr;
}TDD_B0001_v12_t;
typedef struct{
	B0001_v11_t addBearerHdr;
}TDD_B0001_v13_t;

typedef struct{
	quint8 type : 2;
	quint8 SpsConfigReceived : 1;
	quint8 macDrxConfigReceived : 1;
	quint8 caConfigReceived : 1;
	quint8 srsSrCqiConfigReceived : 1;
	quint8 mgConfigReceived : 1;
	quint8 reserved : 1;
}B0002_v10_t;

typedef struct{
	B0002_v10_t ueCfgInfo;
}FDD_B0002_v10_t;
typedef struct{
	B0002_v10_t ueCfgInfo;
}FDD_B0002_v11_t;
typedef struct{
	B0002_v10_t ueCfgInfo;
}FDD_B0002_v12_t;
typedef struct{
	B0002_v10_t ueCfgInfo;
}FDD_B0002_v13_t;

typedef struct{
	B0002_v10_t ueCfgInfo;
}TDD_B0002_v10_t;
typedef struct{
	B0002_v10_t ueCfgInfo;
}TDD_B0002_v11_t;
typedef struct{
	B0002_v10_t ueCfgInfo;
}TDD_B0002_v12_t;
typedef struct{
	B0002_v10_t ueCfgInfo;
}TDD_B0002_v13_t;

typedef struct{
	quint8 type : 2;
	quint8 reserved1 : 1;
	quint8 ltecellIdscell0 : 5;
	quint16 scell0IndexR10 : 5;
	quint16 ltecellIdscell1 : 5;
	quint16 scell1IndexR10 : 5;
	quint16 PUCCHFormat3enable : 1;
	quint16 ltecellIdscell2 : 5;
	quint16 scell2IndexR10 : 5;
	quint16 nbscell : 2;
	quint16 reserved2 : 4;
	quint16 nxPUCCHANList0[4];
	quint16 nxPUCCHANList1[4];
	quint8 aperiodicCSITriggerR10Trigger1;
	quint8 aperiodicCSITriggerR10Trigger2;
}B0003_v10_t;

typedef struct{
	B0003_v10_t ueModif;
}FDD_B0003_v10_t;
typedef struct{
	B0003_v10_t ueModif;
}FDD_B0003_v11_t;
typedef struct{
	B0003_v10_t ueModif;
}FDD_B0003_v12_t;
typedef struct{
	B0003_v10_t ueModif;
}FDD_B0003_v13_t;

typedef struct{
	B0003_v10_t ueModif;
}TDD_B0003_v10_t;
typedef struct{
	B0003_v10_t ueModif;
}TDD_B0003_v11_t;
typedef struct{
	B0003_v10_t ueModif;
}TDD_B0003_v12_t;
typedef struct{
	B0003_v10_t ueModif;
}TDD_B0003_v13_t;

typedef struct{
	quint16 srPUCCHResourceIndex;
	quint8 srConfigurationIndex;
	quint8 reserved;
}srInfo_t;

typedef struct{
	srInfo_t srInfo;
}FDD_B000B_v10_t;
typedef struct{
	srInfo_t srInfo;
}FDD_B000B_v11_t;
typedef struct{
	srInfo_t srInfo;
}FDD_B000B_v12_t;
typedef struct{
	srInfo_t srInfo;
}FDD_B000B_v13_t;

typedef struct{
	srInfo_t srInfo;
}TDD_B000B_v10_t;
typedef struct{
	srInfo_t srInfo;
}TDD_B000B_v11_t;
typedef struct{
	srInfo_t srInfo;
}TDD_B000B_v12_t;
typedef struct{
	srInfo_t srInfo;
}TDD_B000B_v13_t;

typedef struct{
	quint16 srsConfigIndex;
	quint8 srsCyclicShift;
	quint8 srsBandwidth;
	quint8 srsHoppingBandwidth;
	quint8 srsFrequencyDomainPosition;
	quint8 srsTransmissionCom;
	quint8 reserved;
}srsInfo_t;

typedef struct{
	quint16 cqiPucchResourceIndex;
	quint16 cqiPmiConfigIndex;
	quint16 riConfigIndex;
	quint8 wideNarrowBandAndK;
	quint8 reserved;
} periodicCqiInfo_t;

typedef struct{
	quint16 tpcRnti;
	quint8 tpcIndex;
	quint8 reserved;
}tpcInfo_t;

typedef struct{
	quint8 SpsContextId;
	quint8 reserved;
	quint16 SpsCRNTI;
	quint8 SpsTPCRNTI;
	quint8 SpsTPCIndex;
	quint8 sps_period_dl;
	quint8 reserved1;
	quint8 n1PUCCH_ANPersistent[4];
}SpsUeInfo_t;

typedef struct{
	srInfo_t srInfo;
	srsInfo_t srsInfo;
	quint8 cqiMode;
	quint8 isSPSPresent : 1;
	quint8 res : 7;
	quint8 reserved[2];
	periodicCqiInfo_t periodicCqiInfo;
	tpcInfo_t tpcInfo_pucch;
	tpcInfo_t tpcInfo_pusch;
	SpsUeInfo_t spsInfo;
}B0004_v10_t;

typedef struct{
	B0004_v10_t ueSetup;
}FDD_B0004_v10_t;

typedef struct{
	B0004_v10_t ueSetup;
}TDD_B0004_v10_t;

typedef struct{
	srInfo_t srInfo;
	srsInfo_t srsInfo;
	quint8 cqiMode;
	quint8 isSPSPresent : 1;
	quint8 res : 7;
	quint8 reserved[2];
	periodicCqiInfo_t periodicCqiInfo;
	tpcInfo_t tpcInfo_pucch;
	tpcInfo_t tpcInfo_pusch;
	quint8 SpsContextId;
	quint8 sps_period_dl;
	quint16 SpsCRNTI;
	quint8 n1PUCCH_ANPersistent[4];
}B0004_v11_t;

typedef struct{
	B0004_v11_t ueSetup;
}FDD_B0004_v11_t;

typedef struct{
	B0004_v11_t ueSetup;
}TDD_B0004_v11_t;

typedef struct{
	srInfo_t srInfo;
	srsInfo_t srsInfo;
	quint8 cqiMode;
	quint8 isSPSPresent : 1;
	quint8 res : 2;
	quint8 ul_maxHarqTx : 5;
	quint8 reserved[2];
	periodicCqiInfo_t periodicCqiInfo;
	tpcInfo_t tpcInfo_pucch;
	tpcInfo_t tpcInfo_pusch;
	quint8 SpsContextId;
	quint8 sps_period_dl;
	quint16 SpsCRNTI;
	quint8 n1PUCCH_ANPersistent[4];
}B0004_v12_t;

typedef struct{
	B0004_v12_t ueSetup;
}FDD_B0004_v12_t;
typedef struct{
	B0004_v12_t ueSetup;
}FDD_B0004_v13_t;

typedef struct{
	B0004_v12_t ueSetup;
}TDD_B0004_v12_t;
typedef struct{
	B0004_v12_t ueSetup;
}TDD_B0004_v13_t;

typedef struct{
	quint16 lcId : 5;
	quint16 dlSchedulingType : 1;
	quint16 bearerType : 2;
	quint16 isSPS : 1;
	quint16 reserved1 : 3;
	quint16 mimoMode : 2;
	quint16 rlcMode : 2;
	quint8 initialMCSIndexForBearerSetup;
	quint8 harqMaxNumberOfTransmission;
	quint8 qoSClassIdentifier;
	quint8 reserved2;
	quint16 harqMaxTimer;
	quint32 dlGBR;
	quint32 dlMBR;
	quint32 rlcConfigPart0;
	quint32 rlcConfigPart1;
	quint32 ulGbrSPS;
	quint8 nominalMCSforSPSGrantUL;
	quint8 reserved3;
	quint16 threegpprel;
}B0005_v10_t;

typedef struct{
	B0005_v10_t bearerInfo;
}FDD_B0005_v10_t;

typedef struct{
	B0005_v10_t bearerInfo;
}TDD_B0005_v10_t;

typedef struct{
	quint16 lcId : 5;
	quint16 dlSchedulingType : 1;
	quint16 bearerType : 2;
	quint16 isSPS : 1;
	quint16 reserved1 : 3;
	quint16 mimoMode : 2;
	quint16 rlcMode : 2;
	quint8 initialMCSIndexForBearerSetup;
	quint8 harqMaxNumberOfTransmission;
	quint8 qoSClassIdentifier;
	quint8 reserved2;
	quint16 harqMaxTimer;
	quint32 dlGBR;
	quint32 dlMBR;
	quint32 rlcConfigPart0;
	quint32 rlcConfigPart1;
}B0005_v11_t;

typedef struct{
	B0005_v11_t bearerInfo;
}FDD_B0005_v11_t;
typedef struct{
	B0005_v11_t bearerInfo;
}FDD_B0005_v12_t;
typedef struct{
	B0005_v11_t bearerInfo;
}FDD_B0005_v13_t;

typedef struct{
	B0005_v11_t bearerInfo;
}TDD_B0005_v11_t;
typedef struct{
	B0005_v11_t bearerInfo;
}TDD_B0005_v12_t;
typedef struct{
	B0005_v11_t bearerInfo;
}TDD_B0005_v13_t;


typedef struct{
	quint16 rnti;
	quint8 type : 4;
	quint8 bearerNumber : 4;
}B0006_v10_t;

typedef struct{
	B0006_v10_t delBearerHdr;
}FDD_B0006_v10_t;

typedef struct{
	B0006_v10_t delBearerHdr;
}TDD_B0006_v10_t;

typedef struct{
	quint32 traceKey;
	quint16 rnti;
	quint8 type : 4;
	quint8 bearerNumber : 4;
}B0006_v11_t;

typedef struct{
	B0006_v11_t delBearerHdr;
}FDD_B0006_v11_t;
typedef struct{
	B0006_v11_t delBearerHdr;
}FDD_B0006_v12_t;
typedef struct{
	B0006_v11_t delBearerHdr;
}FDD_B0006_v13_t;

typedef struct{
	B0006_v11_t delBearerHdr;
}TDD_B0006_v11_t;
typedef struct{
	B0006_v11_t delBearerHdr;
}TDD_B0006_v12_t;
typedef struct{
	B0006_v11_t delBearerHdr;
}TDD_B0006_v13_t;

typedef struct{
	quint8 lcId;
	quint8 spsConfRelease : 1;
	quint8 voipConfReleased : 1;
	quint8 ueCtxReleased : 1;
	quint8 BrcRbDelCause : 5;
	quint16 spsFreedIdx;
}B0007_v10_t;

typedef struct{
	B0007_v10_t delBearerInfo;
}FDD_B0007_v10_t;
typedef struct{
	B0007_v10_t delBearerInfo;
}FDD_B0007_v11_t;

typedef struct{
	B0007_v10_t delBearerInfo;
}TDD_B0007_v10_t;
typedef struct{
	B0007_v10_t delBearerInfo;
}TDD_B0007_v11_t;

typedef struct{
	quint8 isCatm : 1;
	quint8 spare : 2;
	quint8 lcId : 5;
	quint8 spsConfRelease : 1;
	quint8 voipConfReleased : 1;
	quint8 ueCtxReleased : 1;
	quint8 BrcRbDelCause : 5;
	quint16 spsFreedIdx;
}B0007_v12_t;

typedef struct{
	B0007_v12_t delBearerInfo;
}FDD_B0007_v12_t;
typedef struct{
	B0007_v12_t delBearerInfo;
}FDD_B0007_v13_t;

typedef struct{
	B0007_v12_t delBearerInfo;
}TDD_B0007_v12_t;
typedef struct{
	B0007_v12_t delBearerInfo;
}TDD_B0007_v13_t;

typedef struct{
	quint16 rnti;
	quint8 type : 4;
	quint8 reserved : 4;
}B0008_v10_t;

typedef struct{
	B0008_v10_t ulL1OoS;
}FDD_B0008_v10_t;

typedef struct{
	B0008_v10_t ulL1OoS;
}TDD_B0008_v10_t;

typedef struct{
	quint32 traceKey;
	quint16 rnti;
	quint8 type : 4;
	quint8 reserved : 4;
}B0008_v11_t;

typedef struct{
	B0008_v11_t ulL1OoS;
}FDD_B0008_v11_t;
typedef struct{
	B0008_v11_t ulL1OoS;
}FDD_B0008_v12_t;
typedef struct{
	B0008_v11_t ulL1OoS;
}FDD_B0008_v13_t;

typedef struct{
	B0008_v11_t ulL1OoS;
}TDD_B0008_v11_t;
typedef struct{
	B0008_v11_t ulL1OoS;
}TDD_B0008_v12_t;
typedef struct{
	B0008_v11_t ulL1OoS;
}TDD_B0008_v13_t;

typedef struct{
	quint16 rnti;
	quint8 type : 4;
	quint8 rlc_failure : 4;
	quint8 lcid;
}B0009_v10_t;

typedef struct{
	B0009_v10_t rLCFailure;
}FDD_B0009_v10_t;

typedef struct{
	B0009_v10_t rLCFailure;
}TDD_B0009_v10_t;

typedef struct{
	quint32 traceKey;
	quint16 rnti;
	quint8 type : 4;
	quint8 rlc_failure : 4;
	quint8 lcid;
}B0009_v11_t;

typedef struct{
	B0009_v11_t rLCFailure;
}FDD_B0009_v11_t;
typedef struct{
	B0009_v11_t rLCFailure;
}FDD_B0009_v12_t;
typedef struct{
	B0009_v11_t rLCFailure;
}FDD_B0009_v13_t;

typedef struct{
	B0009_v11_t rLCFailure;
}TDD_B0009_v11_t;
typedef struct{
	B0009_v11_t rLCFailure;
}TDD_B0009_v12_t;
typedef struct{
	B0009_v11_t rLCFailure;
}TDD_B0009_v13_t;


///* SR info to provide to CALL_P (for FDD only) */
///* size = 32 bits, for Cat-M, last u8 = 1 */
typedef struct{
	srInfo_t srInfo;
	quint8 isCatm : 1;
	quint8 ceMode : 1;
	quint8 coverageId : 3;
	quint8 mpdcchStartSFUESS : 3;
	quint8 pucchNumRepetitionCatM : 4;
	quint8 maxNumberOfMpdcchRepetitionCatM : 4;
	quint8 cqiMode : 2;
	quint8 reserved1 : 1;
	quint8 ul_maxHarqTx : 5;
	quint8 reserved2;
}B000A_v12_t;

typedef struct{
	B000A_v12_t ueSetup;
}FDD_B000A_v12_t;
typedef struct{
	B000A_v12_t ueSetup;
}FDD_B000A_v13_t;

typedef struct{
	B000A_v12_t ueSetup;
}TDD_B000A_v12_t;
typedef struct{
	B000A_v12_t ueSetup;
}TDD_B000A_v13_t;

/////////////////////BLOCK1
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0100_v10_t;

typedef struct{
	B0100_v10_t cqiHdr;
}FDD_B0100_v10_t;
typedef struct{
	B0100_v10_t cqiHdr;
}FDD_B0100_v11_t;
typedef struct{
	B0100_v10_t cqiHdr;
}FDD_B0100_v12_t;
typedef struct{
	B0100_v10_t cqiHdr;
}FDD_B0100_v13_t;

typedef struct{
	B0100_v10_t cqiHdr;
}TDD_B0100_v10_t;
typedef struct{
	B0100_v10_t cqiHdr;
}TDD_B0100_v11_t;
typedef struct{
	B0100_v10_t cqiHdr;
}TDD_B0100_v12_t;
typedef struct{
	B0100_v10_t cqiHdr;
}TDD_B0100_v13_t;

typedef struct{
	quint32 rnti : 16;
	quint32 avgSpsSinr : 16;
	quint32 avgPdschSinr : 16;
	quint32 avgPdcchSinr : 16;
	quint32 pcellOrScell : 1;
	quint32 cqiWasValidity : 1;
	quint32 pcqiOrAcqi : 1;
	quint32 rank : 2;
	quint32 pmi : 2;
	quint32 filler : 1;
	quint32 tb1_wbCqi : 4;
	quint32 tb2_wbCqi : 4;
	quint32 tb1_wbSINR : 8;
	quint32 tb2_wbSINR : 8;
}B0101_v10_t;

typedef struct{
	B0101_v10_t cqiUe;
}FDD_B0101_v10_t;
typedef struct{
	B0101_v10_t cqiUe;
}FDD_B0101_v11_t;
typedef struct{
	B0101_v10_t cqiUe;
}FDD_B0101_v12_t;
typedef struct{
	B0101_v10_t cqiUe;
}FDD_B0101_v13_t;

typedef struct{
	B0101_v10_t cqiUe;
}TDD_B0101_v10_t;
typedef struct{
	B0101_v10_t cqiUe;
}TDD_B0101_v11_t;
typedef struct{
	B0101_v10_t cqiUe;
}TDD_B0101_v12_t;
typedef struct{
	B0101_v10_t cqiUe;
}TDD_B0101_v13_t;

/////////////////////BLOCK2
typedef struct{
	quint8 blockId;
	quint8 reserved[3];
	quint16 rach3MacId;
	quint16 rach4MacId;
}B0200_v10_t;

typedef struct{
	B0200_v10_t common01ms;
}FDD_B0200_v10_t;
typedef struct{
	B0200_v10_t common01ms;
}FDD_B0200_v11_t;

typedef struct{
	B0200_v10_t common01ms;
}TDD_B0200_v10_t;
typedef struct{
	B0200_v10_t common01ms;
}TDD_B0200_v11_t;

typedef struct{
	quint8 blockId;
	quint8 isCatm : 1;
	quint8 reserved0 : 7;
	quint8 reserved[2];
	quint16 rach3MacId;
	quint16 rach4MacId;
}B0200_v12_t;

typedef struct{
	B0200_v12_t common01ms;
}FDD_B0200_v12_t;
typedef struct{
	B0200_v12_t common01ms;
}FDD_B0200_v13_t;

typedef struct{
	B0200_v12_t common01ms;
}TDD_B0200_v12_t;
typedef struct{
	B0200_v12_t common01ms;
}TDD_B0200_v13_t;

typedef struct{
	quint8 blockId;
	quint8 reserved[3];
	quint16 rnti;
	quint16 filler;
}B0201_v10_t;

typedef struct{
	B0201_v10_t common01ms;
}FDD_B0201_v10_t;
typedef struct{
	B0201_v10_t common01ms;
}FDD_B0201_v11_t;

typedef struct{
	B0201_v10_t common01ms;
}TDD_B0201_v10_t;
typedef struct{
	B0201_v10_t common01ms;
}TDD_B0201_v11_t;

typedef struct{
	quint8 blockId;
	quint8 isCatm : 1;
	quint8 reserved0 : 7;
	quint8 reserved[2];
	quint16 rnti;
	quint16 filler;
}B0201_v12_t;

typedef struct{
	B0201_v12_t common01ms;
}FDD_B0201_v12_t;
typedef struct{
	B0201_v12_t common01ms;
}FDD_B0201_v13_t;

typedef struct{
	B0201_v12_t common01ms;
}TDD_B0201_v12_t;
typedef struct{
	B0201_v12_t common01ms;
}TDD_B0201_v13_t;

typedef struct{
	quint8 blockId;
	quint8 reserved[3];
	quint16 filler;
	quint16 rnti;
}B0202_v10_t;

typedef struct{
	B0202_v10_t common01ms;
}FDD_B0202_v10_t;
typedef struct{
	B0202_v10_t common01ms;
}FDD_B0202_v11_t;

typedef struct{
	B0202_v10_t common01ms;
}TDD_B0202_v10_t;
typedef struct{
	B0202_v10_t common01ms;
}TDD_B0202_v11_t;

typedef struct{
	quint8 blockId;
	quint8 isCatm : 1;
	quint8 reserved0 : 7;
	quint8 reserved[2];
	quint16 filler;
	quint16 rnti;
}B0202_v12_t;

typedef struct{
	B0202_v12_t common01ms;
}FDD_B0202_v12_t;
typedef struct{
	B0202_v12_t common01ms;
}FDD_B0202_v13_t;

typedef struct{
	B0202_v12_t common01ms;
}TDD_B0202_v12_t;
typedef struct{
	B0202_v12_t common01ms;
}TDD_B0202_v13_t;

/////////////////////BLOCK3
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0300_v10_t;

typedef struct{
	B0300_v10_t multiUe01msHdr;
}FDD_B0300_v10_t;
typedef struct{
	B0300_v10_t multiUe01msHdr;
}FDD_B0300_v11_t;
typedef struct{
	B0300_v10_t multiUe01msHdr;
}FDD_B0300_v12_t;
typedef struct{
	B0300_v10_t multiUe01msHdr;
}FDD_B0300_v13_t;

typedef struct{
	B0300_v10_t multiUe01msHdr;
}TDD_B0300_v10_t;
typedef struct{
	B0300_v10_t multiUe01msHdr;
}TDD_B0300_v11_t;
typedef struct{
	B0300_v10_t multiUe01msHdr;
}TDD_B0300_v12_t;
typedef struct{
	B0300_v10_t multiUe01msHdr;
}TDD_B0300_v13_t;

typedef struct{
	quint16 rnti;
	quint8 TA : 1;
	quint8 VOIP : 1;
	quint8 BE : 1;
	quint8 GBR : 1;
	quint8 reserved : 4;
}B0301_v10_t;

typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}FDD_B0301_v10_t;
typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}FDD_B0301_v11_t;
typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}FDD_B0301_v12_t;
typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}FDD_B0301_v13_t;

typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}TDD_B0301_v10_t;
typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}TDD_B0301_v11_t;
typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}TDD_B0301_v12_t;
typedef struct{
	B0301_v10_t multiUe01msBearerEligible;
}TDD_B0301_v13_t;

/////////////////////BLOCK4
typedef struct{
	quint8 blockId;
	quint16 spare;
}B0400_v10_t;

typedef struct{
	B0400_v10_t sch01msHdr;
}FDD_B0400_v10_t;
typedef struct{
	B0400_v10_t sch01msHdr;
}FDD_B0400_v11_t;
typedef struct{
	B0400_v10_t sch01msHdr;
}FDD_B0400_v12_t;
typedef struct{
	B0400_v10_t sch01msHdr;
}FDD_B0400_v13_t;

typedef struct{
	B0400_v10_t sch01msHdr;
}TDD_B0400_v10_t;
typedef struct{
	B0400_v10_t sch01msHdr;
}TDD_B0400_v11_t;
typedef struct{
	B0400_v10_t sch01msHdr;
}TDD_B0400_v12_t;
typedef struct{
	B0400_v10_t sch01msHdr;
}TDD_B0400_v13_t;

typedef struct{
	quint8 blockId;
	quint16 spare;
	quint8 TimeFreqResBlockOccMatrix[25];
	quint32 ListOfUsers[42];
}B0401_v10_t;

typedef struct{
	B0401_v10_t sch01msBloc;
}FDD_B0401_v10_t;
typedef struct{
	B0401_v10_t sch01msBloc;
}FDD_B0401_v11_t;
typedef struct{
	B0401_v10_t sch01msBloc;
}FDD_B0401_v12_t;
typedef struct{
	B0401_v10_t sch01msBloc;
}FDD_B0401_v13_t;

typedef struct{
	B0401_v10_t sch01msBloc;
}TDD_B0401_v10_t;
typedef struct{
	B0401_v10_t sch01msBloc;
}TDD_B0401_v11_t;
typedef struct{
	B0401_v10_t sch01msBloc;
}TDD_B0401_v12_t;
typedef struct{
	B0401_v10_t sch01msBloc;
}TDD_B0401_v13_t;

typedef struct{
	quint32 rnti : 16;
	quint32 LCID : 5;
	quint32 HARQId : 4;
	quint32 MimoState : 1;
	quint32 MimoSched : 1;
	quint32 CW0Sched : 2;
	quint32 CW1Sched : 2;
	quint32 pcellOrScell : 1;
	quint32 cw0_snr : 8;
	quint32 cw0_blerOffset : 16;
	quint32 cw0_mcs : 8;
	quint32 cw1_snr : 8;
	quint32 cw1_blerOffset : 16;
	quint32 cw1_mcs : 8;
}B0402_v10_t;

typedef struct{
	B0402_v10_t sch01ms;
}FDD_B0402_v10_t;
typedef struct{
	B0402_v10_t sch01ms;
}FDD_B0402_v11_t;
typedef struct{
	B0402_v10_t sch01ms;
}FDD_B0402_v12_t;
typedef struct{
	B0402_v10_t sch01ms;
}FDD_B0402_v13_t;

typedef struct{
	B0402_v10_t sch01ms;
}TDD_B0402_v10_t;
typedef struct{
	B0402_v10_t sch01ms;
}TDD_B0402_v11_t;
typedef struct{
	B0402_v10_t sch01ms;
}TDD_B0402_v12_t;
typedef struct{
	B0402_v10_t sch01ms;
}TDD_B0402_v13_t;

typedef struct{
	quint8 TimeFreqResBlockOccMatrix[25];
}B0403_v10_t;

typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}FDD_B0403_v10_t;
typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}FDD_B0403_v11_t;
typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}FDD_B0403_v12_t;
typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}FDD_B0403_v13_t;

typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}TDD_B0403_v10_t;
typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}TDD_B0403_v11_t;
typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}TDD_B0403_v12_t;
typedef struct{
	B0403_v10_t timeFreqResBlockOcc;
}TDD_B0403_v13_t;

/////////////////////BLOCK5
typedef struct{
	quint8 blockId;
	quint16 RLC_HeadersLength;
}B0500_v10_t;

typedef struct{
	B0500_v10_t rlc;
}FDD_B0500_v10_t;
typedef struct{
	B0500_v10_t rlc;
}FDD_B0500_v11_t;
typedef struct{
	B0500_v10_t rlc;
}FDD_B0500_v12_t;
typedef struct{
	B0500_v10_t rlc;
}FDD_B0500_v13_t;

typedef struct{
	B0500_v10_t rlc;
}TDD_B0500_v10_t;
typedef struct{
	B0500_v10_t rlc;
}TDD_B0500_v11_t;
typedef struct{
	B0500_v10_t rlc;
}TDD_B0500_v12_t;
typedef struct{
	B0500_v10_t rlc;
}TDD_B0500_v13_t;

typedef struct{
	quint8 Length;
	quint16 rnti;
	quint32 rlcDlBufferSize;
	quint32 ltecellidscell : 5;
	quint32 pcellOrScell : 1;
	quint32 PDUSize : 14;
	quint32 nbSegment : 4;
	quint32 UlDl : 1;
	quint32 RlcMode : 2;
	quint32 LCID : 5;
	quint8 Data;
}B0501_v10_t;

typedef struct{
	B0501_v10_t rlcHeader;
}FDD_B0501_v10_t;
typedef struct{
	B0501_v10_t rlcHeader;
}FDD_B0501_v11_t;
typedef struct{
	B0501_v10_t rlcHeader;
}FDD_B0501_v12_t;
typedef struct{
	B0501_v10_t rlcHeader;
}FDD_B0501_v13_t;

typedef struct{
	B0501_v10_t rlcHeader;
}TDD_B0501_v10_t;
typedef struct{
	B0501_v10_t rlcHeader;
}TDD_B0501_v11_t;
typedef struct{
	B0501_v10_t rlcHeader;
}TDD_B0501_v12_t;
typedef struct{
	B0501_v10_t rlcHeader;
}TDD_B0501_v13_t;

typedef struct{
	quint8 FI : 2;
	quint8 E : 1;
	quint8 SN : 5;
}rlcUM5bHdr_t;

typedef struct{
	quint8 R1 : 3;
	quint8 FI : 2;
	quint8 E : 1;
	quint8 SN_2B : 2;
	quint8 SN_8B;
}rlcUM10bHdr_t;

typedef struct{
	quint8 DC : 1;
	quint8 RF : 1;
	quint8 P : 1;
	quint8 FI : 2;
	quint8 E : 1;
	quint8 SN_2B : 2;
	quint8 SN_8B;
}rlcAMDataHdr_t;

typedef struct{
	quint8 DC : 1;
	quint8 RF : 1;
	quint8 P : 1;
	quint8 FI : 2;
	quint8 E : 1;
	quint8 SN_2B : 2;
	quint8 SN_8B;
	quint8 LSF : 1;
	quint8 SO_7B : 7;
	quint8 SO_8B;
}rlcAMDataRFHdr_t;

typedef struct{
	quint8 DC : 1;
	quint8 CPT : 3;
	quint8 ACK_SN_4B : 4;
	quint8 ACK_SN_6B : 6;
	quint8 E1 : 1;
	quint8 NACK_SN_1B_1 : 1;
}rlcAMCtrlHdr_t;

typedef struct{
	quint8 DC : 1;
	quint8 CPT : 3;
	quint8 ACK_SN_4B : 4;
	quint8 ACK_SN_6B : 6;
	quint8 E1 : 1;
	quint8 NACK_SN_1B_1 : 1;
	quint8 NACK_SN_8B;
	quint8 NACK_SN_1B_2 : 1;
	quint8 E1_2 : 1;
	quint8 E2_2 : 1;
	quint8 NACK_SN_2_5B : 5;
}rlcAMCtrlEHdr_t;

/////////////////////BLOCK6
typedef struct{
	quint8 blockId;
	quint8 nbOfTraces;
	quint16 totalSize;
	quint32 upaLoadVersion;
}B0600_v10_t;

typedef struct{
	B0600_v10_t designTrace;
}FDD_B0600_v10_t;
typedef struct{
	B0600_v10_t designTrace;
}FDD_B0600_v11_t;
typedef struct{
	B0600_v10_t designTrace;
}FDD_B0600_v12_t;
typedef struct{
	B0600_v10_t designTrace;
}FDD_B0600_v13_t;

typedef struct{
	B0600_v10_t designTrace;
}TDD_B0600_v10_t;
typedef struct{
	B0600_v10_t designTrace;
}TDD_B0600_v11_t;
typedef struct{
	B0600_v10_t designTrace;
}TDD_B0600_v12_t;
typedef struct{
	B0600_v10_t designTrace;
}TDD_B0600_v13_t;

/////////////////////BLOCK7
typedef struct{
	quint8 blockId;
	quint8 nbOfSignalingInfo;
	quint16 totalSize;
}B0700_v10_t;

typedef struct{
	B0700_v10_t dcchCcchHdr;
}FDD_B0700_v10_t;
typedef struct{
	B0700_v10_t dcchCcchHdr;
}FDD_B0700_v11_t;
typedef struct{
	B0700_v10_t dcchCcchHdr;
}FDD_B0700_v12_t;
typedef struct{
	B0700_v10_t dcchCcchHdr;
}FDD_B0700_v13_t;

typedef struct{
	B0700_v10_t dcchCcchHdr;
}TDD_B0700_v10_t;
typedef struct{
	B0700_v10_t dcchCcchHdr;
}TDD_B0700_v11_t;
typedef struct{
	B0700_v10_t dcchCcchHdr;
}TDD_B0700_v12_t;
typedef struct{
	B0700_v10_t dcchCcchHdr;
}TDD_B0700_v13_t;

typedef struct{
	quint16 signalingInfoLength;
	quint16 rnti;
	quint8 reserved : 2;
	quint8 channelType : 5;
	quint8 signalingInfoDirection : 1;
}B0701_v10_t;

typedef struct{
	B0701_v10_t dcchCcchInfo;
}FDD_B0701_v10_t;
typedef struct{
	B0701_v10_t dcchCcchInfo;
}FDD_B0701_v11_t;

typedef struct{
	B0701_v10_t dcchCcchInfo;
}TDD_B0701_v10_t;
typedef struct{
	B0701_v10_t dcchCcchInfo;
}TDD_B0701_v11_t;

typedef struct{
	quint16 signalingInfoLength;
	quint16 rnti;
	quint8 isCatm : 1;
	quint8 reserved : 1;
	quint8 channelType : 5;
	quint8 signalingInfoDirection : 1;
}B0701_v12_t;

typedef struct{
	B0701_v12_t dcchCcchInfo;
}FDD_B0701_v12_t;
typedef struct{
	B0701_v12_t dcchCcchInfo;
}FDD_B0701_v13_t;

typedef struct{
	B0701_v12_t dcchCcchInfo;
}TDD_B0701_v12_t;
typedef struct{
	B0701_v12_t dcchCcchInfo;
}TDD_B0701_v13_t;

/////////////////////BLOCK8
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0800_v10_t;

typedef struct{
	B0800_v10_t usersSpeedHdr;
}FDD_B0800_v10_t;
typedef struct{
	B0800_v10_t usersSpeedHdr;
}FDD_B0800_v11_t;
typedef struct{
	B0800_v10_t usersSpeedHdr;
}FDD_B0800_v12_t;
typedef struct{
	B0800_v10_t usersSpeedHdr;
}FDD_B0800_v13_t;

typedef struct{
	B0800_v10_t usersSpeedHdr;
}TDD_B0800_v10_t;
typedef struct{
	B0800_v10_t usersSpeedHdr;
}TDD_B0800_v11_t;
typedef struct{
	B0800_v10_t usersSpeedHdr;
}TDD_B0800_v12_t;
typedef struct{
	B0800_v10_t usersSpeedHdr;
}TDD_B0800_v13_t;

typedef struct{
	quint16 macId;
	quint8 speed;
}B0801_v10_t;

typedef struct{
	B0801_v10_t usersSpeed;
}FDD_B0801_v10_t;
typedef struct{
	B0801_v10_t usersSpeed;
}FDD_B0801_v11_t;
typedef struct{
	B0801_v10_t usersSpeed;
}FDD_B0801_v12_t;
typedef struct{
	B0801_v10_t usersSpeed;
}FDD_B0801_v13_t;

typedef struct{
	B0801_v10_t usersSpeed;
}TDD_B0801_v10_t;
typedef struct{
	B0801_v10_t usersSpeed;
}TDD_B0801_v11_t;
typedef struct{
	B0801_v10_t usersSpeed;
}TDD_B0801_v12_t;
typedef struct{
	B0801_v10_t usersSpeed;
}TDD_B0801_v13_t;

/////////////////////BLOCK9
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0900_v10_t;

typedef struct{
	B0900_v10_t usersMimoStateHdr;
}FDD_B0900_v10_t;
typedef struct{
	B0900_v10_t usersMimoStateHdr;
}FDD_B0900_v11_t;
typedef struct{
	B0900_v10_t usersMimoStateHdr;
}FDD_B0900_v12_t;
typedef struct{
	B0900_v10_t usersMimoStateHdr;
}FDD_B0900_v13_t;

typedef struct{
	B0900_v10_t usersMimoStateHdr;
}TDD_B0900_v10_t;
typedef struct{
	B0900_v10_t usersMimoStateHdr;
}TDD_B0900_v11_t;
typedef struct{
	B0900_v10_t usersMimoStateHdr;
}TDD_B0900_v12_t;
typedef struct{
	B0900_v10_t usersMimoStateHdr;
}TDD_B0900_v13_t;

typedef struct{
	quint16 rnti;
	quint8 pcellOrScell : 1;
	quint8 transmissionMode : 3;
	quint8 mimoMode : 4;
}B0901_v10_t;

typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}FDD_B0901_v10_t;
typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}FDD_B0901_v11_t;
typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}FDD_B0901_v12_t;
typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}FDD_B0901_v13_t;

typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}TDD_B0901_v10_t;
typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}TDD_B0901_v11_t;
typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}TDD_B0901_v12_t;
typedef struct{
	B0901_v10_t ueMimoStoreInfo;
}TDD_B0901_v13_t;

/////////////////////BLOCK10
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0A00_v10_t;

typedef struct{
	B0A00_v10_t acqiListHdr;
}FDD_B0A00_v10_t;
typedef struct{
	B0A00_v10_t acqiListHdr;
}FDD_B0A00_v11_t;
typedef struct{
	B0A00_v10_t acqiListHdr;
}FDD_B0A00_v12_t;
typedef struct{
	B0A00_v10_t acqiListHdr;
}FDD_B0A00_v13_t;

typedef struct{
	B0A00_v10_t acqiListHdr;
}TDD_B0A00_v10_t;
typedef struct{
	B0A00_v10_t acqiListHdr;
}TDD_B0A00_v11_t;
typedef struct{
	B0A00_v10_t acqiListHdr;
}TDD_B0A00_v12_t;
typedef struct{
	B0A00_v10_t acqiListHdr;
}TDD_B0A00_v13_t;

/////////////////////BLOCK11
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0B00_v10_t;

typedef struct{
	B0B00_v10_t mGHdr;
}FDD_B0B00_v10_t;
typedef struct{
	B0B00_v10_t mGHdr;
}FDD_B0B00_v11_t;
typedef struct{
	B0B00_v10_t mGHdr;
}FDD_B0B00_v12_t;
typedef struct{
	B0B00_v10_t mGHdr;
}FDD_B0B00_v13_t;

typedef struct{
	B0B00_v10_t mGHdr;
}TDD_B0B00_v10_t;
typedef struct{
	B0B00_v10_t mGHdr;
}TDD_B0B00_v11_t;
typedef struct{
	B0B00_v10_t mGHdr;
}TDD_B0B00_v12_t;
typedef struct{
	B0B00_v10_t mGHdr;
}TDD_B0B00_v13_t;

typedef struct{
	quint16 rnti;
	quint8 startStopMeasGap : 1;
	quint8 measurementGapsPeriod : 1;
	quint8 filler : 6;
	quint8 measurementGapsOffset;
}B0B01_v10_t;

typedef struct{
	B0B01_v10_t mG;
}FDD_B0B01_v10_t;
typedef struct{
	B0B01_v10_t mG;
}FDD_B0B01_v11_t;
typedef struct{
	B0B01_v10_t mG;
}FDD_B0B01_v12_t;
typedef struct{
	B0B01_v10_t mG;
}FDD_B0B01_v13_t;

typedef struct{
	B0B01_v10_t mG;
}TDD_B0B01_v10_t;
typedef struct{
	B0B01_v10_t mG;
}TDD_B0B01_v11_t;
typedef struct{
	B0B01_v10_t mG;
}TDD_B0B01_v12_t;
typedef struct{
	B0B01_v10_t mG;
}TDD_B0B01_v13_t;

/////////////////////BLOCK12
typedef struct{
	quint8 blockId;
	quint8 nbOfUe;
}B0C00_v10_t;

typedef struct{
	B0C00_v10_t an2HarqHdr;
}FDD_B0C00_v10_t;
typedef struct{
	B0C00_v10_t an2HarqHdr;
}FDD_B0C00_v11_t;
typedef struct{
	B0C00_v10_t an2HarqHdr;
}FDD_B0C00_v12_t;
typedef struct{
	B0C00_v10_t an2HarqHdr;
}FDD_B0C00_v13_t;

typedef struct{
	B0C00_v10_t an2HarqHdr;
}TDD_B0C00_v10_t;
typedef struct{
	B0C00_v10_t an2HarqHdr;
}TDD_B0C00_v11_t;
typedef struct{
	B0C00_v10_t an2HarqHdr;
}TDD_B0C00_v12_t;
typedef struct{
	B0C00_v10_t an2HarqHdr;
}TDD_B0C00_v13_t;

typedef struct{
	quint16 rnti;
	quint8 pcellOrScell : 1;
	quint8 dtx : 1;
	quint8 harq0_harqId : 3;
	quint8 harq0_nbAckInfo : 1;
	quint8 harq0_tb1_ackInfo : 1;
	quint8 harq0_tb2_ackInfo : 1;
}f_B0C01_v10_t;

typedef struct{
	f_B0C01_v10_t hardInfo;
}FDD_B0C01_v10_t;
typedef struct{
	f_B0C01_v10_t hardInfo;
}FDD_B0C01_v11_t;
typedef struct{
	f_B0C01_v10_t hardInfo;
}FDD_B0C01_v12_t;
typedef struct{
	f_B0C01_v10_t hardInfo;
}FDD_B0C01_v13_t;

typedef struct{
	quint16 rnti;
	quint16 pcellOrScell : 1;
	quint16 dtx : 1;
	quint16 harq0_harqId : 4;
	quint16 harq0_nbAckInfo : 1;
	quint16 harq0_tb1_ackInfo : 1;
	quint16 harq0_tb2_ackInfo : 1;
	quint16 harq1_harqId : 4;
	quint16 harq1_nbAckInfo : 1;
	quint16 harq1_tb1_ackInfo : 1;
	quint16 harq1_tb2_ackInfo : 1;
	quint16 harq2_harqId : 4;
	quint16 harq2_nbAckInfo : 1;
	quint16 harq2_tb1_ackInfo : 1;
	quint16 harq2_tb2_ackInfo : 1;
	quint16 harq3_harqId : 4;
	quint16 harq3_nbAckInfo : 1;
	quint16 harq3_tb1_ackInfo : 1;
	quint16 harq3_tb2_ackInfo : 1;
	quint16 filler : 2;
}t_B0C01_v10_t;

typedef struct{
	t_B0C01_v10_t hardInfo;
}TDD_B0C01_v10_t;
typedef struct{
	t_B0C01_v10_t hardInfo;
}TDD_B0C01_v11_t;
typedef struct{
	t_B0C01_v10_t hardInfo;
}TDD_B0C01_v12_t;
typedef struct{
	t_B0C01_v10_t hardInfo;
}TDD_B0C01_v13_t;

/////////////////////BLOCK15
typedef struct{
	quint8 blockId;
	quint8 nbOfUeCAmonitor : 1;
	quint8 nbOfUeCAactivation : 1;
	quint8 length : 6;
}B0F00_v10_t;

typedef struct{
	B0F00_v10_t usersCaState;
}FDD_B0F00_v10_t;
typedef struct{
	B0F00_v10_t usersCaState;
}FDD_B0F00_v11_t;
typedef struct{
	B0F00_v10_t usersCaState;
}FDD_B0F00_v12_t;
typedef struct{
	B0F00_v10_t usersCaState;
}FDD_B0F00_v13_t;

typedef struct{
	B0F00_v10_t usersCaState;
}TDD_B0F00_v10_t;
typedef struct{
	B0F00_v10_t usersCaState;
}TDD_B0F00_v11_t;
typedef struct{
	B0F00_v10_t usersCaState;
}TDD_B0F00_v12_t;
typedef struct{
	B0F00_v10_t usersCaState;
}TDD_B0F00_v13_t;

typedef struct{
	quint16 rnti;
	quint16 reserved2 : 1;
	quint16 lteCellIndex_Scell2 : 5;
	quint16 lteCellIndex_Scell1 : 5;
	quint16 lteCellIndex_Scell0 : 5;
	quint16 caConfigState : 3;
	quint16 ultdlttriggercmd : 2;
	quint16 outofrangecqi : 4;
	quint16 caactivationstatus : 4;
	quint16 reserved1 : 3;
	quint16 rlcbufferoccupancy;
}B0F01_v10_t;

typedef struct{
	B0F01_v10_t ueCAmonitor;
}FDD_B0F01_v10_t;

typedef struct{
	B0F01_v10_t ueCAmonitor;
}TDD_B0F01_v10_t;

typedef struct{
	quint16 rnti;
	quint16 reserved2 : 1;
	quint16 lteCellIndex_Scell2 : 5;
	quint16 lteCellIndex_Scell1 : 5;
	quint16 lteCellIndex_Scell0 : 5;
	quint16 reserved : 1;
	quint16 caConfigState : 3;
	quint16 outofrangecqi : 4;
	quint16 caactivationstatus : 4;
	quint16 preselectioncriteria : 4;
	quint16 reserved1 : 6;
	quint16 ultdltullinkbudgetmetric : 10;
	quint16 rlcbufferoccupancy;
}B0F01_v11_t;

typedef struct{
	B0F01_v11_t ueCAmonitor;
}FDD_B0F01_v11_t;
typedef struct{
	B0F01_v11_t ueCAmonitor;
}FDD_B0F01_v12_t;
typedef struct{
	B0F01_v11_t ueCAmonitor;
}FDD_B0F01_v13_t;


typedef struct{
	B0F01_v11_t ueCAmonitor;
}TDD_B0F01_v11_t;
typedef struct{
	B0F01_v11_t ueCAmonitor;
}TDD_B0F01_v12_t;
typedef struct{
	B0F01_v11_t ueCAmonitor;
}TDD_B0F01_v13_t;

typedef struct{
	quint16 rnti;
	quint16 reserved2 : 1;
	quint16 lteCellIndex_Scell2 : 5;
	quint16 lteCellIndex_Scell1 : 5;
	quint16 lteCellIndex_Scell0 : 5;
	quint16 ueCAstateScell2 : 4;
	quint16 ueCAstateScell1 : 4;
	quint16 ueCAstateScell0 : 4;
	quint16 caDeactivationTrafficThroughput : 4;
	quint16 caConfigState : 3;
	quint16 caTrafficCriteria : 2;
	quint16 caRadioCriteria : 4;
	quint16 caScellEffecLoadCriteria : 5;
	quint16 caNbScelleligibleActivation : 2;
	quint16 caActivationUEcategorycriteria : 1;
	quint16 caScellCoverageStatus : 3;
	quint16 caMultiScellPRBloadcriteria : 1;
	quint16 caMultiScellUECategorycriteria1 : 1;
	quint16 caMultiScellUECategorycriteria2 : 1;
	quint16 reserved : 9;
}B0F02_v10_t;

typedef struct{
	B0F02_v10_t ueCAactivation;
}FDD_B0F02_v10_t;

typedef struct{
	B0F02_v10_t ueCAactivation;
}TDD_B0F02_v10_t;

typedef struct{
	quint16 rnti;
	quint16 reserved2 : 1;
	quint16 lteCellIndex_Scell2 : 5;
	quint16 lteCellIndex_Scell1 : 5;
	quint16 lteCellIndex_Scell0 : 5;
	quint16 ueCAstateScell2 : 4;
	quint16 ueCAstateScell1 : 4;
	quint16 ueCAstateScell0 : 4;
	quint16 caDeactivationTrafficThroughput : 4;
	quint16 caConfigState : 3;
	quint16 caTrafficCriteria : 2;
	quint16 caRadioCriteria : 4;
	quint16 caScellEffecLoadCriteria : 5;
	quint16 caNbScelleligibleActivation : 2;
	quint16 caActivationUEcategorycriteria : 1;
	quint16 caScellCoverageStatus : 3;
	quint16 caMultiScellPRBloadcriteria : 1;
	quint16 caMultiScellUECategorycriteria1 : 1;
	quint16 caMultiScellUECategorycriteria2 : 1;
	quint16 ulSinrCriteria : 2;
	quint16 reserved : 7;
}B0F02_v11_t;

typedef struct{
	B0F02_v11_t ueCAactivation;
}FDD_B0F02_v11_t;

typedef struct{
	B0F02_v11_t ueCAactivation;
}TDD_B0F02_v11_t;

typedef struct{
	quint16 rnti;
	quint16 reserved2 : 1;
	quint16 lteCellIndex_Scell2 : 5;
	quint16 lteCellIndex_Scell1 : 5;
	quint16 lteCellIndex_Scell0 : 5;
	quint16 ueCAstateScell2 : 4;
	quint16 ueCAstateScell1 : 4;
	quint16 ueCAstateScell0 : 4;
	quint16 caDeactivationTrafficThroughput : 4;
	quint16 caConfigState : 3;
	quint16 caTrafficCriteria : 2;
	quint16 caRadioCriteria : 4;
	quint16 caScellEffecLoadCriteria : 5;
	quint16 caNbScelleligibleActivation : 2;
	quint16 caActivationUEcategorycriteria : 1;
	quint16 caScellCoverageStatus : 3;
	quint16 caMultiScellPRBloadcriteria : 1;
	quint16 caMultiScellUECategorycriteria1 : 1;
	quint16 caMultiScellUECategorycriteria2 : 1;
	quint16 acqiCapable : 3;
	quint16 acqiBundlingCapable : 2;
	quint16 caCapable : 1;
	quint16 reserved : 3;
}B0F02_v12_t;

typedef struct{
	B0F02_v12_t ueCAactivation;
}FDD_B0F02_v12_t;
typedef struct{
	B0F02_v12_t ueCAactivation;
}FDD_B0F02_v13_t;

typedef struct{
	B0F02_v12_t ueCAactivation;
}TDD_B0F02_v12_t;
typedef struct{
	B0F02_v12_t ueCAactivation;
}TDD_B0F02_v13_t;

/////////////////////ULT/////////////////////
/////////////////////MSG2
typedef struct{
	quint32 r_flag : 1;
	quint32 timing_advance : 11;
	quint32	hopping_flag : 1;
	quint32 fixed_rb_assignment : 10;
	quint32 mcs_truncated : 4;
	quint32 TPC_pusch : 3;
	quint32 Ul_delay : 1;
	quint32 cqi_request_flag : 1;
	quint32	rnti : 16;
	quint32	iot_db_lt : 8;
	quint32	spare : 3;
	quint32	v_rfns : 1;
	quint32	v_ueA : 1;
	quint32	v_ueB : 1;
	quint32	v_ueC : 1;
	quint32	v_ueD : 1;
}B1800_lr151_t;

typedef struct{
	B1800_lr151_t rach_msg2;
}FDD_B1800_v16_t;
typedef struct{
	B1800_lr151_t rach_msg2;
}FDD_B1800_v17_t;
typedef struct{
	B1800_lr151_t rach_msg2;
}FDD_B1800_v18_t;
typedef struct{
	B1800_lr151_t rach_msg2;
}FDD_B1800_v19_t;

typedef struct{
	B1800_lr151_t rach_msg2;
}TDD_B1800_v4_t;
typedef struct{
	B1800_lr151_t rach_msg2;
}TDD_B1800_v5_t;
typedef struct{
	B1800_lr151_t rach_msg2;
}TDD_B1800_v6_t;
typedef struct{
	B1800_lr151_t rach_msg2;
}TDD_B1800_v7_t;

typedef struct{
	quint32 msg2info;
	quint32 rnti : 16;
	quint32 iot_db_lt : 8;
	quint32 spare : 3;
	quint32 v_rfns : 1;
	quint32 v_ueA : 1;
	quint32 v_ueB : 1;
	quint32 v_ueC : 1;
	quint32 v_ueD : 1;
}B1801_lr151_t;

typedef struct{
	B1801_lr151_t rach_msg2_misc;
}FDD_B1801_v16_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}FDD_B1801_v17_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}FDD_B1801_v18_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}FDD_B1801_v19_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}TDD_B1801_v4_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}TDD_B1801_v5_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}TDD_B1801_v6_t;
typedef struct{
	B1801_lr151_t rach_msg2_misc;
}TDD_B1801_v7_t;

typedef struct{
	quint32 number_of_RA_preamble_catm : 4;
	quint32 numRepetitionPerPreambleAttemptCECatM : 4;
	quint32 prach_frequency_offset_catm : 8;
	quint32 prachStartingSubframeCatM : 4;
	quint32 prach_config_index_catm : 6;
	quint32 reserved : 2;
	quint32 mPdcchStartSfCssRaCatM : 4;
	quint32 rnti : 16;
	quint32 iot_db_lt : 8;
	quint32 spare : 3;
	quint32 v_rfns : 1;
	quint32 v_ueA : 1;
	quint32 v_ueB : 1;
	quint32 v_ueC : 1;
	quint32 v_ueD : 1;
}B180A_lr162_t;

typedef struct{
	B180A_lr162_t catm_rach_msg2_cfg;
}FDD_B180A_v18_t;
typedef struct{
	B180A_lr162_t catm_rach_msg2_cfg;
}FDD_B180A_v19_t;

typedef struct{
	B180A_lr162_t catm_rach_msg2_cfg;
}TDD_B180A_v6_t;
typedef struct{
	B180A_lr162_t catm_rach_msg2_cfg;
}TDD_B180A_v7_t;

typedef struct{
	quint32 r_flag : 1;
	quint32 timing_advance : 11;
	quint32	UL_Grant_NB_Index : 3;
	quint32 UL_Grant_Ressource : 4;
	quint32 UL_Grant_Repetition : 2;
	quint32 UL_Grant_MCS : 3;
	quint32 UL_Grant_TPC : 3;
	quint32 UL_Grant_CSI_req_flag : 1;
	quint32 UL_Grant_UL_Delay_flag : 1;
	quint32 UL_Grant_MPDCCH_NB_Index : 2;
	quint32 padding : 1;
	quint32	rnti : 16;
	quint32	iot_db_lt : 8;
	quint32	spare : 3;
	quint32	v_rfns : 1;
	quint32	v_ueA : 1;
	quint32	v_ueB : 1;
	quint32	v_ueC : 1;
	quint32	v_ueD : 1;
}B180B_lr162_t;

typedef struct{
	B180B_lr162_t catm_rach_msg2;
}FDD_B180B_v18_t;
typedef struct{
	B180B_lr162_t catm_rach_msg2;
}FDD_B180B_v19_t;

typedef struct{
	B180B_lr162_t catm_rach_msg2;
}TDD_B180B_v6_t;
typedef struct{
	B180B_lr162_t catm_rach_msg2;
}TDD_B180B_v7_t;

/////////////////////PHICH
typedef struct{
	quint16	hi7 : 2;
	quint16	hi6 : 2;
	quint16	hi5 : 2;
	quint16	hi4 : 2;
	quint16	hi3 : 2;
	quint16	hi2 : 2;
	quint16	hi1 : 2;
	quint16	hi0 : 2;
}B1900_lr151_t;

typedef struct{
	B1900_lr151_t phich;
}FDD_B1900_v16_t;
typedef struct{
	B1900_lr151_t phich;
}FDD_B1900_v17_t;
typedef struct{
	B1900_lr151_t phich;
}FDD_B1900_v18_t;
typedef struct{
	B1900_lr151_t phich;
}FDD_B1900_v19_t;

typedef struct{
	B1900_lr151_t phich;
}TDD_B1900_v4_t;
typedef struct{
	B1900_lr151_t phich;
}TDD_B1900_v5_t;
typedef struct{
	B1900_lr151_t phich;
}TDD_B1900_v6_t;
typedef struct{
	B1900_lr151_t phich;
}TDD_B1900_v7_t;

/////////////////////SPS
typedef struct{
	quint8  sps_context_id;
	quint8  sps_period : 4;
	quint8  sps_grant_txcount : 4;
	quint16 sir_target_sps_correction;
}B1A00_lr151_t;

typedef struct{
	B1A00_lr151_t sps[3];
}FDD_B1A00_v16_t;

typedef struct{
	B1A00_lr151_t sps[3];
}TDD_B1A00_v4_t;


typedef struct{
	quint8  sps_context_id;
	quint8  sps_period : 4;
	quint8  sps_grant_txcount : 4;
	quint16 sir_target_sps_correction;
}B1A00_lr161_t;

typedef struct{
	B1A00_lr161_t sps_act[4];
}FDD_B1A00_v17_t;
typedef struct{
	B1A00_lr161_t sps_act[4];
}FDD_B1A00_v18_t;
typedef struct{
	B1A00_lr161_t sps_act[4];
}FDD_B1A00_v19_t;

typedef struct{
	B1A00_lr161_t sps_act[4];
}TDD_B1A00_v5_t;
typedef struct{
	B1A00_lr161_t sps_act[4];
}TDD_B1A00_v6_t;
typedef struct{
	B1A00_lr161_t sps_act[4];
}TDD_B1A00_v7_t;

typedef struct{
	quint16 c_rnti[7];
	quint16 sps_impl_rel_msk;
}B1A01_lr161_t;

typedef struct{
	B1A01_lr161_t sps_impl_rel;
}FDD_B1A01_v17_t;
typedef struct{
	B1A01_lr161_t sps_impl_rel;
}FDD_B1A01_v18_t;
typedef struct{
	B1A01_lr161_t sps_impl_rel;
}FDD_B1A01_v19_t;

typedef struct{
	B1A01_lr161_t sps_impl_rel;
}TDD_B1A01_v5_t;
typedef struct{
	B1A01_lr161_t sps_impl_rel;
}TDD_B1A01_v6_t;
typedef struct{
	B1A01_lr161_t sps_impl_rel;
}TDD_B1A01_v7_t;

/////////////////////RFNS
typedef struct{
	quint8 call_trace_rfns[20];
	quint32 st_obs;
	quint16 C_RNTI[2];
}B1B00_lr151_t;

typedef struct{
	B1B00_lr151_t rfns;
}FDD_B1B00_v16_t;
typedef struct{
	B1B00_lr151_t rfns;
}FDD_B1B00_v17_t;
typedef struct{
	B1B00_lr151_t rfns;
}FDD_B1B00_v18_t;
typedef struct{
	B1B00_lr151_t rfns;
}FDD_B1B00_v19_t;

typedef struct{
	B1B00_lr151_t rfns;
}TDD_B1B00_v4_t;
typedef struct{
	B1B00_lr151_t rfns;
}TDD_B1B00_v5_t;
typedef struct{
	B1B00_lr151_t rfns;
}TDD_B1B00_v6_t;
typedef struct{
	B1B00_lr151_t rfns;
}TDD_B1B00_v7_t;

/////////////////////Measurement
typedef struct{
	quint8 ul_sps_active : 1;
	quint8 ul_fs_fd_mode : 1;
	quint8 dl_fs_fd_mode : 1;
	quint8 acqi_pcqi_reporting : 1;
	quint8 tti_bundling : 1;
	quint8 drx_configuration : 2;
	quint8 oot : 1;
}ue_state_151_t;

typedef struct{
	quint16 rnti;
	quint16 sps_prb_nb : 4;
	quint16 sps_mcs : 5;
	quint16 sps_start_prb : 7;
	qint16 path_loss_srs;
	quint16 sps_rnti;
	quint32 instant_wideband_srs;
	quint32 sinr_srs_synchronization;
	quint16 pucch_tpc_rnti;
	quint16 pusch_tpc_rnti;
	ue_state_151_t ue_state;
	quint8 pucch_tpc_index : 4;
	quint8 pusch_tpc_index : 4;
	qint8 pusch_sir_target;
	qint8 iot_pusch_sinr_target_corr;
}B1C00_lr151_t;

typedef struct{
	B1C00_lr151_t meas;
}FDD_B1C00_v16_t;

typedef struct{
	B1C00_lr151_t meas;
}TDD_B1C00_v4_t;

typedef struct{
	quint16 rnti;
	quint16 sps_prb_nb : 4;
	quint16 sps_mcs : 5;
	quint16 sps_start_prb : 7;
	qint16 path_loss_srs;
	quint16 sps_rnti;
	quint32 instant_wideband_srs;
	quint32 sinr_srs_synchronization;
	quint16 pucch_tpc_rnti;
	quint16 pusch_tpc_rnti;
	ue_state_151_t ue_state;
	quint8 pucch_tpc_index : 4;
	quint8 pusch_tpc_index : 4;
	qint8 pusch_sir_target;
	quint8 iot_pusch_sinr_target_corr;
}B1C00_lr161_t;

typedef struct{
	B1C00_lr161_t meas;
}FDD_B1C00_v17_t;
typedef struct{
	B1C00_lr161_t meas;
}FDD_B1C00_v18_t;
typedef struct{
	B1C00_lr161_t meas;
}FDD_B1C00_v19_t;

typedef struct{
	B1C00_lr161_t meas;
}TDD_B1C00_v5_t;
typedef struct{
	B1C00_lr161_t meas;
}TDD_B1C00_v6_t;
typedef struct{
	B1C00_lr161_t meas;
}TDD_B1C00_v7_t;

/////////////////////Count
typedef struct{
	quint32 nbUEsFDS : 12;
	quint32 nbUEsFSS : 12;
	quint32 nbUEsXXX : 8;
	qint8 SPScandidateActivation;
	qint8 SPSawaitingRetrans;
	qint8 SPScandidateRelease;
	qint8 TotalUEinSPS;
}B1D00_lr151_t;

typedef struct{
	B1D00_lr151_t counter;
}FDD_B1D00_v16_t;
typedef struct{
	B1D00_lr151_t counter;
}FDD_B1D00_v17_t;
typedef struct{
	B1D00_lr151_t counter;
}FDD_B1D00_v18_t;
typedef struct{
	B1D00_lr151_t counter;
}FDD_B1D00_v19_t;

typedef struct{
	B1D00_lr151_t counter;
}TDD_B1D00_v4_t;
typedef struct{
	B1D00_lr151_t counter;
}TDD_B1D00_v5_t;
typedef struct{
	B1D00_lr151_t counter;
}TDD_B1D00_v6_t;
typedef struct{
	B1D00_lr151_t counter;
}TDD_B1D00_v7_t;

/////////////////////misc
typedef struct{
	quint16 cfi : 2;
	quint16 cfi_change : 1;
	quint16	unused_phich_1 : 1;
	quint16	debug_bit : 1;
	quint16	unused_phich_2 : 1;
	quint16 fpgaAlarm_0x461f : 1;
	quint16	rach_bit : 1;
	quint16 pdcch_dump_size : 8;
}B1E00_lr151_t;

typedef struct{
	B1E00_lr151_t misc;
}FDD_B1E00_v16_t;
typedef struct{
	B1E00_lr151_t misc;
}FDD_B1E00_v17_t;

typedef struct{
	B1E00_lr151_t misc;
}TDD_B1E00_v4_t;
typedef struct{
	B1E00_lr151_t misc;
}TDD_B1E00_v5_t;

typedef struct{
	quint16 cfi : 2;
	quint16 cfi_change : 1;
	quint16 mpdcch_dump_size : 5;
	quint16 fpgaAlarm_0x461f : 1;
	quint16 pdcch_dump_size : 7;
}B1E00_lr162_t;

typedef struct{
	B1E00_lr162_t misc;
}FDD_B1E00_v18_t;
typedef struct{
	B1E00_lr162_t misc;
}FDD_B1E00_v19_t;

typedef struct{
	B1E00_lr162_t misc;
}TDD_B1E00_v6_t;
typedef struct{
	B1E00_lr162_t misc;
}TDD_B1E00_v7_t;

/////////////////////catm
typedef struct{
	quint8 list_id : 3;
	quint8 direction : 1;
	quint8 action : 4;
}mtc_sch_in_lr162_t;

typedef struct{
	quint16 rnti[4];
	mtc_sch_in_lr162_t mtc_scd_in[4];
}B2500_lr162_t;

typedef struct{
	B2500_lr162_t mtc_unicast_scd_in;
}FDD_B2500_v18_t;

typedef struct{
	quint16 list_id : 5;
	quint16 direction : 1;
	quint16 action : 8;
	quint16 reserved : 2;
}mtc_sch_in_lr1712_t;

typedef struct{
	quint16 rnti[3];
	mtc_sch_in_lr1712_t mtc_scd_in[3];
}B2500_lr1712_t;

typedef struct{
	B2500_lr1712_t mtc_unicast_scd_in;
}FDD_B2500_v19_t;

typedef struct{
	B2500_lr162_t mtc_unicast_scd_in;
}TDD_B2500_v6_t;
typedef struct{
	B2500_lr162_t mtc_unicast_scd_in;
}TDD_B2500_v8_t;

typedef struct{
	quint16 rnti;
	quint8 list_id : 3;
	quint8 direction : 1;
	quint8 action : 4;
}B2501_lr162_t;

typedef struct{
	B2501_lr162_t mtc_unicast_scd;
}FDD_B2501_v18_t;

typedef struct{
	quint16 rnti;
	quint16 list_id : 5;
	quint16 direction : 1;
	quint16 action : 8;
	quint16 reserved : 2;
}B2501_lr1712_t;

typedef struct{
	B2501_lr1712_t mtc_unicast_scd;
}FDD_B2501_v19_t;

typedef struct{
	B2501_lr162_t mtc_unicast_scd;
}FDD_B2501_v6_t;
typedef struct{
	B2501_lr162_t mtc_unicast_scd;
}FDD_B2501_v7_t;

typedef struct{
	quint8 narrow_band : 4;
	quint8 rv_index : 4;
}mtc_dbch_scd_out_162_t;

typedef struct{
	quint16 rnti[4];
	mtc_dbch_scd_out_162_t mtc_dbch_scd_out[4];
}B2502_lr162_t;

typedef struct{
	B2502_lr162_t mtc_dbch_scd_out;
}FDD_B2502_v18_t;
typedef struct{
	B2502_lr162_t mtc_dbch_scd_out;
}FDD_B2502_v19_t;

typedef struct{
	B2502_lr162_t mtc_dbch_scd_out;
}TDD_B2502_v6_t;
typedef struct{
	B2502_lr162_t mtc_dbch_scd_out;
}TDD_B2502_v7_t;

typedef struct{
	quint8 narrow_band : 4;
	quint8 rv_index : 4;
	quint16 rnti;
}B2503_lr162_t;

typedef struct{
	B2503_lr162_t mtc_dbch_scd;
}FDD_B2503_v18_t;
typedef struct{
	B2503_lr162_t mtc_dbch_scd;
}FDD_B2503_v19_t;

typedef struct{
	B2503_lr162_t mtc_dbch_scd;
}TDD_B2503_v6_t;
typedef struct{
	B2503_lr162_t mtc_dbch_scd;
}TDD_B2503_v7_t;

typedef struct{
	quint32 traceType : 8;
	quint32 traceVersion : 16;
	quint32 lteCellIndex : 8;
	quint16 sfn : 12;
	quint16 subFrameNumber : 4;
	quint16 header_filler1 : 8;
	quint16 p_dbg : 2;
	quint16 pu1 : 1;
	quint16 pu2 : 1;
	quint16 pd : 1;
	quint16 ps : 1;
	quint16 mode : 2;
}ult_ct_hdr_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	FDD_B1801_v16_t call_trace_rach_msg2;
	FDD_B1900_v16_t call_trace_phich_rf[13];
	FDD_B1E00_v16_t misc;
	quint16 a_ltx_pdcch_buf[156];
	FDD_B1A00_v16_t call_trace_sps_infos;
	qint16 srs_snr_ue[10];
	FDD_B1B00_v16_t call_trace_reason_for_not_scheduled;
	FDD_B1C00_v16_t call_trace_long_term_ue_observation[4];
	FDD_B1D00_v16_t call_trace_counters;
}ult_call_trace_fdd_v16_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	FDD_B1801_v17_t call_trace_rach_msg2;
	FDD_B1900_v17_t call_trace_phich_rf[13];
	FDD_B1E00_v17_t misc;
	quint16 a_ltx_pdcch_buf[156];
	FDD_B1A00_v17_t call_trace_sps_infos;
	qint16 srs_snr_ue[10];
	FDD_B1B00_v17_t call_trace_reason_for_not_scheduled;
	FDD_B1C00_v17_t call_trace_long_term_ue_observation[4];
	FDD_B1D00_v17_t call_trace_counters;
}ult_call_trace_fdd_v17_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	FDD_B1801_v18_t call_trace_rach_msg2;
	FDD_B1900_v18_t call_trace_phich_rf[13];
	FDD_B1E00_v18_t misc;
	quint16 a_ltx_pdcch_buf[156];
	quint16 a_ltx_mpdcch_buf[40];
	FDD_B2500_v18_t mtc_unicast_scd_in;
	FDD_B2502_v18_t mtc_dbch_scd_out;
	FDD_B1A00_v18_t call_trace_sps_infos;
	qint16 srs_snr_ue[10];
	FDD_B1B00_v18_t call_trace_reason_for_not_scheduled;
	FDD_B1C00_v18_t call_trace_long_term_ue_observation[4];
	FDD_B1D00_v18_t call_trace_counters;
}ult_call_trace_fdd_v18_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	FDD_B1801_v19_t call_trace_rach_msg2;
	FDD_B1900_v19_t call_trace_phich_rf[13];
	FDD_B1E00_v19_t misc;
	quint16 a_ltx_pdcch_buf[156];
	quint16 a_ltx_mpdcch_buf[40];
	FDD_B2500_v19_t mtc_unicast_scd_in;
	FDD_B2502_v19_t mtc_dbch_scd_out;
	FDD_B1A00_v19_t call_trace_sps_infos;
	qint16 srs_snr_ue[10];
	FDD_B1B00_v19_t call_trace_reason_for_not_scheduled;
	FDD_B1C00_v19_t call_trace_long_term_ue_observation[4];
	FDD_B1D00_v19_t call_trace_counters;
}ult_call_trace_fdd_v19_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	TDD_B1801_v4_t call_trace_rach_msg2;
	TDD_B1900_v4_t call_trace_phich_rf[13];
	TDD_B1E00_v4_t misc;
	quint16 a_ltx_pdcch_buf[156];
	TDD_B1A00_v4_t call_trace_sps_infos;
	qint16 srs_snr_ue[10];
	TDD_B1B00_v4_t call_trace_reason_for_not_scheduled;
	TDD_B1C00_v4_t call_trace_long_term_ue_observation[4];
	TDD_B1D00_v4_t call_trace_counters;
}ult_call_trace_tdd_v4_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	TDD_B1801_v5_t call_trace_rach_msg2;
	TDD_B1900_v5_t call_trace_phich_rf[13];
	TDD_B1E00_v5_t misc;
	quint16 a_ltx_pdcch_buf[156];
	TDD_B1A00_v5_t call_trace_sps_infos;
	qint16 srs_snr_ue[10];
	TDD_B1B00_v5_t call_trace_reason_for_not_scheduled;
	TDD_B1C00_v5_t call_trace_long_term_ue_observation[4];
	TDD_B1D00_v5_t call_trace_counters;
}ult_call_trace_tdd_v5_t;

typedef struct{
	ult_ct_hdr_t ult_call_trace_hdr;
	TDD_B1801_v6_t call_trace_rach_msg2;
	TDD_B1900_v6_t call_trace_phich_rf[13];
	TDD_B1E00_v6_t misc;
	quint16 a_ltx_pdcch_buf[156];
	quint16 a_ltx_mpdcch_buf[40];
	TDD_B2500_v6_t mtc_unicast_scd_in;
	TDD_B2502_v6_t mtc_dbch_scd_out;
	TDD_B1A00_v6_t call_trace_sps_infos;
	TDD_B1A01_v6_t call_trace_sps_infos_impl_rel;
	qint16 srs_snr_ue[10];
	TDD_B1B00_v6_t call_trace_reason_for_not_scheduled;
	TDD_B1C00_v6_t call_trace_long_term_ue_observation[4];
	TDD_B1D00_v6_t call_trace_counters;
}ult_call_trace_tdd_v6_t;

typedef struct{
	ult_call_trace_tdd_v6_t ult_call_trace_tdd;
}ult_call_trace_tdd_v7_t;

typedef struct{
	quint32	pdcch_fmt : 2;
	quint32	reserved_a : 2;
	quint32	reserved_b : 2;
	quint32	ue_dci0_mask : 1;
	quint32	reserved_c : 1;
	quint32	cell_id : 2;
	quint32	trbk_size : 6;
	quint32	rnti : 16;
}pdcch_hd0_t;

typedef struct{
	quint32	pow_offset_db : 8;
	quint32	ctm_flag : 1;
	quint32	start_cce : 7;
	quint32	subframe : 4;
	quint32	sfn : 12;
}pdcch_hd1_t;

typedef struct{
	pdcch_hd0_t pdcch_hd0;
	pdcch_hd1_t pdcch_hd1;
}pdcch_pkt_hdr_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	quint32 flag_format_0_1A : 1;
	quint32 reserve : 31;
}pdcch_pkt_hdr_dummy_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 9;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 pad : 8;
}dci_format0_5MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 9;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 dai : 2;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 res_alloc_type_or_pad : 1;
	quint32 pad : 5;
}dci_format0_5MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_5MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_5MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_5MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_5MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 11;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 pad : 6;
}dci_format0_10MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 11;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 dai : 2;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 res_alloc_type_or_pad : 1;
	quint32 pad : 3;
}dci_format0_10MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_10MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_10MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 12;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 pad : 5;
}dci_format0_15MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 12;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 dai : 2;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 res_alloc_type_or_pad : 2;
	quint32 pad : 2;
}dci_format0_15MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_15MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_15MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_15MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_15MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 13;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
}dci_format0_20MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 hopping_flag : 1;
	quint32 rb_asgn : 13;
	quint32 mcs : 5;
	quint32 ndi : 1;
	quint32 tpc : 2;
	quint32 cyc_shift : 3;
	quint32 dai : 2;
	quint32 cqi_request : 1;
	quint32 cqi_req_ext_or_pad : 1;
	quint32 res_alloc_type_or_pad : 1;
}dci_format0_20MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_20MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_20MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format0_20MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format0_20MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 pad : 5;
}dci_format1_5MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 pad : 2;
}dci_format1_5MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_5MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_5MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_5MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_5MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
}dci_format1_10MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
}dci_format1_10MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_10MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_10MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc_hi : 1;
	quint32 tpc_low : 1;
	quint32 pad : 31;
}dci_format1_15MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 pad : 28;
}dci_format1_15MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_15MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_15MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_15MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_15MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 mcs : 5;
	quint32 harq_process_hi : 1;
	quint32 harq_process_lo : 2;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 pad : 25;
}dci_format1_20MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 mcs : 5;
	quint32 harq_process_hi : 1;
	quint32 harq_process_lo : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 pad : 22;
}dci_format1_20MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_20MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_20MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1_20MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1_20MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 9;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 pad : 8;
}dci_format1A_5MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 9;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 pad : 5;
}dci_format1A_5MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_5MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_5MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_5MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_5MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 11;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
}dci_format1A_10MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 11;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
}dci_format1A_10MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_10MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_10MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 12;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 pad : 5;
}dci_format1A_15MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 12;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 pad : 2;
}dci_format1A_15MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_15MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_15MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_15MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_15MHZ_tdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 13;
	quint32 mcs : 5;
	quint32 harq_process : 3;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
}dci_format1A_20MHZ_fdd_t;

typedef struct{
	quint32 flag_format_0_1A : 1;
	quint32 loc_dist : 1;
	quint32 rb_asgn : 13;
	quint32 mcs : 5;
	quint32 harq_process : 4;
	quint32 ndi : 1;
	quint32 rv : 2;
	quint32 tpc : 2;
	quint32 dai : 2;
}dci_format1A_20MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_20MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_20MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format1A_20MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format1A_20MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs_hi : 4;
	quint32 tb2_mcs_lo : 1;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 25;
}dci_format2_5MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs_hi : 4;
	quint32 tb2_mcs_lo : 1;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 22;
}dci_format2_5MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_5MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_5MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_5MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_5MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 21;
}dci_format2_10MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 18;
}dci_format2_10MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_10MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_10MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 19;
}dci_format2_15MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 16;
}dci_format2_15MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_15MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_15MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_15MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_15MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 13;
}dci_format2_20MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 3;
	quint32 pad : 10;
}dci_format2_20MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_20MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_20MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_20MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_20MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs_hi : 4;
	quint32 tb2_mcs_lo : 1;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 6;
	quint32 pad : 22;
}dci_format2_5MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_5MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_5MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 6;
	quint32 pad : 18;
}dci_format2_10MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_10MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_10MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 6;
	quint32 pad : 16;
}dci_format2_15MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_15MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_15MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 6;
	quint32 pad : 10;
}dci_format2_20MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2_20MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2_20MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs_hi : 4;
	quint32 tb2_mcs_lo : 1;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 28;
}dci_format2A_5MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs_hi : 4;
	quint32 tb2_mcs_lo : 1;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 25;
}dci_format2A_5MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_5MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_5MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_5MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_5MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 24;
}dci_format2A_10MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 21;
}dci_format2A_10MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_10MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_10MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 22;
}dci_format2A_15MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs_hi : 3;
	quint32 tb1_mcs_lo : 2;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 19;
}dci_format2A_15MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_15MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_15MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_15MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_15MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 16;
}dci_format2A_20MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 13;
}dci_format2A_20MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_20MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_20MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_20MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 13;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs_hi : 4;
	quint32 tb2_mcs_lo : 1;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 2;
	quint32 pad : 26;
}dci_format2A_5MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_5MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_5MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 2;
	quint32 pad : 22;
}dci_format2A_10MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_10MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_10MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 19;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 2;
	quint32 pad : 20;
}dci_format2A_15MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_15MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_15MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 tb_to_cw_swap_flag : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 precoding_info : 2;
	quint32 pad : 14;
}dci_format2A_20MHZ_4tx_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2A_20MHZ_4tx_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2A_20MHZ_4tx_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 scramb_id : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 24;
}dci_format2B_10MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 17;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process : 4;
	quint32 scramb_id : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 21;
}dci_format2B_10MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2B_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2B_10MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2B_10MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2B_10MHZ_tdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 harq_process : 3;
	quint32 scramb_id : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 16;
}dci_format2B_20MHZ_fdd_t;

typedef struct{
	quint32 res_alloc_hdr_type : 1;
	quint32 res_alloc_hdr : 25;
	quint32 tpc : 2;
	quint32 dai : 2;
	quint32 harq_process_1 : 2;
	quint32 harq_process_2 : 2;
	quint32 scramb_id : 1;
	quint32 tb1_mcs : 5;
	quint32 tb1_ndi : 1;
	quint32 tb1_rv : 2;
	quint32 tb2_mcs : 5;
	quint32 tb2_ndi : 1;
	quint32 tb2_rv : 2;
	quint32 pad : 13;
}dci_format2B_20MHZ_tdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2B_20MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format2B_20MHZ_fdd_t;

typedef struct{
	pdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format2B_20MHZ_tdd_t pdcch_pkt_payload;
}pdcch_pkt_format2B_20MHZ_tdd_t;

typedef struct{
	quint32	mepdcch_fmt : 3;
	quint32	reserved_a : 1;
	quint32	packet_type : 2;
	quint32	reserved_b : 2;
	quint32	cell_id : 2;
	quint32	trbk_size : 6;
	quint32	rnti : 16;
}mpdcch_hd0_t;

typedef struct{
	quint32	pow_offset_db : 8;
	quint32	ctm_flag : 1;
	quint32	reserved_a : 2;
	quint32	start_cce : 5;
	quint32	subframe : 4;
	quint32	sfn : 12;
}mpdcch_hd1_t;

typedef struct{
	quint32	start_prb_nb : 7;
	quint32	prb_mapping : 6;
	quint32	port_set : 2;
	quint32	distrib_type : 1;
	quint32	ant_port : 2;
	quint32	rm_size : 12;
	quint32	reserved_a : 2;
}mpdcch_hd2_t;

typedef struct{
	quint32	start_symb : 2;
	quint32	init_scramb : 4;
	quint32	epdcch_id : 9;
	quint32	rnti_type : 1;
	quint32	reserved_a : 1;
	quint32	nb_id : 2;
	quint32	reserved_b : 13;
}mpdcch_hd3_t;

typedef struct{
	mpdcch_hd0_t mpdcch_hd0;
	mpdcch_hd1_t mpdcch_hd1;
	mpdcch_hd2_t mpdcch_hd2;
	mpdcch_hd3_t mpdcch_hd3;
}mpdcch_pkt_hdr_t;

typedef struct{
	mpdcch_pkt_hdr_t pdcch_pkt_hdr;
	quint32 flag_dci_format : 1;
	quint32 reserve : 31;
}mpdcch_pkt_hdr_dummy_t;

typedef struct{
	quint32 Flag_format_diff : 1;
	quint32 FH : 1;
	quint32 RB_ASSIGNMENT : 8;
	quint32 MCS : 4;
	quint32 REPETITION_NUMBER : 2;
	quint32 HARQ_PROCESS_NUMBER : 3;
	quint32 NDI : 1;
	quint32 RV : 2;
	quint32 TPC : 2;
	quint32 CSI : 1;
	quint32 SRS : 1;
	quint32 DCI_SF_REP_NUMBER : 2;
	quint32 padding : 4;
}dci_format6_0A_fdd_t;

typedef struct{
	mpdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format6_0A_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format6_0A_fdd_t;

typedef struct{
	quint32 Flag_format_diff : 1;
	quint32 FH : 1;
	quint32 RB_ASSIGNMENT : 8;
	quint32 MCS : 4;
	quint32 REPETITION_NUMBER : 2;
	quint32 HARQ_PROCESS_NUMBER : 3;
	quint32 NDI : 1;
	quint32 RV : 2;
	quint32 TPC : 2;
	quint32 SRS : 1;
	quint32 HARQ_ACK_OFFSET : 2;
	quint32 DCI_SF_REP_NUMBER : 2;
	quint32 padding : 3;
}dci_format6_1A_fdd_t;

typedef struct{
	mpdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format6_1A_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format6_1A_fdd_t;

typedef struct{
	quint32    pagingFlag : 1;
	quint32    resourceBlockAssignment : 3;
	quint32    mcs : 3;
	quint32    repetitionNumber : 3;
	quint32    subframeRepetitionNumber : 2;
	quint32    reservedDci6_2 : 20;
}dci_format6_2_P_10MHZ_fdd_t;

typedef struct{
	mpdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format6_2_P_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format6_2_P_10MHZ_fdd_t;

typedef struct{
	quint32    pagingFlag : 1;
	quint32    directIndicationInfo : 8;
	quint32    reservedDci6_2 : 23;
}dci_format6_2_10MHZ_fdd_t;

typedef struct{
	mpdcch_pkt_hdr_t pdcch_pkt_hdr;
	dci_format6_2_10MHZ_fdd_t pdcch_pkt_payload;
}pdcch_pkt_format6_2_10MHZ_fdd_t;


#pragma pack()

