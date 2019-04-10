/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "RadioResourceConfigDedicatedSCell-r10.h"

static asn_TYPE_member_t asn_MBR_RadioResourceConfigDedicatedSCell_r10_1[] = {
	{ ATF_POINTER, 4, offsetof(struct RadioResourceConfigDedicatedSCell_r10, physicalConfigDedicatedSCell_r10),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PhysicalConfigDedicatedSCell_r10,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"physicalConfigDedicatedSCell-r10"
		},
	{ ATF_POINTER, 3, offsetof(struct RadioResourceConfigDedicatedSCell_r10, mac_MainConfigSCell_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MAC_MainConfigSCell_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mac-MainConfigSCell-r11"
		},
	{ ATF_POINTER, 2, offsetof(struct RadioResourceConfigDedicatedSCell_r10, naics_Info_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NAICS_AssistanceInfo_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"naics-Info-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct RadioResourceConfigDedicatedSCell_r10, neighCellsCRS_InfoSCell_r13),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NeighCellsCRS_Info_r13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"neighCellsCRS-InfoSCell-r13"
		},
};
static int asn_MAP_RadioResourceConfigDedicatedSCell_r10_oms_1[] = { 0, 1, 2, 3 };
static ber_tlv_tag_t asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_RadioResourceConfigDedicatedSCell_r10_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* physicalConfigDedicatedSCell-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mac-MainConfigSCell-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* naics-Info-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* neighCellsCRS-InfoSCell-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_RadioResourceConfigDedicatedSCell_r10_specs_1 = {
	sizeof(struct RadioResourceConfigDedicatedSCell_r10),
	offsetof(struct RadioResourceConfigDedicatedSCell_r10, _asn_ctx),
	asn_MAP_RadioResourceConfigDedicatedSCell_r10_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_RadioResourceConfigDedicatedSCell_r10_oms_1,	/* Optional members */
	1, 3,	/* Root/Additions */
	0,	/* Start extensions */
	5	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigDedicatedSCell_r10 = {
	"RadioResourceConfigDedicatedSCell-r10",
	"RadioResourceConfigDedicatedSCell-r10",
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
	asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1,
	sizeof(asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1)
		/sizeof(asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1[0]), /* 1 */
	asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1,	/* Same as above */
	sizeof(asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1)
		/sizeof(asn_DEF_RadioResourceConfigDedicatedSCell_r10_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RadioResourceConfigDedicatedSCell_r10_1,
	4,	/* Elements count */
	&asn_SPC_RadioResourceConfigDedicatedSCell_r10_specs_1	/* Additional specs */
};
