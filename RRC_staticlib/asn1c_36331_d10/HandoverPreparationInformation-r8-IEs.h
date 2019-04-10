/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_HandoverPreparationInformation_r8_IEs_H_
#define	_HandoverPreparationInformation_r8_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UE-CapabilityRAT-ContainerList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AS_Config;
struct RRM_Config;
struct AS_Context;
struct HandoverPreparationInformation_v920_IEs;

/* HandoverPreparationInformation-r8-IEs */
typedef struct HandoverPreparationInformation_r8_IEs {
	UE_CapabilityRAT_ContainerList_t	 ue_RadioAccessCapabilityInfo;
	struct AS_Config	*as_Config	/* OPTIONAL */;
	struct RRM_Config	*rrm_Config	/* OPTIONAL */;
	struct AS_Context	*as_Context	/* OPTIONAL */;
	struct HandoverPreparationInformation_v920_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HandoverPreparationInformation_r8_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HandoverPreparationInformation_r8_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "AS-Config.h"
#include "RRM-Config.h"
#include "AS-Context.h"
#include "HandoverPreparationInformation-v920-IEs.h"

#endif	/* _HandoverPreparationInformation_r8_IEs_H_ */
#include <asn_internal.h>
