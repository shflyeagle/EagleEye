/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_LWA_Configuration_r13_H_
#define	_LWA_Configuration_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include "LWA-Config-r13.h"
#include <constr_SEQUENCE.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LWA_Configuration_r13_PR {
	LWA_Configuration_r13_PR_NOTHING,	/* No components present */
	LWA_Configuration_r13_PR_release,
	LWA_Configuration_r13_PR_setup
} LWA_Configuration_r13_PR;

/* LWA-Configuration-r13 */
typedef struct LWA_Configuration_r13 {
	LWA_Configuration_r13_PR present;
	union LWA_Configuration_r13_u {
		NULL_t	 release;
		struct LWA_Configuration_r13__setup {
			LWA_Config_r13_t	 lwa_Config_r13;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} setup;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LWA_Configuration_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LWA_Configuration_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _LWA_Configuration_r13_H_ */
#include <asn_internal.h>
