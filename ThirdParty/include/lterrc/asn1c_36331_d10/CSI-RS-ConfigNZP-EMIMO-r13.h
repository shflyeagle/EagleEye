/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_CSI_RS_ConfigNZP_EMIMO_r13_H_
#define	_CSI_RS_ConfigNZP_EMIMO_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <ENUMERATED.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CSI_RS_ConfigNZP_EMIMO_r13_PR {
	CSI_RS_ConfigNZP_EMIMO_r13_PR_NOTHING,	/* No components present */
	CSI_RS_ConfigNZP_EMIMO_r13_PR_release,
	CSI_RS_ConfigNZP_EMIMO_r13_PR_setup
} CSI_RS_ConfigNZP_EMIMO_r13_PR;
typedef enum CSI_RS_ConfigNZP_EMIMO_r13__setup__cdmType_r13 {
	CSI_RS_ConfigNZP_EMIMO_r13__setup__cdmType_r13_cdm2	= 0,
	CSI_RS_ConfigNZP_EMIMO_r13__setup__cdmType_r13_cdm4	= 1
} e_CSI_RS_ConfigNZP_EMIMO_r13__setup__cdmType_r13;

/* Forward declarations */
struct NZP_ResourceConfig_r13;

/* CSI-RS-ConfigNZP-EMIMO-r13 */
typedef struct CSI_RS_ConfigNZP_EMIMO_r13 {
	CSI_RS_ConfigNZP_EMIMO_r13_PR present;
	union CSI_RS_ConfigNZP_EMIMO_r13_u {
		NULL_t	 release;
		struct CSI_RS_ConfigNZP_EMIMO_r13__setup {
			struct CSI_RS_ConfigNZP_EMIMO_r13__setup__nzp_resourceConfigList_r13 {
				A_SEQUENCE_OF(struct NZP_ResourceConfig_r13) list;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} nzp_resourceConfigList_r13;
			ENUMERATED_t	*cdmType_r13	/* OPTIONAL */;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} setup;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CSI_RS_ConfigNZP_EMIMO_r13_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_cdmType_r13_6;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_CSI_RS_ConfigNZP_EMIMO_r13;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NZP-ResourceConfig-r13.h"

#endif	/* _CSI_RS_ConfigNZP_EMIMO_r13_H_ */
#include <asn_internal.h>
