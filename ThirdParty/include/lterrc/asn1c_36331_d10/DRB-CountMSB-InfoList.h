/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_DRB_CountMSB_InfoList_H_
#define	_DRB_CountMSB_InfoList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DRB_CountMSB_Info;

/* DRB-CountMSB-InfoList */
typedef struct DRB_CountMSB_InfoList {
	A_SEQUENCE_OF(struct DRB_CountMSB_Info) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DRB_CountMSB_InfoList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DRB_CountMSB_InfoList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DRB-CountMSB-Info.h"

#endif	/* _DRB_CountMSB_InfoList_H_ */
#include <asn_internal.h>