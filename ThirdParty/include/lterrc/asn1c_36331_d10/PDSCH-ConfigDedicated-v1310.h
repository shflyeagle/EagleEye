/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PDSCH_ConfigDedicated_v1310_H_
#define	_PDSCH_ConfigDedicated_v1310_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DMRS_Config_v1310;

/* PDSCH-ConfigDedicated-v1310 */
typedef struct PDSCH_ConfigDedicated_v1310 {
	struct DMRS_Config_v1310	*dmrs_ConfigPDSCH_v1310	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDSCH_ConfigDedicated_v1310_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDSCH_ConfigDedicated_v1310;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DMRS-Config-v1310.h"

#endif	/* _PDSCH_ConfigDedicated_v1310_H_ */
#include <asn_internal.h>
