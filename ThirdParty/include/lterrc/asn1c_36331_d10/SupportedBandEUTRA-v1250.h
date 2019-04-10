/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SupportedBandEUTRA_v1250_H_
#define	_SupportedBandEUTRA_v1250_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SupportedBandEUTRA_v1250__dl_256QAM_r12 {
	SupportedBandEUTRA_v1250__dl_256QAM_r12_supported	= 0
} e_SupportedBandEUTRA_v1250__dl_256QAM_r12;
typedef enum SupportedBandEUTRA_v1250__ul_64QAM_r12 {
	SupportedBandEUTRA_v1250__ul_64QAM_r12_supported	= 0
} e_SupportedBandEUTRA_v1250__ul_64QAM_r12;

/* SupportedBandEUTRA-v1250 */
typedef struct SupportedBandEUTRA_v1250 {
	ENUMERATED_t	*dl_256QAM_r12	/* OPTIONAL */;
	ENUMERATED_t	*ul_64QAM_r12	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedBandEUTRA_v1250_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_dl_256QAM_r12_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ul_64QAM_r12_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_SupportedBandEUTRA_v1250;

#ifdef __cplusplus
}
#endif

#endif	/* _SupportedBandEUTRA_v1250_H_ */
#include <asn_internal.h>