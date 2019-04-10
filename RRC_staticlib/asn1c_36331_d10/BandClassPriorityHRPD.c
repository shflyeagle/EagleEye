/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "BandClassPriorityHRPD.h"

static asn_TYPE_member_t asn_MBR_BandClassPriorityHRPD_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct BandClassPriorityHRPD, bandClass),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BandclassCDMA2000,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"bandClass"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BandClassPriorityHRPD, cellReselectionPriority),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellReselectionPriority,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cellReselectionPriority"
		},
};
static ber_tlv_tag_t asn_DEF_BandClassPriorityHRPD_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_BandClassPriorityHRPD_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* bandClass */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cellReselectionPriority */
};
static asn_SEQUENCE_specifics_t asn_SPC_BandClassPriorityHRPD_specs_1 = {
	sizeof(struct BandClassPriorityHRPD),
	offsetof(struct BandClassPriorityHRPD, _asn_ctx),
	asn_MAP_BandClassPriorityHRPD_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_BandClassPriorityHRPD = {
	"BandClassPriorityHRPD",
	"BandClassPriorityHRPD",
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
	asn_DEF_BandClassPriorityHRPD_tags_1,
	sizeof(asn_DEF_BandClassPriorityHRPD_tags_1)
		/sizeof(asn_DEF_BandClassPriorityHRPD_tags_1[0]), /* 1 */
	asn_DEF_BandClassPriorityHRPD_tags_1,	/* Same as above */
	sizeof(asn_DEF_BandClassPriorityHRPD_tags_1)
		/sizeof(asn_DEF_BandClassPriorityHRPD_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_BandClassPriorityHRPD_1,
	2,	/* Elements count */
	&asn_SPC_BandClassPriorityHRPD_specs_1	/* Additional specs */
};

