/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MBMS_Parameters_v1250_H_
#define	_MBMS_Parameters_v1250_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MBMS_Parameters_v1250__mbms_AsyncDC_r12 {
	MBMS_Parameters_v1250__mbms_AsyncDC_r12_supported	= 0
} e_MBMS_Parameters_v1250__mbms_AsyncDC_r12;

/* MBMS-Parameters-v1250 */
typedef struct MBMS_Parameters_v1250 {
	ENUMERATED_t	*mbms_AsyncDC_r12	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMS_Parameters_v1250_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_mbms_AsyncDC_r12_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_MBMS_Parameters_v1250;

#ifdef __cplusplus
}
#endif

#endif	/* _MBMS_Parameters_v1250_H_ */
#include <asn_internal.h>
