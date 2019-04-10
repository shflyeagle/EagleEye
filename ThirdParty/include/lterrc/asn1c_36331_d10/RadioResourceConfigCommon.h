/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RadioResourceConfigCommon_H_
#define	_RadioResourceConfigCommon_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PRACH-Config.h"
#include "PUSCH-ConfigCommon.h"
#include "P-Max.h"
#include "UL-CyclicPrefixLength.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RACH_ConfigCommon;
struct PDSCH_ConfigCommon;
struct PHICH_Config;
struct PUCCH_ConfigCommon;
struct SoundingRS_UL_ConfigCommon;
struct UplinkPowerControlCommon;
struct AntennaInfoCommon;
struct TDD_Config;
struct UplinkPowerControlCommon_v1020;
struct TDD_Config_v1130;
struct PUSCH_ConfigCommon_v1270;
struct PRACH_Config_v1310;
struct FreqHoppingParameters_r13;
struct PDSCH_ConfigCommon_v1310;
struct PUCCH_ConfigCommon_v1310;
struct PUSCH_ConfigCommon_v1310;
struct UplinkPowerControlCommon_v1310;

/* RadioResourceConfigCommon */
typedef struct RadioResourceConfigCommon {
	struct RACH_ConfigCommon	*rach_ConfigCommon	/* OPTIONAL */;
	PRACH_Config_t	 prach_Config;
	struct PDSCH_ConfigCommon	*pdsch_ConfigCommon	/* OPTIONAL */;
	PUSCH_ConfigCommon_t	 pusch_ConfigCommon;
	struct PHICH_Config	*phich_Config	/* OPTIONAL */;
	struct PUCCH_ConfigCommon	*pucch_ConfigCommon	/* OPTIONAL */;
	struct SoundingRS_UL_ConfigCommon	*soundingRS_UL_ConfigCommon	/* OPTIONAL */;
	struct UplinkPowerControlCommon	*uplinkPowerControlCommon	/* OPTIONAL */;
	struct AntennaInfoCommon	*antennaInfoCommon	/* OPTIONAL */;
	P_Max_t	*p_Max	/* OPTIONAL */;
	struct TDD_Config	*tdd_Config	/* OPTIONAL */;
	UL_CyclicPrefixLength_t	 ul_CyclicPrefixLength;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct UplinkPowerControlCommon_v1020	*uplinkPowerControlCommon_v1020	/* OPTIONAL */;
	struct TDD_Config_v1130	*tdd_Config_v1130	/* OPTIONAL */;
	struct PUSCH_ConfigCommon_v1270	*pusch_ConfigCommon_v1270	/* OPTIONAL */;
	struct PRACH_Config_v1310	*prach_Config_v1310	/* OPTIONAL */;
	struct FreqHoppingParameters_r13	*freqHoppingParameters_r13	/* OPTIONAL */;
	struct PDSCH_ConfigCommon_v1310	*pdsch_ConfigCommon_v1310	/* OPTIONAL */;
	struct PUCCH_ConfigCommon_v1310	*pucch_ConfigCommon_v1310	/* OPTIONAL */;
	struct PUSCH_ConfigCommon_v1310	*pusch_ConfigCommon_v1310	/* OPTIONAL */;
	struct UplinkPowerControlCommon_v1310	*uplinkPowerControlCommon_v1310	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RadioResourceConfigCommon_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigCommon;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RACH-ConfigCommon.h"
#include "PDSCH-ConfigCommon.h"
#include "PHICH-Config.h"
#include "PUCCH-ConfigCommon.h"
#include "SoundingRS-UL-ConfigCommon.h"
#include "UplinkPowerControlCommon.h"
#include "AntennaInfoCommon.h"
#include "TDD-Config.h"
#include "UplinkPowerControlCommon-v1020.h"
#include "TDD-Config-v1130.h"
#include "PUSCH-ConfigCommon-v1270.h"
#include "PRACH-Config-v1310.h"
#include "FreqHoppingParameters-r13.h"
#include "PDSCH-ConfigCommon-v1310.h"
#include "PUCCH-ConfigCommon-v1310.h"
#include "PUSCH-ConfigCommon-v1310.h"
#include "UplinkPowerControlCommon-v1310.h"

#endif	/* _RadioResourceConfigCommon_H_ */
#include <asn_internal.h>
