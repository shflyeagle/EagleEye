/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "CountingResponseInfo-r10.h"

static int
memb_countingResponseService_r10_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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

static asn_per_constraints_t asn_PER_memb_countingResponseService_r10_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_CountingResponseInfo_r10_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CountingResponseInfo_r10, countingResponseService_r10),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_countingResponseService_r10_constraint_1,
		&asn_PER_memb_countingResponseService_r10_constr_2,
		0,
		"countingResponseService-r10"
		},
};
static ber_tlv_tag_t asn_DEF_CountingResponseInfo_r10_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CountingResponseInfo_r10_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* countingResponseService-r10 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CountingResponseInfo_r10_specs_1 = {
	sizeof(struct CountingResponseInfo_r10),
	offsetof(struct CountingResponseInfo_r10, _asn_ctx),
	asn_MAP_CountingResponseInfo_r10_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	0,	/* Start extensions */
	2	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CountingResponseInfo_r10 = {
	"CountingResponseInfo-r10",
	"CountingResponseInfo-r10",
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
	asn_DEF_CountingResponseInfo_r10_tags_1,
	sizeof(asn_DEF_CountingResponseInfo_r10_tags_1)
		/sizeof(asn_DEF_CountingResponseInfo_r10_tags_1[0]), /* 1 */
	asn_DEF_CountingResponseInfo_r10_tags_1,	/* Same as above */
	sizeof(asn_DEF_CountingResponseInfo_r10_tags_1)
		/sizeof(asn_DEF_CountingResponseInfo_r10_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CountingResponseInfo_r10_1,
	1,	/* Elements count */
	&asn_SPC_CountingResponseInfo_r10_specs_1	/* Additional specs */
};

