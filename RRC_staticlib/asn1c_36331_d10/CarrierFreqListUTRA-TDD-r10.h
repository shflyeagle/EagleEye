/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_CarrierFreqListUTRA_TDD_r10_H_
#define	_CarrierFreqListUTRA_TDD_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ARFCN-ValueUTRA.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CarrierFreqListUTRA-TDD-r10 */
typedef struct CarrierFreqListUTRA_TDD_r10 {
	A_SEQUENCE_OF(ARFCN_ValueUTRA_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CarrierFreqListUTRA_TDD_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CarrierFreqListUTRA_TDD_r10;

#ifdef __cplusplus
}
#endif

#endif	/* _CarrierFreqListUTRA_TDD_r10_H_ */
#include <asn_internal.h>
