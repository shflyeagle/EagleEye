/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_CandidateCellInfoList_r10_H_
#define	_CandidateCellInfoList_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CandidateCellInfo_r10;

/* CandidateCellInfoList-r10 */
typedef struct CandidateCellInfoList_r10 {
	A_SEQUENCE_OF(struct CandidateCellInfo_r10) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CandidateCellInfoList_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CandidateCellInfoList_r10;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CandidateCellInfo-r10.h"

#endif	/* _CandidateCellInfoList_r10_H_ */
#include <asn_internal.h>
