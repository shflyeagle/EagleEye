/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_IRAT_ParametersUTRA_TDD_v1020_H_
#define	_IRAT_ParametersUTRA_TDD_v1020_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IRAT_ParametersUTRA_TDD_v1020__e_RedirectionUTRA_TDD_r10 {
	IRAT_ParametersUTRA_TDD_v1020__e_RedirectionUTRA_TDD_r10_supported	= 0
} e_IRAT_ParametersUTRA_TDD_v1020__e_RedirectionUTRA_TDD_r10;

/* IRAT-ParametersUTRA-TDD-v1020 */
typedef struct IRAT_ParametersUTRA_TDD_v1020 {
	ENUMERATED_t	 e_RedirectionUTRA_TDD_r10;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IRAT_ParametersUTRA_TDD_v1020_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_e_RedirectionUTRA_TDD_r10_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_IRAT_ParametersUTRA_TDD_v1020;

#ifdef __cplusplus
}
#endif

#endif	/* _IRAT_ParametersUTRA_TDD_v1020_H_ */
#include <asn_internal.h>
