/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_BandCombinationParameters_v1090_H_
#define	_BandCombinationParameters_v1090_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BandParameters_v1090;

/* BandCombinationParameters-v1090 */
typedef struct BandCombinationParameters_v1090 {
	A_SEQUENCE_OF(struct BandParameters_v1090) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BandCombinationParameters_v1090_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BandCombinationParameters_v1090;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BandParameters-v1090.h"

#endif	/* _BandCombinationParameters_v1090_H_ */
#include <asn_internal.h>
