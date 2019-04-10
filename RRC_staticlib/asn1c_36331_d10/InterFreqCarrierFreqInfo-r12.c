/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "InterFreqCarrierFreqInfo-r12.h"

static int
reducedMeasPerformance_r12_22_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
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
reducedMeasPerformance_r12_22_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
reducedMeasPerformance_r12_22_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
reducedMeasPerformance_r12_22_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
reducedMeasPerformance_r12_22_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
reducedMeasPerformance_r12_22_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
reducedMeasPerformance_r12_22_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
reducedMeasPerformance_r12_22_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
reducedMeasPerformance_r12_22_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	reducedMeasPerformance_r12_22_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_reducedMeasPerformance_r12_constr_22 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static int asn_DFL_13_set_15(int set_value, void **sptr) {
	Q_OffsetRange_t *st = *sptr;
	
	if(!st) {
		if(!set_value) return -1;	/* Not a default value */
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	if(set_value) {
		/* Install default value 15 */
		return asn_long2INTEGER(st, 15);
	} else {
		/* Test default value 15 */
		long value;
		if(asn_INTEGER2long(st, &value))
			return -1;
		return (value == 15);
	}
}
static asn_TYPE_member_t asn_MBR_threshX_Q_r12_17[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12__threshX_Q_r12, threshX_HighQ_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReselectionThresholdQ_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"threshX-HighQ-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12__threshX_Q_r12, threshX_LowQ_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReselectionThresholdQ_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"threshX-LowQ-r12"
		},
};
static ber_tlv_tag_t asn_DEF_threshX_Q_r12_tags_17[] = {
	(ASN_TAG_CLASS_CONTEXT | (15 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_threshX_Q_r12_tag2el_17[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* threshX-HighQ-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* threshX-LowQ-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_threshX_Q_r12_specs_17 = {
	sizeof(struct InterFreqCarrierFreqInfo_r12__threshX_Q_r12),
	offsetof(struct InterFreqCarrierFreqInfo_r12__threshX_Q_r12, _asn_ctx),
	asn_MAP_threshX_Q_r12_tag2el_17,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_threshX_Q_r12_17 = {
	"threshX-Q-r12",
	"threshX-Q-r12",
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
	asn_DEF_threshX_Q_r12_tags_17,
	sizeof(asn_DEF_threshX_Q_r12_tags_17)
		/sizeof(asn_DEF_threshX_Q_r12_tags_17[0]) - 1, /* 1 */
	asn_DEF_threshX_Q_r12_tags_17,	/* Same as above */
	sizeof(asn_DEF_threshX_Q_r12_tags_17)
		/sizeof(asn_DEF_threshX_Q_r12_tags_17[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_threshX_Q_r12_17,
	2,	/* Elements count */
	&asn_SPC_threshX_Q_r12_specs_17	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_reducedMeasPerformance_r12_value2enum_22[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_reducedMeasPerformance_r12_enum2value_22[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_reducedMeasPerformance_r12_specs_22 = {
	asn_MAP_reducedMeasPerformance_r12_value2enum_22,	/* "tag" => N; sorted by tag */
	asn_MAP_reducedMeasPerformance_r12_enum2value_22,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_reducedMeasPerformance_r12_tags_22[] = {
	(ASN_TAG_CLASS_CONTEXT | (18 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_reducedMeasPerformance_r12_22 = {
	"reducedMeasPerformance-r12",
	"reducedMeasPerformance-r12",
	reducedMeasPerformance_r12_22_free,
	reducedMeasPerformance_r12_22_print,
	reducedMeasPerformance_r12_22_constraint,
	reducedMeasPerformance_r12_22_decode_ber,
	reducedMeasPerformance_r12_22_encode_der,
	reducedMeasPerformance_r12_22_decode_xer,
	reducedMeasPerformance_r12_22_encode_xer,
	reducedMeasPerformance_r12_22_decode_uper,
	reducedMeasPerformance_r12_22_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_reducedMeasPerformance_r12_tags_22,
	sizeof(asn_DEF_reducedMeasPerformance_r12_tags_22)
		/sizeof(asn_DEF_reducedMeasPerformance_r12_tags_22[0]) - 1, /* 1 */
	asn_DEF_reducedMeasPerformance_r12_tags_22,	/* Same as above */
	sizeof(asn_DEF_reducedMeasPerformance_r12_tags_22)
		/sizeof(asn_DEF_reducedMeasPerformance_r12_tags_22[0]), /* 2 */
	&asn_PER_type_reducedMeasPerformance_r12_constr_22,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_reducedMeasPerformance_r12_specs_22	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_InterFreqCarrierFreqInfo_r12_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, dl_CarrierFreq_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ARFCN_ValueEUTRA_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dl-CarrierFreq-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, q_RxLevMin_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Q_RxLevMin,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"q-RxLevMin-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct InterFreqCarrierFreqInfo_r12, p_Max_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_P_Max,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"p-Max-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, t_ReselectionEUTRA_r12),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_T_Reselection,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"t-ReselectionEUTRA-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct InterFreqCarrierFreqInfo_r12, t_ReselectionEUTRA_SF_r12),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SpeedStateScaleFactors,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"t-ReselectionEUTRA-SF-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, threshX_High_r12),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReselectionThreshold,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"threshX-High-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, threshX_Low_r12),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReselectionThreshold,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"threshX-Low-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, allowedMeasBandwidth_r12),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AllowedMeasBandwidth,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"allowedMeasBandwidth-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, presenceAntennaPort1_r12),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PresenceAntennaPort1,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"presenceAntennaPort1-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct InterFreqCarrierFreqInfo_r12, cellReselectionPriority_r12),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellReselectionPriority,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cellReselectionPriority-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InterFreqCarrierFreqInfo_r12, neighCellConfig_r12),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NeighCellConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"neighCellConfig-r12"
		},
	{ ATF_POINTER, 9, offsetof(struct InterFreqCarrierFreqInfo_r12, q_OffsetFreq_r12),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Q_OffsetRange,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		asn_DFL_13_set_15,	/* DEFAULT 15 */
		"q-OffsetFreq-r12"
		},
	{ ATF_POINTER, 8, offsetof(struct InterFreqCarrierFreqInfo_r12, interFreqNeighCellList_r12),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_InterFreqNeighCellList,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"interFreqNeighCellList-r12"
		},
	{ ATF_POINTER, 7, offsetof(struct InterFreqCarrierFreqInfo_r12, interFreqBlackCellList_r12),
		(ASN_TAG_CLASS_CONTEXT | (13 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_InterFreqBlackCellList,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"interFreqBlackCellList-r12"
		},
	{ ATF_POINTER, 6, offsetof(struct InterFreqCarrierFreqInfo_r12, q_QualMin_r12),
		(ASN_TAG_CLASS_CONTEXT | (14 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Q_QualMin_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"q-QualMin-r12"
		},
	{ ATF_POINTER, 5, offsetof(struct InterFreqCarrierFreqInfo_r12, threshX_Q_r12),
		(ASN_TAG_CLASS_CONTEXT | (15 << 2)),
		0,
		&asn_DEF_threshX_Q_r12_17,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"threshX-Q-r12"
		},
	{ ATF_POINTER, 4, offsetof(struct InterFreqCarrierFreqInfo_r12, q_QualMinWB_r12),
		(ASN_TAG_CLASS_CONTEXT | (16 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Q_QualMin_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"q-QualMinWB-r12"
		},
	{ ATF_POINTER, 3, offsetof(struct InterFreqCarrierFreqInfo_r12, multiBandInfoList_r12),
		(ASN_TAG_CLASS_CONTEXT | (17 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MultiBandInfoList_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"multiBandInfoList-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct InterFreqCarrierFreqInfo_r12, reducedMeasPerformance_r12),
		(ASN_TAG_CLASS_CONTEXT | (18 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_reducedMeasPerformance_r12_22,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"reducedMeasPerformance-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct InterFreqCarrierFreqInfo_r12, q_QualMinRSRQ_OnAllSymbols_r12),
		(ASN_TAG_CLASS_CONTEXT | (19 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Q_QualMin_r9,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"q-QualMinRSRQ-OnAllSymbols-r12"
		},
};
static int asn_MAP_InterFreqCarrierFreqInfo_r12_oms_1[] = { 2, 4, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
static ber_tlv_tag_t asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_InterFreqCarrierFreqInfo_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* dl-CarrierFreq-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* q-RxLevMin-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* p-Max-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* t-ReselectionEUTRA-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* t-ReselectionEUTRA-SF-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* threshX-High-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* threshX-Low-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* allowedMeasBandwidth-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* presenceAntennaPort1-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* cellReselectionPriority-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* neighCellConfig-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* q-OffsetFreq-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* interFreqNeighCellList-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* interFreqBlackCellList-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 }, /* q-QualMin-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (15 << 2)), 15, 0, 0 }, /* threshX-Q-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (16 << 2)), 16, 0, 0 }, /* q-QualMinWB-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (17 << 2)), 17, 0, 0 }, /* multiBandInfoList-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (18 << 2)), 18, 0, 0 }, /* reducedMeasPerformance-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (19 << 2)), 19, 0, 0 } /* q-QualMinRSRQ-OnAllSymbols-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_InterFreqCarrierFreqInfo_r12_specs_1 = {
	sizeof(struct InterFreqCarrierFreqInfo_r12),
	offsetof(struct InterFreqCarrierFreqInfo_r12, _asn_ctx),
	asn_MAP_InterFreqCarrierFreqInfo_r12_tag2el_1,
	20,	/* Count of tags in the map */
	asn_MAP_InterFreqCarrierFreqInfo_r12_oms_1,	/* Optional members */
	12, 0,	/* Root/Additions */
	19,	/* Start extensions */
	21	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_InterFreqCarrierFreqInfo_r12 = {
	"InterFreqCarrierFreqInfo-r12",
	"InterFreqCarrierFreqInfo-r12",
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
	asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1,
	sizeof(asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1)
		/sizeof(asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1[0]), /* 1 */
	asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1)
		/sizeof(asn_DEF_InterFreqCarrierFreqInfo_r12_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_InterFreqCarrierFreqInfo_r12_1,
	20,	/* Elements count */
	&asn_SPC_InterFreqCarrierFreqInfo_r12_specs_1	/* Additional specs */
};

