/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MBMS_SAI_InterFreqList_r11_H_
#define	_MBMS_SAI_InterFreqList_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MBMS_SAI_InterFreq_r11;

/* MBMS-SAI-InterFreqList-r11 */
typedef struct MBMS_SAI_InterFreqList_r11 {
	A_SEQUENCE_OF(struct MBMS_SAI_InterFreq_r11) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMS_SAI_InterFreqList_r11_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMS_SAI_InterFreqList_r11;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MBMS-SAI-InterFreq-r11.h"

#endif	/* _MBMS_SAI_InterFreqList_r11_H_ */
#include <asn_internal.h>
