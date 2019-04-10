/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "PUCCH-ConfigCommon-v1310.h"

static int
pucch_NumRepetitionCE_Msg4_Level0_r13_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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

static void
pucch_NumRepetitionCE_Msg4_Level0_r13_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
pucch_NumRepetitionCE_Msg4_Level0_r13_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level0_r13_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level0_r13_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level0_r13_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level0_r13_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level0_r13_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level0_r13_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
pucch_NumRepetitionCE_Msg4_Level1_r13_8_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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

static void
pucch_NumRepetitionCE_Msg4_Level1_r13_8_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
pucch_NumRepetitionCE_Msg4_Level1_r13_8_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level1_r13_8_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level1_r13_8_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level1_r13_8_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level1_r13_8_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level1_r13_8_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level1_r13_8_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
pucch_NumRepetitionCE_Msg4_Level2_r13_13_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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

static void
pucch_NumRepetitionCE_Msg4_Level2_r13_13_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
pucch_NumRepetitionCE_Msg4_Level2_r13_13_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level2_r13_13_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level2_r13_13_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level2_r13_13_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level2_r13_13_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level2_r13_13_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level2_r13_13_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
pucch_NumRepetitionCE_Msg4_Level3_r13_18_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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

static void
pucch_NumRepetitionCE_Msg4_Level3_r13_18_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
pucch_NumRepetitionCE_Msg4_Level3_r13_18_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level3_r13_18_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level3_r13_18_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level3_r13_18_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level3_r13_18_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
pucch_NumRepetitionCE_Msg4_Level3_r13_18_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
pucch_NumRepetitionCE_Msg4_Level3_r13_18_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_pucch_NumRepetitionCE_Msg4_Level0_r13_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_pucch_NumRepetitionCE_Msg4_Level1_r13_constr_8 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_pucch_NumRepetitionCE_Msg4_Level2_r13_constr_13 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_pucch_NumRepetitionCE_Msg4_Level3_r13_constr_18 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_pucch_NumRepetitionCE_Msg4_Level0_r13_value2enum_3[] = {
	{ 0,	2,	"n1" },
	{ 1,	2,	"n2" },
	{ 2,	2,	"n4" },
	{ 3,	2,	"n8" }
};
static unsigned int asn_MAP_pucch_NumRepetitionCE_Msg4_Level0_r13_enum2value_3[] = {
	0,	/* n1(0) */
	1,	/* n2(1) */
	2,	/* n4(2) */
	3	/* n8(3) */
};
static asn_INTEGER_specifics_t asn_SPC_pucch_NumRepetitionCE_Msg4_Level0_r13_specs_3 = {
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level0_r13_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level0_r13_enum2value_3,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_3 = {
	"pucch-NumRepetitionCE-Msg4-Level0-r13",
	"pucch-NumRepetitionCE-Msg4-Level0-r13",
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_free,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_print,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_constraint,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_decode_ber,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_encode_der,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_decode_xer,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_encode_xer,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_decode_uper,
	pucch_NumRepetitionCE_Msg4_Level0_r13_3_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3,
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3[0]) - 1, /* 1 */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3,	/* Same as above */
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_tags_3[0]), /* 2 */
	&asn_PER_type_pucch_NumRepetitionCE_Msg4_Level0_r13_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_pucch_NumRepetitionCE_Msg4_Level0_r13_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_pucch_NumRepetitionCE_Msg4_Level1_r13_value2enum_8[] = {
	{ 0,	2,	"n1" },
	{ 1,	2,	"n2" },
	{ 2,	2,	"n4" },
	{ 3,	2,	"n8" }
};
static unsigned int asn_MAP_pucch_NumRepetitionCE_Msg4_Level1_r13_enum2value_8[] = {
	0,	/* n1(0) */
	1,	/* n2(1) */
	2,	/* n4(2) */
	3	/* n8(3) */
};
static asn_INTEGER_specifics_t asn_SPC_pucch_NumRepetitionCE_Msg4_Level1_r13_specs_8 = {
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level1_r13_value2enum_8,	/* "tag" => N; sorted by tag */
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level1_r13_enum2value_8,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_8 = {
	"pucch-NumRepetitionCE-Msg4-Level1-r13",
	"pucch-NumRepetitionCE-Msg4-Level1-r13",
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_free,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_print,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_constraint,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_decode_ber,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_encode_der,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_decode_xer,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_encode_xer,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_decode_uper,
	pucch_NumRepetitionCE_Msg4_Level1_r13_8_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8,
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8[0]) - 1, /* 1 */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8,	/* Same as above */
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_tags_8[0]), /* 2 */
	&asn_PER_type_pucch_NumRepetitionCE_Msg4_Level1_r13_constr_8,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_pucch_NumRepetitionCE_Msg4_Level1_r13_specs_8	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_pucch_NumRepetitionCE_Msg4_Level2_r13_value2enum_13[] = {
	{ 0,	2,	"n4" },
	{ 1,	2,	"n8" },
	{ 2,	3,	"n16" },
	{ 3,	3,	"n32" }
};
static unsigned int asn_MAP_pucch_NumRepetitionCE_Msg4_Level2_r13_enum2value_13[] = {
	2,	/* n16(2) */
	3,	/* n32(3) */
	0,	/* n4(0) */
	1	/* n8(1) */
};
static asn_INTEGER_specifics_t asn_SPC_pucch_NumRepetitionCE_Msg4_Level2_r13_specs_13 = {
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level2_r13_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level2_r13_enum2value_13,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_13 = {
	"pucch-NumRepetitionCE-Msg4-Level2-r13",
	"pucch-NumRepetitionCE-Msg4-Level2-r13",
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_free,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_print,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_constraint,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_decode_ber,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_encode_der,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_decode_xer,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_encode_xer,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_decode_uper,
	pucch_NumRepetitionCE_Msg4_Level2_r13_13_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13,
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13[0]) - 1, /* 1 */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13,	/* Same as above */
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_tags_13[0]), /* 2 */
	&asn_PER_type_pucch_NumRepetitionCE_Msg4_Level2_r13_constr_13,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_pucch_NumRepetitionCE_Msg4_Level2_r13_specs_13	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_pucch_NumRepetitionCE_Msg4_Level3_r13_value2enum_18[] = {
	{ 0,	2,	"n4" },
	{ 1,	2,	"n8" },
	{ 2,	3,	"n16" },
	{ 3,	3,	"n32" }
};
static unsigned int asn_MAP_pucch_NumRepetitionCE_Msg4_Level3_r13_enum2value_18[] = {
	2,	/* n16(2) */
	3,	/* n32(3) */
	0,	/* n4(0) */
	1	/* n8(1) */
};
static asn_INTEGER_specifics_t asn_SPC_pucch_NumRepetitionCE_Msg4_Level3_r13_specs_18 = {
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level3_r13_value2enum_18,	/* "tag" => N; sorted by tag */
	asn_MAP_pucch_NumRepetitionCE_Msg4_Level3_r13_enum2value_18,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_18 = {
	"pucch-NumRepetitionCE-Msg4-Level3-r13",
	"pucch-NumRepetitionCE-Msg4-Level3-r13",
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_free,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_print,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_constraint,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_decode_ber,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_encode_der,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_decode_xer,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_encode_xer,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_decode_uper,
	pucch_NumRepetitionCE_Msg4_Level3_r13_18_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18,
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18[0]) - 1, /* 1 */
	asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18,	/* Same as above */
	sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18)
		/sizeof(asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_tags_18[0]), /* 2 */
	&asn_PER_type_pucch_NumRepetitionCE_Msg4_Level3_r13_constr_18,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_pucch_NumRepetitionCE_Msg4_Level3_r13_specs_18	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_PUCCH_ConfigCommon_v1310_1[] = {
	{ ATF_POINTER, 5, offsetof(struct PUCCH_ConfigCommon_v1310, n1PUCCH_AN_InfoList_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_N1PUCCH_AN_InfoList_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"n1PUCCH-AN-InfoList-r13"
		},
	{ ATF_POINTER, 4, offsetof(struct PUCCH_ConfigCommon_v1310, pucch_NumRepetitionCE_Msg4_Level0_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_pucch_NumRepetitionCE_Msg4_Level0_r13_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pucch-NumRepetitionCE-Msg4-Level0-r13"
		},
	{ ATF_POINTER, 3, offsetof(struct PUCCH_ConfigCommon_v1310, pucch_NumRepetitionCE_Msg4_Level1_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_pucch_NumRepetitionCE_Msg4_Level1_r13_8,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pucch-NumRepetitionCE-Msg4-Level1-r13"
		},
	{ ATF_POINTER, 2, offsetof(struct PUCCH_ConfigCommon_v1310, pucch_NumRepetitionCE_Msg4_Level2_r13),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_pucch_NumRepetitionCE_Msg4_Level2_r13_13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pucch-NumRepetitionCE-Msg4-Level2-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct PUCCH_ConfigCommon_v1310, pucch_NumRepetitionCE_Msg4_Level3_r13),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_pucch_NumRepetitionCE_Msg4_Level3_r13_18,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pucch-NumRepetitionCE-Msg4-Level3-r13"
		},
};
static int asn_MAP_PUCCH_ConfigCommon_v1310_oms_1[] = { 0, 1, 2, 3, 4 };
static ber_tlv_tag_t asn_DEF_PUCCH_ConfigCommon_v1310_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_PUCCH_ConfigCommon_v1310_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* n1PUCCH-AN-InfoList-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* pucch-NumRepetitionCE-Msg4-Level0-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* pucch-NumRepetitionCE-Msg4-Level1-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* pucch-NumRepetitionCE-Msg4-Level2-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* pucch-NumRepetitionCE-Msg4-Level3-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_PUCCH_ConfigCommon_v1310_specs_1 = {
	sizeof(struct PUCCH_ConfigCommon_v1310),
	offsetof(struct PUCCH_ConfigCommon_v1310, _asn_ctx),
	asn_MAP_PUCCH_ConfigCommon_v1310_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_PUCCH_ConfigCommon_v1310_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_PUCCH_ConfigCommon_v1310 = {
	"PUCCH-ConfigCommon-v1310",
	"PUCCH-ConfigCommon-v1310",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_PUCCH_ConfigCommon_v1310_tags_1,
	sizeof(asn_DEF_PUCCH_ConfigCommon_v1310_tags_1)
		/sizeof(asn_DEF_PUCCH_ConfigCommon_v1310_tags_1[0]), /* 1 */
	asn_DEF_PUCCH_ConfigCommon_v1310_tags_1,	/* Same as above */
	sizeof(asn_DEF_PUCCH_ConfigCommon_v1310_tags_1)
		/sizeof(asn_DEF_PUCCH_ConfigCommon_v1310_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_PUCCH_ConfigCommon_v1310_1,
	5,	/* Elements count */
	&asn_SPC_PUCCH_ConfigCommon_v1310_specs_1	/* Additional specs */
};

