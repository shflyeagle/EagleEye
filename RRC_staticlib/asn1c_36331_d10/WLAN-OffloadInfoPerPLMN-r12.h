/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_WLAN_OffloadInfoPerPLMN_r12_H_
#define	_WLAN_OffloadInfoPerPLMN_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct WLAN_OffloadConfig_r12;
struct WLAN_Id_List_r12;

/* WLAN-OffloadInfoPerPLMN-r12 */
typedef struct WLAN_OffloadInfoPerPLMN_r12 {
	struct WLAN_OffloadConfig_r12	*wlan_OffloadConfigCommon_r12	/* OPTIONAL */;
	struct WLAN_Id_List_r12	*wlan_Id_List_r12	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} WLAN_OffloadInfoPerPLMN_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WLAN_OffloadInfoPerPLMN_r12;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WLAN-OffloadConfig-r12.h"
#include "WLAN-Id-List-r12.h"

#endif	/* _WLAN_OffloadInfoPerPLMN_r12_H_ */
#include <asn_internal.h>
