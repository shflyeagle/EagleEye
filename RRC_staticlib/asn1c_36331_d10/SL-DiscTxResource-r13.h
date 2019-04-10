/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SL_DiscTxResource_r13_H_
#define	_SL_DiscTxResource_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include "SL-DiscTxConfigScheduled-r13.h"
#include "SL-DiscTxPoolDedicated-r13.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SL_DiscTxResource_r13_PR {
	SL_DiscTxResource_r13_PR_NOTHING,	/* No components present */
	SL_DiscTxResource_r13_PR_release,
	SL_DiscTxResource_r13_PR_setup
} SL_DiscTxResource_r13_PR;
typedef enum SL_DiscTxResource_r13__setup_PR {
	SL_DiscTxResource_r13__setup_PR_NOTHING,	/* No components present */
	SL_DiscTxResource_r13__setup_PR_scheduled_r13,
	SL_DiscTxResource_r13__setup_PR_ue_Selected_r13
} SL_DiscTxResource_r13__setup_PR;

/* SL-DiscTxResource-r13 */
typedef struct SL_DiscTxResource_r13 {
	SL_DiscTxResource_r13_PR present;
	union SL_DiscTxResource_r13_u {
		NULL_t	 release;
		struct SL_DiscTxResource_r13__setup {
			SL_DiscTxResource_r13__setup_PR present;
			union SL_DiscTxResource_r13__setup_u {
				SL_DiscTxConfigScheduled_r13_t	 scheduled_r13;
				SL_DiscTxPoolDedicated_r13_t	 ue_Selected_r13;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} setup;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SL_DiscTxResource_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SL_DiscTxResource_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _SL_DiscTxResource_r13_H_ */
#include <asn_internal.h>
