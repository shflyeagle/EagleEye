/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "SidelinkUEInformation-r12-IEs.h"

static int
discRxInterest_r12_4_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
discRxInterest_r12_4_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
discRxInterest_r12_4_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
discRxInterest_r12_4_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
discRxInterest_r12_4_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
discRxInterest_r12_4_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
discRxInterest_r12_4_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
discRxInterest_r12_4_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
discRxInterest_r12_4_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
discRxInterest_r12_4_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	discRxInterest_r12_4_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_discTxResourceReq_r12_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 63)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_discRxInterest_r12_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_discTxResourceReq_r12_constr_6 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 6,  6,  1,  63 }	/* (1..63) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_discRxInterest_r12_value2enum_4[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_discRxInterest_r12_enum2value_4[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_discRxInterest_r12_specs_4 = {
	asn_MAP_discRxInterest_r12_value2enum_4,	/* "tag" => N; sorted by tag */
	asn_MAP_discRxInterest_r12_enum2value_4,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_discRxInterest_r12_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_discRxInterest_r12_4 = {
	"discRxInterest-r12",
	"discRxInterest-r12",
	discRxInterest_r12_4_free,
	discRxInterest_r12_4_print,
	discRxInterest_r12_4_constraint,
	discRxInterest_r12_4_decode_ber,
	discRxInterest_r12_4_encode_der,
	discRxInterest_r12_4_decode_xer,
	discRxInterest_r12_4_encode_xer,
	discRxInterest_r12_4_decode_uper,
	discRxInterest_r12_4_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_discRxInterest_r12_tags_4,
	sizeof(asn_DEF_discRxInterest_r12_tags_4)
		/sizeof(asn_DEF_discRxInterest_r12_tags_4[0]) - 1, /* 1 */
	asn_DEF_discRxInterest_r12_tags_4,	/* Same as above */
	sizeof(asn_DEF_discRxInterest_r12_tags_4)
		/sizeof(asn_DEF_discRxInterest_r12_tags_4[0]), /* 2 */
	&asn_PER_type_discRxInterest_r12_constr_4,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_discRxInterest_r12_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SidelinkUEInformation_r12_IEs_1[] = {
	{ ATF_POINTER, 6, offsetof(struct SidelinkUEInformation_r12_IEs, commRxInterestedFreq_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ARFCN_ValueEUTRA_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"commRxInterestedFreq-r12"
		},
	{ ATF_POINTER, 5, offsetof(struct SidelinkUEInformation_r12_IEs, commTxResourceReq_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_CommTxResourceReq_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"commTxResourceReq-r12"
		},
	{ ATF_POINTER, 4, offsetof(struct SidelinkUEInformation_r12_IEs, discRxInterest_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_discRxInterest_r12_4,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discRxInterest-r12"
		},
	{ ATF_POINTER, 3, offsetof(struct SidelinkUEInformation_r12_IEs, discTxResourceReq_r12),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_discTxResourceReq_r12_constraint_1,
		&asn_PER_memb_discTxResourceReq_r12_constr_6,
		0,
		"discTxResourceReq-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct SidelinkUEInformation_r12_IEs, lateNonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"lateNonCriticalExtension"
		},
	{ ATF_POINTER, 1, offsetof(struct SidelinkUEInformation_r12_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SidelinkUEInformation_v1310_IEs,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonCriticalExtension"
		},
};
static int asn_MAP_SidelinkUEInformation_r12_IEs_oms_1[] = { 0, 1, 2, 3, 4, 5 };
static ber_tlv_tag_t asn_DEF_SidelinkUEInformation_r12_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SidelinkUEInformation_r12_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* commRxInterestedFreq-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* commTxResourceReq-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* discRxInterest-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* discTxResourceReq-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* lateNonCriticalExtension */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* nonCriticalExtension */
};
static asn_SEQUENCE_specifics_t asn_SPC_SidelinkUEInformation_r12_IEs_specs_1 = {
	sizeof(struct SidelinkUEInformation_r12_IEs),
	offsetof(struct SidelinkUEInformation_r12_IEs, _asn_ctx),
	asn_MAP_SidelinkUEInformation_r12_IEs_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_SidelinkUEInformation_r12_IEs_oms_1,	/* Optional members */
	6, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SidelinkUEInformation_r12_IEs = {
	"SidelinkUEInformation-r12-IEs",
	"SidelinkUEInformation-r12-IEs",
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
	asn_DEF_SidelinkUEInformation_r12_IEs_tags_1,
	sizeof(asn_DEF_SidelinkUEInformation_r12_IEs_tags_1)
		/sizeof(asn_DEF_SidelinkUEInformation_r12_IEs_tags_1[0]), /* 1 */
	asn_DEF_SidelinkUEInformation_r12_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_SidelinkUEInformation_r12_IEs_tags_1)
		/sizeof(asn_DEF_SidelinkUEInformation_r12_IEs_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SidelinkUEInformation_r12_IEs_1,
	6,	/* Elements count */
	&asn_SPC_SidelinkUEInformation_r12_IEs_specs_1	/* Additional specs */
};

