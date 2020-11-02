/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "asn1/ISO_TS_19091_CPM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_RegionalExtension_H_
#define	_RegionalExtension_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RegionId.h"
#include "ANY.h"
#include "asn_ioc.h"
#include "OPEN_TYPE.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Reg_NodeOffsetPointXY__regExtValue_PR {
	Reg_NodeOffsetPointXY__regExtValue_PR_NOTHING	/* No components present */
	
} Reg_NodeOffsetPointXY__regExtValue_PR;

/* RegionalExtension */
typedef struct Reg_NodeOffsetPointXY {
	RegionId_t	 regionId;
	struct Reg_NodeOffsetPointXY__regExtValue {
		Reg_NodeOffsetPointXY__regExtValue_PR present;
		union Reg_NodeOffsetPointXY__regExtValue_u {
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} regExtValue;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Reg_NodeOffsetPointXY_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Reg_NodeOffsetPointXY;
extern asn_SEQUENCE_specifics_t asn_SPC_Reg_NodeOffsetPointXY_specs_1;
extern asn_TYPE_member_t asn_MBR_Reg_NodeOffsetPointXY_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RegionalExtension_H_ */
#include "asn_internal.h"
