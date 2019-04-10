/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_DRB_ToAddMod_H_
#define	_DRB_ToAddMod_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "DRB-Identity.h"
#include <ENUMERATED.h>
#include <BOOLEAN.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DRB_ToAddMod__drb_TypeChange_r12 {
	DRB_ToAddMod__drb_TypeChange_r12_toMCG	= 0
} e_DRB_ToAddMod__drb_TypeChange_r12;
typedef enum DRB_ToAddMod__drb_TypeLWIP_r13 {
	DRB_ToAddMod__drb_TypeLWIP_r13_lwip	= 0,
	DRB_ToAddMod__drb_TypeLWIP_r13_lwip_DL_only	= 1,
	DRB_ToAddMod__drb_TypeLWIP_r13_lwip_UL_only	= 2,
	DRB_ToAddMod__drb_TypeLWIP_r13_lte	= 3
} e_DRB_ToAddMod__drb_TypeLWIP_r13;

/* Forward declarations */
struct PDCP_Config;
struct RLC_Config;
struct LogicalChannelConfig;
struct RLC_Config_v1250;
struct RLC_Config_v1310;

/* DRB-ToAddMod */
typedef struct DRB_ToAddMod {
	long	*eps_BearerIdentity	/* OPTIONAL */;
	DRB_Identity_t	 drb_Identity;
	struct PDCP_Config	*pdcp_Config	/* OPTIONAL */;
	struct RLC_Config	*rlc_Config	/* OPTIONAL */;
	long	*logicalChannelIdentity	/* OPTIONAL */;
	struct LogicalChannelConfig	*logicalChannelConfig	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	ENUMERATED_t	*drb_TypeChange_r12	/* OPTIONAL */;
	struct RLC_Config_v1250	*rlc_Config_v1250	/* OPTIONAL */;
	struct RLC_Config_v1310	*rlc_Config_v1310	/* OPTIONAL */;
	BOOLEAN_t	*drb_TypeLWA_r13	/* OPTIONAL */;
	ENUMERATED_t	*drb_TypeLWIP_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DRB_ToAddMod_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_drb_TypeChange_r12_9;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_drb_TypeLWIP_r13_14;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_DRB_ToAddMod;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PDCP-Config.h"
#include "RLC-Config.h"
#include "LogicalChannelConfig.h"
#include "RLC-Config-v1250.h"
#include "RLC-Config-v1310.h"

#endif	/* _DRB_ToAddMod_H_ */
#include <asn_internal.h>
