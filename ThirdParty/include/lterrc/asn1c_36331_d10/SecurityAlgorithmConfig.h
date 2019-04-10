/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SecurityAlgorithmConfig_H_
#define	_SecurityAlgorithmConfig_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CipheringAlgorithm-r12.h"
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SecurityAlgorithmConfig__integrityProtAlgorithm {
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia0_v920	= 0,
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia1	= 1,
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia2	= 2,
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia3_v1130	= 3,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare4	= 4,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare3	= 5,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare2	= 6,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare1	= 7
	/*
	 * Enumeration is extensible
	 */
} e_SecurityAlgorithmConfig__integrityProtAlgorithm;

/* SecurityAlgorithmConfig */
typedef struct SecurityAlgorithmConfig {
	CipheringAlgorithm_r12_t	 cipheringAlgorithm;
	ENUMERATED_t	 integrityProtAlgorithm;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SecurityAlgorithmConfig_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_integrityProtAlgorithm_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_SecurityAlgorithmConfig;

#ifdef __cplusplus
}
#endif

#endif	/* _SecurityAlgorithmConfig_H_ */
#include <asn_internal.h>
