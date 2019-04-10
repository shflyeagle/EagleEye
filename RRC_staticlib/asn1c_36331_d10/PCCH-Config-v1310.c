/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "PCCH-Config-v1310.h"

static int
mpdcch_NumRepetition_Paging_r13_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
mpdcch_NumRepetition_Paging_r13_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
mpdcch_NumRepetition_Paging_r13_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
mpdcch_NumRepetition_Paging_r13_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
mpdcch_NumRepetition_Paging_r13_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
mpdcch_NumRepetition_Paging_r13_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
mpdcch_NumRepetition_Paging_r13_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
mpdcch_NumRepetition_Paging_r13_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
mpdcch_NumRepetition_Paging_r13_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	mpdcch_NumRepetition_Paging_r13_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
nB_v1310_13_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
nB_v1310_13_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
nB_v1310_13_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
nB_v1310_13_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
nB_v1310_13_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
nB_v1310_13_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
nB_v1310_13_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
nB_v1310_13_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
nB_v1310_13_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
nB_v1310_13_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	nB_v1310_13_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_paging_narrowBands_r13_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 16)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_mpdcch_NumRepetition_Paging_r13_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  8 }	/* (0..8) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_nB_v1310_constr_13 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_paging_narrowBands_r13_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (1..16) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_mpdcch_NumRepetition_Paging_r13_value2enum_3[] = {
	{ 0,	2,	"r1" },
	{ 1,	2,	"r2" },
	{ 2,	2,	"r4" },
	{ 3,	2,	"r8" },
	{ 4,	3,	"r16" },
	{ 5,	3,	"r32" },
	{ 6,	3,	"r64" },
	{ 7,	4,	"r128" },
	{ 8,	4,	"r256" }
};
static unsigned int asn_MAP_mpdcch_NumRepetition_Paging_r13_enum2value_3[] = {
	0,	/* r1(0) */
	7,	/* r128(7) */
	4,	/* r16(4) */
	1,	/* r2(1) */
	8,	/* r256(8) */
	5,	/* r32(5) */
	2,	/* r4(2) */
	6,	/* r64(6) */
	3	/* r8(3) */
};
static asn_INTEGER_specifics_t asn_SPC_mpdcch_NumRepetition_Paging_r13_specs_3 = {
	asn_MAP_mpdcch_NumRepetition_Paging_r13_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_mpdcch_NumRepetition_Paging_r13_enum2value_3,	/* N => "tag"; sorted by N */
	9,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mpdcch_NumRepetition_Paging_r13_3 = {
	"mpdcch-NumRepetition-Paging-r13",
	"mpdcch-NumRepetition-Paging-r13",
	mpdcch_NumRepetition_Paging_r13_3_free,
	mpdcch_NumRepetition_Paging_r13_3_print,
	mpdcch_NumRepetition_Paging_r13_3_constraint,
	mpdcch_NumRepetition_Paging_r13_3_decode_ber,
	mpdcch_NumRepetition_Paging_r13_3_encode_der,
	mpdcch_NumRepetition_Paging_r13_3_decode_xer,
	mpdcch_NumRepetition_Paging_r13_3_encode_xer,
	mpdcch_NumRepetition_Paging_r13_3_decode_uper,
	mpdcch_NumRepetition_Paging_r13_3_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3,
	sizeof(asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3)
		/sizeof(asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3[0]) - 1, /* 1 */
	asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3,	/* Same as above */
	sizeof(asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3)
		/sizeof(asn_DEF_mpdcch_NumRepetition_Paging_r13_tags_3[0]), /* 2 */
	&asn_PER_type_mpdcch_NumRepetition_Paging_r13_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_mpdcch_NumRepetition_Paging_r13_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_nB_v1310_value2enum_13[] = {
	{ 0,	8,	"one64thT" },
	{ 1,	9,	"one128thT" },
	{ 2,	9,	"one256thT" }
};
static unsigned int asn_MAP_nB_v1310_enum2value_13[] = {
	1,	/* one128thT(1) */
	2,	/* one256thT(2) */
	0	/* one64thT(0) */
};
static asn_INTEGER_specifics_t asn_SPC_nB_v1310_specs_13 = {
	asn_MAP_nB_v1310_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_nB_v1310_enum2value_13,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_nB_v1310_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nB_v1310_13 = {
	"nB-v1310",
	"nB-v1310",
	nB_v1310_13_free,
	nB_v1310_13_print,
	nB_v1310_13_constraint,
	nB_v1310_13_decode_ber,
	nB_v1310_13_encode_der,
	nB_v1310_13_decode_xer,
	nB_v1310_13_encode_xer,
	nB_v1310_13_decode_uper,
	nB_v1310_13_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_nB_v1310_tags_13,
	sizeof(asn_DEF_nB_v1310_tags_13)
		/sizeof(asn_DEF_nB_v1310_tags_13[0]) - 1, /* 1 */
	asn_DEF_nB_v1310_tags_13,	/* Same as above */
	sizeof(asn_DEF_nB_v1310_tags_13)
		/sizeof(asn_DEF_nB_v1310_tags_13[0]), /* 2 */
	&asn_PER_type_nB_v1310_constr_13,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_nB_v1310_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_PCCH_Config_v1310_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PCCH_Config_v1310, paging_narrowBands_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_paging_narrowBands_r13_constraint_1,
		&asn_PER_memb_paging_narrowBands_r13_constr_2,
		0,
		"paging-narrowBands-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PCCH_Config_v1310, mpdcch_NumRepetition_Paging_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mpdcch_NumRepetition_Paging_r13_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mpdcch-NumRepetition-Paging-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct PCCH_Config_v1310, nB_v1310),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_nB_v1310_13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nB-v1310"
		},
};
static int asn_MAP_PCCH_Config_v1310_oms_1[] = { 2 };
static ber_tlv_tag_t asn_DEF_PCCH_Config_v1310_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_PCCH_Config_v1310_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* paging-narrowBands-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mpdcch-NumRepetition-Paging-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* nB-v1310 */
};
static asn_SEQUENCE_specifics_t asn_SPC_PCCH_Config_v1310_specs_1 = {
	sizeof(struct PCCH_Config_v1310),
	offsetof(struct PCCH_Config_v1310, _asn_ctx),
	asn_MAP_PCCH_Config_v1310_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_PCCH_Config_v1310_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_PCCH_Config_v1310 = {
	"PCCH-Config-v1310",
	"PCCH-Config-v1310",
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
	asn_DEF_PCCH_Config_v1310_tags_1,
	sizeof(asn_DEF_PCCH_Config_v1310_tags_1)
		/sizeof(asn_DEF_PCCH_Config_v1310_tags_1[0]), /* 1 */
	asn_DEF_PCCH_Config_v1310_tags_1,	/* Same as above */
	sizeof(asn_DEF_PCCH_Config_v1310_tags_1)
		/sizeof(asn_DEF_PCCH_Config_v1310_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_PCCH_Config_v1310_1,
	3,	/* Elements count */
	&asn_SPC_PCCH_Config_v1310_specs_1	/* Additional specs */
};

