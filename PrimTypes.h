#ifndef BQSELAYER_PRIMTYPES_H
#define BQSELAYER_PRIMTYPES_H
#include "CtxCrack.h"
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
typedef tNone tFPnc(tNone);
typedef tFPnc *tFPncPtr;
typedef tGen *tPtr;
#define Null ((tPtr)0U)
typedef char tChr;
typedef char signed tIS8;
#define tIS8_Max 127
#define tIS8_Min (-128)
typedef char unsigned tIU8;
#define tIU8_Max 255
#define tIU8_Min 0
typedef short signed tIS16;
#define tIS16_Max 32767
#define tIS16_Min (-32768)
typedef short unsigned tIU16;
#define tIU16_Max 65535
#define tIU16_Min 0
typedef int signed tIS32;
#define tIS32_Max 2147483647
#define tIS32_Min (-2147483647-1)
typedef int unsigned tIU32;
#define tIU32_Max 4294967295U
#define tIU32_Min 0U
LINK_C_Begin
tIU32 tIU32_Fact(tIU32 base);
LINK_C_End
#ifdef BQSELAYER_PRIMTYPES_IMPL
tIU32 tIU32_Fact(tIU32 base)
{
	if (base == 0U || base == 1U) return 1U;
	const tIU32 itr = base;
	for (tIU32 idx = 2U; idx < itr; ++idx) base *= idx;
	return base;
}
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
typedef long long signed tIS64;
#define tIS64_Max 9223372036854775807LL
#define tIS64_Min (-9223372036854775807LL-1)
typedef long long unsigned tIU64;
#define tIU64_Max 18446744073709551615LLU
#define tIU64_Min 0LLU
LINK_C_Begin
tIU64 tIU64_Fact(tIU64 base);
LINK_C_End
#ifdef BQSELAYER_PRIMTYPES_IMPL
tIU64 tIU64_Fact(tIU64 base)
{
	if (base == 0U || base == 1U) return 1U;
	const tIU64 itr = base;
	for (tIU64 idx = 2U; idx < itr; ++idx) base *= idx;
	return base;
}
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
#if ARCH_Bitness == 64
typedef tIS64 tISSz;
typedef tIU64 tIUSz;
#else
typedef tIS32 tISSz;
typedef tIU32 tIUSz;
#endif/*ARCH_Bitness*/
#ifdef BQSELAYER_PRIMTYPES_IMPL
#define BQSELAYER_TRIG_ITER 7U
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
typedef float tFP32;
#define tFP32_Pi 3.141592653589793F
#define tFP32_2Pi 6.283185307F
#define tFP32_HalfPi 1.570796327F
#define tFP32_Inv2Pi 0.15915494309189535F
#define tFP32_Eps 1.19209290E-7F
#define tFP32_Tol 1E-5F
#define tFP32_EulNum 2.718281828459045F
#define tFP32_EulCnst 0.577215664901532F
#define tFP32_Log2EulNum 1.44269504089F
#define tFP32_RadToDeg(flt) ((flt) * 57.29577951308233F)
#define tFP32_DegToRad(flt) ((flt) * 0.0174532925199433F)
LINK_C_Begin
ForceInline tFP32 tFP32_Inf(tNone);
ForceInline tFP32 tFP32_Abs(tFP32 flt);
ForceInline tFP32 tFP32_Neg(tFP32 flt);
ForceInline tBln tFP32_IsNeg(tFP32 flt);
ForceInline tFP32 tFP32_NegInf(tNone);
ForceInline tFP32 tFP32_QuiNaN(tNone);
ForceInline tFP32 tFP32_SigNaN(tNone);
ForceInline tBln tFP32_Nearby(tFP32 flt, tFP32 cmp);
/*Note: Parameter `ang` is expected to be in radians.*/
tFP32 tFP32_Sine_fast(tFP32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP32 tFP32_Cosine_fast(tFP32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tFP32 tFP32_Tangent_fast(tFP32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tFP32 tFP32_Sine_iter(tFP32 ang, tIUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP32 tFP32_Cosine_iter(tFP32 ang, tIUSz itr);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
tFP32 tFP32_Tangent_iter(tFP32 ang, tIUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP32 tFP32_Sine(tFP32 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP32 tFP32_Cosine(tFP32 ang);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
ForceInline tFP32 tFP32_Tangent(tFP32 ang);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tFP32 tFP32_ArcSine_iter(tFP32 num, tIUSz sqrtItr, tIUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tFP32 tFP32_ArcSine(tFP32 num);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
ForceInline tFP32 tFP32_ArcCosine_iter(tFP32 num, tIUSz sqrtItr, tIUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
ForceInline tFP32 tFP32_ArcCosine(tFP32 num);
tFP32 tFP32_ArcTangent_iter(tFP32 num, tIUSz itr);
ForceInline tFP32 tFP32_ArcTangent(tFP32 num);
tFP32 tFP32_ArcTangent2_iter(tFP32 opp, tFP32 adj, tIUSz itr);
ForceInline tFP32 tFP32_ArcTangent2(tFP32 opp, tFP32 adj);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
tFP32 tFP32_RecipSqrt_iter(tFP32 num, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
ForceInline tFP32 tFP32_RecipSqrt(tFP32 num);
ForceInline tFP32 tFP32_Sqrt_iter(tFP32 num, tIUSz itr);
ForceInline tFP32 tFP32_Sqrt(tFP32 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tFP32 tFP32_Log2_iter(tFP32 num, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
ForceInline tFP32 tFP32_Log2(tFP32 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
ForceInline tFP32 tFP32_Ln_iter(tFP32 num, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
ForceInline tFP32 tFP32_Ln(tFP32 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tFP32 tFP32_Log_iter(tFP32 num, tFP32 base, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tFP32 tFP32_Log(tFP32 num, tFP32 base);
ForceInline tFP32 tFP32_Lerp(tFP32 strt, tFP32 stp, tFP32 fnsh);
ForceInline tFP32 tFP32_Unlerp(tFP32 strt, tFP32 curr, tFP32 fnsh);
tFP32 tFP32_Exp_iter(tFP32 pow, tIUSz itr);
ForceInline tFP32 tFP32_Exp(tFP32 pow);
ForceInline tFP32 tFP32_HypSine_iter(tFP32 num, tIUSz itr);
ForceInline tFP32 tFP32_HypCosine_iter(tFP32 num, tIUSz itr);
tFP32 tFP32_HypTangent_iter(tFP32 num, tIUSz itr);
ForceInline tFP32 tFP32_HypSine(tFP32 num);
ForceInline tFP32 tFP32_HypCosine(tFP32 num);
ForceInline tFP32 tFP32_HypTangent(tFP32 num);
tFP32 tFP32_Mod(tFP32 num, tFP32 denom);
tFP32 tFP32_PowI(tFP32 num, tISSz pow);
tFP32 tFP32_Pow_iter(tFP32 num, tFP32 pow, tIUSz itr);
tFP32 tFP32_Pow(tFP32 num, tFP32 pow);
tFP32 tFP32_Round(tFP32 num);
ForceInline tFP32 tFP32_Recip(tFP32 num);
LINK_C_End
#define tFP32_SignMask 0X80000000U
#define tFP32_ExpoMask 0X7F800000U
#define tFP32_FracMask 0X007FFFFFU
typedef union
{
	tFP32 flt;
	tIU32 raw;
}
tFP32Bits;
#ifdef BQSELAYER_PRIMTYPES_IMPL
ForceInline tBln tFP32_IsNeg(tFP32 flt)
{
	if (tFP32_Nearby(flt, 0.0F)) return False;
	tFP32Bits num;
	num.flt = flt;
	return (tBln)!!(num.raw & tFP32_SignMask);
}
ForceInline tFP32 tFP32_Inf(tNone)
{
	tFP32Bits num;
	num.raw = 0X7F800000U;
	return num.flt;
}
ForceInline tFP32 tFP32_Abs(tFP32 flt)
{
	tFP32Bits num;
	num.flt = flt;
	num.raw &= 0X7FFFFFFFU;
	return num.flt;
}
ForceInline tFP32 tFP32_Neg(tFP32 flt)
{
	tFP32Bits num;
	num.flt = flt;
	num.raw ^= 0X80000000U;
	return num.flt;
}
ForceInline tFP32 tFP32_NegInf(tNone)
{
	tFP32Bits num;
	num.raw = 0XFF800000U;
	return num.flt;
}
ForceInline tFP32 tFP32_QuiNaN(tNone)
{
	tFP32Bits num;
	num.raw = 0XFFC00001U;
	return num.flt;
}
ForceInline tFP32 tFP32_SigNaN(tNone)
{
	tFP32Bits num;
	num.raw = 0XFF800001U;
	return num.flt;
}
ForceInline tBln tFP32_Nearby(tFP32 flt, tFP32 cmp)
{
	return tFP32_Abs(flt - cmp) <= tFP32_Eps;
}
tFP32 tFP32_Sine_fast(tFP32 ang)
{
	tBln neg = False;
	if (tFP32_Nearby(ang, 0.0F)) return 0.0F;
	ang -= (tFP32)((tIS32)(ang * tFP32_Inv2Pi)) * tFP32_2Pi;
	if (tFP32_IsNeg(ang)) ang += tFP32_2Pi;
	if (ang > tFP32_Pi)
	{
		ang -= tFP32_Pi;
		neg = True;
	}
	const tFP32 magicNum = ang * (tFP32_Pi - ang);
	const tFP32 res = (4.0F * magicNum) / (12.33700550F - magicNum);
	if (neg == True) return tFP32_Neg(res);
	return res;
}
ForceInline tFP32 tFP32_Cosine_fast(tFP32 ang)
{
	return tFP32_Sine_fast(tFP32_HalfPi - ang);
}
tFP32 tFP32_Tangent_fast(tFP32 ang)
{
	const tFP32 cosAng = tFP32_Cosine_fast(ang);
	if (tFP32_Nearby(cosAng, 0.0F)) return tFP32_IsNeg(cosAng) ? tFP32_NegInf() : tFP32_Inf();
	const tFP32 sinAng = tFP32_Sine_fast(ang);
	return sinAng / cosAng;
}
tFP32 tFP32_Sine_iter(tFP32 ang, tIUSz itr)
{
	if (tFP32_Nearby(ang, 0.0F)) return 0.0F;
	if (itr == 0U) return ang;
	ang -= (tFP32)((tIS32)(ang * tFP32_Inv2Pi)) * tFP32_2Pi;
	if (tFP32_IsNeg(ang)) ang += tFP32_2Pi;
	tBln neg = False;
	if (ang > tFP32_Pi)
	{
		ang -= tFP32_Pi;
		neg = True;
	}
	const tFP32 angSq = ang * ang;
	tFP32 term = ang;
	tFP32 res = term;
	for (tIUSz idx = 0U; idx < itr; ++idx)
	{
		const tFP32 denom = (tFP32)((2U * idx + 2U) * (2U * idx + 3U));
		term *= -angSq / denom;
		res += term;
	}
	if (neg == True) return tFP32_Neg(res);
	return res;
}
ForceInline tFP32 tFP32_Cosine_iter(tFP32 ang, tIUSz itr)
{
	return tFP32_Sine_iter(tFP32_HalfPi - ang, itr);
}
tFP32 tFP32_Tangent_iter(tFP32 ang, tIUSz itr)
{
	const tFP32 cosAng = tFP32_Cosine_iter(ang, itr);
	const tFP32 sinAng = tFP32_Sine_iter(ang, itr);
	if (tFP32_Nearby(cosAng, 0.0F)) return tFP32_IsNeg(sinAng) ? tFP32_NegInf() : tFP32_Inf();
	return sinAng / cosAng;
}
ForceInline tFP32 tFP32_Sine(tFP32 ang)
{
	return tFP32_Sine_iter(ang, BQSELAYER_TRIG_ITER);
}
ForceInline tFP32 tFP32_Cosine(tFP32 ang)
{
	return tFP32_Cosine_iter(ang, BQSELAYER_TRIG_ITER);
}
ForceInline tFP32 tFP32_Tangent(tFP32 ang)
{
	return tFP32_Tangent_iter(ang, BQSELAYER_TRIG_ITER);
}
tFP32 tFP32_ArcSine_iter(tFP32 num, tIUSz sqrtItr, tIUSz trigItr)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_Abs(num) > 1.0F) return tFP32_SigNaN();
#else
	Assertion(tFP32_Abs(num) <= 1.0F);
#endif/*BQSELAYER_DEBUG*/
	if (tFP32_Nearby(num, 1.0F))  return tFP32_HalfPi;
	if (tFP32_Nearby(num, -1.0F)) return -tFP32_HalfPi;
	return tFP32_ArcTangent_iter(num / tFP32_Sqrt_iter(1 - (num * num), sqrtItr), trigItr);
}
tFP32 tFP32_ArcSine(tFP32 num)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_Abs(num) > 1.0F) return tFP32_SigNaN();
#else
	Assertion(tFP32_Abs(num) <= 1.0F);
#endif/*BQSELAYER_DEBUG*/
	if (tFP32_Nearby(num, 1.0F))  return tFP32_HalfPi;
	if (tFP32_Nearby(num, -1.0F)) return -tFP32_HalfPi;
	return tFP32_ArcTangent(num / tFP32_Sqrt(1 - (num * num)));
}
ForceInline tFP32 tFP32_ArcCosine_iter(tFP32 num, tIUSz sqrtItr, tIUSz trigItr)
{
	return tFP32_HalfPi - tFP32_ArcSine_iter(num, sqrtItr, trigItr);
}
ForceInline tFP32 tFP32_ArcCosine(tFP32 num)
{
	return tFP32_HalfPi - tFP32_ArcSine(num);
}
tFP32 tFP32_ArcTangent_iter(tFP32 num, tIUSz itr)
{
	if (itr == 0U) return num;
	if (num > 1.0F) return tFP32_HalfPi - tFP32_ArcTangent_iter(tFP32_Recip(num), itr);
	if (num < -1.0F) return -tFP32_HalfPi - tFP32_ArcTangent_iter(tFP32_Recip(num), itr);
	tFP32 scale = 1.0F;
	if (tFP32_Abs(num) > 0.5F)
	{
		num = num / (1.0F + tFP32_Sqrt(1.0F + (num * num)));
		scale = 2.0F;
	}
	const tFP32 numSq = num * num;
	tFP32 term = num;
	tFP32 res = term;
	for (tIUSz idx = 0U; idx < itr; ++idx)
	{
		tIUSz idx2 = idx << 1;
		term *= -numSq * ((tFP32)(idx2 + 1U) / (tFP32)(idx2 + 3U));
		res += term;
	}
	return scale * res;
}
ForceInline tFP32 tFP32_ArcTangent(tFP32 num)
{
	return tFP32_ArcTangent_iter(num, BQSELAYER_TRIG_ITER);
}
tFP32 tFP32_ArcTangent2_iter(tFP32 opp, tFP32 adj, tIUSz itr)
{
	if (adj > 0.0F) return tFP32_ArcTangent_iter(opp / adj, itr);
	if (tFP32_IsNeg(adj) && !tFP32_IsNeg(opp)) return tFP32_ArcTangent_iter(opp / adj, itr) + tFP32_Pi;
	if (tFP32_IsNeg(adj) && tFP32_IsNeg(opp)) return tFP32_ArcTangent_iter(opp / adj, itr) - tFP32_Pi;
	if (tFP32_Nearby(adj, 0.0F) && opp > 0.0F) return tFP32_HalfPi;
	if (tFP32_Nearby(adj, 0.0F) && tFP32_IsNeg(opp)) return -tFP32_HalfPi;
	return 0.0F;
}
ForceInline tFP32 tFP32_ArcTangent2(tFP32 opp, tFP32 adj)
{
	return tFP32_ArcTangent2_iter(opp, adj, BQSELAYER_TRIG_ITER);
}
tFP32 tFP32_RecipSqrt_iter(tFP32 num, tIUSz itr)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNeg(num)) return tFP32_SigNaN();
	if (tFP32_Nearby(num, 0.0F)) return tFP32_Inf();
#else
	Assertion(num > 0.0F);
#endif/*BQSELAYER_DEBUG*/
	tFP32Bits number;
	number.flt = num;
	tFP32 halfNum = number.flt * 0.5F;
	number.raw = 0X5F3759DFU - (number.raw >> 1U);
	for (tIUSz idx = 0U; idx < itr; ++idx) number.flt = number.flt * (1.5F - (halfNum * number.flt * number.flt));
	return number.flt;
}
ForceInline tFP32 tFP32_RecipSqrt(tFP32 num)
{
	return tFP32_RecipSqrt_iter(num, 1U);
}
ForceInline tFP32 tFP32_Sqrt_iter(tFP32 num, tIUSz itr)
{
#ifndef BQSELAYER_DBG
	if (tFP32_IsNeg(num)) return tFP32_SigNaN();
#else
	Assertion(!tFP32_IsNeg(num));
#endif/*BQSELAYER_DBG*/
	if (tFP32_Nearby(num, 0.0F)) return 0.0F;
	return num * tFP32_RecipSqrt_iter(num, itr);
}
ForceInline tFP32 tFP32_Sqrt(tFP32 num)
{
#ifndef BQSELAYER_DBG
	if (tFP32_IsNeg(num)) return tFP32_SigNaN();
#else
	Assertion(!tFP32_IsNeg(num));
#endif/*BQSELAYER_DBG*/
	if (tFP32_Nearby(num, 0.0F)) return 0.0F;
	return num * tFP32_RecipSqrt(num);
}
tFP32 tFP32_Log2_iter(tFP32 num, tIUSz itr)
{
#ifndef BQSELAYER_DEBUG
	if (num <= 0.0F) return tFP32_SigNaN();
#else
	Assertion(num > 0.0F);
#endif/*BQSELAYER_DEBUG*/
	tFP32Bits numBits;
	numBits.flt = num;
	tIS16 expVal = ((numBits.raw >> 23U) & tIU8_Max) - 127;
	tFP32Bits mantBits;
	mantBits.raw = (numBits.raw & 0X7FFFFFU) | (127U << 23U);
	tBln sub = True;
	const tFP32 valX = mantBits.flt - 1.0F;
	tFP32 mantApprox = valX;
	tFP32 powVal = mantApprox;
	for (tIUSz idx = 2U; idx < itr + 2U; ++idx)
	{
		powVal *= valX;
		if (sub) mantApprox -= powVal / (tFP32)idx;
		else mantApprox += powVal / (tFP32)idx;
		sub = !sub;
	}
	return (tFP32)expVal + (mantApprox * tFP32_Log2EulNum);
}
ForceInline tFP32 tFP32_Log2(tFP32 num)
{
	return tFP32_Log2_iter(num, 4U);
}
ForceInline tFP32 tFP32_Ln_iter(tFP32 num, tIUSz itr)
{
	return tFP32_Log2_iter(num, itr) / tFP32_Log2EulNum;
}
ForceInline tFP32 tFP32_Ln(tFP32 num)
{
	return tFP32_Log2(num) / tFP32_Log2EulNum;
}
tFP32 tFP32_Log_iter(tFP32 num, tFP32 base, tIUSz itr)
{
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0F || tFP32_Nearby(base, 1.0F)) return tFP32_SigNaN();
#else
	Assertion(base > 0.0F && !tFP32_Nearby(base, 1.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32_Log2_iter(num, itr) / tFP32_Log2_iter(base, itr);
}
tFP32 tFP32_Log(tFP32 num, tFP32 base)
{
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0F || tFP32_Nearby(base, 1.0F)) return tFP32_SigNaN();
#else
	Assertion(base > 0.0F && !tFP32_Nearby(base, 1.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32_Log2(num) / tFP32_Log2(base);
}
ForceInline tFP32 tFP32_Lerp(tFP32 strt, tFP32 stp, tFP32 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
ForceInline tFP32 tFP32_Unlerp(tFP32 strt, tFP32 curr, tFP32 fnsh)
{
	if (tFP32_Nearby(strt, fnsh)) return 0.0F;
	return (curr - strt) / (fnsh - strt);
}
tFP32 tFP32_Exp_iter(tFP32 pow, tIUSz itr)
{
	if (tFP32_Nearby(pow, 0.0F)) return 1.0F;
	if (tFP32_Nearby(pow, 1.0F)) return tFP32_EulNum;
	tFP32 res = 1.0F;
	tFP32 term = 1.0F;
	for (tIUSz idx = 1U; idx <= itr; ++idx)
	{
		term *= pow / (tFP32)idx;
		res += term;
	}
	return res;
}
ForceInline tFP32 tFP32_Exp(tFP32 pow)
{
	return tFP32_Exp_iter(pow, 10U);
}
ForceInline tFP32 tFP32_HypSine_iter(tFP32 num, tIUSz itr)
{
	tFP32 expNum = tFP32_Exp_iter(num, itr);
	return (expNum - tFP32_Recip(expNum)) * 0.5F;
}
ForceInline tFP32 tFP32_HypCosine_iter(tFP32 num, tIUSz itr)
{
	tFP32 expNum = tFP32_Exp_iter(num, itr);
	return (expNum + tFP32_Recip(expNum)) * 0.5F;
}
tFP32 tFP32_HypTangent_iter(tFP32 num, tIUSz itr)
{
	tFP32 expNum = tFP32_Exp_iter(num, itr);
	tFP32 invExpNum = tFP32_Recip(expNum);
	const tFP32 hypSine = (expNum - invExpNum) * 0.5F;
	const tFP32 hypCosine = (expNum + invExpNum) * 0.5F;
	return hypSine / hypCosine;
}
ForceInline tFP32 tFP32_HypSine(tFP32 num)
{
	tFP32 expNum = tFP32_Exp(num);
	return (expNum - tFP32_Recip(expNum)) * 0.5F;
}
ForceInline tFP32 tFP32_HypCosine(tFP32 num)
{
	tFP32 expNum = tFP32_Exp(num);
	return (expNum + tFP32_Recip(expNum)) * 0.5F;
}
tFP32 tFP32_HypTangent(tFP32 num)
{
	tFP32 expNum = tFP32_Exp(num);
	tFP32 invExpNum = tFP32_Recip(expNum);
	const tFP32 hypSine = (expNum - invExpNum) * 0.5F;
	const tFP32 hypCosine = (expNum + invExpNum) * 0.5F;
	return hypSine / hypCosine;
}
tFP32 tFP32_Mod(tFP32 num, tFP32 denom)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_Nearby(denom, 0.0F)) return tFP32_SigNaN();
#else
	Assertion(!tFP32_Nearby(denom, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	tIS32 quot = (tIS32)(num / denom);
	return num - ((tFP32)quot * denom);
}
tFP32 tFP32_PowI(tFP32 base, tISSz exp)
{
	if (exp == 0) return 1.0F;
	if (exp < 0) return tFP32_Recip(tFP32_PowI(base, -exp));
	tFP32 result = 1.0F;
	while (exp != 0)
	{
		if (exp & 1) result *= base;
		base *= base;
		exp >>= 1U;
	}
	return result;
}
tFP32 tFP32_Pow_iter(tFP32 base, tFP32 exp, tIUSz itr)
{
	tISSz intPart = (tISSz)exp;
	tFP32 whole = tFP32_PowI(base, intPart);
	if ((tFP32)intPart == exp) return whole;
	tFP32 fracPart = exp - (tFP32)intPart;
	if (tFP32_Nearby(fracPart, 0.5F)) return whole * tFP32_Sqrt_iter(base, itr);
	if (tFP32_Nearby(fracPart, -0.5F)) return whole * tFP32_RecipSqrt_iter(base, itr);
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0F) return tFP32_SigNaN();
#else
	Assertion(base > 0.0F);
#endif/*BQSELAYER_DEBUG*/
	return whole * tFP32_Exp_iter(fracPart * tFP32_Ln_iter(base, itr), itr);
}
tFP32 tFP32_Pow(tFP32 base, tFP32 exp)
{
	tISSz intPart = (tISSz)exp;
	tFP32 whole = tFP32_PowI(base, intPart);
	if ((tFP32)intPart == exp) return whole;
	tFP32 fracPart = exp - (tFP32)intPart;
	if (tFP32_Nearby(fracPart, 0.5F)) return whole * tFP32_Sqrt(base);
	if (tFP32_Nearby(fracPart, -0.5F)) return whole * tFP32_RecipSqrt(base);
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0F) return tFP32_SigNaN();
#else
	Assertion(base > 0.0F);
#endif/*BQSELAYER_DEBUG*/
	return whole * tFP32_Exp(fracPart * tFP32_Ln(base));
}
tFP32 tFP32_Round(tFP32 num)
{
	tISSz intPart = (tISSz)num;
	if (num == (tFP32)intPart) return num;
	if (tFP32_IsNeg(num)) return tFP32_Neg(tFP32_Round(tFP32_Neg(num)));
	tFP32 fracPart = num - (tFP32)intPart;
	if (fracPart < 0.5F) return (tFP32)intPart;
	else return (tFP32)intPart + 1.0F;
}
ForceInline tFP32 tFP32_Recip(tFP32 num)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_Nearby(num, 0.0F)) return tFP32_IsNeg(num) ? tFP32_Inf() : tFP32_NegInf();
#else
	Assertion(!tFP32_Nearby(num, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return 1.0F / num;
}
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
typedef double tFP64;
#define tFP64_Pi 3.141592653589793
#define tFP64_2Pi 6.283185307
#define tFP64_HalfPi 1.570796327
#define tFP64_Inv2Pi 0.15915494309189535
#define tFP64_Eps 2.2204460492503131E-16
#define tFP64_Tol 1E-5
#define tFP64_EulNum 2.718281828459045
#define tFP64_EulCnst 0.577215664901532
#define tFP64_Log2EulNum 1.44269504089
#define tFP64_RadToDeg(dbl) ((dbl) * 57.29577951308233)
#define tFP64_DegToRad(dbl) ((dbl) * 0.0174532925199433)
LINK_C_Begin
ForceInline tFP64 tFP64_Inf(tNone);
ForceInline tFP64 tFP64_Abs(tFP64 dbl);
ForceInline tFP64 tFP64_Neg(tFP64 dbl);
ForceInline tBln tFP64_IsNeg(tFP64 dbl);
ForceInline tFP64 tFP64_NegInf(tNone);
ForceInline tFP64 tFP64_QuiNaN(tNone);
ForceInline tFP64 tFP64_SigNaN(tNone);
ForceInline tBln tFP64_Nearby(tFP64 dbl, tFP64 cmp);
/*Note: Parameter `ang` is expected to be in radians.*/
tFP64 tFP64_Sine_fast(tFP64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP64 tFP64_Cosine_fast(tFP64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tFP64 tFP64_Tangent_fast(tFP64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
tFP64 tFP64_Sine_iter(tFP64 ang, tIUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP64 tFP64_Cosine_iter(tFP64 ang, tIUSz itr);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
tFP64 tFP64_Tangent_iter(tFP64 ang, tIUSz itr);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP64 tFP64_Sine(tFP64 ang);
/*Note: Parameter `ang` is expected to be in radians.*/
ForceInline tFP64 tFP64_Cosine(tFP64 ang);
/*Note: Parameter `ang` is expected to be in radians. Returns SigNan when `ang` is equal to integer multiples of Pi/2.*/
ForceInline tFP64 tFP64_Tangent(tFP64 ang);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tFP64 tFP64_ArcSine_iter(tFP64 num, tIUSz sqrtItr, tIUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
tFP64 tFP64_ArcSine(tFP64 num);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
ForceInline tFP64 tFP64_ArcCosine_iter(tFP64 num, tIUSz sqrtItr, tIUSz trigItr);
/*Note: Returns SigNaN when |`num`| is greater than 1.*/
ForceInline tFP64 tFP64_ArcCosine(tFP64 num);
tFP64 tFP64_ArcTangent_iter(tFP64 num, tIUSz itr);
ForceInline tFP64 tFP64_ArcTangent(tFP64 num);
tFP64 tFP64_ArcTangent2_iter(tFP64 opp, tFP64 adj, tIUSz itr);
ForceInline tFP64 tFP64_ArcTangent2(tFP64 opp, tFP64 adj);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
tFP64 tFP64_RecipSqrt_iter(tFP64 num, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than 0, and Inf when `num` is equal to 0.*/
ForceInline tFP64 tFP64_RecipSqrt(tFP64 num);
ForceInline tFP64 tFP64_Sqrt_iter(tFP64 num, tIUSz itr);
ForceInline tFP64 tFP64_Sqrt(tFP64 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tFP64 tFP64_Log2_iter(tFP64 num, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
ForceInline tFP64 tFP64_Log2(tFP64 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
ForceInline tFP64 tFP64_Ln_iter(tFP64 num, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
ForceInline tFP64 tFP64_Ln(tFP64 num);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tFP64 tFP64_Log_iter(tFP64 num, tFP64 base, tIUSz itr);
/*Note: Returns SigNaN when `num` is less than or equal to 0.*/
tFP64 tFP64_Log(tFP64 num, tFP64 base);
ForceInline tFP64 tFP64_Lerp(tFP64 strt, tFP64 stp, tFP64 fnsh);
ForceInline tFP64 tFP64_Unlerp(tFP64 strt, tFP64 curr, tFP64 fnsh);
tFP64 tFP64_Exp_iter(tFP64 pow, tIUSz itr);
ForceInline tFP64 tFP64_Exp(tFP64 pow);
ForceInline tFP64 tFP64_HypSine_iter(tFP64 num, tIUSz itr);
ForceInline tFP64 tFP64_HypCosine_iter(tFP64 num, tIUSz itr);
tFP64 tFP64_HypTangent_iter(tFP64 num, tIUSz itr);
ForceInline tFP64 tFP64_HypSine(tFP64 num);
ForceInline tFP64 tFP64_HypCosine(tFP64 num);
ForceInline tFP64 tFP64_HypTangent(tFP64 num);
tFP64 tFP64_Mod(tFP64 num, tFP64 denom);
tFP64 tFP64_PowI(tFP64 num, tISSz pow);
tFP64 tFP64_Pow_iter(tFP64 num, tFP64 pow, tIUSz itr);
tFP64 tFP64_Pow(tFP64 num, tFP64 pow);
tFP64 tFP64_Round(tFP64 num);
ForceInline tFP64 tFP64_Recip(tFP64 num);
LINK_C_End
#define tFP64_SignMask 0X8000000000000000LLU
#define tFP64_ExpoMask 0X7FF0000000000000LLU
#define tFP64_FracMask 0X000FFFFFFFFFFFFFLLU
typedef union
{
	tFP64 dbl;
	tIU64 raw;
}
tFP64Bits;
#ifdef BQSELAYER_PRIMTYPES_IMPL
ForceInline tFP64 tFP64_Inf(tNone)
{
	tFP64Bits num;
	num.raw = 0X7FF0000000000000LLU;
	return num.dbl;
}
ForceInline tFP64 tFP64_Abs(tFP64 dbl)
{
	tFP64Bits num;
	num.dbl = dbl;
	num.raw &= 0X7FFFFFFFFFFFFFFFLLU;
	return num.dbl;
}
ForceInline tBln tFP64_IsNeg(tFP64 dbl)
{
	if (tFP64_Nearby(dbl, 0.0)) return False;
	tFP64Bits num;
	num.dbl = dbl;
	return (tBln)!!(num.raw & tFP64_SignMask);
}
ForceInline tFP64 tFP64_Neg(tFP64 dbl)
{
	tFP64Bits num;
	num.dbl = dbl;
	num.raw ^= 0X8000000000000000LLU;
	return num.dbl;
}
ForceInline tFP64 tFP64_NegInf(tNone)
{
	tFP64Bits num;
	num.raw = 0XFFF0000000000000LLU;
	return num.dbl;
}
ForceInline tFP64 tFP64_QuiNaN(tNone)
{
	tFP64Bits num;
	num.raw = 0XFFF8000000000001LLU;
	return num.dbl;
}
ForceInline tFP64 tFP64_SigNaN(tNone)
{
	tFP64Bits num;
	num.raw = 0XFFF0000000000001LLU;
	return num.dbl;
}
ForceInline tBln tFP64_Nearby(tFP64 dbl, tFP64 cmp)
{
	return tFP64_Abs(dbl - cmp) <= tFP64_Eps;
}
tFP64 tFP64_Sine_fast(tFP64 ang)
{
	tBln neg = False;
	if (tFP64_Nearby(ang, 0.0)) return 0.0;
	while (ang > tFP64_2Pi) ang -= tFP64_2Pi;
	ang -= (tFP64)((tIS64)(ang * tFP64_Inv2Pi)) * tFP64_2Pi;
	if (tFP64_IsNeg(ang)) ang += tFP64_2Pi;
	if (ang > tFP64_Pi)
	{
		ang -= tFP64_Pi;
		neg = True;
	}
	const tFP64 magicNum = ang * (tFP64_Pi - ang);
	const tFP64 res = (4.0 * magicNum) / (12.33700550 - magicNum);
	if (neg == True) return tFP64_Neg(res);
	return res;
}
ForceInline tFP64 tFP64_Cosine_fast(tFP64 ang)
{
	return tFP64_Sine_fast(tFP64_HalfPi - ang);
}
tFP64 tFP64_Tangent_fast(tFP64 ang)
{
	const tFP64 cosAng = tFP64_Cosine_fast(ang);
	if (tFP64_Nearby(cosAng, 0.0)) return tFP64_IsNeg(cosAng) ? tFP64_NegInf() : tFP64_Inf();
	const tFP64 sinAng = tFP64_Sine_fast(ang);
	return sinAng / cosAng;
}
tFP64 tFP64_Sine_iter(tFP64 ang, tIUSz itr)
{
	if (tFP64_Nearby(ang, 0.0)) return 0.0;
	if (itr == 0U) return ang;
	while (ang > tFP64_2Pi) ang -= tFP64_2Pi;
	ang -= (tFP64)((tIS64)(ang * tFP64_Inv2Pi)) * tFP64_2Pi;
	tBln neg = False;
	if (ang > tFP64_Pi)
	{
		ang -= tFP64_Pi;
		neg = True;
	}
	const tFP64 angSq = ang * ang;
	tFP64 term = ang;
	tFP64 res = term;
	for (tIUSz idx = 0U; idx < itr; ++idx)
	{
		const tFP64 denom = (tFP64)((2U * idx + 2U) * (2U * idx + 3U));
		term *= -angSq / denom;
		res += term;
	}
	if (neg == True) return tFP64_Neg(res);
	return res;
}
ForceInline tFP64 tFP64_Cosine_iter(tFP64 ang, tIUSz itr)
{
	return tFP64_Sine_iter(tFP64_HalfPi - ang, itr);
}
tFP64 tFP64_Tangent_iter(tFP64 ang, tIUSz itr)
{
	const tFP64 cosAng = tFP64_Cosine_iter(ang, itr);
	const tFP64 sinAng = tFP64_Sine_iter(ang, itr);
	if (tFP64_Nearby(cosAng, 0.0)) return tFP64_IsNeg(sinAng) ? tFP64_NegInf() : tFP64_Inf();
	return sinAng / cosAng;
}
ForceInline tFP64 tFP64_Sine(tFP64 ang)
{
	return tFP64_Sine_iter(ang, BQSELAYER_TRIG_ITER);
}
ForceInline tFP64 tFP64_Cosine(tFP64 ang)
{
	return tFP64_Cosine_iter(ang, BQSELAYER_TRIG_ITER);
}
ForceInline tFP64 tFP64_Tangent(tFP64 ang)
{
	return tFP64_Tangent_iter(ang, BQSELAYER_TRIG_ITER);
}
tFP64 tFP64_ArcSine_iter(tFP64 num, tIUSz sqrtItr, tIUSz trigItr)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_Abs(num) > 1.0) return tFP64_SigNaN();
#else
	Assertion(tFP64_Abs(num) <= 1.0);
#endif/*BQSELAYER_DEBUG*/
	if (tFP64_Nearby(num, 1.0))  return tFP64_HalfPi;
	if (tFP64_Nearby(num, -1.0)) return -tFP64_HalfPi;
	return tFP64_ArcTangent_iter(num / tFP64_Sqrt_iter(1 - (num * num), sqrtItr), trigItr);
}
tFP64 tFP64_ArcSine(tFP64 num)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_Abs(num) > 1.0) return tFP64_SigNaN();
#else
	Assertion(tFP64_Abs(num) <= 1.0);
#endif/*BQSELAYER_DEBUG*/
	if (tFP64_Nearby(num, 1.0))  return tFP64_HalfPi;
	if (tFP64_Nearby(num, -1.0)) return -tFP64_HalfPi;
	return tFP64_ArcTangent(num / tFP64_Sqrt(1 - (num * num)));
}
ForceInline tFP64 tFP64_ArcCosine_iter(tFP64 num, tIUSz sqrtItr, tIUSz trigItr)
{
	return tFP64_HalfPi - tFP64_ArcSine_iter(num, sqrtItr, trigItr);
}
ForceInline tFP64 tFP64_ArcCosine(tFP64 num)
{
	return tFP64_HalfPi - tFP64_ArcSine(num);
}
tFP64 tFP64_ArcTangent_iter(tFP64 num, tIUSz itr)
{
	if (itr == 0U) return num;
	if (num > 1.0) return tFP64_HalfPi - tFP64_ArcTangent_iter(tFP64_Recip(num), itr);
	if (num < -1.0) return -tFP64_HalfPi - tFP64_ArcTangent_iter(tFP64_Recip(num), itr);
	tFP64 scale = 1.0;
	if (tFP64_Abs(num) > 0.5)
	{
		num = num / (1.0 + tFP64_Sqrt(1.0 + (num * num)));
		scale = 2.0;
	}
	const tFP64 numSq = num * num;
	tFP64 term = num;
	tFP64 res = term;
	for (tIUSz idx = 0U; idx < itr; ++idx)
	{
		tIUSz idx2 = idx << 1;
		term *= -numSq * ((tFP64)(idx2 + 1U) / (tFP64)(idx2 + 3U));
		res += term;
	}
	return scale * res;
}
ForceInline tFP64 tFP64_ArcTangent(tFP64 num)
{
	return tFP64_ArcTangent_iter(num, BQSELAYER_TRIG_ITER);
}
tFP64 tFP64_ArcTangent2_iter(tFP64 opp, tFP64 adj, tIUSz itr)
{
	if (adj > 0.0) return tFP64_ArcTangent_iter(opp / adj, itr);
	if (tFP64_IsNeg(adj) && !tFP64_IsNeg(opp)) return tFP64_ArcTangent_iter(opp / adj, itr) + tFP64_Pi;
	if (tFP64_IsNeg(adj) && tFP64_IsNeg(opp)) return tFP64_ArcTangent_iter(opp / adj, itr) - tFP64_Pi;
	if (tFP64_Nearby(adj, 0.0) && opp > 0.0) return tFP64_HalfPi;
	if (tFP64_Nearby(adj, 0.0) && tFP64_IsNeg(opp)) return -tFP64_HalfPi;
	return 0.0;
}
ForceInline tFP64 tFP64_ArcTangent2(tFP64 opp, tFP64 adj)
{
	return tFP64_ArcTangent2_iter(opp, adj, BQSELAYER_TRIG_ITER);
}
tFP64 tFP64_RecipSqrt_iter(tFP64 num, tIUSz itr)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNeg(num)) return tFP64_SigNaN();
	if (tFP64_Nearby(num, 0.0)) return tFP64_Inf();
#else
	Assertion(num > 0.0);
#endif/*BQSELAYER_DEBUG*/
	tFP64Bits number;
	number.dbl = num;
	tFP64 halfNum = number.dbl * 0.5;
	number.raw = 0X5FE6EC85E7DE30DAULL - (number.raw >> 1U);
	for (tIUSz idx = 0U; idx < itr; ++idx) number.dbl = number.dbl * (1.5 - (halfNum * number.dbl * number.dbl));
	return number.dbl;
}
ForceInline tFP64 tFP64_RecipSqrt(tFP64 num)
{
	return tFP64_RecipSqrt_iter(num, 1U);
}
ForceInline tFP64 tFP64_Sqrt_iter(tFP64 num, tIUSz itr)
{
#ifndef BQSELAYER_DBG
	if (tFP64_IsNeg(num)) return tFP64_SigNaN();
#else
	Assertion(!tFP64_IsNeg(num));
#endif/*BQSELAYER_DBG*/
	if (tFP64_Nearby(num, 0.0)) return 0.0;
	return num * tFP64_RecipSqrt_iter(num, itr);
}
ForceInline tFP64 tFP64_Sqrt(tFP64 num)
{
#ifndef BQSELAYER_DBG
	if (tFP64_IsNeg(num)) return tFP64_SigNaN();
#else
	Assertion(!tFP64_IsNeg(num));
#endif/*BQSELAYER_DBG*/
	if (tFP64_Nearby(num, 0.0)) return 0.0;
	return num * tFP64_RecipSqrt(num);
}
tFP64 tFP64_Log2_iter(tFP64 num, tIUSz itr)
{
#ifndef BQSELAYER_DEBUG
	if (num <= 0.0) return tFP64_SigNaN();
#else
	Assertion(num > 0.0F);
#endif/*BQSELAYER_DEBUG*/
	tFP64Bits numBits;
	numBits.dbl = num;
	tIS32 expVal = (tIS32)(((numBits.raw >> 52U) & 0x7FFULL) - 1023ULL);
	tFP64Bits mantBits;
	mantBits.raw = (numBits.raw & 0xFFFFFFFFFFFFFULL) | (1023ULL << 52U);
	tBln sub = True;
	const tFP64 valX = mantBits.dbl - 1.0;
	tFP64 mantApprox = valX;
	tFP64 powVal = mantApprox;
	for (tIUSz idx = 2U; idx < itr + 2U; ++idx)
	{
		powVal *= valX;
		if (sub) mantApprox -= powVal / (tFP64)idx;
		else mantApprox += powVal / (tFP64)idx;
		sub = !sub;
	}
	return (tFP64)expVal + (mantApprox * tFP64_Log2EulNum);
}
ForceInline tFP64 tFP64_Log2(tFP64 num)
{
	return tFP64_Log2_iter(num, 4U);
}
ForceInline tFP64 tFP64_Ln_iter(tFP64 num, tIUSz itr)
{
	return tFP64_Log2_iter(num, itr) / tFP64_Log2EulNum;
}
ForceInline tFP64 tFP64_Ln(tFP64 num)
{
	return tFP64_Log2(num) / tFP64_Log2EulNum;
}
tFP64 tFP64_Log_iter(tFP64 num, tFP64 base, tIUSz itr)
{
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0 || tFP64_Nearby(base, 1.0)) return tFP64_SigNaN();
#else
	Assertion(base > 0.0F && !tFP64_Nearby(base, 1.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64_Log2_iter(num, itr) / tFP64_Log2_iter(base, itr);
}
tFP64 tFP64_Log(tFP64 num, tFP64 base)
{
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0 || tFP64_Nearby(base, 1.0)) return tFP64_SigNaN();
#else
	Assertion(base > 0.0F && !tFP64_Nearby(base, 1.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64_Log2(num) / tFP64_Log2(base);
}
ForceInline tFP64 tFP64_Lerp(tFP64 strt, tFP64 stp, tFP64 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
ForceInline tFP64 tFP64_Unlerp(tFP64 strt, tFP64 curr, tFP64 fnsh)
{
	if (tFP64_Nearby(strt, fnsh)) return 0.0;
	return (curr - strt) / (fnsh - strt);
}
tFP64 tFP64_Exp_iter(tFP64 pow, tIUSz itr)
{
	if (tFP64_Nearby(pow, 0.0)) return 1.0;
	if (tFP64_Nearby(pow, 1.0)) return tFP64_EulNum;
	tFP64 res = 1.0;
	tFP64 term = 1.0;
	for (tIUSz idx = 1U; idx <= itr; ++idx)
	{
		term *= pow / (tFP64)idx;
		res += term;
	}
	return res;
}
ForceInline tFP64 tFP64_Exp(tFP64 pow)
{
	return tFP64_Exp_iter(pow, 10U);
}
ForceInline tFP64 tFP64_HypSine_iter(tFP64 num, tIUSz itr)
{
	tFP64 expNum = tFP64_Exp_iter(num, itr);
	return (expNum - tFP64_Recip(expNum)) * 0.5;
}
ForceInline tFP64 tFP64_HypCosine_iter(tFP64 num, tIUSz itr)
{
	tFP64 expNum = tFP64_Exp_iter(num, itr);
	return (expNum + tFP64_Recip(expNum)) * 0.5;
}
tFP64 tFP64_HypTangent_iter(tFP64 num, tIUSz itr)
{
	tFP64 expNum = tFP64_Exp_iter(num, itr);
	tFP64 invExpNum = tFP64_Recip(expNum);
	const tFP64 hypSine = (expNum - invExpNum) * 0.5;
	const tFP64 hypCosine = (expNum + invExpNum) * 0.5;
	return hypSine / hypCosine;
}
ForceInline tFP64 tFP64_HypSine(tFP64 num)
{
	tFP64 expNum = tFP64_Exp(num);
	return (expNum - tFP64_Recip(expNum)) * 0.5;
}
ForceInline tFP64 tFP64_HypCosine(tFP64 num)
{
	tFP64 expNum = tFP64_Exp(num);
	return (expNum + tFP64_Recip(expNum)) * 0.5;
}
ForceInline tFP64 tFP64_HypTangent(tFP64 num)
{
	tFP64 expNum = tFP64_Exp(num);
	tFP64 invExpNum = tFP64_Recip(expNum);
	const tFP64 hypSine = (expNum - invExpNum) * 0.5;
	const tFP64 hypCosine = (expNum + invExpNum) * 0.5;
	return hypSine / hypCosine;
}
tFP64 tFP64_Mod(tFP64 num, tFP64 denom)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_Nearby(denom, 0.0)) return tFP64_SigNaN();
#else
	Assertion(!tFP64_Nearby(denom, 0.0));
#endif/*BQSELAYER_DEBUG*/
	tIS64 quot = (tIS64)(num / denom);
	return num - ((tFP64)quot * denom);
}
tFP64 tFP64_PowI(tFP64 base, tISSz exp)
{
	if (exp == 0) return 1.0;
	if (exp < 0) return tFP64_Recip(tFP64_PowI(base, -exp));
	tFP64 result = 1.0;
	while (exp != 0)
	{
		if (exp & 1) result *= base;
		base *= base;
		exp >>= 1U;
	}
	return result;
}
tFP64 tFP64_Pow_iter(tFP64 base, tFP64 exp, tIUSz itr)
{
	tISSz intPart = (tISSz)exp;
	tFP64 whole = tFP64_PowI(base, intPart);
	if ((tFP64)intPart == exp) return whole;
	tFP64 fracPart = exp - (tFP64)intPart;
	if (tFP64_Nearby(fracPart, 0.5)) return whole * tFP64_Sqrt_iter(base, itr);
	if (tFP64_Nearby(fracPart, -0.5)) return whole * tFP64_RecipSqrt_iter(base, itr);
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0) return tFP64_SigNaN();
#else
	Assertion(base > 0.0);
#endif/*BQSELAYER_DEBUG*/
	return whole * tFP64_Exp_iter(fracPart * tFP64_Ln_iter(base, itr), itr);
}
tFP64 tFP64_Pow(tFP64 base, tFP64 exp)
{
	tISSz intPart = (tISSz)exp;
	tFP64 whole = tFP64_PowI(base, intPart);
	if ((tFP64)intPart == exp) return whole;
	tFP64 fracPart = exp - (tFP64)intPart;
	if (tFP64_Nearby(fracPart, 0.5)) return whole * tFP64_Sqrt(base);
	if (tFP64_Nearby(fracPart, -0.5)) return whole * tFP64_RecipSqrt(base);
#ifndef BQSELAYER_DEBUG
	if (base <= 0.0) return tFP64_SigNaN();
#else
	Assertion(base > 0.0);
#endif/*BQSELAYER_DEBUG*/
	return whole * tFP64_Exp(fracPart * tFP64_Ln(base));
}
tFP64 tFP64_Round(tFP64 num)
{
	tISSz intPart = (tISSz)num;
	if (num == (tFP64)intPart) return num;
	if (tFP64_IsNeg(num)) return tFP64_Neg(tFP64_Round(tFP64_Neg(num)));
	tFP64 fracPart = num - (tFP64)intPart;
	if (fracPart < 0.5) return (tFP64)intPart;
	else return (tFP64)intPart + 1.0;
}
ForceInline tFP64 tFP64_Recip(tFP64 num)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_Nearby(num, 0.0)) return tFP64_IsNeg(num) ? tFP64_Inf() : tFP64_NegInf();
#else
	Assertion(!tFP64_Nearby(num, 0.0));
#endif/*BQSELAYER_DEBUG*/
	// TODO: Assembly optimizations here.
	return 1.0 / num;
}
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
#ifdef BQSELAYER_PRIMTYPES_IMPL
#undef BQSELAYER_TRIG_ITER
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
#define BQSELAYER_DECLARE_COMMON_FUNC(tType)							\
ForceInline tType tType##_MinOf(tType Num1, tType Num2);				\
ForceInline tType tType##_MaxOf(tType Num1, tType Num2);				\
ForceInline tType tType##_Clamp(tType Lo, tType Num, tType Hi);			\
ForceInline tType tType##_ClampTop(tType Num1, tType Num2);				\
ForceInline tType tType##_ClampBot(tType Num1, tType Num2);				\
ForceInline tNone tType##_Swap(tType *Num1, tType *Num2);				\
ForceInline tType tType##_Sq(tType Num);								\
ForceInline tType tType##_Cb(tType Num);
#ifdef BQSELAYER_PRIMTYPES_IMPL
#define BQSELAYER_DEFINE_COMMON_FUNC(tType)								\
ForceInline tType tType##_MinOf(tType Num1, tType Num2)					\
{																		\
	return Num1 < Num2 ? Num1 : Num2;									\
}																		\
ForceInline tType tType##_MaxOf(tType Num1, tType Num2)					\
{																		\
	return Num1 > Num2 ? Num1 : Num2;									\
}																		\
ForceInline tType tType##_Clamp(tType Lo, tType Num, tType Hi)			\
{																		\
	return (Num < Lo) ? Lo : (Hi < Num) ? Hi : Num; 					\
}																		\
ForceInline tType tType##_ClampTop(tType Num1, tType Num2)				\
{																		\
	return Num1 < Num2 ? Num1 : Num2;									\
}																		\
ForceInline tType tType##_ClampBot(tType Num1, tType Num2)				\
{																		\
	return Num1 > Num2 ? Num1 : Num2;									\
}																		\
ForceInline tNone tType##_Swap(tType *Num1, tType *Num2)		    	\
{																		\
	tType tmp = *Num1;													\
	*Num1 = *Num2;												 	    \
	*Num2 = tmp;														\
}																		\
ForceInline tType tType##_Sq(tType Num)									\
{																		\
	return Num * Num;													\
}																		\
ForceInline tType tType##_Cb(tType Num)									\
{																		\
	return Num * Num * Num;												\
}
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
#define WrapStatement(Stmnt) do{Stmnt}while(0U)
#define ForceDump() (*(voltaile tIUSz *)0U = 0U)
#define Assertion(Cnd) WrapStatement(if(!(Cnd)){ForceDump();})
#define Stringify_inner(Str) #Str
#define Stringify(Str) Stringify_inner(Str)
#define Glueify_inner(StrA, StrB) StrA##StrB
#define Glueify(StrA, StrB) Glueify_inner(StrA, StrB)
#define ArrLng(Arr) (sizeof(Arr)/sizeof(Arr[0]))
#define NumFromPtr(Ptr) (tIUSz)((tIU8 *)Ptr - (tIU8 *)0U)
#define PtrFromNum(Num) (tPtr)((tIU8 *)0U + (Num))
#define OffsetOf(tType, Memb) ((tIUSz)&(((tType *)0U)->Memb))
#define MemberSize(tType, Memb) (sizeof(((tType *)0U)->Memb))
LINK_C_Begin
BQSELAYER_DECLARE_COMMON_FUNC(tISSz);
BQSELAYER_DECLARE_COMMON_FUNC(tIUSz);
BQSELAYER_DECLARE_COMMON_FUNC(tIS8);
BQSELAYER_DECLARE_COMMON_FUNC(tIU8);
BQSELAYER_DECLARE_COMMON_FUNC(tIS16);
BQSELAYER_DECLARE_COMMON_FUNC(tIU16);
BQSELAYER_DECLARE_COMMON_FUNC(tIS32);
BQSELAYER_DECLARE_COMMON_FUNC(tIU32);
BQSELAYER_DECLARE_COMMON_FUNC(tIS64);
BQSELAYER_DECLARE_COMMON_FUNC(tIU64);
BQSELAYER_DECLARE_COMMON_FUNC(tFP32);
BQSELAYER_DECLARE_COMMON_FUNC(tFP64);
LINK_C_End
#ifdef BQSELAYER_PRIMTYPES_IMPL
BQSELAYER_DEFINE_COMMON_FUNC(tISSz);
BQSELAYER_DEFINE_COMMON_FUNC(tIUSz);
BQSELAYER_DEFINE_COMMON_FUNC(tIS8);
BQSELAYER_DEFINE_COMMON_FUNC(tIU8);
BQSELAYER_DEFINE_COMMON_FUNC(tIS16);
BQSELAYER_DEFINE_COMMON_FUNC(tIU16);
BQSELAYER_DEFINE_COMMON_FUNC(tIS32);
BQSELAYER_DEFINE_COMMON_FUNC(tIU32);
BQSELAYER_DEFINE_COMMON_FUNC(tIS64);
BQSELAYER_DEFINE_COMMON_FUNC(tIU64);
BQSELAYER_DEFINE_COMMON_FUNC(tFP32);
BQSELAYER_DEFINE_COMMON_FUNC(tFP64);
#undef BQSELAYER_DEFINE_COMMON_FUNC
#endif/*BQSELAYER_PRIMTYPES_IMPL*/
#undef BQSELAYER_DECLARE_COMMON_FUNC
#if ARCH_Bitness == 64
typedef tFP64 tFPSz;
#else
typedef tFP32 tFPSz;
#endif/*ARCH_Bitness*/
#endif/*BQSELAYER_PRIMTYPES_H*/