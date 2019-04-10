/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "MeasIdToAddModExt-r12.h"

static asn_TYPE_member_t asn_MBR_MeasIdToAddModExt_r12_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MeasIdToAddModExt_r12, measId_v1250),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasId_v1250,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measId-v1250"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MeasIdToAddModExt_r12, measObjectId_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasObjectId,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"measObjectId-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MeasIdToAddModExt_r12, reportConfigId_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReportConfigId,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"reportConfigId-r12"
		},
};
static ber_tlv_tag_t asn_DEF_MeasIdToAddModExt_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_MeasIdToAddModExt_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* measId-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* measObjectId-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* reportConfigId-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_MeasIdToAddModExt_r12_specs_1 = {
	sizeof(struct MeasIdToAddModExt_r12),
	offsetof(struct MeasIdToAddModExt_r12, _asn_ctx),
	asn_MAP_MeasIdToAddModExt_r12_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_MeasIdToAddModExt_r12 = {
	"MeasIdToAddModExt-r12",
	"MeasIdToAddModExt-r12",
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
	asn_DEF_MeasIdToAddModExt_r12_tags_1,
	sizeof(asn_DEF_MeasIdToAddModExt_r12_tags_1)
		/sizeof(asn_DEF_MeasIdToAddModExt_r12_tags_1[0]), /* 1 */
	asn_DEF_MeasIdToAddModExt_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_MeasIdToAddModExt_r12_tags_1)
		/sizeof(asn_DEF_MeasIdToAddModExt_r12_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_MeasIdToAddModExt_r12_1,
	3,	/* Elements count */
	&asn_SPC_MeasIdToAddModExt_r12_specs_1	/* Additional specs */
};

