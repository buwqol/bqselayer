#ifndef BQSELAYER_DBG_H
#define BQSELAYER_DBG_H
#include "CtxCrack.h"
#include "PrimTypes.h"
LINK_C_Begin
tNone BQSELAYER_StaticChecks(tNone);
LINK_C_End
#ifdef BQSELAYER_IMPL
tNone BQSELAYER_StaticChecks(tNone)
{
	typedef char BQSELAYER_StaticAssert_tSSz_size[(sizeof(tSSz) == sizeof(tPtr)) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tUSz_size[(sizeof(tUSz) == sizeof(tPtr)) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tS8_size[(sizeof(tS8) == 1U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tU8_size[(sizeof(tU8) == 1U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tS16_size[(sizeof(tS16) == 2U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tU16_size[(sizeof(tU16) == 2U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tS32_size[(sizeof(tS32) == 4U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tU32_size[(sizeof(tU32) == 4U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tS64_size[(sizeof(tS64) == 8U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tU64_size[(sizeof(tU64) == 8U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tF32_IEEE754_size[(sizeof(tF32) == 4U) ? 1U : -1];
	typedef char BQSELAYER_StaticAssert_tF64_IEEE754_size[(sizeof(tF64) == 8U) ? 1U : -1];
}
#endif/*BQSELAYER_IMPL*/
#endif/*BQSELAYER_DBG_H*/