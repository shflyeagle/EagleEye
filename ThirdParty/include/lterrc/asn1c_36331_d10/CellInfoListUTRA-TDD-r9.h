/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_CellInfoListUTRA_TDD_r9_H_
#define	_CellInfoListUTRA_TDD_r9_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CellInfoUTRA_TDD_r9;

/* CellInfoListUTRA-TDD-r9 */
typedef struct CellInfoListUTRA_TDD_r9 {
	A_SEQUENCE_OF(struct CellInfoUTRA_TDD_r9) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CellInfoListUTRA_TDD_r9_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CellInfoListUTRA_TDD_r9;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CellInfoUTRA-TDD-r9.h"

#endif	/* _CellInfoListUTRA_TDD_r9_H_ */
#include <asn_internal.h>
