/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_EstablishmentCause_H_
#define	_EstablishmentCause_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum EstablishmentCause {
	EstablishmentCause_emergency	= 0,
	EstablishmentCause_highPriorityAccess	= 1,
	EstablishmentCause_mt_Access	= 2,
	EstablishmentCause_mo_Signalling	= 3,
	EstablishmentCause_mo_Data	= 4,
	EstablishmentCause_delayTolerantAccess_v1020	= 5,
	EstablishmentCause_mo_VoiceCall_v1280	= 6,
	EstablishmentCause_spare1	= 7
} e_EstablishmentCause;

/* EstablishmentCause */
typedef ENUMERATED_t	 EstablishmentCause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EstablishmentCause;
asn_struct_free_f EstablishmentCause_free;
asn_struct_print_f EstablishmentCause_print;
asn_constr_check_f EstablishmentCause_constraint;
ber_type_decoder_f EstablishmentCause_decode_ber;
der_type_encoder_f EstablishmentCause_encode_der;
xer_type_decoder_f EstablishmentCause_decode_xer;
xer_type_encoder_f EstablishmentCause_encode_xer;
per_type_decoder_f EstablishmentCause_decode_uper;
per_type_encoder_f EstablishmentCause_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _EstablishmentCause_H_ */
#include <asn_internal.h>