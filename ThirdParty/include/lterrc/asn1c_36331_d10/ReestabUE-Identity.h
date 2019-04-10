/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_ReestabUE_Identity_H_
#define	_ReestabUE_Identity_H_


#include <asn_application.h>

/* Including external dependencies */
#include "C-RNTI.h"
#include "PhysCellId.h"
#include "ShortMAC-I.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ReestabUE-Identity */
typedef struct ReestabUE_Identity {
	C_RNTI_t	 c_RNTI;
	PhysCellId_t	 physCellId;
	ShortMAC_I_t	 shortMAC_I;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReestabUE_Identity_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReestabUE_Identity;

#ifdef __cplusplus
}
#endif

#endif	/* _ReestabUE_Identity_H_ */
#include <asn_internal.h>
