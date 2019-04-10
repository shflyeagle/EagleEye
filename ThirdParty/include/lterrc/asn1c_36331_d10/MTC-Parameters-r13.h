/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MTC_Parameters_r13_H_
#define	_MTC_Parameters_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MTC_Parameters_r13__ce_ModeA_r13 {
	MTC_Parameters_r13__ce_ModeA_r13_supported	= 0
} e_MTC_Parameters_r13__ce_ModeA_r13;
typedef enum MTC_Parameters_r13__ce_ModeB_r13 {
	MTC_Parameters_r13__ce_ModeB_r13_supported	= 0
} e_MTC_Parameters_r13__ce_ModeB_r13;

/* MTC-Parameters-r13 */
typedef struct MTC_Parameters_r13 {
	ENUMERATED_t	*ce_ModeA_r13	/* OPTIONAL */;
	ENUMERATED_t	*ce_ModeB_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MTC_Parameters_r13_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_ce_ModeA_r13_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ce_ModeB_r13_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_MTC_Parameters_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _MTC_Parameters_r13_H_ */
#include <asn_internal.h>