/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "PDCP-Parameters-v1130.h"

static int
pdcp_SN_Extension_r11_2_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
pdcp_SN_Extension_r11_2_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
pdcp_SN_Extension_r11_2_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
pdcp_SN_Extension_r11_2_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
pdcp_SN_Extension_r11_2_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
pdcp_SN_Extension_r11_2_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
pdcp_SN_Extension_r11_2_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
pdcp_SN_Extension_r11_2_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
pdcp_SN_Extension_r11_2_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	pdcp_SN_Extension_r11_2_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
supportRohcContextContinue_r11_4_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
supportRohcContextContinue_r11_4_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
supportRohcContextContinue_r11_4_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
supportRohcContextContinue_r11_4_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
supportRohcContextContinue_r11_4_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
supportRohcContextContinue_r11_4_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
supportRohcContextContinue_r11_4_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
supportRohcContextContinue_r11_4_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
supportRohcContextContinue_r11_4_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	supportRohcContextContinue_r11_4_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_pdcp_SN_Extension_r11_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_supportRohcContextContinue_r11_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_pdcp_SN_Extension_r11_value2enum_2[] = {
	{ 0,	9,	"supported" }
};
static unsigned int asn_MAP_pdcp_SN_Extension_r11_enum2value_2[] = {
	0	/* supported(0) */
};
static asn_INTEGER_specifics_t asn_SPC_pdcp_SN_Extension_r11_specs_2 = {
	asn_MAP_pdcp_SN_Extension_r11_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_pdcp_SN_Extension_r11_enum2value_2,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_pdcp_SN_Extension_r11_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pdcp_SN_Extension_r11_2 = {
	"pdcp-SN-Extension-r11",
	"pdcp-SN-Extension-r11",
	pdcp_SN_Extension_r11_2_free,
	pdcp_SN_Extension_r11_2_print,
	pdcp_SN_Extension_r11_2_constraint,
	pdcp_SN_Extension_r11_2_decode_ber,
	pdcp_SN_Extension_r11_2_encode_der,
	pdcp_SN_Extension_r11_2_decode_xer,
	pdcp_SN_Extension_r11_2_encode_xer,
	pdcp_SN_Extension_r11_2_decode_uper,
	pdcp_SN_Extension_r11_2_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_pdcp_SN_Extension_r11_tags_2,
	sizeof(asn_DEF_pdcp_SN_Extension_r11_tags_2)
		/sizeof(asn_DEF_pdcp_SN_Extension_r11_tags_2[0]) - 1, /* 1 */
	asn_DEF_pdcp_SN_Extension_r11_tags_2,	/* Same as above */
	sizeof(asn_DEF_pdcp_SN_Extension_r11_tags_2)
		/sizeof(asn_DEF_pdcp_SN_Extension_r11_tags_2[0]), /* 2 */
	&asn_PER_type_pdcp_SN_Extension_r11_constr_2,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_pdcp_SN_Extension_r11_specs_2	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_supportRohcContextContinue_r11_value2enum_4[] = {
	{ 0,	9,	"supported" }
};
static unsigned int asn_MAP_supportRohcContextContinue_r11_enum2value_4[] = {
	0	/* supported(0) */
};
static asn_INTEGER_specifics_t asn_SPC_supportRohcContextContinue_r11_specs_4 = {
	asn_MAP_supportRohcContextContinue_r11_value2enum_4,	/* "tag" => N; sorted by tag */
	asn_MAP_supportRohcContextContinue_r11_enum2value_4,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_supportRohcContextContinue_r11_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_supportRohcContextContinue_r11_4 = {
	"supportRohcContextContinue-r11",
	"supportRohcContextContinue-r11",
	supportRohcContextContinue_r11_4_free,
	supportRohcContextContinue_r11_4_print,
	supportRohcContextContinue_r11_4_constraint,
	supportRohcContextContinue_r11_4_decode_ber,
	supportRohcContextContinue_r11_4_encode_der,
	supportRohcContextContinue_r11_4_decode_xer,
	supportRohcContextContinue_r11_4_encode_xer,
	supportRohcContextContinue_r11_4_decode_uper,
	supportRohcContextContinue_r11_4_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_supportRohcContextContinue_r11_tags_4,
	sizeof(asn_DEF_supportRohcContextContinue_r11_tags_4)
		/sizeof(asn_DEF_supportRohcContextContinue_r11_tags_4[0]) - 1, /* 1 */
	asn_DEF_supportRohcContextContinue_r11_tags_4,	/* Same as above */
	sizeof(asn_DEF_supportRohcContextContinue_r11_tags_4)
		/sizeof(asn_DEF_supportRohcContextContinue_r11_tags_4[0]), /* 2 */
	&asn_PER_type_supportRohcContextContinue_r11_constr_4,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_supportRohcContextContinue_r11_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_PDCP_Parameters_v1130_1[] = {
	{ ATF_POINTER, 2, offsetof(struct PDCP_Parameters_v1130, pdcp_SN_Extension_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_pdcp_SN_Extension_r11_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pdcp-SN-Extension-r11"
		},
	{ ATF_POINTER, 1, offsetof(struct PDCP_Parameters_v1130, supportRohcContextContinue_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_supportRohcContextContinue_r11_4,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"supportRohcContextContinue-r11"
		},
};
static int asn_MAP_PDCP_Parameters_v1130_oms_1[] = { 0, 1 };
static ber_tlv_tag_t asn_DEF_PDCP_Parameters_v1130_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_PDCP_Parameters_v1130_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pdcp-SN-Extension-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* supportRohcContextContinue-r11 */
};
static asn_SEQUENCE_specifics_t asn_SPC_PDCP_Parameters_v1130_specs_1 = {
	sizeof(struct PDCP_Parameters_v1130),
	offsetof(struct PDCP_Parameters_v1130, _asn_ctx),
	asn_MAP_PDCP_Parameters_v1130_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_PDCP_Parameters_v1130_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_PDCP_Parameters_v1130 = {
	"PDCP-Parameters-v1130",
	"PDCP-Parameters-v1130",
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
	asn_DEF_PDCP_Parameters_v1130_tags_1,
	sizeof(asn_DEF_PDCP_Parameters_v1130_tags_1)
		/sizeof(asn_DEF_PDCP_Parameters_v1130_tags_1[0]), /* 1 */
	asn_DEF_PDCP_Parameters_v1130_tags_1,	/* Same as above */
	sizeof(asn_DEF_PDCP_Parameters_v1130_tags_1)
		/sizeof(asn_DEF_PDCP_Parameters_v1130_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_PDCP_Parameters_v1130_1,
	2,	/* Elements count */
	&asn_SPC_PDCP_Parameters_v1130_specs_1	/* Additional specs */
};

