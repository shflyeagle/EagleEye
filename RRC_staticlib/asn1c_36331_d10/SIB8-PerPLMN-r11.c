/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "SIB8-PerPLMN-r11.h"

static int
memb_plmn_Identity_r11_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 6)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_parametersCDMA2000_r11_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_plmn_Identity_r11_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  1,  6 }	/* (1..6) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_parametersCDMA2000_r11_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SIB8_PerPLMN_r11__parametersCDMA2000_r11, choice.explicitValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ParametersCDMA2000_r11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"explicitValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SIB8_PerPLMN_r11__parametersCDMA2000_r11, choice.defaultValue),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"defaultValue"
		},
};
static asn_TYPE_tag2member_t asn_MAP_parametersCDMA2000_r11_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* explicitValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* defaultValue */
};
static asn_CHOICE_specifics_t asn_SPC_parametersCDMA2000_r11_specs_3 = {
	sizeof(struct SIB8_PerPLMN_r11__parametersCDMA2000_r11),
	offsetof(struct SIB8_PerPLMN_r11__parametersCDMA2000_r11, _asn_ctx),
	offsetof(struct SIB8_PerPLMN_r11__parametersCDMA2000_r11, present),
	sizeof(((struct SIB8_PerPLMN_r11__parametersCDMA2000_r11 *)0)->present),
	asn_MAP_parametersCDMA2000_r11_tag2el_3,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_parametersCDMA2000_r11_3 = {
	"parametersCDMA2000-r11",
	"parametersCDMA2000-r11",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_parametersCDMA2000_r11_constr_3,
	asn_MBR_parametersCDMA2000_r11_3,
	2,	/* Elements count */
	&asn_SPC_parametersCDMA2000_r11_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SIB8_PerPLMN_r11_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SIB8_PerPLMN_r11, plmn_Identity_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_plmn_Identity_r11_constraint_1,
		&asn_PER_memb_plmn_Identity_r11_constr_2,
		0,
		"plmn-Identity-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SIB8_PerPLMN_r11, parametersCDMA2000_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_parametersCDMA2000_r11_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"parametersCDMA2000-r11"
		},
};
static ber_tlv_tag_t asn_DEF_SIB8_PerPLMN_r11_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SIB8_PerPLMN_r11_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* plmn-Identity-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* parametersCDMA2000-r11 */
};
static asn_SEQUENCE_specifics_t asn_SPC_SIB8_PerPLMN_r11_specs_1 = {
	sizeof(struct SIB8_PerPLMN_r11),
	offsetof(struct SIB8_PerPLMN_r11, _asn_ctx),
	asn_MAP_SIB8_PerPLMN_r11_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SIB8_PerPLMN_r11 = {
	"SIB8-PerPLMN-r11",
	"SIB8-PerPLMN-r11",
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
	asn_DEF_SIB8_PerPLMN_r11_tags_1,
	sizeof(asn_DEF_SIB8_PerPLMN_r11_tags_1)
		/sizeof(asn_DEF_SIB8_PerPLMN_r11_tags_1[0]), /* 1 */
	asn_DEF_SIB8_PerPLMN_r11_tags_1,	/* Same as above */
	sizeof(asn_DEF_SIB8_PerPLMN_r11_tags_1)
		/sizeof(asn_DEF_SIB8_PerPLMN_r11_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SIB8_PerPLMN_r11_1,
	2,	/* Elements count */
	&asn_SPC_SIB8_PerPLMN_r11_specs_1	/* Additional specs */
};

