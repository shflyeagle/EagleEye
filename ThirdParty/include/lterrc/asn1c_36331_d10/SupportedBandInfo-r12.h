/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SupportedBandInfo_r12_H_
#define	_SupportedBandInfo_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SupportedBandInfo_r12__support_r12 {
	SupportedBandInfo_r12__support_r12_supported	= 0
} e_SupportedBandInfo_r12__support_r12;

/* SupportedBandInfo-r12 */
typedef struct SupportedBandInfo_r12 {
	ENUMERATED_t	*support_r12	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedBandInfo_r12_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_support_r12_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_SupportedBandInfo_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _SupportedBandInfo_r12_H_ */
#include <asn_internal.h>
