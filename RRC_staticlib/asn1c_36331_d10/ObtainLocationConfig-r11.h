/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_ObtainLocationConfig_r11_H_
#define	_ObtainLocationConfig_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ObtainLocationConfig_r11__obtainLocation_r11 {
	ObtainLocationConfig_r11__obtainLocation_r11_setup	= 0
} e_ObtainLocationConfig_r11__obtainLocation_r11;

/* ObtainLocationConfig-r11 */
typedef struct ObtainLocationConfig_r11 {
	ENUMERATED_t	*obtainLocation_r11	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ObtainLocationConfig_r11_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_obtainLocation_r11_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_ObtainLocationConfig_r11;

#ifdef __cplusplus
}
#endif

#endif	/* _ObtainLocationConfig_r11_H_ */
#include <asn_internal.h>