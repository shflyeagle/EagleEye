/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "AC-BarringPerPLMN-r12.h"

static int
ac_BarringSkipForMMTELVoice_r12_7_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
ac_BarringSkipForMMTELVoice_r12_7_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
ac_BarringSkipForMMTELVoice_r12_7_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForMMTELVoice_r12_7_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
ac_BarringSkipForMMTELVoice_r12_7_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForMMTELVoice_r12_7_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
ac_BarringSkipForMMTELVoice_r12_7_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForMMTELVoice_r12_7_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
ac_BarringSkipForMMTELVoice_r12_7_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	ac_BarringSkipForMMTELVoice_r12_7_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
ac_BarringSkipForMMTELVideo_r12_9_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
ac_BarringSkipForMMTELVideo_r12_9_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
ac_BarringSkipForMMTELVideo_r12_9_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForMMTELVideo_r12_9_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
ac_BarringSkipForMMTELVideo_r12_9_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForMMTELVideo_r12_9_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
ac_BarringSkipForMMTELVideo_r12_9_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForMMTELVideo_r12_9_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
ac_BarringSkipForMMTELVideo_r12_9_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	ac_BarringSkipForMMTELVideo_r12_9_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
ac_BarringSkipForSMS_r12_11_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
ac_BarringSkipForSMS_r12_11_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
ac_BarringSkipForSMS_r12_11_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForSMS_r12_11_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
ac_BarringSkipForSMS_r12_11_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForSMS_r12_11_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
ac_BarringSkipForSMS_r12_11_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
ac_BarringSkipForSMS_r12_11_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
ac_BarringSkipForSMS_r12_11_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	ac_BarringSkipForSMS_r12_11_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_plmn_IdentityIndex_r12_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 6)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_ac_BarringSkipForMMTELVoice_r12_constr_7 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_ac_BarringSkipForMMTELVideo_r12_constr_9 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_ac_BarringSkipForSMS_r12_constr_11 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_plmn_IdentityIndex_r12_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  1,  6 }	/* (1..6) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ac_BarringInfo_r12_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct AC_BarringPerPLMN_r12__ac_BarringInfo_r12, ac_BarringForEmergency_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringForEmergency-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct AC_BarringPerPLMN_r12__ac_BarringInfo_r12, ac_BarringForMO_Signalling_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AC_BarringConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringForMO-Signalling-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct AC_BarringPerPLMN_r12__ac_BarringInfo_r12, ac_BarringForMO_Data_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AC_BarringConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringForMO-Data-r12"
		},
};
static int asn_MAP_ac_BarringInfo_r12_oms_3[] = { 1, 2 };
static ber_tlv_tag_t asn_DEF_ac_BarringInfo_r12_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ac_BarringInfo_r12_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ac-BarringForEmergency-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ac-BarringForMO-Signalling-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ac-BarringForMO-Data-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ac_BarringInfo_r12_specs_3 = {
	sizeof(struct AC_BarringPerPLMN_r12__ac_BarringInfo_r12),
	offsetof(struct AC_BarringPerPLMN_r12__ac_BarringInfo_r12, _asn_ctx),
	asn_MAP_ac_BarringInfo_r12_tag2el_3,
	3,	/* Count of tags in the map */
	asn_MAP_ac_BarringInfo_r12_oms_3,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ac_BarringInfo_r12_3 = {
	"ac-BarringInfo-r12",
	"ac-BarringInfo-r12",
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
	asn_DEF_ac_BarringInfo_r12_tags_3,
	sizeof(asn_DEF_ac_BarringInfo_r12_tags_3)
		/sizeof(asn_DEF_ac_BarringInfo_r12_tags_3[0]) - 1, /* 1 */
	asn_DEF_ac_BarringInfo_r12_tags_3,	/* Same as above */
	sizeof(asn_DEF_ac_BarringInfo_r12_tags_3)
		/sizeof(asn_DEF_ac_BarringInfo_r12_tags_3[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ac_BarringInfo_r12_3,
	3,	/* Elements count */
	&asn_SPC_ac_BarringInfo_r12_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_ac_BarringSkipForMMTELVoice_r12_value2enum_7[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_ac_BarringSkipForMMTELVoice_r12_enum2value_7[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_ac_BarringSkipForMMTELVoice_r12_specs_7 = {
	asn_MAP_ac_BarringSkipForMMTELVoice_r12_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_ac_BarringSkipForMMTELVoice_r12_enum2value_7,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ac_BarringSkipForMMTELVoice_r12_7 = {
	"ac-BarringSkipForMMTELVoice-r12",
	"ac-BarringSkipForMMTELVoice-r12",
	ac_BarringSkipForMMTELVoice_r12_7_free,
	ac_BarringSkipForMMTELVoice_r12_7_print,
	ac_BarringSkipForMMTELVoice_r12_7_constraint,
	ac_BarringSkipForMMTELVoice_r12_7_decode_ber,
	ac_BarringSkipForMMTELVoice_r12_7_encode_der,
	ac_BarringSkipForMMTELVoice_r12_7_decode_xer,
	ac_BarringSkipForMMTELVoice_r12_7_encode_xer,
	ac_BarringSkipForMMTELVoice_r12_7_decode_uper,
	ac_BarringSkipForMMTELVoice_r12_7_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7,
	sizeof(asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7)
		/sizeof(asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7[0]) - 1, /* 1 */
	asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7,	/* Same as above */
	sizeof(asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7)
		/sizeof(asn_DEF_ac_BarringSkipForMMTELVoice_r12_tags_7[0]), /* 2 */
	&asn_PER_type_ac_BarringSkipForMMTELVoice_r12_constr_7,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ac_BarringSkipForMMTELVoice_r12_specs_7	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_ac_BarringSkipForMMTELVideo_r12_value2enum_9[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_ac_BarringSkipForMMTELVideo_r12_enum2value_9[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_ac_BarringSkipForMMTELVideo_r12_specs_9 = {
	asn_MAP_ac_BarringSkipForMMTELVideo_r12_value2enum_9,	/* "tag" => N; sorted by tag */
	asn_MAP_ac_BarringSkipForMMTELVideo_r12_enum2value_9,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ac_BarringSkipForMMTELVideo_r12_9 = {
	"ac-BarringSkipForMMTELVideo-r12",
	"ac-BarringSkipForMMTELVideo-r12",
	ac_BarringSkipForMMTELVideo_r12_9_free,
	ac_BarringSkipForMMTELVideo_r12_9_print,
	ac_BarringSkipForMMTELVideo_r12_9_constraint,
	ac_BarringSkipForMMTELVideo_r12_9_decode_ber,
	ac_BarringSkipForMMTELVideo_r12_9_encode_der,
	ac_BarringSkipForMMTELVideo_r12_9_decode_xer,
	ac_BarringSkipForMMTELVideo_r12_9_encode_xer,
	ac_BarringSkipForMMTELVideo_r12_9_decode_uper,
	ac_BarringSkipForMMTELVideo_r12_9_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9,
	sizeof(asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9)
		/sizeof(asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9[0]) - 1, /* 1 */
	asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9,	/* Same as above */
	sizeof(asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9)
		/sizeof(asn_DEF_ac_BarringSkipForMMTELVideo_r12_tags_9[0]), /* 2 */
	&asn_PER_type_ac_BarringSkipForMMTELVideo_r12_constr_9,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ac_BarringSkipForMMTELVideo_r12_specs_9	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_ac_BarringSkipForSMS_r12_value2enum_11[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_ac_BarringSkipForSMS_r12_enum2value_11[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_ac_BarringSkipForSMS_r12_specs_11 = {
	asn_MAP_ac_BarringSkipForSMS_r12_value2enum_11,	/* "tag" => N; sorted by tag */
	asn_MAP_ac_BarringSkipForSMS_r12_enum2value_11,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_ac_BarringSkipForSMS_r12_tags_11[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ac_BarringSkipForSMS_r12_11 = {
	"ac-BarringSkipForSMS-r12",
	"ac-BarringSkipForSMS-r12",
	ac_BarringSkipForSMS_r12_11_free,
	ac_BarringSkipForSMS_r12_11_print,
	ac_BarringSkipForSMS_r12_11_constraint,
	ac_BarringSkipForSMS_r12_11_decode_ber,
	ac_BarringSkipForSMS_r12_11_encode_der,
	ac_BarringSkipForSMS_r12_11_decode_xer,
	ac_BarringSkipForSMS_r12_11_encode_xer,
	ac_BarringSkipForSMS_r12_11_decode_uper,
	ac_BarringSkipForSMS_r12_11_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ac_BarringSkipForSMS_r12_tags_11,
	sizeof(asn_DEF_ac_BarringSkipForSMS_r12_tags_11)
		/sizeof(asn_DEF_ac_BarringSkipForSMS_r12_tags_11[0]) - 1, /* 1 */
	asn_DEF_ac_BarringSkipForSMS_r12_tags_11,	/* Same as above */
	sizeof(asn_DEF_ac_BarringSkipForSMS_r12_tags_11)
		/sizeof(asn_DEF_ac_BarringSkipForSMS_r12_tags_11[0]), /* 2 */
	&asn_PER_type_ac_BarringSkipForSMS_r12_constr_11,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ac_BarringSkipForSMS_r12_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_AC_BarringPerPLMN_r12_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct AC_BarringPerPLMN_r12, plmn_IdentityIndex_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_plmn_IdentityIndex_r12_constraint_1,
		&asn_PER_memb_plmn_IdentityIndex_r12_constr_2,
		0,
		"plmn-IdentityIndex-r12"
		},
	{ ATF_POINTER, 7, offsetof(struct AC_BarringPerPLMN_r12, ac_BarringInfo_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_ac_BarringInfo_r12_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringInfo-r12"
		},
	{ ATF_POINTER, 6, offsetof(struct AC_BarringPerPLMN_r12, ac_BarringSkipForMMTELVoice_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ac_BarringSkipForMMTELVoice_r12_7,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringSkipForMMTELVoice-r12"
		},
	{ ATF_POINTER, 5, offsetof(struct AC_BarringPerPLMN_r12, ac_BarringSkipForMMTELVideo_r12),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ac_BarringSkipForMMTELVideo_r12_9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringSkipForMMTELVideo-r12"
		},
	{ ATF_POINTER, 4, offsetof(struct AC_BarringPerPLMN_r12, ac_BarringSkipForSMS_r12),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ac_BarringSkipForSMS_r12_11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringSkipForSMS-r12"
		},
	{ ATF_POINTER, 3, offsetof(struct AC_BarringPerPLMN_r12, ac_BarringForCSFB_r12),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AC_BarringConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ac-BarringForCSFB-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct AC_BarringPerPLMN_r12, ssac_BarringForMMTEL_Voice_r12),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AC_BarringConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ssac-BarringForMMTEL-Voice-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct AC_BarringPerPLMN_r12, ssac_BarringForMMTEL_Video_r12),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AC_BarringConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ssac-BarringForMMTEL-Video-r12"
		},
};
static int asn_MAP_AC_BarringPerPLMN_r12_oms_1[] = { 1, 2, 3, 4, 5, 6, 7 };
static ber_tlv_tag_t asn_DEF_AC_BarringPerPLMN_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_AC_BarringPerPLMN_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* plmn-IdentityIndex-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ac-BarringInfo-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ac-BarringSkipForMMTELVoice-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ac-BarringSkipForMMTELVideo-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* ac-BarringSkipForSMS-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* ac-BarringForCSFB-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* ssac-BarringForMMTEL-Voice-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 } /* ssac-BarringForMMTEL-Video-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_AC_BarringPerPLMN_r12_specs_1 = {
	sizeof(struct AC_BarringPerPLMN_r12),
	offsetof(struct AC_BarringPerPLMN_r12, _asn_ctx),
	asn_MAP_AC_BarringPerPLMN_r12_tag2el_1,
	8,	/* Count of tags in the map */
	asn_MAP_AC_BarringPerPLMN_r12_oms_1,	/* Optional members */
	7, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_AC_BarringPerPLMN_r12 = {
	"AC-BarringPerPLMN-r12",
	"AC-BarringPerPLMN-r12",
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
	asn_DEF_AC_BarringPerPLMN_r12_tags_1,
	sizeof(asn_DEF_AC_BarringPerPLMN_r12_tags_1)
		/sizeof(asn_DEF_AC_BarringPerPLMN_r12_tags_1[0]), /* 1 */
	asn_DEF_AC_BarringPerPLMN_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_AC_BarringPerPLMN_r12_tags_1)
		/sizeof(asn_DEF_AC_BarringPerPLMN_r12_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_AC_BarringPerPLMN_r12_1,
	8,	/* Elements count */
	&asn_SPC_AC_BarringPerPLMN_r12_specs_1	/* Additional specs */
};

