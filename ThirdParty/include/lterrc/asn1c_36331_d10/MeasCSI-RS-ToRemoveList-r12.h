/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MeasCSI_RS_ToRemoveList_r12_H_
#define	_MeasCSI_RS_ToRemoveList_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MeasCSI-RS-Id-r12.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MeasCSI-RS-ToRemoveList-r12 */
typedef struct MeasCSI_RS_ToRemoveList_r12 {
	A_SEQUENCE_OF(MeasCSI_RS_Id_r12_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasCSI_RS_ToRemoveList_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasCSI_RS_ToRemoveList_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasCSI_RS_ToRemoveList_r12_H_ */
#include <asn_internal.h>
