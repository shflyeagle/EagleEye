/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "Paging-v1310-IEs.h"

static int
redistributionIndication_r13_2_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
redistributionIndication_r13_2_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
redistributionIndication_r13_2_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
redistributionIndication_r13_2_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
redistributionIndication_r13_2_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
redistributionIndication_r13_2_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
redistributionIndication_r13_2_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
redistributionIndication_r13_2_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
redistributionIndication_r13_2_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
redistributionIndication_r13_2_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	redistributionIndication_r13_2_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
systemInfoModification_eDRX_r13_4_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
systemInfoModification_eDRX_r13_4_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
systemInfoModification_eDRX_r13_4_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
systemInfoModification_eDRX_r13_4_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
systemInfoModification_eDRX_r13_4_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
systemInfoModification_eDRX_r13_4_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
systemInfoModification_eDRX_r13_4_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
systemInfoModification_eDRX_r13_4_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
systemInfoModification_eDRX_r13_4_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	systemInfoModification_eDRX_r13_4_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_redistributionIndication_r13_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_systemInfoModification_eDRX_r13_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_redistributionIndication_r13_value2enum_2[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_redistributionIndication_r13_enum2value_2[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_redistributionIndication_r13_specs_2 = {
	asn_MAP_redistributionIndication_r13_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_redistributionIndication_r13_enum2value_2,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_redistributionIndication_r13_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_redistributionIndication_r13_2 = {
	"redistributionIndication-r13",
	"redistributionIndication-r13",
	redistributionIndication_r13_2_free,
	redistributionIndication_r13_2_print,
	redistributionIndication_r13_2_constraint,
	redistributionIndication_r13_2_decode_ber,
	redistributionIndication_r13_2_encode_der,
	redistributionIndication_r13_2_decode_xer,
	redistributionIndication_r13_2_encode_xer,
	redistributionIndication_r13_2_decode_uper,
	redistributionIndication_r13_2_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_redistributionIndication_r13_tags_2,
	sizeof(asn_DEF_redistributionIndication_r13_tags_2)
		/sizeof(asn_DEF_redistributionIndication_r13_tags_2[0]) - 1, /* 1 */
	asn_DEF_redistributionIndication_r13_tags_2,	/* Same as above */
	sizeof(asn_DEF_redistributionIndication_r13_tags_2)
		/sizeof(asn_DEF_redistributionIndication_r13_tags_2[0]), /* 2 */
	&asn_PER_type_redistributionIndication_r13_constr_2,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_redistributionIndication_r13_specs_2	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_systemInfoModification_eDRX_r13_value2enum_4[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_systemInfoModification_eDRX_r13_enum2value_4[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_systemInfoModification_eDRX_r13_specs_4 = {
	asn_MAP_systemInfoModification_eDRX_r13_value2enum_4,	/* "tag" => N; sorted by tag */
	asn_MAP_systemInfoModification_eDRX_r13_enum2value_4,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_systemInfoModification_eDRX_r13_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_systemInfoModification_eDRX_r13_4 = {
	"systemInfoModification-eDRX-r13",
	"systemInfoModification-eDRX-r13",
	systemInfoModification_eDRX_r13_4_free,
	systemInfoModification_eDRX_r13_4_print,
	systemInfoModification_eDRX_r13_4_constraint,
	systemInfoModification_eDRX_r13_4_decode_ber,
	systemInfoModification_eDRX_r13_4_encode_der,
	systemInfoModification_eDRX_r13_4_decode_xer,
	systemInfoModification_eDRX_r13_4_encode_xer,
	systemInfoModification_eDRX_r13_4_decode_uper,
	systemInfoModification_eDRX_r13_4_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_systemInfoModification_eDRX_r13_tags_4,
	sizeof(asn_DEF_systemInfoModification_eDRX_r13_tags_4)
		/sizeof(asn_DEF_systemInfoModification_eDRX_r13_tags_4[0]) - 1, /* 1 */
	asn_DEF_systemInfoModification_eDRX_r13_tags_4,	/* Same as above */
	sizeof(asn_DEF_systemInfoModification_eDRX_r13_tags_4)
		/sizeof(asn_DEF_systemInfoModification_eDRX_r13_tags_4[0]), /* 2 */
	&asn_PER_type_systemInfoModification_eDRX_r13_constr_4,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_systemInfoModification_eDRX_r13_specs_4	/* Additional specs */
};

static ber_tlv_tag_t asn_DEF_nonCriticalExtension_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SEQUENCE_specifics_t asn_SPC_nonCriticalExtension_specs_6 = {
	sizeof(struct Paging_v1310_IEs__nonCriticalExtension),
	offsetof(struct Paging_v1310_IEs__nonCriticalExtension, _asn_ctx),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nonCriticalExtension_6 = {
	"nonCriticalExtension",
	"nonCriticalExtension",
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
	asn_DEF_nonCriticalExtension_tags_6,
	sizeof(asn_DEF_nonCriticalExtension_tags_6)
		/sizeof(asn_DEF_nonCriticalExtension_tags_6[0]) - 1, /* 1 */
	asn_DEF_nonCriticalExtension_tags_6,	/* Same as above */
	sizeof(asn_DEF_nonCriticalExtension_tags_6)
		/sizeof(asn_DEF_nonCriticalExtension_tags_6[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	&asn_SPC_nonCriticalExtension_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Paging_v1310_IEs_1[] = {
	{ ATF_POINTER, 3, offsetof(struct Paging_v1310_IEs, redistributionIndication_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_redistributionIndication_r13_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"redistributionIndication-r13"
		},
	{ ATF_POINTER, 2, offsetof(struct Paging_v1310_IEs, systemInfoModification_eDRX_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_systemInfoModification_eDRX_r13_4,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"systemInfoModification-eDRX-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct Paging_v1310_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_nonCriticalExtension_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonCriticalExtension"
		},
};
static int asn_MAP_Paging_v1310_IEs_oms_1[] = { 0, 1, 2 };
static ber_tlv_tag_t asn_DEF_Paging_v1310_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_Paging_v1310_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* redistributionIndication-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* systemInfoModification-eDRX-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* nonCriticalExtension */
};
static asn_SEQUENCE_specifics_t asn_SPC_Paging_v1310_IEs_specs_1 = {
	sizeof(struct Paging_v1310_IEs),
	offsetof(struct Paging_v1310_IEs, _asn_ctx),
	asn_MAP_Paging_v1310_IEs_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_Paging_v1310_IEs_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Paging_v1310_IEs = {
	"Paging-v1310-IEs",
	"Paging-v1310-IEs",
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
	asn_DEF_Paging_v1310_IEs_tags_1,
	sizeof(asn_DEF_Paging_v1310_IEs_tags_1)
		/sizeof(asn_DEF_Paging_v1310_IEs_tags_1[0]), /* 1 */
	asn_DEF_Paging_v1310_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_Paging_v1310_IEs_tags_1)
		/sizeof(asn_DEF_Paging_v1310_IEs_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Paging_v1310_IEs_1,
	3,	/* Elements count */
	&asn_SPC_Paging_v1310_IEs_specs_1	/* Additional specs */
};

