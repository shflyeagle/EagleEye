/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MBMSInterestIndication_v1310_IEs_H_
#define	_MBMSInterestIndication_v1310_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MBMS_ServiceList_r13;

/* MBMSInterestIndication-v1310-IEs */
typedef struct MBMSInterestIndication_v1310_IEs {
	struct MBMS_ServiceList_r13	*mbms_Services_r13	/* OPTIONAL */;
	struct MBMSInterestIndication_v1310_IEs__nonCriticalExtension {
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nonCriticalExtension;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMSInterestIndication_v1310_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMSInterestIndication_v1310_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MBMS-ServiceList-r13.h"

#endif	/* _MBMSInterestIndication_v1310_IEs_H_ */
#include <asn_internal.h>
