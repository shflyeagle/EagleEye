/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "SystemInformationBlockType6.h"

static int
memb_lateNonCriticalExtension_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

static int
memb_carrierFreqListUTRA_FDD_v1250_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size >= 1 && size <= 16)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_carrierFreqListUTRA_TDD_v1250_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size >= 1 && size <= 16)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_carrierFreqListUTRA_FDD_v1250_constr_8 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_carrierFreqListUTRA_TDD_v1250_constr_10 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_lateNonCriticalExtension_constr_7 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_SEMI_CONSTRAINED,	-1, -1,  0,  0 }	/* (SIZE(0..MAX)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_carrierFreqListUTRA_FDD_v1250_constr_8 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_carrierFreqListUTRA_TDD_v1250_constr_10 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_carrierFreqListUTRA_FDD_v1250_8[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_CarrierFreqInfoUTRA_v1250,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8[] = {
	(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_carrierFreqListUTRA_FDD_v1250_specs_8 = {
	sizeof(struct SystemInformationBlockType6__carrierFreqListUTRA_FDD_v1250),
	offsetof(struct SystemInformationBlockType6__carrierFreqListUTRA_FDD_v1250, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_carrierFreqListUTRA_FDD_v1250_8 = {
	"carrierFreqListUTRA-FDD-v1250",
	"carrierFreqListUTRA-FDD-v1250",
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
	asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8,
	sizeof(asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8)
		/sizeof(asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8[0]) - 1, /* 1 */
	asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8,	/* Same as above */
	sizeof(asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8)
		/sizeof(asn_DEF_carrierFreqListUTRA_FDD_v1250_tags_8[0]), /* 2 */
	&asn_PER_type_carrierFreqListUTRA_FDD_v1250_constr_8,
	asn_MBR_carrierFreqListUTRA_FDD_v1250_8,
	1,	/* Single element */
	&asn_SPC_carrierFreqListUTRA_FDD_v1250_specs_8	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_carrierFreqListUTRA_TDD_v1250_10[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_CarrierFreqInfoUTRA_v1250,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_carrierFreqListUTRA_TDD_v1250_specs_10 = {
	sizeof(struct SystemInformationBlockType6__carrierFreqListUTRA_TDD_v1250),
	offsetof(struct SystemInformationBlockType6__carrierFreqListUTRA_TDD_v1250, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_carrierFreqListUTRA_TDD_v1250_10 = {
	"carrierFreqListUTRA-TDD-v1250",
	"carrierFreqListUTRA-TDD-v1250",
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
	asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10,
	sizeof(asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10)
		/sizeof(asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10[0]) - 1, /* 1 */
	asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10,	/* Same as above */
	sizeof(asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10)
		/sizeof(asn_DEF_carrierFreqListUTRA_TDD_v1250_tags_10[0]), /* 2 */
	&asn_PER_type_carrierFreqListUTRA_TDD_v1250_constr_10,
	asn_MBR_carrierFreqListUTRA_TDD_v1250_10,
	1,	/* Single element */
	&asn_SPC_carrierFreqListUTRA_TDD_v1250_specs_10	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SystemInformationBlockType6_1[] = {
	{ ATF_POINTER, 2, offsetof(struct SystemInformationBlockType6, carrierFreqListUTRA_FDD),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CarrierFreqListUTRA_FDD,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"carrierFreqListUTRA-FDD"
		},
	{ ATF_POINTER, 1, offsetof(struct SystemInformationBlockType6, carrierFreqListUTRA_TDD),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CarrierFreqListUTRA_TDD,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"carrierFreqListUTRA-TDD"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SystemInformationBlockType6, t_ReselectionUTRA),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_T_Reselection,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"t-ReselectionUTRA"
		},
	{ ATF_POINTER, 6, offsetof(struct SystemInformationBlockType6, t_ReselectionUTRA_SF),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SpeedStateScaleFactors,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"t-ReselectionUTRA-SF"
		},
	{ ATF_POINTER, 5, offsetof(struct SystemInformationBlockType6, lateNonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_lateNonCriticalExtension_constraint_1,
		&asn_PER_memb_lateNonCriticalExtension_constr_7,
		0,
		"lateNonCriticalExtension"
		},
	{ ATF_POINTER, 4, offsetof(struct SystemInformationBlockType6, carrierFreqListUTRA_FDD_v1250),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		0,
		&asn_DEF_carrierFreqListUTRA_FDD_v1250_8,
		memb_carrierFreqListUTRA_FDD_v1250_constraint_1,
		&asn_PER_memb_carrierFreqListUTRA_FDD_v1250_constr_8,
		0,
		"carrierFreqListUTRA-FDD-v1250"
		},
	{ ATF_POINTER, 3, offsetof(struct SystemInformationBlockType6, carrierFreqListUTRA_TDD_v1250),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		0,
		&asn_DEF_carrierFreqListUTRA_TDD_v1250_10,
		memb_carrierFreqListUTRA_TDD_v1250_constraint_1,
		&asn_PER_memb_carrierFreqListUTRA_TDD_v1250_constr_10,
		0,
		"carrierFreqListUTRA-TDD-v1250"
		},
	{ ATF_POINTER, 2, offsetof(struct SystemInformationBlockType6, carrierFreqListUTRA_FDD_Ext_r12),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CarrierFreqListUTRA_FDD_Ext_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"carrierFreqListUTRA-FDD-Ext-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct SystemInformationBlockType6, carrierFreqListUTRA_TDD_Ext_r12),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CarrierFreqListUTRA_TDD_Ext_r12,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"carrierFreqListUTRA-TDD-Ext-r12"
		},
};
static int asn_MAP_SystemInformationBlockType6_oms_1[] = { 0, 1, 3, 4, 5, 6, 7, 8 };
static ber_tlv_tag_t asn_DEF_SystemInformationBlockType6_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SystemInformationBlockType6_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* carrierFreqListUTRA-FDD */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* carrierFreqListUTRA-TDD */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* t-ReselectionUTRA */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* t-ReselectionUTRA-SF */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* lateNonCriticalExtension */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* carrierFreqListUTRA-FDD-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* carrierFreqListUTRA-TDD-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* carrierFreqListUTRA-FDD-Ext-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* carrierFreqListUTRA-TDD-Ext-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_SystemInformationBlockType6_specs_1 = {
	sizeof(struct SystemInformationBlockType6),
	offsetof(struct SystemInformationBlockType6, _asn_ctx),
	asn_MAP_SystemInformationBlockType6_tag2el_1,
	9,	/* Count of tags in the map */
	asn_MAP_SystemInformationBlockType6_oms_1,	/* Optional members */
	3, 5,	/* Root/Additions */
	3,	/* Start extensions */
	10	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SystemInformationBlockType6 = {
	"SystemInformationBlockType6",
	"SystemInformationBlockType6",
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
	asn_DEF_SystemInformationBlockType6_tags_1,
	sizeof(asn_DEF_SystemInformationBlockType6_tags_1)
		/sizeof(asn_DEF_SystemInformationBlockType6_tags_1[0]), /* 1 */
	asn_DEF_SystemInformationBlockType6_tags_1,	/* Same as above */
	sizeof(asn_DEF_SystemInformationBlockType6_tags_1)
		/sizeof(asn_DEF_SystemInformationBlockType6_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_SystemInformationBlockType6_1,
	9,	/* Elements count */
	&asn_SPC_SystemInformationBlockType6_specs_1	/* Additional specs */
};

