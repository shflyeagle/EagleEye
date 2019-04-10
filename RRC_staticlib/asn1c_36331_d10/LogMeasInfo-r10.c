/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "LogMeasInfo-r10.h"

static int
inDeviceCoexDetected_r13_19_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
inDeviceCoexDetected_r13_19_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
inDeviceCoexDetected_r13_19_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
inDeviceCoexDetected_r13_19_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
inDeviceCoexDetected_r13_19_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
inDeviceCoexDetected_r13_19_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
inDeviceCoexDetected_r13_19_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
inDeviceCoexDetected_r13_19_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
inDeviceCoexDetected_r13_19_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	inDeviceCoexDetected_r13_19_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
memb_relativeTimeStamp_r10_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 7200)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_inDeviceCoexDetected_r13_constr_19 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_relativeTimeStamp_r10_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 13,  13,  0,  7200 }	/* (0..7200) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_measResultServCell_r10_5[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LogMeasInfo_r10__measResultServCell_r10, rsrpResult_r10),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSRP_Range,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rsrpResult-r10"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LogMeasInfo_r10__measResultServCell_r10, rsrqResult_r10),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSRQ_Range,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rsrqResult-r10"
		},
};
static ber_tlv_tag_t asn_DEF_measResultServCell_r10_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_measResultServCell_r10_tag2el_5[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rsrpResult-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* rsrqResult-r10 */
};
static asn_SEQUENCE_specifics_t asn_SPC_measResultServCell_r10_specs_5 = {
	sizeof(struct LogMeasInfo_r10__measResultServCell_r10),
	offsetof(struct LogMeasInfo_r10__measResultServCell_r10, _asn_ctx),
	asn_MAP_measResultServCell_r10_tag2el_5,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_measResultServCell_r10_5 = {
	"measResultServCell-r10",
	"measResultServCell-r10",
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
	asn_DEF_measResultServCell_r10_tags_5,
	sizeof(asn_DEF_measResultServCell_r10_tags_5)
		/sizeof(asn_DEF_measResultServCell_r10_tags_5[0]) - 1, /* 1 */
	asn_DEF_measResultServCell_r10_tags_5,	/* Same as above */
	sizeof(asn_DEF_measResultServCell_r10_tags_5)
		/sizeof(asn_DEF_measResultServCell_r10_tags_5[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_measResultServCell_r10_5,
	2,	/* Elements count */
	&asn_SPC_measResultServCell_r10_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_measResultNeighCells_r10_8[] = {
	{ ATF_POINTER, 4, offsetof(struct LogMeasInfo_r10__measResultNeighCells_r10, measResultListEUTRA_r10),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultList2EUTRA_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListEUTRA-r10"
		},
	{ ATF_POINTER, 3, offsetof(struct LogMeasInfo_r10__measResultNeighCells_r10, measResultListUTRA_r10),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultList2UTRA_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListUTRA-r10"
		},
	{ ATF_POINTER, 2, offsetof(struct LogMeasInfo_r10__measResultNeighCells_r10, measResultListGERAN_r10),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultList2GERAN_r10,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListGERAN-r10"
		},
	{ ATF_POINTER, 1, offsetof(struct LogMeasInfo_r10__measResultNeighCells_r10, measResultListCDMA2000_r10),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultList2CDMA2000_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListCDMA2000-r10"
		},
};
static int asn_MAP_measResultNeighCells_r10_oms_8[] = { 0, 1, 2, 3 };
static ber_tlv_tag_t asn_DEF_measResultNeighCells_r10_tags_8[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_measResultNeighCells_r10_tag2el_8[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* measResultListEUTRA-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* measResultListUTRA-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* measResultListGERAN-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* measResultListCDMA2000-r10 */
};
static asn_SEQUENCE_specifics_t asn_SPC_measResultNeighCells_r10_specs_8 = {
	sizeof(struct LogMeasInfo_r10__measResultNeighCells_r10),
	offsetof(struct LogMeasInfo_r10__measResultNeighCells_r10, _asn_ctx),
	asn_MAP_measResultNeighCells_r10_tag2el_8,
	4,	/* Count of tags in the map */
	asn_MAP_measResultNeighCells_r10_oms_8,	/* Optional members */
	4, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_measResultNeighCells_r10_8 = {
	"measResultNeighCells-r10",
	"measResultNeighCells-r10",
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
	asn_DEF_measResultNeighCells_r10_tags_8,
	sizeof(asn_DEF_measResultNeighCells_r10_tags_8)
		/sizeof(asn_DEF_measResultNeighCells_r10_tags_8[0]) - 1, /* 1 */
	asn_DEF_measResultNeighCells_r10_tags_8,	/* Same as above */
	sizeof(asn_DEF_measResultNeighCells_r10_tags_8)
		/sizeof(asn_DEF_measResultNeighCells_r10_tags_8[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_measResultNeighCells_r10_8,
	4,	/* Elements count */
	&asn_SPC_measResultNeighCells_r10_specs_8	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_inDeviceCoexDetected_r13_value2enum_19[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_inDeviceCoexDetected_r13_enum2value_19[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_inDeviceCoexDetected_r13_specs_19 = {
	asn_MAP_inDeviceCoexDetected_r13_value2enum_19,	/* "tag" => N; sorted by tag */
	asn_MAP_inDeviceCoexDetected_r13_enum2value_19,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_inDeviceCoexDetected_r13_tags_19[] = {
	(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_inDeviceCoexDetected_r13_19 = {
	"inDeviceCoexDetected-r13",
	"inDeviceCoexDetected-r13",
	inDeviceCoexDetected_r13_19_free,
	inDeviceCoexDetected_r13_19_print,
	inDeviceCoexDetected_r13_19_constraint,
	inDeviceCoexDetected_r13_19_decode_ber,
	inDeviceCoexDetected_r13_19_encode_der,
	inDeviceCoexDetected_r13_19_decode_xer,
	inDeviceCoexDetected_r13_19_encode_xer,
	inDeviceCoexDetected_r13_19_decode_uper,
	inDeviceCoexDetected_r13_19_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_inDeviceCoexDetected_r13_tags_19,
	sizeof(asn_DEF_inDeviceCoexDetected_r13_tags_19)
		/sizeof(asn_DEF_inDeviceCoexDetected_r13_tags_19[0]) - 1, /* 1 */
	asn_DEF_inDeviceCoexDetected_r13_tags_19,	/* Same as above */
	sizeof(asn_DEF_inDeviceCoexDetected_r13_tags_19)
		/sizeof(asn_DEF_inDeviceCoexDetected_r13_tags_19[0]), /* 2 */
	&asn_PER_type_inDeviceCoexDetected_r13_constr_19,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_inDeviceCoexDetected_r13_specs_19	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_LogMeasInfo_r10_1[] = {
	{ ATF_POINTER, 1, offsetof(struct LogMeasInfo_r10, locationInfo_r10),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LocationInfo_r10,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"locationInfo-r10"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LogMeasInfo_r10, relativeTimeStamp_r10),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_relativeTimeStamp_r10_constraint_1,
		&asn_PER_memb_relativeTimeStamp_r10_constr_3,
		0,
		"relativeTimeStamp-r10"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LogMeasInfo_r10, servCellIdentity_r10),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellGlobalIdEUTRA,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"servCellIdentity-r10"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LogMeasInfo_r10, measResultServCell_r10),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		0,
		&asn_DEF_measResultServCell_r10_5,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultServCell-r10"
		},
	{ ATF_POINTER, 7, offsetof(struct LogMeasInfo_r10, measResultNeighCells_r10),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		0,
		&asn_DEF_measResultNeighCells_r10_8,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultNeighCells-r10"
		},
	{ ATF_POINTER, 6, offsetof(struct LogMeasInfo_r10, measResultListEUTRA_v1090),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultList2EUTRA_v9e0,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListEUTRA-v1090"
		},
	{ ATF_POINTER, 5, offsetof(struct LogMeasInfo_r10, measResultListMBSFN_r12),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultListMBSFN_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListMBSFN-r12"
		},
	{ ATF_POINTER, 4, offsetof(struct LogMeasInfo_r10, measResultServCell_v1250),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSRQ_Range_v1250,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultServCell-v1250"
		},
	{ ATF_POINTER, 3, offsetof(struct LogMeasInfo_r10, servCellRSRQ_Type_r12),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSRQ_Type_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"servCellRSRQ-Type-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct LogMeasInfo_r10, measResultListEUTRA_v1250),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultList2EUTRA_v1250,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measResultListEUTRA-v1250"
		},
	{ ATF_POINTER, 1, offsetof(struct LogMeasInfo_r10, inDeviceCoexDetected_r13),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_inDeviceCoexDetected_r13_19,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"inDeviceCoexDetected-r13"
		},
};
static int asn_MAP_LogMeasInfo_r10_oms_1[] = { 0, 4, 5, 6, 7, 8, 9, 10 };
static ber_tlv_tag_t asn_DEF_LogMeasInfo_r10_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_LogMeasInfo_r10_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* locationInfo-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* relativeTimeStamp-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* servCellIdentity-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* measResultServCell-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* measResultNeighCells-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* measResultListEUTRA-v1090 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* measResultListMBSFN-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* measResultServCell-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* servCellRSRQ-Type-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* measResultListEUTRA-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 } /* inDeviceCoexDetected-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_LogMeasInfo_r10_specs_1 = {
	sizeof(struct LogMeasInfo_r10),
	offsetof(struct LogMeasInfo_r10, _asn_ctx),
	asn_MAP_LogMeasInfo_r10_tag2el_1,
	11,	/* Count of tags in the map */
	asn_MAP_LogMeasInfo_r10_oms_1,	/* Optional members */
	2, 6,	/* Root/Additions */
	4,	/* Start extensions */
	12	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_LogMeasInfo_r10 = {
	"LogMeasInfo-r10",
	"LogMeasInfo-r10",
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
	asn_DEF_LogMeasInfo_r10_tags_1,
	sizeof(asn_DEF_LogMeasInfo_r10_tags_1)
		/sizeof(asn_DEF_LogMeasInfo_r10_tags_1[0]), /* 1 */
	asn_DEF_LogMeasInfo_r10_tags_1,	/* Same as above */
	sizeof(asn_DEF_LogMeasInfo_r10_tags_1)
		/sizeof(asn_DEF_LogMeasInfo_r10_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_LogMeasInfo_r10_1,
	11,	/* Elements count */
	&asn_SPC_LogMeasInfo_r10_specs_1	/* Additional specs */
};

