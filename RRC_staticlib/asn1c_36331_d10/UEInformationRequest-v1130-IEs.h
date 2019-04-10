/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_UEInformationRequest_v1130_IEs_H_
#define	_UEInformationRequest_v1130_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UEInformationRequest_v1130_IEs__connEstFailReportReq_r11 {
	UEInformationRequest_v1130_IEs__connEstFailReportReq_r11_true	= 0
} e_UEInformationRequest_v1130_IEs__connEstFailReportReq_r11;

/* Forward declarations */
struct UEInformationRequest_v1250_IEs;

/* UEInformationRequest-v1130-IEs */
typedef struct UEInformationRequest_v1130_IEs {
	ENUMERATED_t	*connEstFailReportReq_r11	/* OPTIONAL */;
	struct UEInformationRequest_v1250_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UEInformationRequest_v1130_IEs_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_connEstFailReportReq_r11_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_UEInformationRequest_v1130_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UEInformationRequest-v1250-IEs.h"

#endif	/* _UEInformationRequest_v1130_IEs_H_ */
#include <asn_internal.h>