/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "/home/qiongbod/asn1c-0.9.27/asn1c/input/36331-d10.asn"
 * 	`asn1c -S /home/qiongbod/asn1c-0.9.27/skeletons -fcompound-names -fwide-types -gen-PER`
 */

#ifndef	_SL_DiscTxResourceReq_r13_H_
#define	_SL_DiscTxResourceReq_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SL-DiscTxResourceReq-r13 */
typedef struct SL_DiscTxResourceReq_r13 {
	long	*carrierFreqDiscTx_r13	/* OPTIONAL */;
	long	 discTxResourceReq_r13;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SL_DiscTxResourceReq_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SL_DiscTxResourceReq_r13;

#ifdef __cplusplus
}
#endif

#endif	/* _SL_DiscTxResourceReq_r13_H_ */
#include <asn_internal.h>
