/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_Paging_v1130_IEs_H_
#define	_Paging_v1130_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Paging_v1130_IEs__eab_ParamModification_r11 {
	Paging_v1130_IEs__eab_ParamModification_r11_true	= 0
} e_Paging_v1130_IEs__eab_ParamModification_r11;

/* Forward declarations */
struct Paging_v1310_IEs;

/* Paging-v1130-IEs */
typedef struct Paging_v1130_IEs {
	ENUMERATED_t	*eab_ParamModification_r11	/* OPTIONAL */;
	struct Paging_v1310_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Paging_v1130_IEs_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_eab_ParamModification_r11_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_Paging_v1130_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Paging-v1310-IEs.h"

#endif	/* _Paging_v1130_IEs_H_ */
#include <asn_internal.h>
