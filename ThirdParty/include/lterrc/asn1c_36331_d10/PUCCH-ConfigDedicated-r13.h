/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_PUCCH_ConfigDedicated_r13_H_
#define	_PUCCH_ConfigDedicated_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>
#include <NativeInteger.h>
#include <BOOLEAN.h>
#include <NULL.h>
#include <constr_SEQUENCE.h>
#include <constr_CHOICE.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_PR {
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_PR_release,
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_PR_setup
} PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup__repetitionFactor_r13 {
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup__repetitionFactor_r13_n2	= 0,
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup__repetitionFactor_r13_n4	= 1,
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup__repetitionFactor_r13_n6	= 2,
	PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup__repetitionFactor_r13_spare1	= 3
} e_PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup__repetitionFactor_r13;
typedef enum PUCCH_ConfigDedicated_r13__tdd_AckNackFeedbackMode_r13 {
	PUCCH_ConfigDedicated_r13__tdd_AckNackFeedbackMode_r13_bundling	= 0,
	PUCCH_ConfigDedicated_r13__tdd_AckNackFeedbackMode_r13_multiplexing	= 1
} e_PUCCH_ConfigDedicated_r13__tdd_AckNackFeedbackMode_r13;
typedef enum PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR {
	PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR_format3_r13,
	PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR_channelSelection_r13,
	PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR_format4_r13,
	PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR_format5_r13
} PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_PR {
	PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_PR_release,
	PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_PR_setup
} PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_PR {
	PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_PR_release,
	PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_PR_setup
} PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__twoAntennaPortActivatedPUCCH_Format1a1b_r13 {
	PUCCH_ConfigDedicated_r13__twoAntennaPortActivatedPUCCH_Format1a1b_r13_true	= 0
} e_PUCCH_ConfigDedicated_r13__twoAntennaPortActivatedPUCCH_Format1a1b_r13;
typedef enum PUCCH_ConfigDedicated_r13__simultaneousPUCCH_PUSCH_r13 {
	PUCCH_ConfigDedicated_r13__simultaneousPUCCH_PUSCH_r13_true	= 0
} e_PUCCH_ConfigDedicated_r13__simultaneousPUCCH_PUSCH_r13;
typedef enum PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_PR {
	PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_PR_release,
	PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_PR_setup
} PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_PR {
	PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_PR_release,
	PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_PR_setup
} PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__codebooksizeDetermination_r13 {
	PUCCH_ConfigDedicated_r13__codebooksizeDetermination_r13_dai	= 0,
	PUCCH_ConfigDedicated_r13__codebooksizeDetermination_r13_cc	= 1
} e_PUCCH_ConfigDedicated_r13__codebooksizeDetermination_r13;
typedef enum PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_PR {
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_PR_release,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_PR_setup
} PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_PR;
typedef enum PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_PR {
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_PR_NOTHING,	/* No components present */
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_PR_modeA,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_PR_modeB
} PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_PR;
typedef enum PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format1_r13 {
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format1_r13_r1	= 0,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format1_r13_r2	= 1,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format1_r13_r4	= 2,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format1_r13_r8	= 3
} e_PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format1_r13;
typedef enum PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format2_r13 {
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format2_r13_r1	= 0,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format2_r13_r2	= 1,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format2_r13_r4	= 2,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format2_r13_r8	= 3
} e_PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA__pucch_NumRepetitionCE_format2_r13;
typedef enum PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format1_r13 {
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format1_r13_r4	= 0,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format1_r13_r8	= 1,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format1_r13_r16	= 2,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format1_r13_r32	= 3
} e_PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format1_r13;
typedef enum PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format2_r13 {
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format2_r13_r4	= 0,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format2_r13_r8	= 1,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format2_r13_r16	= 2,
	PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format2_r13_r32	= 3
} e_PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB__pucch_NumRepetitionCE_format2_r13;

/* Forward declarations */
struct N1PUCCH_AN_CS_r10;
struct Format4_resource_r13;
struct Format5_resource_r13;

