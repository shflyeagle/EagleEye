/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_HandoverFromEUTRAPreparationRequest_r8_IEs_H_
#define	_HandoverFromEUTRAPreparationRequest_r8_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CDMA2000-Type.h"
#include "RAND-CDMA2000.h"
#include "MobilityParametersCDMA2000.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct HandoverFromEUTRAPreparationRequest_v890_IEs;

/* HandoverFromEUTRAPreparationRequest-r8-IEs */
typedef struct HandoverFromEUTRAPreparationRequest_r8_IEs {
	CDMA2000_Type_t	 cdma2000_Type;
	RAND_CDMA2000_t	*rand	/* OPTIONAL */;
	MobilityParametersCDMA2000_t	*mobilityParameters	/* OPTIONAL */;
	struct HandoverFromEUTRAPreparationRequest_v890_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HandoverFromEUTRAPreparationRequest_r8_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HandoverFromEUTRAPreparationRequest_r8_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "HandoverFromEUTRAPreparationRequest-v890-IEs.h"

#endif	/* _HandoverFromEUTRAPreparationRequest_r8_IEs_H_ */
#include <asn_internal.h>
