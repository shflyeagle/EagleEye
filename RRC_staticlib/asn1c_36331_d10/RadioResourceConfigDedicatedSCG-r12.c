/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "RadioResourceConfigDedicatedSCG-r12.h"

static asn_TYPE_member_t asn_MBR_RadioResourceConfigDedicatedSCG_r12_1[] = {
	{ ATF_POINTER, 3, offsetof(struct RadioResourceConfigDedicatedSCG_r12, drb_ToAddModListSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DRB_ToAddModListSCG_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"drb-ToAddModListSCG-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct RadioResourceConfigDedicatedSCG_r12, mac_MainConfigSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MAC_MainConfig,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mac-MainConfigSCG-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct RadioResourceConfigDedicatedSCG_r12, rlf_TimersAndConstantsSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_RLF_TimersAndConstantsSCG_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rlf-TimersAndConstantsSCG-r12"
		},
};
static int asn_MAP_RadioResourceConfigDedicatedSCG_r12_oms_1[] = { 0, 1, 2 };
static ber_tlv_tag_t asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_RadioResourceConfigDedicatedSCG_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* drb-ToAddModListSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mac-MainConfigSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* rlf-TimersAndConstantsSCG-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_RadioResourceConfigDedicatedSCG_r12_specs_1 = {
	sizeof(struct RadioResourceConfigDedicatedSCG_r12),
	offsetof(struct RadioResourceConfigDedicatedSCG_r12, _asn_ctx),
	asn_MAP_RadioResourceConfigDedicatedSCG_r12_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_RadioResourceConfigDedicatedSCG_r12_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigDedicatedSCG_r12 = {
	"RadioResourceConfigDedicatedSCG-r12",
	"RadioResourceConfigDedicatedSCG-r12",
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
	asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1,
	sizeof(asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1)
		/sizeof(asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1[0]), /* 1 */
	asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1)
		/sizeof(asn_DEF_RadioResourceConfigDedicatedSCG_r12_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RadioResourceConfigDedicatedSCG_r12_1,
	3,	/* Elements count */
	&asn_SPC_RadioResourceConfigDedicatedSCG_r12_specs_1	/* Additional specs */
};

