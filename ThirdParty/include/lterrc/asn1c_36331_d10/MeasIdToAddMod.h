/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MeasIdToAddMod_H_
#define	_MeasIdToAddMod_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MeasId.h"
#include "MeasObjectId.h"
#include "ReportConfigId.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MeasIdToAddMod */
typedef struct MeasIdToAddMod {
	MeasId_t	 measId;
	MeasObjectId_t	 measObjectId;
	ReportConfigId_t	 reportConfigId;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasIdToAddMod_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasIdToAddMod;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasIdToAddMod_H_ */
#include <asn_internal.h>
