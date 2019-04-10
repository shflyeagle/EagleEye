/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PhyLayerParameters_v9d0_H_
#define	_PhyLayerParameters_v9d0_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PhyLayerParameters_v9d0__tm5_FDD_r9 {
	PhyLayerParameters_v9d0__tm5_FDD_r9_supported	= 0
} e_PhyLayerParameters_v9d0__tm5_FDD_r9;
typedef enum PhyLayerParameters_v9d0__tm5_TDD_r9 {
	PhyLayerParameters_v9d0__tm5_TDD_r9_supported	= 0
} e_PhyLayerParameters_v9d0__tm5_TDD_r9;

/* PhyLayerParameters-v9d0 */
typedef struct PhyLayerParameters_v9d0 {
	ENUMERATED_t	*tm5_FDD_r9	/* OPTIONAL */;
	ENUMERATED_t	*tm5_TDD_r9	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PhyLayerParameters_v9d0_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_tm5_FDD_r9_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_tm5_TDD_r9_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PhyLayerParameters_v9d0;

#ifdef __cplusplus
}
#endif

#endif	/* _PhyLayerParameters_v9d0_H_ */
#include <asn_internal.h>
