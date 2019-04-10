/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "UplinkPowerControlDedicated.h"

static int
deltaMCS_Enabled_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
deltaMCS_Enabled_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
deltaMCS_Enabled_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
deltaMCS_Enabled_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
deltaMCS_Enabled_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
deltaMCS_Enabled_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
deltaMCS_Enabled_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
deltaMCS_Enabled_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
deltaMCS_Enabled_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
deltaMCS_Enabled_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	deltaMCS_Enabled_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_p0_UE_PUSCH_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -8 && value <= 7)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_p0_UE_PUCCH_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -8 && value <= 7)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_pSRS_Offset_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 15)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_deltaMCS_Enabled_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_p0_UE_PUSCH_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4, -8,  7 }	/* (-8..7) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_p0_UE_PUCCH_constr_7 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4, -8,  7 }	/* (-8..7) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_pSRS_Offset_constr_8 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_deltaMCS_Enabled_value2enum_3[] = {
	{ 0,	3,	"en0" },
	{ 1,	3,	"en1" }
};
static unsigned int asn_MAP_deltaMCS_Enabled_enum2value_3[] = {
	0,	/* en0(0) */
	1	/* en1(1) */
};
static asn_INTEGER_specifics_t asn_SPC_deltaMCS_Enabled_specs_3 = {
	asn_MAP_deltaMCS_Enabled_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_deltaMCS_Enabled_enum2value_3,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_deltaMCS_Enabled_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_deltaMCS_Enabled_3 = {
	"deltaMCS-Enabled",
	"deltaMCS-Enabled",
	deltaMCS_Enabled_3_free,
	deltaMCS_Enabled_3_print,
	deltaMCS_Enabled_3_constraint,
	deltaMCS_Enabled_3_decode_ber,
	deltaMCS_Enabled_3_encode_der,
	deltaMCS_Enabled_3_decode_xer,
	deltaMCS_Enabled_3_encode_xer,
	deltaMCS_Enabled_3_decode_uper,
	deltaMCS_Enabled_3_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_deltaMCS_Enabled_tags_3,
	sizeof(asn_DEF_deltaMCS_Enabled_tags_3)
		/sizeof(asn_DEF_deltaMCS_Enabled_tags_3[0]) - 1, /* 1 */
	asn_DEF_deltaMCS_Enabled_tags_3,	/* Same as above */
	sizeof(asn_DEF_deltaMCS_Enabled_tags_3)
		/sizeof(asn_DEF_deltaMCS_Enabled_tags_3[0]), /* 2 */
	&asn_PER_type_deltaMCS_Enabled_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_deltaMCS_Enabled_specs_3	/* Additional specs */
};

static int asn_DFL_9_set_4(int set_value, void **sptr) {
	FilterCoefficient_t *st = *sptr;
	
	if(!st) {
		if(!set_value) return -1;	/* Not a default value */
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	if(set_value) {
		/* Install default value 4 */
		return asn_long2INTEGER(st, 4);
	} else {
		/* Test default value 4 */
		long value;
		if(asn_INTEGER2long(st, &value))
			return -1;
		return (value == 4);
	}
}
static asn_TYPE_member_t asn_MBR_UplinkPowerControlDedicated_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UplinkPowerControlDedicated, p0_UE_PUSCH),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_p0_UE_PUSCH_constraint_1,
		&asn_PER_memb_p0_UE_PUSCH_constr_2,
		0,
		"p0-UE-PUSCH"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UplinkPowerControlDedicated, deltaMCS_Enabled),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_deltaMCS_Enabled_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"deltaMCS-Enabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UplinkPowerControlDedicated, accumulationEnabled),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"accumulationEnabled"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UplinkPowerControlDedicated, p0_UE_PUCCH),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_p0_UE_PUCCH_constraint_1,
		&asn_PER_memb_p0_UE_PUCCH_constr_7,
		0,
		"p0-UE-PUCCH"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UplinkPowerControlDedicated, pSRS_Offset),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_pSRS_Offset_constraint_1,
		&asn_PER_memb_pSRS_Offset_constr_8,
		0,
		"pSRS-Offset"
		},
	{ ATF_POINTER, 1, offsetof(struct UplinkPowerControlDedicated, filterCoefficient),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FilterCoefficient,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		asn_DFL_9_set_4,	/* DEFAULT 4 */
		"filterCoefficient"
		},
};
static int asn_MAP_UplinkPowerControlDedicated_oms_1[] = { 5 };
static ber_tlv_tag_t asn_DEF_UplinkPowerControlDedicated_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_UplinkPowerControlDedicated_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* p0-UE-PUSCH */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* deltaMCS-Enabled */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* accumulationEnabled */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* p0-UE-PUCCH */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* pSRS-Offset */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* filterCoefficient */
};
static asn_SEQUENCE_specifics_t asn_SPC_UplinkPowerControlDedicated_specs_1 = {
	sizeof(struct UplinkPowerControlDedicated),
	offsetof(struct UplinkPowerControlDedicated, _asn_ctx),
	asn_MAP_UplinkPowerControlDedicated_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_UplinkPowerControlDedicated_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_UplinkPowerControlDedicated = {
	"UplinkPowerControlDedicated",
	"UplinkPowerControlDedicated",
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
	asn_DEF_UplinkPowerControlDedicated_tags_1,
	sizeof(asn_DEF_UplinkPowerControlDedicated_tags_1)
		/sizeof(asn_DEF_UplinkPowerControlDedicated_tags_1[0]), /* 1 */
	asn_DEF_UplinkPowerControlDedicated_tags_1,	/* Same as above */
	sizeof(asn_DEF_UplinkPowerControlDedicated_tags_1)
		/sizeof(asn_DEF_UplinkPowerControlDedicated_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_UplinkPowerControlDedicated_1,
	6,	/* Elements count */
	&asn_SPC_UplinkPowerControlDedicated_specs_1	/* Additional specs */
};

