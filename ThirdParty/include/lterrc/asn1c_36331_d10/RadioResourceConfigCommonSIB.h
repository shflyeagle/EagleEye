/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RadioResourceConfigCommonSIB_H_
#define	_RadioResourceConfigCommonSIB_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RACH-ConfigCommon.h"
#include "BCCH-Config.h"
#include "PCCH-Config.h"
#include "PRACH-ConfigSIB.h"
#include "PDSCH-ConfigCommon.h"
#include "PUSCH-ConfigCommon.h"
#include "PUCCH-ConfigCommon.h"
#include "SoundingRS-UL-ConfigCommon.h"
#include "UplinkPowerControlCommon.h"
#include "UL-CyclicPrefixLength.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UplinkPowerControlCommon_v1020;
struct RACH_ConfigCommon_v1250;
struct PUSCH_ConfigCommon_v1270;
struct BCCH_Config_v1310;
struct PCCH_Config_v1310;
struct FreqHoppingParameters_r13;
struct PDSCH_ConfigCommon_v1310;
struct PUSCH_ConfigCommon_v1310;
struct PRACH_ConfigSIB_v1310;
struct PUCCH_ConfigCommon_v1310;

/* RadioResourceConfigCommonSIB */
typedef struct RadioResourceConfigCommonSIB {
	RACH_ConfigCommon_t	 rach_ConfigCommon;
	BCCH_Config_t	 bcch_Config;
	PCCH_Config_t	 pcch_Config;
	PRACH_ConfigSIB_t	 prach_Config;
	PDSCH_ConfigCommon_t	 pdsch_ConfigCommon;
	PUSCH_ConfigCommon_t	 pusch_ConfigCommon;
	PUCCH_ConfigCommon_t	 pucch_ConfigCommon;
	SoundingRS_UL_ConfigCommon_t	 soundingRS_UL_ConfigCommon;
	UplinkPowerControlCommon_t	 uplinkPowerControlCommon;
	UL_CyclicPrefixLength_t	 ul_CyclicPrefixLength;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct UplinkPowerControlCommon_v1020	*uplinkPowerControlCommon_v1020	/* OPTIONAL */;
	struct RACH_ConfigCommon_v1250	*rach_ConfigCommon_v1250	/* OPTIONAL */;
	struct PUSCH_ConfigCommon_v1270	*pusch_ConfigCommon_v1270	/* OPTIONAL */;
	struct BCCH_Config_v1310	*bcch_Config_v1310	/* OPTIONAL */;
	struct PCCH_Config_v1310	*pcch_Config_v1310	/* OPTIONAL */;
	struct FreqHoppingParameters_r13	*freqHoppingParameters_r13	/* OPTIONAL */;
	struct PDSCH_ConfigCommon_v1310	*pdsch_ConfigCommon_v1310	/* OPTIONAL */;
	struct PUSCH_ConfigCommon_v1310	*pusch_ConfigCommon_v1310	/* OPTIONAL */;
	struct PRACH_ConfigSIB_v1310	*prach_ConfigCommon_v1310	/* OPTIONAL */;
	struct PUCCH_ConfigCommon_v1310	*pucch_ConfigCommon_v1310	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RadioResourceConfigCommonSIB_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigCommonSIB;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UplinkPowerControlCommon-v1020.h"
#include "RACH-ConfigCommon-v1250.h"
#include "PUSCH-ConfigCommon-v1270.h"
#include "BCCH-Config-v1310.h"
#include "PCCH-Config-v1310.h"
#include "FreqHoppingParameters-r13.h"
#include "PDSCH-ConfigCommon-v1310.h"
#include "PUSCH-ConfigCommon-v1310.h"
#include "PRACH-ConfigSIB-v1310.h"
#include "PUCCH-ConfigCommon-v1310.h"

#endif	/* _RadioResourceConfigCommonSIB_H_ */
#include <asn_internal.h>
