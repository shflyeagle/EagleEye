/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_WLAN_Identifiers_r12_H_
#define	_WLAN_Identifiers_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* WLAN-Identifiers-r12 */
typedef struct WLAN_Identifiers_r12 {
	OCTET_STRING_t	*ssid_r12	/* OPTIONAL */;
	OCTET_STRING_t	*bssid_r12	/* OPTIONAL */;
	OCTET_STRING_t	*hessid_r12	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} WLAN_Identifiers_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WLAN_Identifiers_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _WLAN_Identifiers_r12_H_ */
#include <asn_internal.h>
