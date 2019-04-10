/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_UL_ReferenceSignalsPUSCH_H_
#define	_UL_ReferenceSignalsPUSCH_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UL-ReferenceSignalsPUSCH */
typedef struct UL_ReferenceSignalsPUSCH {
	BOOLEAN_t	 groupHoppingEnabled;
	long	 groupAssignmentPUSCH;
	BOOLEAN_t	 sequenceHoppingEnabled;
	long	 cyclicShift;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UL_ReferenceSignalsPUSCH_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UL_ReferenceSignalsPUSCH;

#ifdef __cplusplus
}
#endif

#endif	/* _UL_ReferenceSignalsPUSCH_H_ */
#include <asn_internal.h>