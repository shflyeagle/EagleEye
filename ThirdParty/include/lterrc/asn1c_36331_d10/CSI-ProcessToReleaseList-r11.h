/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_CSI_ProcessToReleaseList_r11_H_
#define	_CSI_ProcessToReleaseList_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CSI-ProcessId-r11.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CSI-ProcessToReleaseList-r11 */
typedef struct CSI_ProcessToReleaseList_r11 {
	A_SEQUENCE_OF(CSI_ProcessId_r11_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CSI_ProcessToReleaseList_r11_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CSI_ProcessToReleaseList_r11;

#ifdef __cplusplus
}
#endif

#endif	/* _CSI_ProcessToReleaseList_r11_H_ */
#include <asn_internal.h>
