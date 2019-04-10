/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "AC-BarringPerPLMN-List-r12.h"

static asn_per_constraints_t asn_PER_type_AC_BarringPerPLMN_List_r12_constr_1 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 3,  3,  1,  6 }	/* (SIZE(1..6)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_AC_BarringPerPLMN_List_r12_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_AC_BarringPerPLMN_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_AC_BarringPerPLMN_List_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_AC_BarringPerPLMN_List_r12_specs_1 = {
	sizeof(struct AC_BarringPerPLMN_List_r12),
	offsetof(struct AC_BarringPerPLMN_List_r12, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_AC_BarringPerPLMN_List_r12 = {
	"AC-BarringPerPLMN-List-r12",
	"AC-BarringPerPLMN-List-r12",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_AC_BarringPerPLMN_List_r12_tags_1,
	sizeof(asn_DEF_AC_BarringPerPLMN_List_r12_tags_1)
		/sizeof(asn_DEF_AC_BarringPerPLMN_List_r12_tags_1[0]), /* 1 */
	asn_DEF_AC_BarringPerPLMN_List_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_AC_BarringPerPLMN_List_r12_tags_1)
		/sizeof(asn_DEF_AC_BarringPerPLMN_List_r12_tags_1[0]), /* 1 */
	&asn_PER_type_AC_BarringPerPLMN_List_r12_constr_1,
	asn_MBR_AC_BarringPerPLMN_List_r12_1,
	1,	/* Single element */
	&asn_SPC_AC_BarringPerPLMN_List_r12_specs_1	/* Additional specs */
};

