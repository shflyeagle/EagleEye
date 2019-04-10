/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MeasObjectWLAN_r13_H_
#define	_MeasObjectWLAN_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include "WLAN-BandIndicator-r13.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MeasObjectWLAN_r13__carrierFreq_r13_PR {
	MeasObjectWLAN_r13__carrierFreq_r13_PR_NOTHING,	/* No components present */
	MeasObjectWLAN_r13__carrierFreq_r13_PR_bandIndicatorListWLAN_r13,
	MeasObjectWLAN_r13__carrierFreq_r13_PR_carrierInfoListWLAN_r13
} MeasObjectWLAN_r13__carrierFreq_r13_PR;

/* Forward declarations */
struct WLAN_Id_List_r13;
struct WLAN_CarrierInfo_r13;

/* MeasObjectWLAN-r13 */
typedef struct MeasObjectWLAN_r13 {
	struct MeasObjectWLAN_r13__carrierFreq_r13 {
		MeasObjectWLAN_r13__carrierFreq_r13_PR present;
		union MeasObjectWLAN_r13__carrierFreq_r13_u {
			struct MeasObjectWLAN_r13__carrierFreq_r13__bandIndicatorListWLAN_r13 {
				A_SEQUENCE_OF(WLAN_BandIndicator_r13_t) list;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} bandIndicatorListWLAN_r13;
			struct MeasObjectWLAN_r13__carrierFreq_r13__carrierInfoListWLAN_r13 {
				A_SEQUENCE_OF(struct WLAN_CarrierInfo_r13) list;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} carrierInfoListWLAN_r13;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *carrierFreq_r13;
	struct WLAN_Id_List_r13	*wlan_ToAddModList_r13	/* OPTIONAL */;
	struct WLAN_Id_List_r13	*wlan_ToRemoveList_r13	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasObjectWLAN_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasObjectWLAN_r13;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WLAN-Id-List-r13.h"
#include "WLAN-CarrierInfo-r13.h"

#endif	/* _MeasObjectWLAN_r13_H_ */
#include <asn_internal.h>
