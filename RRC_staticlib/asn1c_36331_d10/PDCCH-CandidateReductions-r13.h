/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PDCCH_CandidateReductions_r13_H_
#define	_PDCCH_CandidateReductions_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include "PDCCH-CandidateReductionValue-r13.h"
#include <constr_SEQUENCE.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PDCCH_CandidateReductions_r13_PR {
	PDCCH_CandidateReductions_r13_PR_NOTHING,	/* No components present */
	PDCCH_CandidateReductions_r13_PR_release,
	PDCCH_CandidateReductions_r13_PR_setup
} PDCCH_CandidateReductions_r13_PR;

/* PDCCH-CandidateReductions-r13 */
typedef struct PDCCH_CandidateReductions_r13 {
	PDCCH_CandidateReductions_r13_PR present;
	union PDCCH_CandidateReductions_r13_u {
		NULL_t	 release;
		struct PDCCH_CandidateReductions_r13__setup {
			PDCCH_CandidateReductionValue_r13_t	 pdcch_candidateReductionAL1;
			PDCCH_CandidateReductionValue_r13_t	 pdcch_candidateReductionAL2;
			PDCCH_CandidateReductionValue_r13_t	 pdcch_candidateReductionAL3;
			PDCCH_CandidateReductionValue_r13_t	 pdcch_candidateReductionAL4;
			PDCCH_CandidateReductionValue_r13_t	 pdcch_candidateReductionAL5;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} setup;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDCCH_CandidateReductions_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDCCH_CandidateReductions_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _PDCCH_CandidateReductions_r13_H_ */
#include <asn_internal.h>
