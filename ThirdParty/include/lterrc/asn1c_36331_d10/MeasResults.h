/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MeasResults_H_
#define	_MeasResults_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MeasId.h"
#include "MeasId-v1250.h"
#include "RSRQ-Range-v1250.h"
#include "RSRP-Range.h"
#include "RSRQ-Range.h"
#include <constr_SEQUENCE.h>
#include "MeasResultListEUTRA.h"
#include "MeasResultListUTRA.h"
#include "MeasResultListGERAN.h"
#include "MeasResultsCDMA2000.h"
#include <constr_CHOICE.h>
#include "RS-SINR-Range-r13.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MeasResults__measResultNeighCells_PR {
	MeasResults__measResultNeighCells_PR_NOTHING,	/* No components present */
	MeasResults__measResultNeighCells_PR_measResultListEUTRA,
	MeasResults__measResultNeighCells_PR_measResultListUTRA,
	MeasResults__measResultNeighCells_PR_measResultListGERAN,
	MeasResults__measResultNeighCells_PR_measResultsCDMA2000,
	/* Extensions may appear below */
	
} MeasResults__measResultNeighCells_PR;

/* Forward declarations */
struct MeasResultForECID_r9;
struct LocationInfo_r10;
struct MeasResultServFreqList_r10;
struct MeasResultCSI_RS_List_r12;
struct MeasResultForRSSI_r13;
struct MeasResultServFreqListExt_r13;
struct MeasResultSSTD_r13;
struct UL_PDCP_DelayResultList_r13;
struct MeasResultListWLAN_r13;

/* MeasResults */
typedef struct MeasResults {
	MeasId_t	 measId;
	struct MeasResults__measResultPCell {
		RSRP_Range_t	 rsrpResult;
		RSRQ_Range_t	 rsrqResult;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} measResultPCell;
	struct MeasResults__measResultNeighCells {
		MeasResults__measResultNeighCells_PR present;
		union MeasResults__measResultNeighCells_u {
			MeasResultListEUTRA_t	 measResultListEUTRA;
			MeasResultListUTRA_t	 measResultListUTRA;
			MeasResultListGERAN_t	 measResultListGERAN;
			MeasResultsCDMA2000_t	 measResultsCDMA2000;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *measResultNeighCells;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct MeasResultForECID_r9	*measResultForECID_r9	/* OPTIONAL */;
	struct LocationInfo_r10	*locationInfo_r10	/* OPTIONAL */;
	struct MeasResultServFreqList_r10	*measResultServFreqList_r10	/* OPTIONAL */;
	MeasId_v1250_t	*measId_v1250	/* OPTIONAL */;
	RSRQ_Range_v1250_t	*measResultPCell_v1250	/* OPTIONAL */;
	struct MeasResultCSI_RS_List_r12	*measResultCSI_RS_List_r12	/* OPTIONAL */;
	struct MeasResultForRSSI_r13	*measResultForRSSI_r13	/* OPTIONAL */;
	struct MeasResultServFreqListExt_r13	*measResultServFreqListExt_r13	/* OPTIONAL */;
	struct MeasResultSSTD_r13	*measResultSSTD_r13	/* OPTIONAL */;
	struct MeasResults__measResultPCell_v1310 {
		RS_SINR_Range_r13_t	 rs_sinr_Result_r13;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *measResultPCell_v1310;
	struct UL_PDCP_DelayResultList_r13	*ul_PDCP_DelayResultList_r13	/* OPTIONAL */;
	struct MeasResultListWLAN_r13	*measResultListWLAN_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasResults_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasResults;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MeasResultForECID-r9.h"
#include "LocationInfo-r10.h"
#include "MeasResultServFreqList-r10.h"
#include "MeasResultCSI-RS-List-r12.h"
#include "MeasResultForRSSI-r13.h"
#include "MeasResultServFreqListExt-r13.h"
#include "MeasResultSSTD-r13.h"
#include "UL-PDCP-DelayResultList-r13.h"
#include "MeasResultListWLAN-r13.h"

#endif	/* _MeasResults_H_ */
#include <asn_internal.h>
