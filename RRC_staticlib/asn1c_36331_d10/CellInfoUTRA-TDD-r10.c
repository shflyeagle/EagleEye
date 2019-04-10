/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "CellInfoUTRA-TDD-r10.h"

static asn_TYPE_member_t asn_MBR_CellInfoUTRA_TDD_r10_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CellInfoUTRA_TDD_r10, physCellId_r10),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PhysCellIdUTRA_TDD,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"physCellId-r10"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CellInfoUTRA_TDD_r10, carrierFreq_r10),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ARFCN_ValueUTRA,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"carrierFreq-r10"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CellInfoUTRA_TDD_r10, utra_BCCH_Container_r10),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"utra-BCCH-Container-r10"
		},
};
static ber_tlv_tag_t asn_DEF_CellInfoUTRA_TDD_r10_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CellInfoUTRA_TDD_r10_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* physCellId-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* carrierFreq-r10 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* utra-BCCH-Container-r10 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CellInfoUTRA_TDD_r10_specs_1 = {
	sizeof(struct CellInfoUTRA_TDD_r10),
	offsetof(struct CellInfoUTRA_TDD_r10, _asn_ctx),
	asn_MAP_CellInfoUTRA_TDD_r10_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CellInfoUTRA_TDD_r10 = {
	"CellInfoUTRA-TDD-r10",
	"CellInfoUTRA-TDD-r10",
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
	asn_DEF_CellInfoUTRA_TDD_r10_tags_1,
	sizeof(asn_DEF_CellInfoUTRA_TDD_r10_tags_1)
		/sizeof(asn_DEF_CellInfoUTRA_TDD_r10_tags_1[0]), /* 1 */
	asn_DEF_CellInfoUTRA_TDD_r10_tags_1,	/* Same as above */
	sizeof(asn_DEF_CellInfoUTRA_TDD_r10_tags_1)
		/sizeof(asn_DEF_CellInfoUTRA_TDD_r10_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CellInfoUTRA_TDD_r10_1,
	3,	/* Elements count */
	&asn_SPC_CellInfoUTRA_TDD_r10_specs_1	/* Additional specs */
};

