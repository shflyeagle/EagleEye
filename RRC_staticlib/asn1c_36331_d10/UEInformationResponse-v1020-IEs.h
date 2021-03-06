/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_UEInformationResponse_v1020_IEs_H_
#define	_UEInformationResponse_v1020_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct LogMeasReport_r10;
struct UEInformationResponse_v1130_IEs;

/* UEInformationResponse-v1020-IEs */
typedef struct UEInformationResponse_v1020_IEs {
	struct LogMeasReport_r10	*logMeasReport_r10	/* OPTIONAL */;
	struct UEInformationResponse_v1130_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UEInformationResponse_v1020_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UEInformationResponse_v1020_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "LogMeasReport-r10.h"
#include "UEInformationResponse-v1130-IEs.h"

#endif	/* _UEInformationResponse_v1020_IEs_H_ */
#include <asn_internal.h>
