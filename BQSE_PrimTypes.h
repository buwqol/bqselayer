#ifndef BQSELAYER_PRIMTYPES_H
#define BQSELAYER_PRIMTYPES_H
#include "BQSE_CtxCrack.h"
/*Primitive types*/
#if defined(LANG_Cpp)
typedef bool tBln;
#elif defined(LANG_C) && LANG_Ver >= 1999
typedef _Bool tBln;
#else
typedef char unsigned tBln;
#endif
#ifndef True
#define True ((tBln)1)
#endif
#ifndef False
#define False ((tBln)0)
#endif
#define tNone void
#define tGen void
#define tInt int
typedef tNone tFnc(tNone);
typedef tFnc *tFncPtr;
typedef tGen *tPtr;
#define Null ((tPtr)0U)
typedef char tChr;
typedef char signed tS8;
#define tS8_Max 127
#define tS8_Min (-128)
typedef char unsigned tU8;
#define tU8_Max 255
#define tU8_Min 0
typedef short signed tS16;
#define tS16_Max 32767
#define tS16_Min (-32768)
typedef short unsigned tU16;
#define tU16_Max 65535
#define tU16_Min 0
typedef int signed tS32;
#define tS32_Max 2147483647
#define tS32_Min (-2147483647-1)
typedef int unsigned tU32;
#define tU32_Max 4294967295U
#define tU32_Min 0U
typedef long long signed tS64;
#define tS64_Max 9223372036854775807LL
#define tS64_Min (-9223372036854775807LL-1)
typedef long long unsigned tU64;
#define tU64_Max 18446744073709551615LLU
#define tU64_Min 0LLU
// TODO: tF16 half precision floating point type.
typedef float tF32;
#define tF32_Pi 3.141592653589793F
#define tF32_Eps 1.19209290E-7F
#define tF32_Tol 1E-5F
#define tF32_EulNum 2.718281828459045F
#define tF32_EulCnst 0.577215664901532F
#define tF32_RadToDeg(flt) ((flt) * 57.29577951308233F)
#define tF32_DegToRad(flt) ((flt) * 0.0174532925199433F)
tF32 tF32_Inf(tNone);
tF32 tF32_Abs(tF32 flt);
tF32 tF32_Neg(tF32 flt);
tF32 tF32_NegInf(tNone);
tF32 tF32_QuiNaN(tNone);
tF32 tF32_SigNaN(tNone);
tF32 tF32_Sine(tF32 ang);
tF32 tF32_Cosine(tF32 ang);
tF32 tF32_Tangent(tF32 ang);
tF32 tF32_SineInv(tF32 num);
tF32 tF32_CosineInv(tF32 num);
tF32 tF32_TangentInv(tF32 num);
tF32 tF32_TangentInv2(tF32 opp, tF32 adj);
tF32 tF32_HypSine(tF32 ang);
tF32 tF32_HypCosine(tF32 ang);
tF32 tF32_HypTangent(tF32 ang);
tF32 tF32_Sqrt(tF32 num);
tF32 tF32_InvSqrt(tF32 num);
tF32 tF32_Ln(tF32 num);
tF32 tF32_Log(tF32 num, tF32 btm);
tF32 tF32_Lerp(tF32 strt, tF32 stp, tF32 fnsh);
tF32 tF32_Unlerp(tF32 strt, tF32 curr, tF32 fnsh);
#define tF32_SignMask 0X80000000U
#define tF32_ExpoMask 0X7F800000U
#define tF32_FracMask 0X007FFFFFU
typedef union
{
	tF32 flt;
	tU32 raw;
}
tF32Bits;
#ifdef BQSE_MASTER
tF32 tF32_Inf(tNone)
{
	tF32Bits num;
	num.raw = 0X7F800000U;
	return num.flt;
}
tF32 tF32_Abs(tF32 flt)
{
	tF32Bits num;
	num.flt = flt;
	num.raw &= 0X7FFFFFFFU;
	return num.flt;
}
tF32 tF32_Neg(tF32 flt)
{
	tF32Bits num;
	num.flt = flt;
	num.raw ^= 0X80000000U;
	return num.flt;
}
tF32 tF32_NegInf(tNone)
{
	tF32Bits num;
	num.raw = 0XFF800000U;
	return num.flt;
}
tF32 tF32_QuiNaN(tNone)
{
	tF32Bits num;
	num.raw = 0XFFC00001U;
	return num.flt;
}
tF32 tF32_SigNaN(tNone)
{
	tF32Bits num;
	num.raw = 0XFF800001U;
	return num.flt;
}
#include <math.h> // TODO: Move away from this eventually.
tF32 tF32_Sine(tF32 ang)
{
	return sinf(ang);
}
tF32 tF32_Cosine(tF32 ang)
{
	return cosf(ang);
}
tF32 tF32_Tangent(tF32 ang)
{
	return tanf(ang);
}
tF32 tF32_SineInv(tF32 num)
{
	return asinf(num);
}
tF32 tF32_CosineInv(tF32 num)
{
	return acosf(num);
}
tF32 tF32_TangentInv(tF32 num)
{
	return atanf(num);
}
tF32 tF32_TangentInv2(tF32 opp, tF32 adj)
{
	return atan2(opp, adj);
}
tF32 tF32_HypSine(tF32 ang)
{
	return sinhf(ang);
}
tF32 tF32_HypCosine(tF32 ang)
{
	return coshf(ang);
}
tF32 tF32_HypTangent(tF32 ang)
{
	return tanhf(ang);
}
tF32 tF32_Sqrt(tF32 num)
{
	return sqrtf(num);
}
// Fast inverse sqrt from Quake 3.
tF32 tF32_InvSqrt(tF32 num)
{
	static const tF32 threeHalfs = 1.5F;
	tF32Bits number;
	number.flt = num;
	tF32 halfNum = number.flt * 0.5F;
	number.raw = 0X5F3759DFU - (number.raw >> 1U);
	number.flt = number.flt * (threeHalfs - (halfNum * number.flt * number.flt));
	// number.flt = number.flt * (threeHalf - (halfNum * number.flt * number.flt)); // Enable this if you need the precision.
	return number.flt;
}
tF32 tF32_Ln(tF32 num)
{
	return logf(num);
}
tF32 tF32_Log(tF32 num, tF32 btm)
{
	return tF32_Ln(num) / tF32_Ln(btm);
}
tF32 tF32_Lerp(tF32 strt, tF32 stp, tF32 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
tF32 tF32_Unlerp(tF32 strt, tF32 curr, tF32 fnsh)
{
	if (strt == fnsh) return 0.0F;
	return (curr - strt) / (fnsh - strt);
}
#endif//BQSE_MASTER
typedef double tF64;
#define tF64_Pi 3.141592653589793
#define tF64_Eps 2.2204460492503131E-16
#define tF64_Tol 1E-5
#define tF64_EulNum 2.718281828459045
#define tF64_EulCnst 0.577215664901532
#define tF64_RadToDeg(dbl) ((dbl) * 57.29577951308233)
#define tF64_DegToRad(dbl) ((dbl) * 0.0174532925199433)
tF64 tF64_Inf(tNone);
tF64 tF64_Abs(tF64 dbl);
tF64 tF64_Neg(tF64 dbl);
tF64 tF64_NegInf(tNone);
tF64 tF64_QuiNaN(tNone);
tF64 tF64_SigNaN(tNone);
tF64 tF64_Sine(tF64 ang);
tF64 tF64_Cosine(tF64 ang);
tF64 tF64_Tangent(tF64 ang);
tF64 tF64_SineInv(tF64 num);
tF64 tF64_CosineInv(tF64 num);
tF64 tF64_TangentInv(tF64 num);
tF64 tF64_TangentInv2(tF64 opp, tF64 adj);
tF64 tF64_HypSine(tF64 ang);
tF64 tF64_HypCosine(tF64 ang);
tF64 tF64_HypTangent(tF64 ang);
tF64 tF64_Sqrt(tF64 num);
tF64 tF64_InvSqrt(tF64 num);
tF64 tF64_Ln(tF64 num);
tF64 tF64_Log(tF64 num, tF64 btm);
tF64 tF64_Lerp(tF64 strt, tF64 stp, tF64 fnsh);
tF64 tF64_Unlerp(tF64 strt, tF64 curr, tF64 fnsh);
#define tF64_SignMask 0X8000000000000000LLU
#define tF64_ExpoMask 0X7FF0000000000000LLU
#define tF64_FracMask 0X000FFFFFFFFFFFFFLLU
typedef union
{
	tF64 dbl;
	tU64 raw;
}
tF64Bits;
#ifdef BQSE_MASTER
tF64 tF64_Inf(tNone)
{
	tF64Bits num;
	num.raw = 0X7FF0000000000000LLU;
	return num.dbl;
}
tF64 tF64_Abs(tF64 dbl)
{
	tF64Bits num;
	num.dbl = dbl;
	num.raw &= 0X7FFFFFFFFFFFFFFFLLU;
	return num.dbl;
}
tF64 tF64_Neg(tF64 dbl)
{
	tF64Bits num;
	num.dbl = dbl;
	num.raw ^= 0X8000000000000000LLU;
	return num.dbl;
}
tF64 tF64_NegInf(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF0000000000000LLU;
	return num.dbl;
}
tF64 tF64_QuiNaN(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF8000000000001LLU;
	return num.dbl;
}
tF64 tF64_SigNaN(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF0000000000001LLU;
	return num.dbl;
}
tF64 tF64_Sine(tF64 ang)
{
	return sin(ang);
}
tF64 tF64_Cosine(tF64 ang)
{
	return cos(ang);
}
tF64 tF64_Tangent(tF64 ang)
{
	return tan(ang);
}
tF64 tF64_SineInv(tF64 num)
{
	return asin(num);
}
tF64 tF64_CosineInv(tF64 num)
{
	return acos(num);
}
tF64 tF64_TangentInv(tF64 num)
{
	return atan(num);
}
tF64 tF64_TangentInv2(tF64 opp, tF64 adj)
{
	return atan2(opp, adj);
}
tF64 tF64_HypSine(tF64 ang)
{
	return sinh(ang);
}
tF64 tF64_HypCosine(tF64 ang)
{
	return cosh(ang);
}
tF64 tF64_HypTangent(tF64 ang)
{
	return tanh(ang);
}
tF64 tF64_Sqrt(tF64 num)
{
	return sqrt(num);
}
tF64 tF64_InvSqrt(tF64 num)
{
	static const tF64 threeHalfs = 1.5;
	tF64Bits number;
	number.dbl = num;
	tF64 halfNum = number.dbl * 0.5;
	number.raw = 0X5FE6EC85E7DE30DAULL - (number.raw >> 1U);
	number.dbl = number.dbl * (threeHalfs - (halfNum * number.dbl * number.dbl));
	// number.dbl = number.dbl * (threeHalfs - (halfNum * number.dbl * number.dbl)); // Optional second iteration.
	return number.dbl;
}
tF64 tF64_Ln(tF64 num)
{
	return log(num);
}
tF64 tF64_Log(tF64 num, tF64 btm)
{
	return tF64_Ln(num) / tF64_Ln(btm);
}
tF64 tF64_Lerp(tF64 strt, tF64 stp, tF64 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
tF64 tF64_Unlerp(tF64 strt, tF64 curr, tF64 fnsh)
{
	if (strt == fnsh) return 0.0;
	return (curr - strt) / (fnsh - strt);
}
#endif//BQSE_MASTER
#if ARCH_Bitness == 64
typedef tS64 tSSz;
typedef tU64 tUSz;
#else
typedef tS32 tSSz;
typedef tU32 tUSz;
#endif
#define BQSE_DECLARE_MINMAXCLAMPS(tType)			\
tType tType##_MinOf(tType Num1, tType Num2);		\
tType tType##_MaxOf(tType Num1, tType Num2);		\
tType tType##_Clamp(tType Lo, tType Num, tType Hi);	\
tType tType##_ClampTop(tType Num1, tType Num2);		\
tType tType##_ClampBot(tType Num1, tType Num2);		
#define BQSE_DEFINE_MINMAXCLAMPS(tType)				\
tType tType##_MinOf(tType Num1, tType Num2)			\
{													\
	return Num1 < Num2 ? Num1 : Num2;				\
}													\
tType tType##_MaxOf(tType Num1, tType Num2)			\
{													\
	return Num1 > Num2 ? Num1 : Num2;				\
}													\
tType tType##_Clamp(tType Lo, tType Num, tType Hi)	\
{													\
	return (Num < Lo) ? Lo : (Hi < Num) ? Hi : Num; \
}													\
tType tType##_ClampTop(tType Num1, tType Num2)		\
{													\
	return Num1 < Num2 ? Num1 : Num2;				\
}													\
tType tType##_ClampBot(tType Num1, tType Num2)		\
{													\
	return Num1 > Num2 ? Num1 : Num2;				\
}
#define WrapStatement(Stmnt) do{Stmnt}while(0U)
#define ForceDump() (*(voltaile tUSz *)0U = 0U)
#define Assertion(Cnd) WrapStatement(if(!(Cnd)){ForceDump();})
#define Stringify_inner(Str) #Str
#define Stringify(Str) Stringify_inner(Str)
#define Glueify_inner(StrA, StrB) StrA##StrB
#define Glueify(StrA, StrB) Glueify_inner(StrA, StrB)
#define ArrLng(Arr) (sizeof(Arr)/sizeof(Arr[0]))
#define NumFromPtr(Ptr) (tUSz)((tU8 *)Ptr - (tU8 *)0U)
#define PtrFromNum(Num) (tPtr)((tU8 *)0U + (Num))
#define OffsetOf(tType, Memb) ((tUSz)&(((tType*)0U)->Memb))
#define MemberSize(tType, Memb) (sizeof(((tType *)0U)->Memb))
BQSE_DECLARE_MINMAXCLAMPS(tSSz);
BQSE_DECLARE_MINMAXCLAMPS(tUSz);
BQSE_DECLARE_MINMAXCLAMPS(tS8);
BQSE_DECLARE_MINMAXCLAMPS(tU8);
BQSE_DECLARE_MINMAXCLAMPS(tS16);
BQSE_DECLARE_MINMAXCLAMPS(tU16);
BQSE_DECLARE_MINMAXCLAMPS(tS32);
BQSE_DECLARE_MINMAXCLAMPS(tU32);
BQSE_DECLARE_MINMAXCLAMPS(tS64);
BQSE_DECLARE_MINMAXCLAMPS(tU64);
BQSE_DECLARE_MINMAXCLAMPS(tF32);
BQSE_DECLARE_MINMAXCLAMPS(tF64);
#ifdef BQSE_MASTER
BQSE_DEFINE_MINMAXCLAMPS(tSSz);
BQSE_DEFINE_MINMAXCLAMPS(tUSz);
BQSE_DEFINE_MINMAXCLAMPS(tS8);
BQSE_DEFINE_MINMAXCLAMPS(tU8);
BQSE_DEFINE_MINMAXCLAMPS(tS16);
BQSE_DEFINE_MINMAXCLAMPS(tU16);
BQSE_DEFINE_MINMAXCLAMPS(tS32);
BQSE_DEFINE_MINMAXCLAMPS(tU32);
BQSE_DEFINE_MINMAXCLAMPS(tS64);
BQSE_DEFINE_MINMAXCLAMPS(tU64);
BQSE_DEFINE_MINMAXCLAMPS(tF32);
BQSE_DEFINE_MINMAXCLAMPS(tF64);
#endif
#undef BQSE_DECLARE_MINMAXCLAMPS
#undef BQSE_DEFINE_MINMAXCLAMPS
// TODO: Write a function to actually use these static asserts.
typedef char BQSE_StaticAssert_tSSz[(sizeof(tSSz) == sizeof(tPtr)) ? 1U : -1];
typedef char BQSE_StaticAssert_tUSz[(sizeof(tUSz) == sizeof(tPtr)) ? 1U : -1];
typedef char BQSE_StaticAssert_tS8[(sizeof(tS8) == 1U) ? 1U : -1];
typedef char BQSE_StaticAssert_tU8[(sizeof(tU8) == 1U) ? 1U : -1];
typedef char BQSE_StaticAssert_tS16[(sizeof(tS16) == 2U) ? 1U : -1];
typedef char BQSE_StaticAssert_tU16[(sizeof(tU16) == 2U) ? 1U : -1];
typedef char BQSE_StaticAssert_tS32[(sizeof(tS32) == 4U) ? 1U : -1];
typedef char BQSE_StaticAssert_tU32[(sizeof(tU32) == 4U) ? 1U : -1];
typedef char BQSE_StaticAssert_tS64[(sizeof(tS64) == 8U) ? 1U : -1];
typedef char BQSE_StaticAssert_tU64[(sizeof(tU64) == 8U) ? 1U : -1];
typedef char BQSE_StaticAssert_tF32_IEEE754[(sizeof(tF32) == 4U) ? 1U : -1];
typedef char BQSE_StaticAssert_tF64_IEEE754[(sizeof(tF64) == 8U) ? 1U : -1];
#endif/*BQSELAYER_PRIMTYPES_H*/