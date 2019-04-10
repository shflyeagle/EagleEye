/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "P-a.h"

int
P_a_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_ENUMERATED.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ENUMERATED,
 * so here we adjust the DEF accordingly.
 */
static void
P_a_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_ENUMERATED.free_struct;
	td->print_struct   = asn_DEF_ENUMERATED.print_struct;
	td->check_constraints = asn_DEF_ENUMERATED.check_constraints;
	td->ber_decoder    = asn_DEF_ENUMERATED.ber_decoder;
	td->der_encoder    = asn_DEF_ENUMERATED.der_encoder;
	td->xer_decoder    = asn_DEF_ENUMERATED.xer_decoder;
	td->xer_encoder    = asn_DEF_ENUMERATED.xer_encoder;
	td->uper_decoder   = asn_DEF_ENUMERATED.uper_decoder;
	td->uper_encoder   = asn_DEF_ENUMERATED.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_ENUMERATED.per_constraints;
	td->elements       = asn_DEF_ENUMERATED.elements;
	td->elements_count = asn_DEF_ENUMERATED.elements_count;
     /* td->specifics      = asn_DEF_ENUMERATED.specifics;	// Defined explicitly */
}

void
P_a_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	P_a_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
P_a_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
P_a_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
P_a_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
P_a_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
P_a_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

asn_dec_rval_t
P_a_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

asn_enc_rval_t
P_a_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	P_a_1_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_P_a_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  7 }	/* (0..7) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_P_a_value2enum_1[] = {
	{ 0,	4,	"dB-6" },
	{ 1,	9,	"dB-4dot77" },
	{ 2,	4,	"dB-3" },
	{ 3,	9,	"dB-1dot77" },
	{ 4,	3,	"dB0" },
	{ 5,	3,	"dB1" },
	{ 6,	3,	"dB2" },
	{ 7,	3,	"dB3" }
};
static unsigned int asn_MAP_P_a_enum2value_1[] = {
	3,	/* dB-1dot77(3) */
	2,	/* dB-3(2) */
	1,	/* dB-4dot77(1) */
	0,	/* dB-6(0) */
	4,	/* dB0(4) */
	5,	/* dB1(5) */
	6,	/* dB2(6) */
	7	/* dB3(7) */
};
static asn_INTEGER_specifics_t asn_SPC_P_a_specs_1 = {
	asn_MAP_P_a_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_P_a_enum2value_1,	/* N => "tag"; sorted by N */
	8,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_P_a_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_P_a = {
	"P-a",
	"P-a",
	P_a_free,
	P_a_print,
	P_a_constraint,
	P_a_decode_ber,
	P_a_encode_der,
	P_a_decode_xer,
	P_a_encode_xer,
	P_a_decode_uper,
	P_a_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_P_a_tags_1,
	sizeof(asn_DEF_P_a_tags_1)
		/sizeof(asn_DEF_P_a_tags_1[0]), /* 1 */
	asn_DEF_P_a_tags_1,	/* Same as above */
	sizeof(asn_DEF_P_a_tags_1)
		/sizeof(asn_DEF_P_a_tags_1[0]), /* 1 */
	&asn_PER_type_P_a_constr_1,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_P_a_specs_1	/* Additional specs */
};
