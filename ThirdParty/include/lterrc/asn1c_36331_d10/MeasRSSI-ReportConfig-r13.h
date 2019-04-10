/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_MeasRSSI_ReportConfig_r13_H_
#define	_MeasRSSI_ReportConfig_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RSSI-Range-r13.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MeasRSSI-ReportConfig-r13 */
typedef struct MeasRSSI_ReportConfig_r13 {
	RSSI_Range_r13_t	*channelOccupancyThreshold_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasRSSI_ReportConfig_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasRSSI_ReportConfig_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasRSSI_ReportConfig_r13_H_ */
#include <asn_internal.h>
