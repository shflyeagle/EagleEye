/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_NZP_ResourceConfig_r13_H_
#define	_NZP_ResourceConfig_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ResourceConfig-r13.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NZP-ResourceConfig-r13 */
typedef struct NZP_ResourceConfig_r13 {
	ResourceConfig_r13_t	 resourceConfig_r13;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NZP_ResourceConfig_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NZP_ResourceConfig_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _NZP_ResourceConfig_r13_H_ */
#include <asn_internal.h>
