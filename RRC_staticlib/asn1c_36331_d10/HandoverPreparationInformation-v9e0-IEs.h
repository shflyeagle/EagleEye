/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_HandoverPreparationInformation_v9e0_IEs_H_
#define	_HandoverPreparationInformation_v9e0_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AS_Config_v9e0;
struct HandoverPreparationInformation_v1130_IEs;

/* HandoverPreparationInformation-v9e0-IEs */
typedef struct HandoverPreparationInformation_v9e0_IEs {
	struct AS_Config_v9e0	*as_Config_v9e0	/* OPTIONAL */;
	struct HandoverPreparationInformation_v1130_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HandoverPreparationInformation_v9e0_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HandoverPreparationInformation_v9e0_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "AS-Config-v9e0.h"
#include "HandoverPreparationInformation-v1130-IEs.h"

#endif	/* _HandoverPreparationInformation_v9e0_IEs_H_ */
#include <asn_internal.h>
