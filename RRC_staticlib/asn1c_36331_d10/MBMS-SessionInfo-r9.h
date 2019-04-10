/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MBMS_SessionInfo_r9_H_
#define	_MBMS_SessionInfo_r9_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TMGI-r9.h"
#include <OCTET_STRING.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MBMS-SessionInfo-r9 */
typedef struct MBMS_SessionInfo_r9 {
	TMGI_r9_t	 tmgi_r9;
	OCTET_STRING_t	*sessionId_r9	/* OPTIONAL */;
	long	 logicalChannelIdentity_r9;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMS_SessionInfo_r9_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMS_SessionInfo_r9;

#ifdef __cplusplus
}
#endif

#endif	/* _MBMS_SessionInfo_r9_H_ */
#include <asn_internal.h>
