/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_FreqPriorityEUTRA_r12_H_
#define	_FreqPriorityEUTRA_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ARFCN-ValueEUTRA-r9.h"
#include "CellReselectionPriority.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FreqPriorityEUTRA-r12 */
typedef struct FreqPriorityEUTRA_r12 {
	ARFCN_ValueEUTRA_r9_t	 carrierFreq_r12;
	CellReselectionPriority_t	 cellReselectionPriority_r12;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FreqPriorityEUTRA_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FreqPriorityEUTRA_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _FreqPriorityEUTRA_r12_H_ */
#include <asn_internal.h>
