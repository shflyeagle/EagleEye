/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RACH_ConfigCommonSCell_r11_H_
#define	_RACH_ConfigCommonSCell_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PowerRampingParameters.h"
#include "PreambleTransMax.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RACH-ConfigCommonSCell-r11 */
typedef struct RACH_ConfigCommonSCell_r11 {
	PowerRampingParameters_t	 powerRampingParameters_r11;
	struct RACH_ConfigCommonSCell_r11__ra_SupervisionInfo_r11 {
		PreambleTransMax_t	 preambleTransMax_r11;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ra_SupervisionInfo_r11;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RACH_ConfigCommonSCell_r11_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RACH_ConfigCommonSCell_r11;

#ifdef __cplusplus
}
#endif

#endif	/* _RACH_ConfigCommonSCell_r11_H_ */
#include <asn_internal.h>
