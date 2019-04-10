/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#include "WLAN-Identifiers-r12.h"

static int
memb_ssid_r12_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 32)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bssid_r12_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 6)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_hessid_r12_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 6)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_ssid_r12_constr_2 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 5,  5,  1,  32 }	/* (SIZE(1..32)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_bssid_r12_constr_3 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  6,  6 }	/* (SIZE(6..6)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_hessid_r12_constr_4 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  6,  6 }	/* (SIZE(6..6)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_WLAN_Identifiers_r12_1[] = {
	{ ATF_POINTER, 3, offsetof(struct WLAN_Identifiers_r12, ssid_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_ssid_r12_constraint_1,
		&asn_PER_memb_ssid_r12_constr_2,
		0,
		"ssid-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct WLAN_Identifiers_r12, bssid_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_bssid_r12_constraint_1,
		&asn_PER_memb_bssid_r12_constr_3,
		0,
		"bssid-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct WLAN_Identifiers_r12, hessid_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_hessid_r12_constraint_1,
		&asn_PER_memb_hessid_r12_constr_4,
		0,
		"hessid-r12"
		},
};
static int asn_MAP_WLAN_Identifiers_r12_oms_1[] = { 0, 1, 2 };
static ber_tlv_tag_t asn_DEF_WLAN_Identifiers_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_WLAN_Identifiers_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ssid-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* bssid-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* hessid-r12 */
};
static asn_SEQUENCE_specifics_t asn_SPC_WLAN_Identifiers_r12_specs_1 = {
	sizeof(struct WLAN_Identifiers_r12),
	offsetof(struct WLAN_Identifiers_r12, _asn_ctx),
	asn_MAP_WLAN_Identifiers_r12_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_WLAN_Identifiers_r12_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_WLAN_Identifiers_r12 = {
	"WLAN-Identifiers-r12",
	"WLAN-Identifiers-r12",
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
	asn_DEF_WLAN_Identifiers_r12_tags_1,
	sizeof(asn_DEF_WLAN_Identifiers_r12_tags_1)
		/sizeof(asn_DEF_WLAN_Identifiers_r12_tags_1[0]), /* 1 */
	asn_DEF_WLAN_Identifiers_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_WLAN_Identifiers_r12_tags_1)
		/sizeof(asn_DEF_WLAN_Identifiers_r12_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_WLAN_Identifiers_r12_1,
	3,	/* Elements count */
	&asn_SPC_WLAN_Identifiers_r12_specs_1	/* Additional specs */
};

