/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_RLF_Report_r9_H_
#define	_RLF_Report_r9_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <ENUMERATED.h>
#include "RSRQ-Range-v1250.h"
#include "RSRP-Range.h"
#include "RSRQ-Range.h"
#include <constr_SEQUENCE.h>
#include "CellGlobalIdEUTRA.h"
#include "PhysCellId.h"
#include "ARFCN-ValueEUTRA.h"
#include <constr_CHOICE.h>
#include "ARFCN-ValueEUTRA-v9e0.h"
#include "C-RNTI.h"
#include "TimeSinceFailure-r11.h"
#include "ARFCN-ValueUTRA.h"
#include "PhysCellIdUTRA-FDD.h"
#include "PhysCellIdUTRA-TDD.h"
#include "TrackingAreaCode.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RLF_Report_r9__failedPCellId_r10_PR {
	RLF_Report_r9__failedPCellId_r10_PR_NOTHING,	/* No components present */
	RLF_Report_r9__failedPCellId_r10_PR_cellGlobalId_r10,
	RLF_Report_r9__failedPCellId_r10_PR_pci_arfcn_r10
} RLF_Report_r9__failedPCellId_r10_PR;
typedef enum RLF_Report_r9__connectionFailureType_r10 {
	RLF_Report_r9__connectionFailureType_r10_rlf	= 0,
	RLF_Report_r9__connectionFailureType_r10_hof	= 1
} e_RLF_Report_r9__connectionFailureType_r10;
typedef enum RLF_Report_r9__basicFields_r11__rlf_Cause_r11 {
	RLF_Report_r9__basicFields_r11__rlf_Cause_r11_t310_Expiry	= 0,
	RLF_Report_r9__basicFields_r11__rlf_Cause_r11_randomAccessProblem	= 1,
	RLF_Report_r9__basicFields_r11__rlf_Cause_r11_rlc_MaxNumRetx	= 2,
	RLF_Report_r9__basicFields_r11__rlf_Cause_r11_t312_Expiry_r12	= 3
} e_RLF_Report_r9__basicFields_r11__rlf_Cause_r11;
typedef enum RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_PR {
	RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_PR_NOTHING,	/* No components present */
	RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_PR_fdd_r11,
	RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_PR_tdd_r11
} RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_PR;
typedef enum RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_PR {
	RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_PR_NOTHING,	/* No components present */
	RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_PR_fdd_r11,
	RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_PR_tdd_r11
} RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_PR;
typedef enum RLF_Report_r9__drb_EstablishedWithQCI_1_r13 {
	RLF_Report_r9__drb_EstablishedWithQCI_1_r13_qci1	= 0
} e_RLF_Report_r9__drb_EstablishedWithQCI_1_r13;

/* Forward declarations */
struct LocationInfo_r10;
struct CellGlobalIdEUTRA;
struct RSRQ_Type_r12;
struct MeasResultList2EUTRA_v1250;
struct MeasResultList2EUTRA_r9;
struct MeasResultList2UTRA_r9;
struct MeasResultListGERAN;
struct MeasResultList2CDMA2000_r9;
struct CellGlobalIdUTRA;

