/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "SidelinkUEInformation-v1310-IEs.h"

static int
ue_Type_r13_6_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
ue_Type_r13_6_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
ue_Type_r13_6_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
ue_Type_r13_6_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
ue_Type_r13_6_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
ue_Type_r13_6_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
ue_Type_r13_6_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
ue_Type_r13_6_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
ue_Type_r13_6_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
ue_Type_r13_6_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	ue_Type_r13_6_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_carrierFreqDiscTx_r13_constraint_9(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 8)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_ue_Type_r13_constr_6 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_carrierFreqDiscTx_r13_constr_10 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  1,  8 }	/* (1..8) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_ue_Type_r13_value2enum_6[] = {
	{ 0,	7,	"relayUE" },
	{ 1,	8,	"remoteUE" }
};
static unsigned int asn_MAP_ue_Type_r13_enum2value_6[] = {
	0,	/* relayUE(0) */
	1	/* remoteUE(1) */
};
static asn_INTEGER_specifics_t asn_SPC_ue_Type_r13_specs_6 = {
	asn_MAP_ue_Type_r13_value2enum_6,	/* "tag" => N; sorted by tag */
	asn_MAP_ue_Type_r13_enum2value_6,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_ue_Type_r13_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ue_Type_r13_6 = {
	"ue-Type-r13",
	"ue-Type-r13",
	ue_Type_r13_6_free,
	ue_Type_r13_6_print,
	ue_Type_r13_6_constraint,
	ue_Type_r13_6_decode_ber,
	ue_Type_r13_6_encode_der,
	ue_Type_r13_6_decode_xer,
	ue_Type_r13_6_encode_xer,
	ue_Type_r13_6_decode_uper,
	ue_Type_r13_6_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ue_Type_r13_tags_6,
	sizeof(asn_DEF_ue_Type_r13_tags_6)
		/sizeof(asn_DEF_ue_Type_r13_tags_6[0]) - 1, /* 1 */
	asn_DEF_ue_Type_r13_tags_6,	/* Same as above */
	sizeof(asn_DEF_ue_Type_r13_tags_6)
		/sizeof(asn_DEF_ue_Type_r13_tags_6[0]), /* 2 */
	&asn_PER_type_ue_Type_r13_constr_6,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ue_Type_r13_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_commTxResourceInfoReqRelay_r13_3[] = {
	{ ATF_POINTER, 2, offsetof(struct SidelinkUEInformation_v1310_IEs__commTxResourceInfoReqRelay_r13, commTxResourceReqRelay_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_CommTxResourceReq_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"commTxResourceReqRelay-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct SidelinkUEInformation_v1310_IEs__commTxResourceInfoReqRelay_r13, commTxResourceReqRelayUC_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_CommTxResourceReq_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"commTxResourceReqRelayUC-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SidelinkUEInformation_v1310_IEs__commTxResourceInfoReqRelay_r13, ue_Type_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ue_Type_r13_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ue-Type-r13"
		},
};
static int asn_MAP_commTxResourceInfoReqRelay_r13_oms_3[] = { 0, 1 };
static ber_tlv_tag_t asn_DEF_commTxResourceInfoReqRelay_r13_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_commTxResourceInfoReqRelay_r13_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* commTxResourceReqRelay-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* commTxResourceReqRelayUC-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ue-Type-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_commTxResourceInfoReqRelay_r13_specs_3 = {
	sizeof(struct SidelinkUEInformation_v1310_IEs__commTxResourceInfoReqRelay_r13),
	offsetof(struct SidelinkUEInformation_v1310_IEs__commTxResourceInfoReqRelay_r13, _asn_ctx),
	asn_MAP_commTxResourceInfoReqRelay_r13_tag2el_3,
	3,	/* Count of tags in the map */
	asn_MAP_commTxResourceInfoReqRelay_r13_oms_3,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_commTxResourceInfoReqRelay_r13_3 = {
	"commTxResourceInfoReqRelay-r13",
	"commTxResourceInfoReqRelay-r13",
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
	asn_DEF_commTxResourceInfoReqRelay_r13_tags_3,
	sizeof(asn_DEF_commTxResourceInfoReqRelay_r13_tags_3)
		/sizeof(asn_DEF_commTxResourceInfoReqRelay_r13_tags_3[0]) - 1, /* 1 */
	asn_DEF_commTxResourceInfoReqRelay_r13_tags_3,	/* Same as above */
	sizeof(asn_DEF_commTxResourceInfoReqRelay_r13_tags_3)
		/sizeof(asn_DEF_commTxResourceInfoReqRelay_r13_tags_3[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_commTxResourceInfoReqRelay_r13_3,
	3,	/* Elements count */
	&asn_SPC_commTxResourceInfoReqRelay_r13_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_discTxResourceReq_v1310_9[] = {
	{ ATF_POINTER, 2, offsetof(struct SidelinkUEInformation_v1310_IEs__discTxResourceReq_v1310, carrierFreqDiscTx_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_carrierFreqDiscTx_r13_constraint_9,
		&asn_PER_memb_carrierFreqDiscTx_r13_constr_10,
		0,
		"carrierFreqDiscTx-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct SidelinkUEInformation_v1310_IEs__discTxResourceReq_v1310, discTxResourceReqAddFreq_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_DiscTxResourceReqPerFreqList_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discTxResourceReqAddFreq-r13"
		},
};
static int asn_MAP_discTxResourceReq_v1310_oms_9[] = { 0, 1 };
static ber_tlv_tag_t asn_DEF_discTxResourceReq_v1310_tags_9[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_discTxResourceReq_v1310_tag2el_9[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* carrierFreqDiscTx-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* discTxResourceReqAddFreq-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_discTxResourceReq_v1310_specs_9 = {
	sizeof(struct SidelinkUEInformation_v1310_IEs__discTxResourceReq_v1310),
	offsetof(struct SidelinkUEInformation_v1310_IEs__discTxResourceReq_v1310, _asn_ctx),
	asn_MAP_discTxResourceReq_v1310_tag2el_9,
	2,	/* Count of tags in the map */
	asn_MAP_discTxResourceReq_v1310_oms_9,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_discTxResourceReq_v1310_9 = {
	"discTxResourceReq-v1310",
	"discTxResourceReq-v1310",
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
	asn_DEF_discTxResourceReq_v1310_tags_9,
	sizeof(asn_DEF_discTxResourceReq_v1310_tags_9)
		/sizeof(asn_DEF_discTxResourceReq_v1310_tags_9[0]) - 1, /* 1 */
	asn_DEF_discTxResourceReq_v1310_tags_9,	/* Same as above */
	sizeof(asn_DEF_discTxResourceReq_v1310_tags_9)
		/sizeof(asn_DEF_discTxResourceReq_v1310_tags_9[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_discTxResourceReq_v1310_9,
	2,	/* Elements count */
	&asn_SPC_discTxResourceReq_v1310_specs_9	/* Additional specs */
};

static ber_tlv_tag_t asn_DEF_nonCriticalExtension_tags_16[] = {
	(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SEQUENCE_specifics_t asn_SPC_nonCriticalExtension_specs_16 = {
	sizeof(struct SidelinkUEInformation_v1310_IEs__nonCriticalExtension),
	offsetof(struct SidelinkUEInformation_v1310_IEs__nonCriticalExtension, _asn_ctx),
	0,	/* No top level tags */
	0,	/* No tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nonCriticalExtension_16 = {
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
	asn_DEF_nonCriticalExtension_tags_16,
	sizeof(asn_DEF_nonCriticalExtension_tags_16)
		/sizeof(asn_DEF_nonCriticalExtension_tags_16[0]) - 1, /* 1 */
	asn_DEF_nonCriticalExtension_tags_16,	/* Same as above */
	sizeof(asn_DEF_nonCriticalExtension_tags_16)
		/sizeof(asn_DEF_nonCriticalExtension_tags_16[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	&asn_SPC_nonCriticalExtension_specs_16	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SidelinkUEInformation_v1310_IEs_1[] = {
	{ ATF_POINTER, 8, offsetof(struct SidelinkUEInformation_v1310_IEs, commTxResourceReqUC_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_CommTxResourceReq_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"commTxResourceReqUC-r13"
		},
	{ ATF_POINTER, 7, offsetof(struct SidelinkUEInformation_v1310_IEs, commTxResourceInfoReqRelay_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_commTxResourceInfoReqRelay_r13_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"commTxResourceInfoReqRelay-r13"
		},
	{ ATF_POINTER, 6, offsetof(struct SidelinkUEInformation_v1310_IEs, discTxResourceReq_v1310),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_discTxResourceReq_v1310_9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discTxResourceReq-v1310"
		},
	{ ATF_POINTER, 5, offsetof(struct SidelinkUEInformation_v1310_IEs, discTxResourceReqPS_r13),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_DiscTxResourceReq_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discTxResourceReqPS-r13"
		},
	{ ATF_POINTER, 4, offsetof(struct SidelinkUEInformation_v1310_IEs, discRxGapReq_r13),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_GapRequest_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discRxGapReq-r13"
		},
	{ ATF_POINTER, 3, offsetof(struct SidelinkUEInformation_v1310_IEs, discTxGapReq_r13),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_GapRequest_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discTxGapReq-r13"
		},
	{ ATF_POINTER, 2, offsetof(struct SidelinkUEInformation_v1310_IEs, discSysInfoReportFreqList_r13),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_DiscSysInfoReportFreqList_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"discSysInfoReportFreqList-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct SidelinkUEInformation_v1310_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		0,
		&asn_DEF_nonCriticalExtension_16,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonCriticalExtension"
		},
};
static int asn_MAP_SidelinkUEInformation_v1310_IEs_oms_1[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
static ber_tlv_tag_t asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SidelinkUEInformation_v1310_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* commTxResourceReqUC-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* commTxResourceInfoReqRelay-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* discTxResourceReq-v1310 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* discTxResourceReqPS-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* discRxGapReq-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* discTxGapReq-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* discSysInfoReportFreqList-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 } /* nonCriticalExtension */
};
static asn_SEQUENCE_specifics_t asn_SPC_SidelinkUEInformation_v1310_IEs_specs_1 = {
	sizeof(struct SidelinkUEInformation_v1310_IEs),
	offsetof(struct SidelinkUEInformation_v1310_IEs, _asn_ctx),
	asn_MAP_SidelinkUEInformation_v1310_IEs_tag2el_1,
	8,	/* Count of tags in the map */
	asn_MAP_SidelinkUEInformation_v1310_IEs_oms_1,	/* Optional members */
	8, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SidelinkUEInformation_v1310_IEs = {
	"SidelinkUEInformation-v1310-IEs",
	"SidelinkUEInformation-v1310-IEs",
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
	asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1,
	sizeof(asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1)
		/sizeof(asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1[0]), /* 1 */
	asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1)
		/sizeof(asn_DEF_SidelinkUEInformation_v1310_IEs_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SidelinkUEInformation_v1310_IEs_1,
	8,	/* Elements count */
	&asn_SPC_SidelinkUEInformation_v1310_IEs_specs_1	/* Additional specs */
};
