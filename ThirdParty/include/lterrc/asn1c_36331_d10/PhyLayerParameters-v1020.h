/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PhyLayerParameters_v1020_H_
#define	_PhyLayerParameters_v1020_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PhyLayerParameters_v1020__twoAntennaPortsForPUCCH_r10 {
	PhyLayerParameters_v1020__twoAntennaPortsForPUCCH_r10_supported	= 0
} e_PhyLayerParameters_v1020__twoAntennaPortsForPUCCH_r10;
typedef enum PhyLayerParameters_v1020__tm9_With_8Tx_FDD_r10 {
	PhyLayerParameters_v1020__tm9_With_8Tx_FDD_r10_supported	= 0
} e_PhyLayerParameters_v1020__tm9_With_8Tx_FDD_r10;
typedef enum PhyLayerParameters_v1020__pmi_Disabling_r10 {
	PhyLayerParameters_v1020__pmi_Disabling_r10_supported	= 0
} e_PhyLayerParameters_v1020__pmi_Disabling_r10;
typedef enum PhyLayerParameters_v1020__crossCarrierScheduling_r10 {
	PhyLayerParameters_v1020__crossCarrierScheduling_r10_supported	= 0
} e_PhyLayerParameters_v1020__crossCarrierScheduling_r10;
typedef enum PhyLayerParameters_v1020__simultaneousPUCCH_PUSCH_r10 {
	PhyLayerParameters_v1020__simultaneousPUCCH_PUSCH_r10_supported	= 0
} e_PhyLayerParameters_v1020__simultaneousPUCCH_PUSCH_r10;
typedef enum PhyLayerParameters_v1020__multiClusterPUSCH_WithinCC_r10 {
	PhyLayerParameters_v1020__multiClusterPUSCH_WithinCC_r10_supported	= 0
} e_PhyLayerParameters_v1020__multiClusterPUSCH_WithinCC_r10;

/* Forward declarations */
struct NonContiguousUL_RA_WithinCC_List_r10;

/* PhyLayerParameters-v1020 */
typedef struct PhyLayerParameters_v1020 {
	ENUMERATED_t	*twoAntennaPortsForPUCCH_r10	/* OPTIONAL */;
	ENUMERATED_t	*tm9_With_8Tx_FDD_r10	/* OPTIONAL */;
	ENUMERATED_t	*pmi_Disabling_r10	/* OPTIONAL */;
	ENUMERATED_t	*crossCarrierScheduling_r10	/* OPTIONAL */;
	ENUMERATED_t	*simultaneousPUCCH_PUSCH_r10	/* OPTIONAL */;
	ENUMERATED_t	*multiClusterPUSCH_WithinCC_r10	/* OPTIONAL */;
	struct NonContiguousUL_RA_WithinCC_List_r10	*nonContiguousUL_RA_WithinCC_List_r10	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PhyLayerParameters_v1020_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_twoAntennaPortsForPUCCH_r10_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_tm9_With_8Tx_FDD_r10_4;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_pmi_Disabling_r10_6;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_crossCarrierScheduling_r10_8;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_simultaneousPUCCH_PUSCH_r10_10;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_multiClusterPUSCH_WithinCC_r10_12;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PhyLayerParameters_v1020;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NonContiguousUL-RA-WithinCC-List-r10.h"

#endif	/* _PhyLayerParameters_v1020_H_ */
#include <asn_internal.h>
