#ifndef BQSELAYER_DBG_H
#define BQSELAYER_DBG_H
#include "CtxCrack.h"
#include "PrimTypes.h"
LINK_C_Begin
tNone BQSELAYER_StaticChecks(tNone);
LINK_C_End
#ifdef BQSELAYER_DBG_IMPL
tNone BQSELAYER_StaticChecks(tNone)
{
	typedef char BQSELAYER_StaticAssert_tISSz_size[(sizeof(tISSz) == sizeof(tPtr)) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIUSz_size[(sizeof(tIUSz) == sizeof(tPtr)) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIS8_size[(sizeof(tIS8) == 1U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIU8_size[(sizeof(tIU8) == 1U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIS16_size[(sizeof(tIS16) == 2U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIU16_size[(sizeof(tIU16) == 2U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIS32_size[(sizeof(tIS32) == 4U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIU32_size[(sizeof(tIU32) == 4U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIS64_size[(sizeof(tIS64) == 8U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tIU64_size[(sizeof(tIU64) == 8U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tFP32_IEEE754_size[(sizeof(tFP32) == 4U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tFP64_IEEE754_size[(sizeof(tFP64) == 8U) ? 1U : -1];
}
#endif/*BQSELAYER_DBG_IMPL*/
#endif/*BQSELAYER_DBG_H*/