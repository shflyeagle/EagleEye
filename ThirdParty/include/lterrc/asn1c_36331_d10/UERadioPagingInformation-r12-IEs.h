/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_UERadioPagingInformation_r12_IEs_H_
#define	_UERadioPagingInformation_r12_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UERadioPagingInformation_v1310_IEs;

/* UERadioPagingInformation-r12-IEs */
typedef struct UERadioPagingInformation_r12_IEs {
	OCTET_STRING_t	 ue_RadioPagingInfo_r12;
	struct UERadioPagingInformation_v1310_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UERadioPagingInformation_r12_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UERadioPagingInformation_r12_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UERadioPagingInformation-v1310-IEs.h"

#endif	/* _UERadioPagingInformation_r12_IEs_H_ */
#include <asn_internal.h>
