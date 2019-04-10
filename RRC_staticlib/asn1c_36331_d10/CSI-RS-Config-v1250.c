/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "CSI-RS-Config-v1250.h"

static int
memb_zeroTxPowerCSI_RS_List_r12_constraint_5(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 5)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_zeroTxPowerCSI_RS_List_r12_constr_6 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 3,  3,  1,  5 }	/* (SIZE(1..5)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_zeroTxPowerCSI_RS_List_r12_constr_6 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 3,  3,  1,  5 }	/* (SIZE(1..5)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_ds_ZeroTxPowerCSI_RS_r12_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_zeroTxPowerCSI_RS_List_r12_6[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ZeroTxPowerCSI_RS_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_zeroTxPowerCSI_RS_List_r12_specs_6 = {
	sizeof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12__setup__zeroTxPowerCSI_RS_List_r12),
	offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12__setup__zeroTxPowerCSI_RS_List_r12, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_zeroTxPowerCSI_RS_List_r12_6 = {
	"zeroTxPowerCSI-RS-List-r12",
	"zeroTxPowerCSI-RS-List-r12",
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
	asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6,
	sizeof(asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6)
		/sizeof(asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6[0]) - 1, /* 1 */
	asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6,	/* Same as above */
	sizeof(asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6)
		/sizeof(asn_DEF_zeroTxPowerCSI_RS_List_r12_tags_6[0]), /* 2 */
	&asn_PER_type_zeroTxPowerCSI_RS_List_r12_constr_6,
	asn_MBR_zeroTxPowerCSI_RS_List_r12_6,
	1,	/* Single element */
	&asn_SPC_zeroTxPowerCSI_RS_List_r12_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_setup_5[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12__setup, zeroTxPowerCSI_RS_List_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_zeroTxPowerCSI_RS_List_r12_6,
		memb_zeroTxPowerCSI_RS_List_r12_constraint_5,
		&asn_PER_memb_zeroTxPowerCSI_RS_List_r12_constr_6,
		0,
		"zeroTxPowerCSI-RS-List-r12"
		},
};
static ber_tlv_tag_t asn_DEF_setup_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_setup_tag2el_5[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* zeroTxPowerCSI-RS-List-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_setup_specs_5 = {
	sizeof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12__setup),
	offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12__setup, _asn_ctx),
	asn_MAP_setup_tag2el_5,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_setup_5 = {
	"setup",
	"setup",
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
	asn_DEF_setup_tags_5,
	sizeof(asn_DEF_setup_tags_5)
		/sizeof(asn_DEF_setup_tags_5[0]) - 1, /* 1 */
	asn_DEF_setup_tags_5,	/* Same as above */
	sizeof(asn_DEF_setup_tags_5)
		/sizeof(asn_DEF_setup_tags_5[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_setup_5,
	1,	/* Elements count */
	&asn_SPC_setup_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ds_ZeroTxPowerCSI_RS_r12_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_setup_5,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"setup"
		},
};
static asn_TYPE_tag2member_t asn_MAP_ds_ZeroTxPowerCSI_RS_r12_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup */
};
static asn_CHOICE_specifics_t asn_SPC_ds_ZeroTxPowerCSI_RS_r12_specs_3 = {
	sizeof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12),
	offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12, _asn_ctx),
	offsetof(struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12, present),
	sizeof(((struct CSI_RS_Config_v1250__ds_ZeroTxPowerCSI_RS_r12 *)0)->present),
	asn_MAP_ds_ZeroTxPowerCSI_RS_r12_tag2el_3,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ds_ZeroTxPowerCSI_RS_r12_3 = {
	"ds-ZeroTxPowerCSI-RS-r12",
	"ds-ZeroTxPowerCSI-RS-r12",
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
	&asn_PER_type_ds_ZeroTxPowerCSI_RS_r12_constr_3,
	asn_MBR_ds_ZeroTxPowerCSI_RS_r12_3,
	2,	/* Elements count */
	&asn_SPC_ds_ZeroTxPowerCSI_RS_r12_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_CSI_RS_Config_v1250_1[] = {
	{ ATF_POINTER, 2, offsetof(struct CSI_RS_Config_v1250, zeroTxPowerCSI_RS2_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_ZeroTxPowerCSI_RS_Conf_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"zeroTxPowerCSI-RS2-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_Config_v1250, ds_ZeroTxPowerCSI_RS_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_ds_ZeroTxPowerCSI_RS_r12_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ds-ZeroTxPowerCSI-RS-r12"
		},
};
static int asn_MAP_CSI_RS_Config_v1250_oms_1[] = { 0, 1 };
static ber_tlv_tag_t asn_DEF_CSI_RS_Config_v1250_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CSI_RS_Config_v1250_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* zeroTxPowerCSI-RS2-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ds-ZeroTxPowerCSI-RS-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CSI_RS_Config_v1250_specs_1 = {
	sizeof(struct CSI_RS_Config_v1250),
	offsetof(struct CSI_RS_Config_v1250, _asn_ctx),
	asn_MAP_CSI_RS_Config_v1250_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_CSI_RS_Config_v1250_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CSI_RS_Config_v1250 = {
	"CSI-RS-Config-v1250",
	"CSI-RS-Config-v1250",
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
	asn_DEF_CSI_RS_Config_v1250_tags_1,
	sizeof(asn_DEF_CSI_RS_Config_v1250_tags_1)
		/sizeof(asn_DEF_CSI_RS_Config_v1250_tags_1[0]), /* 1 */
	asn_DEF_CSI_RS_Config_v1250_tags_1,	/* Same as above */
	sizeof(asn_DEF_CSI_RS_Config_v1250_tags_1)
		/sizeof(asn_DEF_CSI_RS_Config_v1250_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CSI_RS_Config_v1250_1,
	2,	/* Elements count */
	&asn_SPC_CSI_RS_Config_v1250_specs_1	/* Additional specs */
};

