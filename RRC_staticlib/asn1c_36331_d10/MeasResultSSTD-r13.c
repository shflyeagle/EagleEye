/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "MeasResultSSTD-r13.h"

static int
memb_sfn_OffsetResult_r13_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1023)) {
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
memb_frameBoundaryOffsetResult_r13_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -4 && value <= 5)) {
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
memb_subframeBoundaryOffsetResult_r13_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 63)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_sfn_OffsetResult_r13_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 10,  10,  0,  1023 }	/* (0..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_frameBoundaryOffsetResult_r13_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4, -4,  5 }	/* (-4..5) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_subframeBoundaryOffsetResult_r13_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 6,  6,  0,  63 }	/* (0..63) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_MeasResultSSTD_r13_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MeasResultSSTD_r13, sfn_OffsetResult_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_sfn_OffsetResult_r13_constraint_1,
		&asn_PER_memb_sfn_OffsetResult_r13_constr_2,
		0,
		"sfn-OffsetResult-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MeasResultSSTD_r13, frameBoundaryOffsetResult_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_frameBoundaryOffsetResult_r13_constraint_1,
		&asn_PER_memb_frameBoundaryOffsetResult_r13_constr_3,
		0,
		"frameBoundaryOffsetResult-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MeasResultSSTD_r13, subframeBoundaryOffsetResult_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_subframeBoundaryOffsetResult_r13_constraint_1,
		&asn_PER_memb_subframeBoundaryOffsetResult_r13_constr_4,
		0,
		"subframeBoundaryOffsetResult-r13"
		},
};
static ber_tlv_tag_t asn_DEF_MeasResultSSTD_r13_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_MeasResultSSTD_r13_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sfn-OffsetResult-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* frameBoundaryOffsetResult-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* subframeBoundaryOffsetResult-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_MeasResultSSTD_r13_specs_1 = {
	sizeof(struct MeasResultSSTD_r13),
	offsetof(struct MeasResultSSTD_r13, _asn_ctx),
	asn_MAP_MeasResultSSTD_r13_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_MeasResultSSTD_r13 = {
	"MeasResultSSTD-r13",
	"MeasResultSSTD-r13",
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
	asn_DEF_MeasResultSSTD_r13_tags_1,
	sizeof(asn_DEF_MeasResultSSTD_r13_tags_1)
		/sizeof(asn_DEF_MeasResultSSTD_r13_tags_1[0]), /* 1 */
	asn_DEF_MeasResultSSTD_r13_tags_1,	/* Same as above */
	sizeof(asn_DEF_MeasResultSSTD_r13_tags_1)
		/sizeof(asn_DEF_MeasResultSSTD_r13_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_MeasResultSSTD_r13_1,
	3,	/* Elements count */
	&asn_SPC_MeasResultSSTD_r13_specs_1	/* Additional specs */
};

