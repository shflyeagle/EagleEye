/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SystemInformationBlockType1_v1310_IEs_H_
#define	_SystemInformationBlockType1_v1310_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <ENUMERATED.h>
#include <NativeInteger.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SystemInformationBlockType1_v1310_IEs__eDRX_Allowed_r13 {
	SystemInformationBlockType1_v1310_IEs__eDRX_Allowed_r13_true	= 0
} e_SystemInformationBlockType1_v1310_IEs__eDRX_Allowed_r13;
typedef enum SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13 {
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms20	= 0,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms40	= 1,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms60	= 2,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms80	= 3,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms120	= 4,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms160	= 5,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_ms200	= 6,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13_spare	= 7
} e_SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_WindowLength_BR_r13;
typedef enum SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_RepetitionPattern_r13 {
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_RepetitionPattern_r13_everyRF	= 0,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_RepetitionPattern_r13_every2ndRF	= 1,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_RepetitionPattern_r13_every4thRF	= 2,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_RepetitionPattern_r13_every8thRF	= 3
} e_SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_RepetitionPattern_r13;
typedef enum SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_PR {
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_PR_NOTHING,	/* No components present */
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_PR_subframePattern10_r13,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_PR_subframePattern40_r13
} SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_PR;
typedef enum SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_HoppingConfigCommon_r13 {
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_HoppingConfigCommon_r13_on	= 0,
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_HoppingConfigCommon_r13_off	= 1
} e_SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_HoppingConfigCommon_r13;
typedef enum SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_ValidityTime_r13 {
	SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_ValidityTime_r13_true	= 0
} e_SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__si_ValidityTime_r13;

/* Forward declarations */
struct CellSelectionInfoCE_r13;
struct SchedulingInfoList_BR_r13;
struct SystemInfoValueTagList_r13;

/* SystemInformationBlockType1-v1310-IEs */
typedef struct SystemInformationBlockType1_v1310_IEs {
	BIT_STRING_t	*hyperSFN_r13	/* OPTIONAL */;
	ENUMERATED_t	*eDRX_Allowed_r13	/* OPTIONAL */;
	struct CellSelectionInfoCE_r13	*cellSelectionInfoCE_r13	/* OPTIONAL */;
	struct SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13 {
		ENUMERATED_t	 si_WindowLength_BR_r13;
		ENUMERATED_t	 si_RepetitionPattern_r13;
		struct SchedulingInfoList_BR_r13	*schedulingInfoList_BR_r13	/* OPTIONAL */;
		struct SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13 {
			SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_PR present;
			union SystemInformationBlockType1_v1310_IEs__bandwidthReducedAccessRelatedInfo_r13__fdd_DownlinkOrTddSubframeBitmapLC_r13_u {
				BIT_STRING_t	 subframePattern10_r13;
				BIT_STRING_t	 subframePattern40_r13;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} *fdd_DownlinkOrTddSubframeBitmapLC_r13;
		BIT_STRING_t	*fdd_UplinkSubframeBitmapLC_r13	/* OPTIONAL */;
		long	 startSymbolLC_r13;
		ENUMERATED_t	 si_HoppingConfigCommon_r13;
		ENUMERATED_t	*si_ValidityTime_r13	/* OPTIONAL */;
		struct SystemInfoValueTagList_r13	*systemInfoValueTagList_r13	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *bandwidthReducedAccessRelatedInfo_r13;
	struct SystemInformationBlockType1_v1310_IEs__nonCriticalExtension {
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nonCriticalExtension;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SystemInformationBlockType1_v1310_IEs_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_eDRX_Allowed_r13_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_si_WindowLength_BR_r13_7;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_si_RepetitionPattern_r13_16;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_si_HoppingConfigCommon_r13_27;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_si_ValidityTime_r13_30;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_SystemInformationBlockType1_v1310_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CellSelectionInfoCE-r13.h"
#include "SchedulingInfoList-BR-r13.h"
#include "SystemInfoValueTagList-r13.h"

#endif	/* _SystemInformationBlockType1_v1310_IEs_H_ */
#include <asn_internal.h>
