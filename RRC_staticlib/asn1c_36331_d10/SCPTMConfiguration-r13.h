/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SCPTMConfiguration_r13_H_
#define	_SCPTMConfiguration_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SC-MTCH-InfoList-r13.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SCPTM_NeighbourCellList_r13;

/* SCPTMConfiguration-r13 */
typedef struct SCPTMConfiguration_r13 {
	SC_MTCH_InfoList_r13_t	 sc_mtch_InfoList_r13;
	struct SCPTM_NeighbourCellList_r13	*scptm_NeighbourCellList_r13	/* OPTIONAL */;
	OCTET_STRING_t	*lateNonCriticalExtension	/* OPTIONAL */;
	struct SCPTMConfiguration_r13__nonCriticalExtension {
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nonCriticalExtension;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SCPTMConfiguration_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SCPTMConfiguration_r13;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SCPTM-NeighbourCellList-r13.h"

#endif	/* _SCPTMConfiguration_r13_H_ */
#include <asn_internal.h>
