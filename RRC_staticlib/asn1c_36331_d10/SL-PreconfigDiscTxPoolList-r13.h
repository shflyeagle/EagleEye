/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-Sidelink-Preconf"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SL_PreconfigDiscTxPoolList_r13_H_
#define	_SL_PreconfigDiscTxPoolList_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SL_PreconfigDiscPool_r13;

/* SL-PreconfigDiscTxPoolList-r13 */
typedef struct SL_PreconfigDiscTxPoolList_r13 {
	A_SEQUENCE_OF(struct SL_PreconfigDiscPool_r13) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SL_PreconfigDiscTxPoolList_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SL_PreconfigDiscTxPoolList_r13;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SL-PreconfigDiscPool-r13.h"

#endif	/* _SL_PreconfigDiscTxPoolList_r13_H_ */
#include <asn_internal.h>
