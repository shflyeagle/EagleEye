/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RetxBSR_Timer_r12_H_
#define	_RetxBSR_Timer_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RetxBSR_Timer_r12 {
	RetxBSR_Timer_r12_sf320	= 0,
	RetxBSR_Timer_r12_sf640	= 1,
	RetxBSR_Timer_r12_sf1280	= 2,
	RetxBSR_Timer_r12_sf2560	= 3,
	RetxBSR_Timer_r12_sf5120	= 4,
	RetxBSR_Timer_r12_sf10240	= 5,
	RetxBSR_Timer_r12_spare2	= 6,
	RetxBSR_Timer_r12_spare1	= 7
} e_RetxBSR_Timer_r12;

/* RetxBSR-Timer-r12 */
typedef ENUMERATED_t	 RetxBSR_Timer_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RetxBSR_Timer_r12;
asn_struct_free_f RetxBSR_Timer_r12_free;
asn_struct_print_f RetxBSR_Timer_r12_print;
asn_constr_check_f RetxBSR_Timer_r12_constraint;
ber_type_decoder_f RetxBSR_Timer_r12_decode_ber;
der_type_encoder_f RetxBSR_Timer_r12_encode_der;
xer_type_decoder_f RetxBSR_Timer_r12_decode_xer;
xer_type_encoder_f RetxBSR_Timer_r12_encode_xer;
per_type_decoder_f RetxBSR_Timer_r12_decode_uper;
per_type_encoder_f RetxBSR_Timer_r12_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _RetxBSR_Timer_r12_H_ */
#include <asn_internal.h>
