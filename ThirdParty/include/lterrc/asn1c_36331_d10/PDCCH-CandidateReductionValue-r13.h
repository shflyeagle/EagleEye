/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PDCCH_CandidateReductionValue_r13_H_
#define	_PDCCH_CandidateReductionValue_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PDCCH_CandidateReductionValue_r13 {
	PDCCH_CandidateReductionValue_r13_n0	= 0,
	PDCCH_CandidateReductionValue_r13_n33	= 1,
	PDCCH_CandidateReductionValue_r13_n66	= 2,
	PDCCH_CandidateReductionValue_r13_n100	= 3
} e_PDCCH_CandidateReductionValue_r13;

/* PDCCH-CandidateReductionValue-r13 */
typedef ENUMERATED_t	 PDCCH_CandidateReductionValue_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDCCH_CandidateReductionValue_r13;
asn_struct_free_f PDCCH_CandidateReductionValue_r13_free;
asn_struct_print_f PDCCH_CandidateReductionValue_r13_print;
asn_constr_check_f PDCCH_CandidateReductionValue_r13_constraint;
ber_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_ber;
der_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_der;
xer_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_xer;
xer_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_xer;
per_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_uper;
per_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _PDCCH_CandidateReductionValue_r13_H_ */
#include <asn_internal.h>