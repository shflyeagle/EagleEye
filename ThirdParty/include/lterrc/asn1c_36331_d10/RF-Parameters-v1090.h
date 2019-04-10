/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RF_Parameters_v1090_H_
#define	_RF_Parameters_v1090_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SupportedBandCombination_v1090;

/* RF-Parameters-v1090 */
typedef struct RF_Parameters_v1090 {
	struct SupportedBandCombination_v1090	*supportedBandCombination_v1090	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RF_Parameters_v1090_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RF_Parameters_v1090;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SupportedBandCombination-v1090.h"

#endif	/* _RF_Parameters_v1090_H_ */
#include <asn_internal.h>
