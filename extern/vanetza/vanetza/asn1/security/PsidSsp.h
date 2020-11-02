/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IEEE1609dot2BaseTypes"
 * 	found in "asn1/IEEE1609dot2BaseTypes.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_PsidSsp_H_
#define	_PsidSsp_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Psid.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ServiceSpecificPermissions;

/* PsidSsp */
typedef struct PsidSsp {
	Psid_t	 psid;
	struct ServiceSpecificPermissions	*ssp;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PsidSsp_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PsidSsp;
extern asn_SEQUENCE_specifics_t asn_SPC_PsidSsp_specs_1;
extern asn_TYPE_member_t asn_MBR_PsidSsp_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ServiceSpecificPermissions.h"

#endif	/* _PsidSsp_H_ */
#include "asn_internal.h"
