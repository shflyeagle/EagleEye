/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_QuantityConfigUTRA_v1020_H_
#define	_QuantityConfigUTRA_v1020_H_


#include <asn_application.h>

/* Including external dependencies */
#include "FilterCoefficient.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* QuantityConfigUTRA-v1020 */
typedef struct QuantityConfigUTRA_v1020 {
	FilterCoefficient_t	*filterCoefficient2_FDD_r10	/* DEFAULT 4 */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} QuantityConfigUTRA_v1020_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_QuantityConfigUTRA_v1020;

#ifdef __cplusplus
}
#endif

#endif	/* _QuantityConfigUTRA_v1020_H_ */
#include <asn_internal.h>