/* PUCCH-ConfigDedicated-r13 */
typedef struct PUCCH_ConfigDedicated_r13 {
	struct PUCCH_ConfigDedicated_r13__ackNackRepetition_r13 {
		PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_PR present;
		union PUCCH_ConfigDedicated_r13__ackNackRepetition_r13_u {
			NULL_t	 release;
			struct PUCCH_ConfigDedicated_r13__ackNackRepetition_r13__setup {
				ENUMERATED_t	 repetitionFactor_r13;
				long	 n1PUCCH_AN_Rep_r13;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ackNackRepetition_r13;
	ENUMERATED_t	*tdd_AckNackFeedbackMode_r13	/* OPTIONAL */;
	struct PUCCH_ConfigDedicated_r13__pucch_Format_r13 {
		PUCCH_ConfigDedicated_r13__pucch_Format_r13_PR present;
		union PUCCH_ConfigDedicated_r13__pucch_Format_r13_u {
			struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13 {
				struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__n3PUCCH_AN_List_r13 {
					A_SEQUENCE_OF(long) list;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} *n3PUCCH_AN_List_r13;
				struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13 {
					PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_PR present;
					union PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13_u {
						NULL_t	 release;
						struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13__setup {
							struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format3_r13__twoAntennaPortActivatedPUCCH_Format3_r13__setup__n3PUCCH_AN_ListP1_r13 {
								A_SEQUENCE_OF(long) list;
								
								/* Context for parsing across buffer boundaries */
								asn_struct_ctx_t _asn_ctx;
							} n3PUCCH_AN_ListP1_r13;
							
							/* Context for parsing across buffer boundaries */
							asn_struct_ctx_t _asn_ctx;
						} setup;
					} choice;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} *twoAntennaPortActivatedPUCCH_Format3_r13;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} format3_r13;
			struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13 {
				struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13 {
					PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_PR present;
					union PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13_u {
						NULL_t	 release;
						struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13__setup {
							struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13__setup__n1PUCCH_AN_CS_List_r13 {
								A_SEQUENCE_OF(struct N1PUCCH_AN_CS_r10) list;
								
								/* Context for parsing across buffer boundaries */
								asn_struct_ctx_t _asn_ctx;
							} n1PUCCH_AN_CS_List_r13;
							struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__channelSelection_r13__n1PUCCH_AN_CS_r13__setup__n1PUCCH_AN_CS_ListP1_r13 {
								A_SEQUENCE_OF(long) list;
								
								/* Context for parsing across buffer boundaries */
								asn_struct_ctx_t _asn_ctx;
							} n1PUCCH_AN_CS_ListP1_r13;
							
							/* Context for parsing across buffer boundaries */
							asn_struct_ctx_t _asn_ctx;
						} setup;
					} choice;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} *n1PUCCH_AN_CS_r13;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} channelSelection_r13;
			struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format4_r13 {
				struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format4_r13__format4_resourceConfiguration_r13 {
					A_SEQUENCE_OF(struct Format4_resource_r13) list;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} format4_resourceConfiguration_r13;
				struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format4_r13__format4_MultiCSI_resourceConfiguration_r13 {
					A_SEQUENCE_OF(struct Format4_resource_r13) list;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} *format4_MultiCSI_resourceConfiguration_r13;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} format4_r13;
			struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format5_r13 {
				struct PUCCH_ConfigDedicated_r13__pucch_Format_r13__format5_r13__format5_resourceConfiguration_r13 {
					A_SEQUENCE_OF(struct Format5_resource_r13) list;
					
					/* Context for parsing across buffer boundaries */
					asn_struct_ctx_t _asn_ctx;
				} format5_resourceConfiguration_r13;
				struct Format5_resource_r13	*format5_MultiCSI_resourceConfiguration_r13	/* OPTIONAL */;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} format5_r13;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *pucch_Format_r13;
	ENUMERATED_t	*twoAntennaPortActivatedPUCCH_Format1a1b_r13	/* OPTIONAL */;
	ENUMERATED_t	*simultaneousPUCCH_PUSCH_r13	/* OPTIONAL */;
	long	*n1PUCCH_AN_RepP1_r13	/* OPTIONAL */;
	struct PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13 {
		PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_PR present;
		union PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13_u {
			NULL_t	 release;
			struct PUCCH_ConfigDedicated_r13__nPUCCH_Param_r13__setup {
				long	 nPUCCH_Identity_r13;
				long	 n1PUCCH_AN_r13;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nPUCCH_Param_r13;
	struct PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13 {
		PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_PR present;
		union PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13_u {
			NULL_t	 release;
			struct PUCCH_ConfigDedicated_r13__nkaPUCCH_Param_r13__setup {
				long	 nkaPUCCH_AN_r13;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nkaPUCCH_Param_r13;
	BOOLEAN_t	 spatialBundlingPUCCH_r13;
	BOOLEAN_t	 spatialBundlingPUSCH_r13;
	BOOLEAN_t	 harq_TimingTDD_r13;
	ENUMERATED_t	*codebooksizeDetermination_r13	/* OPTIONAL */;
	long	*maximumPayloadCoderate_r13	/* OPTIONAL */;
	struct PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13 {
		PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_PR present;
		union PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13_u {
			NULL_t	 release;
			struct PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup {
				PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_PR present;
				union PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup_u {
					struct PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeA {
						ENUMERATED_t	 pucch_NumRepetitionCE_format1_r13;
						ENUMERATED_t	 pucch_NumRepetitionCE_format2_r13;
						
						/* Context for parsing across buffer boundaries */
						asn_struct_ctx_t _asn_ctx;
					} modeA;
					struct PUCCH_ConfigDedicated_r13__pucch_NumRepetitionCE_r13__setup__modeB {
						ENUMERATED_t	 pucch_NumRepetitionCE_format1_r13;
						ENUMERATED_t	 pucch_NumRepetitionCE_format2_r13;
						
						/* Context for parsing across buffer boundaries */
						asn_struct_ctx_t _asn_ctx;
					} modeB;
				} choice;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *pucch_NumRepetitionCE_r13;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PUCCH_ConfigDedicated_r13_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_repetitionFactor_r13_5;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_tdd_AckNackFeedbackMode_r13_11;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_twoAntennaPortActivatedPUCCH_Format1a1b_r13_40;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_simultaneousPUCCH_PUSCH_r13_42;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_codebooksizeDetermination_r13_57;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_format1_r13_65;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_format2_r13_70;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_format1_r13_76;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_pucch_NumRepetitionCE_format2_r13_81;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PUCCH_ConfigDedicated_r13;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "N1PUCCH-AN-CS-r10.h"
#include "Format4-resource-r13.h"
#include "Format5-resource-r13.h"

#endif	/* _PUCCH_ConfigDedicated_r13_H_ */
#include <asn_internal.h>
