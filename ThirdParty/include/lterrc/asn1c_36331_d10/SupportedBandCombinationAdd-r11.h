/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SupportedBandCombinationAdd_r11_H_
#define	_SupportedBandCombinationAdd_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BandCombinationParameters_r11;

/* SupportedBandCombinationAdd-r11 */
typedef struct SupportedBandCombinationAdd_r11 {
	A_SEQUENCE_OF(struct BandCombinationParameters_r11) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedBandCombinationAdd_r11_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupportedBandCombinationAdd_r11;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BandCombinationParameters-r11.h"

#endif	/* _SupportedBandCombinationAdd_r11_H_ */
#include <asn_internal.h>