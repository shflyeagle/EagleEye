/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RRCConnectionSetupComplete_v1250_IEs_H_
#define	_RRCConnectionSetupComplete_v1250_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RRCConnectionSetupComplete_v1250_IEs__mobilityState_r12 {
	RRCConnectionSetupComplete_v1250_IEs__mobilityState_r12_normal	= 0,
	RRCConnectionSetupComplete_v1250_IEs__mobilityState_r12_medium	= 1,
	RRCConnectionSetupComplete_v1250_IEs__mobilityState_r12_high	= 2,
	RRCConnectionSetupComplete_v1250_IEs__mobilityState_r12_spare	= 3
} e_RRCConnectionSetupComplete_v1250_IEs__mobilityState_r12;
typedef enum RRCConnectionSetupComplete_v1250_IEs__mobilityHistoryAvail_r12 {
	RRCConnectionSetupComplete_v1250_IEs__mobilityHistoryAvail_r12_true	= 0
} e_RRCConnectionSetupComplete_v1250_IEs__mobilityHistoryAvail_r12;
typedef enum RRCConnectionSetupComplete_v1250_IEs__logMeasAvailableMBSFN_r12 {
	RRCConnectionSetupComplete_v1250_IEs__logMeasAvailableMBSFN_r12_true	= 0
} e_RRCConnectionSetupComplete_v1250_IEs__logMeasAvailableMBSFN_r12;

/* RRCConnectionSetupComplete-v1250-IEs */
typedef struct RRCConnectionSetupComplete_v1250_IEs {
	ENUMERATED_t	*mobilityState_r12	/* OPTIONAL */;
	ENUMERATED_t	*mobilityHistoryAvail_r12	/* OPTIONAL */;
	ENUMERATED_t	*logMeasAvailableMBSFN_r12	/* OPTIONAL */;
	struct RRCConnectionSetupComplete_v1250_IEs__nonCriticalExtension {
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nonCriticalExtension;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RRCConnectionSetupComplete_v1250_IEs_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_mobilityState_r12_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_mobilityHistoryAvail_r12_7;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_logMeasAvailableMBSFN_r12_9;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RRCConnectionSetupComplete_v1250_IEs;

#ifdef __cplusplus
}
#endif

#endif	/* _RRCConnectionSetupComplete_v1250_IEs_H_ */
#include <asn_internal.h>
