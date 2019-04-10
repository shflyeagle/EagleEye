/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "SL-GapPattern-r13.h"

static int
gapPeriod_r13_2_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
gapPeriod_r13_2_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
gapPeriod_r13_2_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
gapPeriod_r13_2_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
gapPeriod_r13_2_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
gapPeriod_r13_2_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
gapPeriod_r13_2_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
gapPeriod_r13_2_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
gapPeriod_r13_2_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
gapPeriod_r13_2_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	gapPeriod_r13_2_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_gapSubframeBitmap_r13_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size >= 1 && size <= 10240)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_gapPeriod_r13_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  14 }	/* (0..14) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_gapSubframeBitmap_r13_constr_19 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 14,  14,  1,  10240 }	/* (SIZE(1..10240)) */,
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_gapPeriod_r13_value2enum_2[] = {
	{ 0,	4,	"sf40" },
	{ 1,	4,	"sf60" },
	{ 2,	4,	"sf70" },
	{ 3,	4,	"sf80" },
	{ 4,	5,	"sf120" },
	{ 5,	5,	"sf140" },
	{ 6,	5,	"sf160" },
	{ 7,	5,	"sf240" },
	{ 8,	5,	"sf280" },
	{ 9,	5,	"sf320" },
	{ 10,	5,	"sf640" },
	{ 11,	6,	"sf1280" },
	{ 12,	6,	"sf2560" },
	{ 13,	6,	"sf5120" },
	{ 14,	7,	"sf10240" }
};
static unsigned int asn_MAP_gapPeriod_r13_enum2value_2[] = {
	14,	/* sf10240(14) */
	4,	/* sf120(4) */
	11,	/* sf1280(11) */
	5,	/* sf140(5) */
	6,	/* sf160(6) */
	7,	/* sf240(7) */
	12,	/* sf2560(12) */
	8,	/* sf280(8) */
	9,	/* sf320(9) */
	0,	/* sf40(0) */
	13,	/* sf5120(13) */
	1,	/* sf60(1) */
	10,	/* sf640(10) */
	2,	/* sf70(2) */
	3	/* sf80(3) */
};
static asn_INTEGER_specifics_t asn_SPC_gapPeriod_r13_specs_2 = {
	asn_MAP_gapPeriod_r13_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_gapPeriod_r13_enum2value_2,	/* N => "tag"; sorted by N */
	15,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_gapPeriod_r13_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_gapPeriod_r13_2 = {
	"gapPeriod-r13",
	"gapPeriod-r13",
	gapPeriod_r13_2_free,
	gapPeriod_r13_2_print,
	gapPeriod_r13_2_constraint,
	gapPeriod_r13_2_decode_ber,
	gapPeriod_r13_2_encode_der,
	gapPeriod_r13_2_decode_xer,
	gapPeriod_r13_2_encode_xer,
	gapPeriod_r13_2_decode_uper,
	gapPeriod_r13_2_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_gapPeriod_r13_tags_2,
	sizeof(asn_DEF_gapPeriod_r13_tags_2)
		/sizeof(asn_DEF_gapPeriod_r13_tags_2[0]) - 1, /* 1 */
	asn_DEF_gapPeriod_r13_tags_2,	/* Same as above */
	sizeof(asn_DEF_gapPeriod_r13_tags_2)
		/sizeof(asn_DEF_gapPeriod_r13_tags_2[0]), /* 2 */
	&asn_PER_type_gapPeriod_r13_constr_2,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_gapPeriod_r13_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SL_GapPattern_r13_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SL_GapPattern_r13, gapPeriod_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_gapPeriod_r13_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gapPeriod-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SL_GapPattern_r13, gapOffset_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_SL_OffsetIndicator_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gapOffset-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SL_GapPattern_r13, gapSubframeBitmap_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		memb_gapSubframeBitmap_r13_constraint_1,
		&asn_PER_memb_gapSubframeBitmap_r13_constr_19,
		0,
		"gapSubframeBitmap-r13"
		},
};
static ber_tlv_tag_t asn_DEF_SL_GapPattern_r13_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SL_GapPattern_r13_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gapPeriod-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* gapOffset-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* gapSubframeBitmap-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_SL_GapPattern_r13_specs_1 = {
	sizeof(struct SL_GapPattern_r13),
	offsetof(struct SL_GapPattern_r13, _asn_ctx),
	asn_MAP_SL_GapPattern_r13_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SL_GapPattern_r13 = {
	"SL-GapPattern-r13",
	"SL-GapPattern-r13",
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
	asn_DEF_SL_GapPattern_r13_tags_1,
	sizeof(asn_DEF_SL_GapPattern_r13_tags_1)
		/sizeof(asn_DEF_SL_GapPattern_r13_tags_1[0]), /* 1 */
	asn_DEF_SL_GapPattern_r13_tags_1,	/* Same as above */
	sizeof(asn_DEF_SL_GapPattern_r13_tags_1)
		/sizeof(asn_DEF_SL_GapPattern_r13_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SL_GapPattern_r13_1,
	3,	/* Elements count */
	&asn_SPC_SL_GapPattern_r13_specs_1	/* Additional specs */
};

