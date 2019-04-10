/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_CSFBParametersRequestCDMA2000_H_
#define	_CSFBParametersRequestCDMA2000_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CSFBParametersRequestCDMA2000-r8-IEs.h"
#include <constr_SEQUENCE.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CSFBParametersRequestCDMA2000__criticalExtensions_PR {
	CSFBParametersRequestCDMA2000__criticalExtensions_PR_NOTHING,	/* No components present */
	CSFBParametersRequestCDMA2000__criticalExtensions_PR_csfbParametersRequestCDMA2000_r8,
	CSFBParametersRequestCDMA2000__criticalExtensions_PR_criticalExtensionsFuture
} CSFBParametersRequestCDMA2000__criticalExtensions_PR;

/* CSFBParametersRequestCDMA2000 */
typedef struct CSFBParametersRequestCDMA2000 {
	struct CSFBParametersRequestCDMA2000__criticalExtensions {
		CSFBParametersRequestCDMA2000__criticalExtensions_PR present;
		union CSFBParametersRequestCDMA2000__criticalExtensions_u {
			CSFBParametersRequestCDMA2000_r8_IEs_t	 csfbParametersRequestCDMA2000_r8;
			struct CSFBParametersRequestCDMA2000__criticalExtensions__criticalExtensionsFuture {
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} criticalExtensionsFuture;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} criticalExtensions;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CSFBParametersRequestCDMA2000_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CSFBParametersRequestCDMA2000;

#ifdef __cplusplus
}
#endif

#endif	/* _CSFBParametersRequestCDMA2000_H_ */
#include <asn_internal.h>
