/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_FreqHoppingParameters_r13_H_
#define	_FreqHoppingParameters_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <NativeInteger.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum FreqHoppingParameters_r13__mpdcch_pdsch_HoppingNB_r13 {
	FreqHoppingParameters_r13__mpdcch_pdsch_HoppingNB_r13_nb2	= 0,
	FreqHoppingParameters_r13__mpdcch_pdsch_HoppingNB_r13_nb4	= 1
} e_FreqHoppingParameters_r13__mpdcch_pdsch_HoppingNB_r13;
typedef enum FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_PR {
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_PR_NOTHING,	/* No components present */
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_PR_interval_FDD_r13,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_PR_interval_TDD_r13
} FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_PR;
typedef enum FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13 {
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int1	= 0,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int2	= 1,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int4	= 2,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13_int8	= 3
} e_FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_FDD_r13;
typedef enum FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13 {
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int1	= 0,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int5	= 1,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int10	= 2,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13_int20	= 3
} e_FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13__interval_TDD_r13;
typedef enum FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_PR {
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_PR_NOTHING,	/* No components present */
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_PR_interval_FDD_r13,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_PR_interval_TDD_r13
} FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_PR;
typedef enum FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13 {
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int2	= 0,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int4	= 1,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int8	= 2,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13_int16	= 3
} e_FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_FDD_r13;
typedef enum FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13 {
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int5	= 0,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int10	= 1,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int20	= 2,
	FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13_int40	= 3
} e_FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13__interval_TDD_r13;
typedef enum FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_PR {
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_PR_NOTHING,	/* No components present */
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_PR_interval_FDD_r13,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_PR_interval_TDD_r13
} FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_PR;
typedef enum FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_FDD_r13 {
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_FDD_r13_int1	= 0,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_FDD_r13_int2	= 1,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_FDD_r13_int4	= 2,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_FDD_r13_int8	= 3
} e_FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_FDD_r13;
typedef enum FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_TDD_r13 {
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_TDD_r13_int1	= 0,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_TDD_r13_int5	= 1,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_TDD_r13_int10	= 2,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_TDD_r13_int20	= 3
} e_FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13__interval_TDD_r13;
typedef enum FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_PR {
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_PR_NOTHING,	/* No components present */
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_PR_interval_FDD_r13,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_PR_interval_TDD_r13
} FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_PR;
typedef enum FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_FDD_r13 {
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_FDD_r13_int2	= 0,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_FDD_r13_int4	= 1,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_FDD_r13_int8	= 2,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_FDD_r13_int16	= 3
} e_FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_FDD_r13;
typedef enum FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_TDD_r13 {
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_TDD_r13_int5	= 0,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_TDD_r13_int10	= 1,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_TDD_r13_int20	= 2,
	FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_TDD_r13_int40	= 3
} e_FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13__interval_TDD_r13;

/* FreqHoppingParameters-r13 */
typedef struct FreqHoppingParameters_r13 {
	ENUMERATED_t	*mpdcch_pdsch_HoppingNB_r13	/* OPTIONAL */;
	struct FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13 {
		FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_PR present;
		union FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeA_r13_u {
			ENUMERATED_t	 interval_FDD_r13;
			ENUMERATED_t	 interval_TDD_r13;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *interval_DLHoppingConfigCommonModeA_r13;
	struct FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13 {
		FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_PR present;
		union FreqHoppingParameters_r13__interval_DLHoppingConfigCommonModeB_r13_u {
			ENUMERATED_t	 interval_FDD_r13;
			ENUMERATED_t	 interval_TDD_r13;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *interval_DLHoppingConfigCommonModeB_r13;
	struct FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13 {
		FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_PR present;
		union FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeA_r13_u {
			ENUMERATED_t	 interval_FDD_r13;
			ENUMERATED_t	 interval_TDD_r13;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *interval_ULHoppingConfigCommonModeA_r13;
	struct FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13 {
		FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_PR present;
		union FreqHoppingParameters_r13__interval_ULHoppingConfigCommonModeB_r13_u {
			ENUMERATED_t	 interval_FDD_r13;
			ENUMERATED_t	 interval_TDD_r13;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *interval_ULHoppingConfigCommonModeB_r13;
	long	*mpdcch_pdsch_HoppingOffset_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FreqHoppingParameters_r13_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_mpdcch_pdsch_HoppingNB_r13_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_FDD_r13_6;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_TDD_r13_11;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_FDD_r13_17;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_TDD_r13_22;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_FDD_r13_28;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_TDD_r13_33;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_FDD_r13_39;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_interval_TDD_r13_44;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_FreqHoppingParameters_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _FreqHoppingParameters_r13_H_ */
#include <asn_internal.h>
