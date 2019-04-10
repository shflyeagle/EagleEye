/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PDCP_Parameters_v1130_H_
#define	_PDCP_Parameters_v1130_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PDCP_Parameters_v1130__pdcp_SN_Extension_r11 {
	PDCP_Parameters_v1130__pdcp_SN_Extension_r11_supported	= 0
} e_PDCP_Parameters_v1130__pdcp_SN_Extension_r11;
typedef enum PDCP_Parameters_v1130__supportRohcContextContinue_r11 {
	PDCP_Parameters_v1130__supportRohcContextContinue_r11_supported	= 0
} e_PDCP_Parameters_v1130__supportRohcContextContinue_r11;

/* PDCP-Parameters-v1130 */
typedef struct PDCP_Parameters_v1130 {
	ENUMERATED_t	*pdcp_SN_Extension_r11	/* OPTIONAL */;
	ENUMERATED_t	*supportRohcContextContinue_r11	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDCP_Parameters_v1130_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_pdcp_SN_Extension_r11_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_supportRohcContextContinue_r11_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PDCP_Parameters_v1130;

#ifdef __cplusplus
}
#endif

#endif	/* _PDCP_Parameters_v1130_H_ */
#include <asn_internal.h>