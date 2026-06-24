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
#define True ((tBln)1U)
#endif
#ifndef False
#define False ((tBln)0U)
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
LINK_C_Begin
tU32 tU32_Fact(tU32 base);
LINK_C_End
#ifdef BQSE_IMPL
tU32 tU32_Fact(tU32 base)
{
	if (base == 0U || base == 1U) return 1U;
	const tU32 itr = base;
	for (tU32 idx = 2U; idx < itr; ++idx) base *= idx;
	return base;
}
#endif/*BQSE_IMPL*/
typedef long long signed tS64;
#define tS64_Max 9223372036854775807LL
#define tS64_Min (-9223372036854775807LL-1)
typedef long long unsigned tU64;
#define tU64_Max 18446744073709551615LLU
#define tU64_Min 0LLU
LINK_C_Begin
tU64 tU64_Fact(tU64 base);
LINK_C_End
#ifdef BQSE_IMPL
tU64 tU64_Fact(tU64 base)
{
	if (base == 0U || base == 1U) return 1U;
	const tU64 itr = base;
	for (tU64 idx = 2U; idx < itr; ++idx) base *= idx;
	return base;
}
#endif/*BQSE_IMPL*/
#if ARCH_Bitness == 64
typedef tS64 tSSz;
typedef tU64 tUSz;
#else
typedef tS32 tSSz;
typedef tU32 tUSz;
#endif/*ARCH_Bitness*/
#ifdef BQSE_IMPL
#define BQSE_TRIG_ITER 7U
#endif/*BQSE_IMPL*/
typedef float tF32;
#define tF32_Pi 3.141592653589793F
#define tF32_2Pi 6.283185307F
#define tF32_HalfPi 1.570796327F
#define tF32_Inv2Pi 0.15915494309189535F
#define tF32_Eps 1.19209290E-7F
#define tF32_Tol 1E-5F
#define tF32_EulNum 2.718281828459045F
#define tF32_EulCnst 0.577215664901532F
#define tF32_Log2EulNum 1.44269504089F
#define tF32_RadToDeg(flt) ((flt) * 57.29577951308233F)
#define tF32_DegToRad(flt) ((flt) * 0.0174532925199433F)
LINK_C_Begin
tF32 tF32_Inf(tNone);
tF32 tF32_Abs(tF32 flt);
tF32 tF32_Neg(tF32 flt);
tBln tF32_IsNeg(tF32 flt);
tF32 tF32_NegInf(tNone);
tF32 tF32_QuiNaN(tNone);
tF32 tF32_SigNaN(tNone);
tBln tF32_Nearby(tF32 flt, tF32 cmp);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Sine_fast(tF32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Cosine_fast(tF32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Tangent_fast(tF32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Sine_iter(tF32 ang, tUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Cosine_iter(tF32 ang, tUSz itr);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
tF32 tF32_Tangent_iter(tF32 ang, tUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Sine(tF32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF32 tF32_Cosine(tF32 ang);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
tF32 tF32_Tangent(tF32 ang);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF32 tF32_ArcSine_iter(tF32 num, tUSz sqrtItr, tUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF32 tF32_ArcSine(tF32 num);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF32 tF32_ArcCosine_iter(tF32 num, tUSz sqrtItr, tUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF32 tF32_ArcCosine(tF32 num);
tF32 tF32_ArcTangent_iter(tF32 num, tUSz itr);
tF32 tF32_ArcTangent(tF32 num);
tF32 tF32_ArcTangent2_iter(tF32 opp, tF32 adj, tUSz itr);
tF32 tF32_ArcTangent2(tF32 opp, tF32 adj);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
tF32 tF32_InvSqrt_iter(tF32 num, tUSz itr);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
tF32 tF32_InvSqrt(tF32 num);
tF32 tF32_Sqrt_iter(tF32 num, tUSz itr);
tF32 tF32_Sqrt(tF32 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF32 tF32_Log2_iter(tF32 num, tUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF32 tF32_Log2(tF32 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF32 tF32_Ln_iter(tF32 num, tUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF32 tF32_Ln(tF32 num);
/*Note: Returns SigNaN when num is less than or equal to 0, base is less than or equal to 0, or base equal to 1.*/
tF32 tF32_Log_iter(tF32 num, tF32 base, tUSz itr);
/*Note: Returns SigNaN when num is less than or equal to 0, base is less than or equal to 0, or base equal to 1.*/
tF32 tF32_Log(tF32 num, tF32 base);
tF32 tF32_Lerp(tF32 strt, tF32 stp, tF32 fnsh);
tF32 tF32_Unlerp(tF32 strt, tF32 curr, tF32 fnsh);
tF32 tF32_Exp_iter(tF32 pow, tUSz itr);
tF32 tF32_Exp(tF32 pow);
tF32 tF32_HypSine_iter(tF32 num, tUSz itr);
tF32 tF32_HypCosine_iter(tF32 num, tUSz itr);
tF32 tF32_HypTangent_iter(tF32 num, tUSz itr);
tF32 tF32_HypSine(tF32 num);
tF32 tF32_HypCosine(tF32 num);
tF32 tF32_HypTangent(tF32 num);
tF32 tF32_Mod(tF32 num, tF32 denom);
LINK_C_End
#define tF32_SignMask 0X80000000U
#define tF32_ExpoMask 0X7F800000U
#define tF32_FracMask 0X007FFFFFU
typedef union
{
	tF32 flt;
	tU32 raw;
}
tF32Bits;
#ifdef BQSE_IMPL
tBln tF32_IsNeg(tF32 flt)
{
	tF32Bits num;
	num.flt = flt;
	return (tBln)!!(num.raw & tF32_SignMask);
}
BQSE_FORCEINLINE tF32 tF32_Inf(tNone)
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
BQSE_FORCEINLINE tF32 tF32_NegInf(tNone)
{
	tF32Bits num;
	num.raw = 0XFF800000U;
	return num.flt;
}
BQSE_FORCEINLINE tF32 tF32_QuiNaN(tNone)
{
	tF32Bits num;
	num.raw = 0XFFC00001U;
	return num.flt;
}
BQSE_FORCEINLINE tF32 tF32_SigNaN(tNone)
{
	tF32Bits num;
	num.raw = 0XFF800001U;
	return num.flt;
}
BQSE_FORCEINLINE tBln tF32_Nearby(tF32 flt, tF32 cmp)
{
	return tF32_Abs(flt - cmp) <= tF32_Eps;
}
tF32 tF32_PowI(tF32 base, tUSz exp)
{
	tF32 result = 1.0F;
	while (exp != 0U)
	{
		if (exp & 1U) result *= base;
		base *= base;
		exp >>= 1U;
	}
	return result;
}
tF32 tF32_Sine_fast(tF32 ang)
{
	tBln neg = False;
	if (tF32_Nearby(ang, 0.0F)) return 0.0F;
	ang -= (tF32)((tS32)(ang * tF32_Inv2Pi)) * tF32_2Pi;
	if (ang < 0.0F) ang += tF32_2Pi;
	if (ang > tF32_Pi)
	{
		ang -= tF32_Pi;
		neg = True;
	}
	const tF32 magicNum = ang * (tF32_Pi - ang);
	const tF32 res = (4.0F * magicNum) / (12.33700550F - magicNum);
	if (neg == True) return tF32_Neg(res);
	return res;
}
BQSE_FORCEINLINE tF32 tF32_Cosine_fast(tF32 ang)
{
	return tF32_Sine_fast(tF32_HalfPi - ang);
}
tF32 tF32_Tangent_fast(tF32 ang)
{
	const tF32 cosAng = tF32_Cosine_fast(ang);
	if (tF32_Nearby(cosAng, 0.0F)) return tF32_IsNeg(cosAng) ? tF32_NegInf() : tF32_Inf();
	const tF32 sinAng = tF32_Sine_fast(ang);
	return sinAng / cosAng;
}
tF32 tF32_Sine_iter(tF32 ang, tUSz itr)
{
	if (tF32_Nearby(ang, 0.0F)) return 0.0F;
	if (itr == 0U) return ang;
	ang -= (tF32)((tS32)(ang * tF32_Inv2Pi)) * tF32_2Pi;
	if (ang < 0.0F) ang += tF32_2Pi;
	tBln neg = False;
	if (ang > tF32_Pi)
	{
		ang -= tF32_Pi;
		neg = True;
	}
	const tF32 angSq = ang * ang;
	tF32 term = ang;
	tF32 res = term;
	for (tUSz idx = 0U; idx < itr; ++idx)
	{
		const tF32 denom = (tF32)((2U * idx + 2U) * (2U * idx + 3U));
		term *= -angSq / denom;
		res += term;
	}
	if (neg == True) return tF32_Neg(res);
	return res;
}
BQSE_FORCEINLINE tF32 tF32_Cosine_iter(tF32 ang, tUSz itr)
{
	return tF32_Sine_iter(tF32_HalfPi - ang, itr);
}
tF32 tF32_Tangent_iter(tF32 ang, tUSz itr)
{
	const tF32 cosAng = tF32_Cosine_iter(ang, itr);
	const tF32 sinAng = tF32_Sine_iter(ang, itr);
	if (tF32_Nearby(cosAng, 0.0F)) return tF32_IsNeg(sinAng) ? tF32_NegInf() : tF32_Inf();
	return sinAng / cosAng;
}
BQSE_FORCEINLINE tF32 tF32_Sine(tF32 ang)
{
	return tF32_Sine_iter(ang, BQSE_TRIG_ITER);
}
BQSE_FORCEINLINE tF32 tF32_Cosine(tF32 ang)
{
	return tF32_Cosine_iter(ang, BQSE_TRIG_ITER);
}
BQSE_FORCEINLINE tF32 tF32_Tangent(tF32 ang)
{
	return tF32_Tangent_iter(ang, BQSE_TRIG_ITER);
}
tF32 tF32_ArcSine_iter(tF32 num, tUSz sqrtItr, tUSz trigItr)
{
#ifndef BQSE_DEBUG
	if (tF32_Abs(num) > 1.0F) return tF32_SigNaN();
#else
	Assertion(tF32_Abs(num) <= 1.0F);
#endif
	if (tF32_Nearby(num, 1.0F))  return tF32_HalfPi;
	if (tF32_Nearby(num, -1.0F)) return -tF32_HalfPi;
	return tF32_ArcTangent_iter(num / tF32_Sqrt_iter(1 - (num * num), sqrtItr), trigItr);
}
tF32 tF32_ArcSine(tF32 num)
{
#ifndef BQSE_DEBUG
	if (tF32_Abs(num) > 1.0F) return tF32_SigNaN();
#else
	Assertion(tF32_Abs(num) <= 1.0F);
#endif
	if (tF32_Nearby(num, 1.0F))  return tF32_HalfPi;
	if (tF32_Nearby(num, -1.0F)) return -tF32_HalfPi;
	return tF32_ArcTangent(num / tF32_Sqrt(1 - (num * num)));
}
BQSE_FORCEINLINE tF32 tF32_ArcCosine_iter(tF32 num, tUSz sqrtItr, tUSz trigItr)
{
	return tF32_HalfPi - tF32_ArcSine_iter(num, sqrtItr, trigItr);
}
BQSE_FORCEINLINE tF32 tF32_ArcCosine(tF32 num)
{
	return tF32_HalfPi - tF32_ArcSine(num);
}
tF32 tF32_ArcTangent_iter(tF32 num, tUSz itr)
{
	if (itr == 0U) return num;
	if (num > 1.0F) return tF32_HalfPi - tF32_ArcTangent_iter(1.0F / num, itr);
	if (num < -1.0F) return -tF32_HalfPi - tF32_ArcTangent_iter(1.0F / num, itr);
	tF32 scale = 1.0F;
	if (tF32_Abs(num) > 0.5F)
	{
		num = num / (1.0F + tF32_Sqrt(1.0F + (num * num)));
		scale = 2.0F;
	}
	const tF32 numSq = num * num;
	tF32 term = num;
	tF32 res = term;
	for (tUSz idx = 0U; idx < itr; ++idx)
	{
		tUSz idx2 = idx << 1;
		term *= -numSq * ((tF32)(idx2 + 1U) / (tF32)(idx2 + 3U));
		res += term;
	}
	return scale * res;
}
BQSE_FORCEINLINE tF32 tF32_ArcTangent(tF32 num)
{
	return tF32_ArcTangent_iter(num, BQSE_TRIG_ITER);
}
tF32 tF32_ArcTangent2_iter(tF32 opp, tF32 adj, tUSz itr)
{
	if (adj > 0.0F) return tF32_ArcTangent_iter(opp / adj, itr);
	if (adj < 0.0F && opp >= 0.0F) return tF32_ArcTangent_iter(opp / adj, itr) + tF32_Pi;
	if (adj < 0.0F && opp < 0.0F) return tF32_ArcTangent_iter(opp / adj, itr) - tF32_Pi;
	if (tF32_Nearby(adj, 0.0F) && opp > 0.0F) return tF32_HalfPi;
	if (tF32_Nearby(adj, 0.0F) && opp < 0.0F) return -tF32_HalfPi;
	return 0.0F;
}
BQSE_FORCEINLINE tF32 tF32_ArcTangent2(tF32 opp, tF32 adj)
{
	return tF32_ArcTangent2_iter(opp, adj, BQSE_TRIG_ITER);
}
tF32 tF32_InvSqrt_iter(tF32 num, tUSz itr)
{
#ifndef BQSE_DEBUG
	if (tF32_Nearby(num, 0.0F)) return tF32_Inf();
	if (num < 0.0F) return tF32_SigNaN();
#else
	Assertion(num > 0.0F);
#endif
	static const tF32 threeHalfs = 1.5F;
	tF32Bits number;
	number.flt = num;
	tF32 halfNum = number.flt * 0.5F;
	number.raw = 0X5F3759DFU - (number.raw >> 1U);
	for (tUSz idx = 0U; idx < itr; ++idx) number.flt = number.flt * (threeHalfs - (halfNum * number.flt * number.flt));
	return number.flt;
}
BQSE_FORCEINLINE tF32 tF32_InvSqrt(tF32 num)
{
	return tF32_InvSqrt_iter(num, 1U);
}
BQSE_FORCEINLINE tF32 tF32_Sqrt_iter(tF32 num, tUSz itr)
{
	return num * tF32_InvSqrt_iter(num, itr);
}
BQSE_FORCEINLINE tF32 tF32_Sqrt(tF32 num)
{
	return num * tF32_InvSqrt(num);
}
tF32 tF32_Log2_iter(tF32 num, tUSz itr)
{
#ifndef BQSE_DEBUG
	if (num <= 0.0F) return tF32_SigNaN();
#else
	Assertion(num > 0.0F);
#endif
	tF32Bits numBits;
	numBits.flt = num;
	tS16 expVal = ((numBits.raw >> 23U) & tU8_Max) - 127;
	tF32Bits mantBits;
	mantBits.raw = (numBits.raw & 0X7FFFFFU) | (127U << 23);
	tBln sub = True;
	const tF32 valX = mantBits.flt - 1.0F;
	tF32 mantApprox = valX;
	tF32 powVal = mantApprox;
	for (tUSz idx = 2U; idx < itr + 2U; ++idx)
	{
		powVal *= valX;
		if (sub) mantApprox -= powVal / (tF32)idx;
		else mantApprox += powVal / (tF32)idx;
		sub = !sub;
	}
	return (tF32)expVal + (mantApprox * tF32_Log2EulNum);
}
BQSE_FORCEINLINE tF32 tF32_Log2(tF32 num)
{
	return tF32_Log2_iter(num, 4U);
}
BQSE_FORCEINLINE tF32 tF32_Ln_iter(tF32 num, tUSz itr)
{
	return tF32_Log2_iter(num, itr) / tF32_Log2EulNum;
}
BQSE_FORCEINLINE tF32 tF32_Ln(tF32 num)
{
	return tF32_Log2(num) / tF32_Log2EulNum;
}
tF32 tF32_Log_iter(tF32 num, tF32 base, tUSz itr)
{
#ifndef BQSE_DEBUG
	if (base <= 0.0F || tF32_Nearby(base, 1.0F)) return tF32_SigNaN();
#else
	Assertion(base > 0.0F && !tF32_Nearby(base, 1.0F));
#endif
	return tF32_Log2_iter(num, itr) / tF32_Log2_iter(base, itr);
}
tF32 tF32_Log(tF32 num, tF32 base)
{
#ifndef BQSE_DEBUG
	if (base <= 0.0F || tF32_Nearby(base, 1.0F)) return tF32_SigNaN();
#else
	Assertion(base > 0.0F && !tF32_Nearby(base, 1.0F));
#endif
	return tF32_Log2(num) / tF32_Log2(base);
}
BQSE_FORCEINLINE tF32 tF32_Lerp(tF32 strt, tF32 stp, tF32 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
BQSE_FORCEINLINE tF32 tF32_Unlerp(tF32 strt, tF32 curr, tF32 fnsh)
{
	if (tF32_Nearby(strt, fnsh)) return 0.0F;
	return (curr - strt) / (fnsh - strt);
}
tF32 tF32_Exp_iter(tF32 pow, tUSz itr)
{
	if (tF32_Nearby(pow, 0.0F)) return 1.0F;
	if (tF32_Nearby(pow, 1.0F)) return tF32_EulNum;
	tF32 res = 1.0F;
	tF32 term = 1.0F;
	for (tUSz idx = 1U; idx <= itr; ++idx)
	{
		term *= pow / (tF32)idx;
		res += term;
	}
	return res;
}
BQSE_FORCEINLINE tF32 tF32_Exp(tF32 pow)
{
	return tF32_Exp_iter(pow, 10U);
}
BQSE_FORCEINLINE tF32 tF32_HypSine_iter(tF32 num, tUSz itr)
{
	tF32 expNum = tF32_Exp_iter(num, itr);
	return (expNum - (1.0F / expNum)) * 0.5F;
}
BQSE_FORCEINLINE tF32 tF32_HypCosine_iter(tF32 num, tUSz itr)
{
	tF32 expNum = tF32_Exp_iter(num, itr);
	return (expNum + (1.0F / expNum)) * 0.5F;
}
tF32 tF32_HypTangent_iter(tF32 num, tUSz itr)
{
	tF32 expNum = tF32_Exp_iter(num, itr);
	tF32 invExpNum = 1.0F / expNum;
	const tF32 hypSine = (expNum - invExpNum) * 0.5F;
	const tF32 hypCosine = (expNum + invExpNum) * 0.5F;
	return hypSine / hypCosine;
}
BQSE_FORCEINLINE tF32 tF32_HypSine(tF32 num)
{
	tF32 expNum = tF32_Exp(num);
	return (expNum - (1.0F / expNum)) * 0.5F;
}
BQSE_FORCEINLINE tF32 tF32_HypCosine(tF32 num)
{
	tF32 expNum = tF32_Exp(num);
	return (expNum + (1.0F / expNum)) * 0.5F;
}
tF32 tF32_HypTangent(tF32 num)
{
	tF32 expNum = tF32_Exp(num);
	tF32 invExpNum = 1.0F / expNum;
	const tF32 hypSine = (expNum - invExpNum) * 0.5F;
	const tF32 hypCosine = (expNum + invExpNum) * 0.5F;
	return hypSine / hypCosine;
}
tF32 tF32_Mod(tF32 num, tF32 denom)
{
#ifndef BQSE_DEBUG
	if (tF32_Nearby(denom, 0.0F)) return tF32_SigNaN();
#else
	Assertion(!tF32_Nearby(denom, 0.0F));
#endif
	tS32 quot = (tS32)(num / denom);
	return num - ((tF32)quot * denom);
}
#endif/*BQSE_IMPL*/
typedef double tF64;
#define tF64_Pi 3.141592653589793
#define tF64_2Pi 6.283185307
#define tF64_HalfPi 1.570796327
#define tF64_Inv2Pi 0.15915494309189535
#define tF64_Eps 2.2204460492503131E-16
#define tF64_Tol 1E-5
#define tF64_EulNum 2.718281828459045
#define tF64_EulCnst 0.577215664901532
#define tF64_Log2EulNum 1.44269504089
#define tF64_RadToDeg(dbl) ((dbl) * 57.29577951308233)
#define tF64_DegToRad(dbl) ((dbl) * 0.0174532925199433)
LINK_C_Begin
tF64 tF64_Inf(tNone);
tF64 tF64_Abs(tF64 dbl);
tF64 tF64_Neg(tF64 dbl);
tBln tF64_IsNeg(tF64 dbl);
tF64 tF64_NegInf(tNone);
tF64 tF64_QuiNaN(tNone);
tF64 tF64_SigNaN(tNone);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Sine_fast(tF64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Cosine_fast(tF64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Tangent_fast(tF64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Sine_iter(tF64 ang, tUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Cosine_iter(tF64 ang, tUSz itr);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
tF64 tF64_Tangent_iter(tF64 ang, tUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Sine(tF64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tF64 tF64_Cosine(tF64 ang);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
tF64 tF64_Tangent(tF64 ang);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF64 tF64_ArcSine_iter(tF64 num, tUSz sqrtItr, tUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF64 tF64_ArcSine(tF64 num);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF64 tF64_ArcCosine_iter(tF64 num, tUSz sqrtItr, tUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tF64 tF64_ArcCosine(tF64 num);
tF64 tF64_ArcTangent_iter(tF64 num, tUSz itr);
tF64 tF64_ArcTangent(tF64 num);
tF64 tF64_ArcTangent2_iter(tF64 opp, tF64 adj, tUSz itr);
tF64 tF64_ArcTangent2(tF64 opp, tF64 adj);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
tF64 tF64_InvSqrt_iter(tF64 num, tUSz itr);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
tF64 tF64_InvSqrt(tF64 num);
tF64 tF64_Sqrt_iter(tF64 num, tUSz itr);
tF64 tF64_Sqrt(tF64 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF64 tF64_Log2_iter(tF64 num, tUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF64 tF64_Log2(tF64 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF64 tF64_Ln_iter(tF64 num, tUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF64 tF64_Ln(tF64 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF64 tF64_Log_iter(tF64 num, tF64 base, tUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tF64 tF64_Log(tF64 num, tF64 base);
tF64 tF64_Lerp(tF64 strt, tF64 stp, tF64 fnsh);
tF64 tF64_Unlerp(tF64 strt, tF64 curr, tF64 fnsh);
tF64 tF64_Exp_iter(tF64 pow, tUSz itr);
tF64 tF64_Exp(tF64 pow);
tF64 tF64_HypSine_iter(tF64 num, tUSz itr);
tF64 tF64_HypCosine_iter(tF64 num, tUSz itr);
tF64 tF64_HypTangent_iter(tF64 num, tUSz itr);
tF64 tF64_HypSine(tF64 num);
tF64 tF64_HypCosine(tF64 num);
tF64 tF64_HypTangent(tF64 num);
tF64 tF64_Mod(tF64 num, tF64 denom);
LINK_C_End
#define tF64_SignMask 0X8000000000000000LLU
#define tF64_ExpoMask 0X7FF0000000000000LLU
#define tF64_FracMask 0X000FFFFFFFFFFFFFLLU
typedef union
{
	tF64 dbl;
	tU64 raw;
}
tF64Bits;
#ifdef BQSE_IMPL
BQSE_FORCEINLINE tF64 tF64_Inf(tNone)
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
tBln tF64_IsNeg(tF64 dbl)
{
	tF64Bits num;
	num.dbl = dbl;
	return (tBln)!!(num.raw & tF64_SignMask);
}
tF64 tF64_Neg(tF64 dbl)
{
	tF64Bits num;
	num.dbl = dbl;
	num.raw ^= 0X8000000000000000LLU;
	return num.dbl;
}
BQSE_FORCEINLINE tF64 tF64_NegInf(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF0000000000000LLU;
	return num.dbl;
}
BQSE_FORCEINLINE tF64 tF64_QuiNaN(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF8000000000001LLU;
	return num.dbl;
}
BQSE_FORCEINLINE tF64 tF64_SigNaN(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF0000000000001LLU;
	return num.dbl;
}
BQSE_FORCEINLINE tBln tF64_Nearby(tF64 dbl, tF64 cmp)
{
	return tF64_Abs(dbl - cmp) <= tF64_Eps;
}
tF64 tF64_PowI(tF64 base, tUSz exp)
{
	tF64 result = 1.0;
	while (exp != 0U)
	{
		if (exp & 1U) result *= base;
		base *= base;
		exp >>= 1U;
	}
	return result;
}
tF64 tF64_Sine_fast(tF64 ang)
{
	tBln neg = False;
	if (tF64_Nearby(ang, 0.0)) return 0.0;
	while (ang > tF64_2Pi) ang -= tF64_2Pi;
	ang -= (tF64)((tS64)(ang * tF64_Inv2Pi)) * tF64_2Pi;
	if (ang < 0.0) ang += tF64_2Pi;
	if (ang > tF64_Pi)
	{
		ang -= tF64_Pi;
		neg = True;
	}
	const tF64 magicNum = ang * (tF64_Pi - ang);
	const tF64 res = (4.0 * magicNum) / (12.33700550 - magicNum);
	if (neg == True) return tF64_Neg(res);
	return res;
}
BQSE_FORCEINLINE tF64 tF64_Cosine_fast(tF64 ang)
{
	return tF64_Sine_fast(tF64_HalfPi - ang);
}
tF64 tF64_Tangent_fast(tF64 ang)
{
	const tF64 cosAng = tF64_Cosine_fast(ang);
	if (tF64_Nearby(cosAng, 0.0)) return tF64_IsNeg(cosAng) ? tF64_NegInf() : tF64_Inf();
	const tF64 sinAng = tF64_Sine_fast(ang);
	return sinAng / cosAng;
}
tF64 tF64_Sine_iter(tF64 ang, tUSz itr)
{
	if (tF64_Nearby(ang, 0.0)) return 0.0;
	if (itr == 0U) return ang;
	while (ang > tF64_2Pi) ang -= tF64_2Pi;
	ang -= (tF64)((tS64)(ang * tF64_Inv2Pi)) * tF64_2Pi;
	tBln neg = False;
	if (ang > tF64_Pi)
	{
		ang -= tF64_Pi;
		neg = True;
	}
	const tF64 angSq = ang * ang;
	tF64 term = ang;
	tF64 res = term;
	for (tUSz idx = 0U; idx < itr; ++idx)
	{
		const tF64 denom = (tF64)((2U * idx + 2U) * (2U * idx + 3U));
		term *= -angSq / denom;
		res += term;
	}
	if (neg == True) return tF64_Neg(res);
	return res;
}
BQSE_FORCEINLINE tF64 tF64_Cosine_iter(tF64 ang, tUSz itr)
{
	return tF64_Sine_iter(tF64_HalfPi - ang, itr);
}
tF64 tF64_Tangent_iter(tF64 ang, tUSz itr)
{
	const tF64 cosAng = tF64_Cosine_iter(ang, itr);
	const tF64 sinAng = tF64_Sine_iter(ang, itr);
	if (tF64_Nearby(cosAng, 0.0)) return tF64_IsNeg(sinAng) ? tF64_NegInf() : tF64_Inf();
	return sinAng / cosAng;
}
BQSE_FORCEINLINE tF64 tF64_Sine(tF64 ang)
{
	return tF64_Sine_iter(ang, BQSE_TRIG_ITER);
}
BQSE_FORCEINLINE tF64 tF64_Cosine(tF64 ang)
{
	return tF64_Cosine_iter(ang, BQSE_TRIG_ITER);
}
BQSE_FORCEINLINE tF64 tF64_Tangent(tF64 ang)
{
	return tF64_Tangent_iter(ang, BQSE_TRIG_ITER);
}
tF64 tF64_ArcSine_iter(tF64 num, tUSz sqrtItr, tUSz trigItr)
{
#ifndef BQSE_DEBUG
	if (tF64_Abs(num) > 1.0) return tF64_SigNaN();
#else
	Assertion(tF64_Abs(num) <= 1.0);
#endif
	if (tF64_Nearby(num, 1.0))  return tF64_HalfPi;
	if (tF64_Nearby(num, -1.0)) return -tF64_HalfPi;
	return tF64_ArcTangent_iter(num / tF64_Sqrt_iter(1 - (num * num), sqrtItr), trigItr);
}
tF64 tF64_ArcSine(tF64 num)
{
#ifndef BQSE_DEBUG
	if (tF64_Abs(num) > 1.0) return tF64_SigNaN();
#else
	Assertion(tF64_Abs(num) > 1.0);
#endif
	if (tF64_Nearby(num, 1.0))  return tF64_HalfPi;
	if (tF64_Nearby(num, -1.0)) return -tF64_HalfPi;
	return tF64_ArcTangent(num / tF64_Sqrt(1 - (num * num)));
}
BQSE_FORCEINLINE tF64 tF64_ArcCosine_iter(tF64 num, tUSz sqrtItr, tUSz trigItr)
{
	return tF64_HalfPi - tF64_ArcSine_iter(num, sqrtItr, trigItr);
}
BQSE_FORCEINLINE tF64 tF64_ArcCosine(tF64 num)
{
	return tF64_HalfPi - tF64_ArcSine(num);
}
tF64 tF64_ArcTangent_iter(tF64 num, tUSz itr)
{
	if (itr == 0U) return num;
	if (num > 1.0) return tF64_HalfPi - tF64_ArcTangent_iter(1.0 / num, itr);
	if (num < -1.0) return -tF64_HalfPi - tF64_ArcTangent_iter(1.0 / num, itr);
	tF64 scale = 1.0;
	if (tF64_Abs(num) > 0.5)
	{
		num = num / (1.0 + tF64_Sqrt(1.0 + (num * num)));
		scale = 2.0;
	}
	const tF64 numSq = num * num;
	tF64 term = num;
	tF64 res = term;
	for (tUSz idx = 0U; idx < itr; ++idx)
	{
		tUSz idx2 = idx << 1;
		term *= -numSq * ((tF64)(idx2 + 1U) / (tF64)(idx2 + 3U));
		res += term;
	}
	return scale * res;
}
BQSE_FORCEINLINE tF64 tF64_ArcTangent(tF64 num)
{
	return tF64_ArcTangent_iter(num, BQSE_TRIG_ITER);
}
tF64 tF64_ArcTangent2_iter(tF64 opp, tF64 adj, tUSz itr)
{
	if (adj > 0.0) return tF64_ArcTangent_iter(opp / adj, itr);
	if (adj < 0.0 && opp >= 0.0) return tF64_ArcTangent_iter(opp / adj, itr) + tF64_Pi;
	if (adj < 0.0 && opp < 0.0) return tF64_ArcTangent_iter(opp / adj, itr) - tF64_Pi;
	if (tF64_Nearby(adj, 0.0) && opp > 0.0) return tF64_HalfPi;
	if (tF64_Nearby(adj, 0.0) && opp < 0.0) return -tF64_HalfPi;
	return 0.0;
}
BQSE_FORCEINLINE tF64 tF64_ArcTangent2(tF64 opp, tF64 adj)
{
	return tF64_ArcTangent2_iter(opp, adj, BQSE_TRIG_ITER);
}
tF64 tF64_InvSqrt_iter(tF64 num, tUSz itr)
{
#ifndef BQSE_DEBUG
	if (num < 0.0) return tF64_SigNaN();
#else
	Assertion(num >= 0.0);
#endif
	static const tF64 threeHalfs = 1.5;
	tF64Bits number;
	number.dbl = num;
	tF64 halfNum = number.dbl * 0.5;
	number.raw = 0X5FE6EC85E7DE30DAULL - (number.raw >> 1U);
	for (tUSz idx = 0U; idx < itr; ++idx) number.dbl = number.dbl * (threeHalfs - (halfNum * number.dbl * number.dbl));
	return number.dbl;
}
BQSE_FORCEINLINE tF64 tF64_InvSqrt(tF64 num)
{
	return tF64_InvSqrt_iter(num, 1U);
}
BQSE_FORCEINLINE tF64 tF64_Sqrt_iter(tF64 num, tUSz itr)
{
	return num * tF64_InvSqrt_iter(num, itr);
}
BQSE_FORCEINLINE tF64 tF64_Sqrt(tF64 num)
{
	return num * tF64_InvSqrt(num);
}
tF64 tF64_Log2_iter(tF64 num, tUSz itr)
{
#ifndef BQSE_DEBUG
	if (num <= 0.0) return tF64_SigNaN();
#else
	Assertion(num > 0.0F);
#endif
	tF64Bits numBits;
	numBits.dbl = num;
	tS32 expVal = (tS32)(((numBits.raw >> 52U) & 0x7FFULL) - 1023ULL);
	tF64Bits mantBits;
	mantBits.raw = (numBits.raw & 0xFFFFFFFFFFFFFULL) | (1023ULL << 52U);
	tBln sub = True;
	const tF64 valX = mantBits.dbl - 1.0;
	tF64 mantApprox = valX;
	tF64 powVal = mantApprox;
	for (tUSz idx = 2U; idx < itr + 2U; ++idx)
	{
		powVal *= valX;
		if (sub) mantApprox -= powVal / (tF64)idx;
		else mantApprox += powVal / (tF64)idx;
		sub = !sub;
	}
	return (tF64)expVal + (mantApprox * tF64_Log2EulNum);
}
BQSE_FORCEINLINE tF64 tF64_Log2(tF64 num)
{
	return tF64_Log2_iter(num, 4U);
}
BQSE_FORCEINLINE tF64 tF64_Ln_iter(tF64 num, tUSz itr)
{
	return tF64_Log2_iter(num, itr) / tF64_Log2EulNum;
}
BQSE_FORCEINLINE tF64 tF64_Ln(tF64 num)
{
	return tF64_Log2(num) / tF64_Log2EulNum;
}
tF64 tF64_Log_iter(tF64 num, tF64 base, tUSz itr)
{
#ifndef BQSE_DEBUG
	if (base <= 0.0 || tF64_Nearby(base, 1.0)) return tF64_SigNaN();
#else
	Assertion(base > 0.0F && !tF64_Nearby(base, 1.0));
#endif
	return tF64_Log2_iter(num, itr) / tF64_Log2_iter(base, itr);
}
tF64 tF64_Log(tF64 num, tF64 base)
{
#ifndef BQSE_DEBUG
	if (base <= 0.0 || tF64_Nearby(base, 1.0)) return tF64_SigNaN();
#else
	Assertion(base > 0.0F && !tF64_Nearby(base, 1.0));
#endif
	return tF64_Log2(num) / tF64_Log2(base);
}
BQSE_FORCEINLINE tF64 tF64_Lerp(tF64 strt, tF64 stp, tF64 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
BQSE_FORCEINLINE tF64 tF64_Unlerp(tF64 strt, tF64 curr, tF64 fnsh)
{
	if (tF64_Nearby(strt, fnsh)) return 0.0;
	return (curr - strt) / (fnsh - strt);
}
tF64 tF64_Exp_iter(tF64 pow, tUSz itr)
{
	if (tF64_Nearby(pow, 0.0)) return 1.0;
	if (tF64_Nearby(pow, 1.0)) return tF64_EulNum;
	tF64 res = 1.0;
	tF64 term = 1.0;
	for (tUSz idx = 1U; idx <= itr; ++idx)
	{
		term *= pow / (tF64)idx;
		res += term;
	}
	return res;
}
BQSE_FORCEINLINE tF64 tF64_Exp(tF64 pow)
{
	return tF64_Exp_iter(pow, 10U);
}
BQSE_FORCEINLINE tF64 tF64_HypSine_iter(tF64 num, tUSz itr)
{
	tF64 expNum = tF64_Exp_iter(num, itr);
	return (expNum - (1.0 / expNum)) * 0.5;
}
BQSE_FORCEINLINE tF64 tF64_HypCosine_iter(tF64 num, tUSz itr)
{
	tF64 expNum = tF64_Exp_iter(num, itr);
	return (expNum + (1.0 / expNum)) * 0.5;
}
tF64 tF64_HypTangent_iter(tF64 num, tUSz itr)
{
	tF64 expNum = tF64_Exp_iter(num, itr);
	tF64 invExpNum = 1.0 / expNum;
	const tF64 hypSine = (expNum - invExpNum) * 0.5;
	const tF64 hypCosine = (expNum + invExpNum) * 0.5;
	return hypSine / hypCosine;
}
BQSE_FORCEINLINE tF64 tF64_HypSine(tF64 num)
{
	tF64 expNum = tF64_Exp(num);
	return (expNum - (1.0 / expNum)) * 0.5;
}
BQSE_FORCEINLINE tF64 tF64_HypCosine(tF64 num)
{
	tF64 expNum = tF64_Exp(num);
	return (expNum + (1.0 / expNum)) * 0.5;
}
BQSE_FORCEINLINE tF64 tF64_HypTangent(tF64 num)
{
	tF64 expNum = tF64_Exp(num);
	tF64 invExpNum = 1.0 / expNum;
	const tF64 hypSine = (expNum - invExpNum) * 0.5;
	const tF64 hypCosine = (expNum + invExpNum) * 0.5;
	return hypSine / hypCosine;
}
tF64 tF64_Mod(tF64 num, tF64 denom)
{
#ifndef BQSE_DEBUG
	if (tF64_Nearby(denom, 0.0)) return tF64_SigNaN();
#else
	Assertion(!tF64_Nearby(denom, 0.0));
#endif
	tS64 quot = (tS64)(num / denom);
	return num - ((tF64)quot * denom);
}
#endif/*BQSE_IMPL*/
#ifdef BQSE_IMPL
#undef BQSE_TRIG_ITER
#endif/*BQSE_IMPL*/
#define BQSE_DECLARE_MINMAXCLAMPSWAP(tType)								\
tType tType##_MinOf(tType Num1, tType Num2);							\
tType tType##_MaxOf(tType Num1, tType Num2);							\
tType tType##_Clamp(tType Lo, tType Num, tType Hi);						\
tType tType##_ClampTop(tType Num1, tType Num2);							\
tType tType##_ClampBot(tType Num1, tType Num2);							\
tNone tType##_Swap(tType *Num1, tType *Num2);
#ifdef BQSE_IMPL
#define BQSE_DEFINE_MINMAXCLAMPSWAP(tType)								\
BQSE_FORCEINLINE tType tType##_MinOf(tType Num1, tType Num2)			\
{																		\
	return Num1 < Num2 ? Num1 : Num2;									\
}																		\
BQSE_FORCEINLINE tType tType##_MaxOf(tType Num1, tType Num2)			\
{																		\
	return Num1 > Num2 ? Num1 : Num2;									\
}																		\
BQSE_FORCEINLINE tType tType##_Clamp(tType Lo, tType Num, tType Hi)		\
{																		\
	return (Num < Lo) ? Lo : (Hi < Num) ? Hi : Num; 					\
}																		\
BQSE_FORCEINLINE tType tType##_ClampTop(tType Num1, tType Num2)			\
{																		\
	return Num1 < Num2 ? Num1 : Num2;									\
}																		\
BQSE_FORCEINLINE tType tType##_ClampBot(tType Num1, tType Num2)			\
{																		\
	return Num1 > Num2 ? Num1 : Num2;									\
}																		\
BQSE_FORCEINLINE tNone tType##_Swap(tType *Num1, tType *Num2)		    \
{																		\
	tType tmp = *Num1;													\
	*Num1 = *Num2;												 	    \
	*Num2 = tmp;														\
}
#endif/*BQSE_IMPL*/
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
#define OffsetOf(tType, Memb) ((tUSz)&(((tType *)0U)->Memb))
#define MemberSize(tType, Memb) (sizeof(((tType *)0U)->Memb))
LINK_C_Begin
BQSE_DECLARE_MINMAXCLAMPSWAP(tSSz);
BQSE_DECLARE_MINMAXCLAMPSWAP(tUSz);
BQSE_DECLARE_MINMAXCLAMPSWAP(tS8);
BQSE_DECLARE_MINMAXCLAMPSWAP(tU8);
BQSE_DECLARE_MINMAXCLAMPSWAP(tS16);
BQSE_DECLARE_MINMAXCLAMPSWAP(tU16);
BQSE_DECLARE_MINMAXCLAMPSWAP(tS32);
BQSE_DECLARE_MINMAXCLAMPSWAP(tU32);
BQSE_DECLARE_MINMAXCLAMPSWAP(tS64);
BQSE_DECLARE_MINMAXCLAMPSWAP(tU64);
BQSE_DECLARE_MINMAXCLAMPSWAP(tF32);
BQSE_DECLARE_MINMAXCLAMPSWAP(tF64);
LINK_C_End
#ifdef BQSE_IMPL
BQSE_DEFINE_MINMAXCLAMPSWAP(tSSz);
BQSE_DEFINE_MINMAXCLAMPSWAP(tUSz);
BQSE_DEFINE_MINMAXCLAMPSWAP(tS8);
BQSE_DEFINE_MINMAXCLAMPSWAP(tU8);
BQSE_DEFINE_MINMAXCLAMPSWAP(tS16);
BQSE_DEFINE_MINMAXCLAMPSWAP(tU16);
BQSE_DEFINE_MINMAXCLAMPSWAP(tS32);
BQSE_DEFINE_MINMAXCLAMPSWAP(tU32);
BQSE_DEFINE_MINMAXCLAMPSWAP(tS64);
BQSE_DEFINE_MINMAXCLAMPSWAP(tU64);
BQSE_DEFINE_MINMAXCLAMPSWAP(tF32);
BQSE_DEFINE_MINMAXCLAMPSWAP(tF64);
#undef BQSE_DEFINE_MINMAXCLAMPSWAP
#endif/*BQSE_IMPL*/
#undef BQSE_DECLARE_MINMAXCLAMPSWAP
#if ARCH_Bitness == 64
typedef tF64 tFSz;
#else
typedef tF32 tFSz;
#endif/*ARCH_Bitness*/
#endif/*BQSELAYER_PRIMTYPES_H*/