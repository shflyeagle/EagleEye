/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_BLER_Result_r12_H_
#define	_BLER_Result_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BLER-Range-r12.h"
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BLER-Result-r12 */
typedef struct BLER_Result_r12 {
	BLER_Range_r12_t	 bler_r12;
	struct BLER_Result_r12__blocksReceived_r12 {
		BIT_STRING_t	 n_r12;
		BIT_STRING_t	 m_r12;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} blocksReceived_r12;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BLER_Result_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BLER_Result_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _BLER_Result_r12_H_ */
#include <asn_internal.h>
