/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SL_CarrierFreqInfo_v1310_H_
#define	_SL_CarrierFreqInfo_v1310_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SL_ResourcesInterFreq_r13;
struct SL_DiscConfigOtherInterFreq_r13;

/* SL-CarrierFreqInfo-v1310 */
typedef struct SL_CarrierFreqInfo_v1310 {
	struct SL_ResourcesInterFreq_r13	*discResourcesNonPS_r13	/* OPTIONAL */;
	struct SL_ResourcesInterFreq_r13	*discResourcesPS_r13	/* OPTIONAL */;
	struct SL_DiscConfigOtherInterFreq_r13	*discConfigOther_r13	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SL_CarrierFreqInfo_v1310_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SL_CarrierFreqInfo_v1310;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SL-ResourcesInterFreq-r13.h"
#include "SL-DiscConfigOtherInterFreq-r13.h"

#endif	/* _SL_CarrierFreqInfo_v1310_H_ */
#include <asn_internal.h>
