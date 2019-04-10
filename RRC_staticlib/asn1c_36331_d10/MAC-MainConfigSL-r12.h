/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MAC_MainConfigSL_r12_H_
#define	_MAC_MainConfigSL_r12_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PeriodicBSR-Timer-r12.h"
#include "RetxBSR-Timer-r12.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAC-MainConfigSL-r12 */
typedef struct MAC_MainConfigSL_r12 {
	PeriodicBSR_Timer_r12_t	*periodic_BSR_TimerSL	/* OPTIONAL */;
	RetxBSR_Timer_r12_t	 retx_BSR_TimerSL;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MAC_MainConfigSL_r12_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAC_MainConfigSL_r12;

#ifdef __cplusplus
}
#endif

#endif	/* _MAC_MainConfigSL_r12_H_ */
#include <asn_internal.h>