/* RLF-Report-r9 */
typedef struct RLF_Report_r9 {
	struct RLF_Report_r9__measResultLastServCell_r9 {
		RSRP_Range_t	 rsrpResult_r9;
		RSRQ_Range_t	*rsrqResult_r9	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} measResultLastServCell_r9;
	struct RLF_Report_r9__measResultNeighCells_r9 {
		struct MeasResultList2EUTRA_r9	*measResultListEUTRA_r9	/* OPTIONAL */;
		struct MeasResultList2UTRA_r9	*measResultListUTRA_r9	/* OPTIONAL */;
		struct MeasResultListGERAN	*measResultListGERAN_r9	/* OPTIONAL */;
		struct MeasResultList2CDMA2000_r9	*measResultsCDMA2000_r9	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *measResultNeighCells_r9;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct LocationInfo_r10	*locationInfo_r10	/* OPTIONAL */;
	struct RLF_Report_r9__failedPCellId_r10 {
		RLF_Report_r9__failedPCellId_r10_PR present;
		union RLF_Report_r9__failedPCellId_r10_u {
			CellGlobalIdEUTRA_t	 cellGlobalId_r10;
			struct RLF_Report_r9__failedPCellId_r10__pci_arfcn_r10 {
				PhysCellId_t	 physCellId_r10;
				ARFCN_ValueEUTRA_t	 carrierFreq_r10;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} pci_arfcn_r10;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *failedPCellId_r10;
	struct CellGlobalIdEUTRA	*reestablishmentCellId_r10	/* OPTIONAL */;
	long	*timeConnFailure_r10	/* OPTIONAL */;
	ENUMERATED_t	*connectionFailureType_r10	/* OPTIONAL */;
	struct CellGlobalIdEUTRA	*previousPCellId_r10	/* OPTIONAL */;
	struct RLF_Report_r9__failedPCellId_v1090 {
		ARFCN_ValueEUTRA_v9e0_t	 carrierFreq_v1090;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *failedPCellId_v1090;
	struct RLF_Report_r9__basicFields_r11 {
		C_RNTI_t	 c_RNTI_r11;
		ENUMERATED_t	 rlf_Cause_r11;
		TimeSinceFailure_r11_t	 timeSinceFailure_r11;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *basicFields_r11;
	struct RLF_Report_r9__previousUTRA_CellId_r11 {
		ARFCN_ValueUTRA_t	 carrierFreq_r11;
		struct RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11 {
			RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_PR present;
			union RLF_Report_r9__previousUTRA_CellId_r11__physCellId_r11_u {
				PhysCellIdUTRA_FDD_t	 fdd_r11;
				PhysCellIdUTRA_TDD_t	 tdd_r11;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} physCellId_r11;
		struct CellGlobalIdUTRA	*cellGlobalId_r11	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *previousUTRA_CellId_r11;
	struct RLF_Report_r9__selectedUTRA_CellId_r11 {
		ARFCN_ValueUTRA_t	 carrierFreq_r11;
		struct RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11 {
			RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_PR present;
			union RLF_Report_r9__selectedUTRA_CellId_r11__physCellId_r11_u {
				PhysCellIdUTRA_FDD_t	 fdd_r11;
				PhysCellIdUTRA_TDD_t	 tdd_r11;
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} physCellId_r11;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *selectedUTRA_CellId_r11;
	struct RLF_Report_r9__failedPCellId_v1250 {
		TrackingAreaCode_t	 tac_FailedPCell_r12;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *failedPCellId_v1250;
	RSRQ_Range_v1250_t	*measResultLastServCell_v1250	/* OPTIONAL */;
	struct RSRQ_Type_r12	*lastServCellRSRQ_Type_r12	/* OPTIONAL */;
	struct MeasResultList2EUTRA_v1250	*measResultListEUTRA_v1250	/* OPTIONAL */;
	ENUMERATED_t	*drb_EstablishedWithQCI_1_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RLF_Report_r9_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_connectionFailureType_r10_19;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_rlf_Cause_r11_27;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_drb_EstablishedWithQCI_1_r13_49;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RLF_Report_r9;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "LocationInfo-r10.h"
#include "CellGlobalIdEUTRA.h"
#include "RSRQ-Type-r12.h"
#include "MeasResultList2EUTRA-v1250.h"
#include "MeasResultList2EUTRA-r9.h"
#include "MeasResultList2UTRA-r9.h"
#include "MeasResultListGERAN.h"
#include "MeasResultList2CDMA2000-r9.h"
#include "CellGlobalIdUTRA.h"

#endif	/* _RLF_Report_r9_H_ */
#include <asn_internal.h>
