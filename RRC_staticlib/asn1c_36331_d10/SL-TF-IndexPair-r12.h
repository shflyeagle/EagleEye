/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SL_TF_IndexPair_r12_H_
#define	_SL_TF_IndexPair_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SL-TF-IndexPair-r12 */
typedef struct SL_TF_IndexPair_r12 {
	long	*discSF_Index_r12	/* OPTIONAL */;
	long	*discPRB_Index_r12	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SL_TF_IndexPair_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SL_TF_IndexPair_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _SL_TF_IndexPair_r12_H_ */
#include <asn_internal.h>
