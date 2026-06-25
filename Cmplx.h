#ifndef BQSELAYER_CMPLX_H
#define BQSELAYER_CMPLX_H
#include "PrimTypes.h"
typedef tF32 tF32Real;
typedef tF32 tF32Imag;
typedef struct { tF32Real real; tF32Imag imag; } tF32Cmplx;
tF32Cmplx tF32Cmplx_Make(tF32 real, tF32 imag);
tF32Cmplx tF32Cmplx_Zero(void);
tF32Cmplx tF32Cmplx_Add(tF32Cmplx num1, tF32Cmplx num2);
tF32Cmplx tF32Cmplx_Sub(tF32Cmplx lhs, tF32Cmplx rhs);
tF32Cmplx tF32Cmplx_Mul(tF32Cmplx num1, tF32Cmplx num2);
tF32Cmplx tF32Cmplx_Div(tF32Cmplx lhs, tF32Cmplx rhs);
tF32Cmplx tF32Cmplx_Conj(tF32Cmplx num);
tF32 tF32Cmplx_MagSq(tF32Cmplx num);
tF32 tF32Cmplx_Mag_iter(tF32Cmplx num, tUSz itr);
tF32 tF32Cmplx_Mag(tF32Cmplx num);
tF32Cmplx tF32Cmplx_AddF(tF32Cmplx num, tF32 flt);
tF32Cmplx tF32Cmplx_SubF(tF32Cmplx num, tF32 flt);
tF32Cmplx tF32Cmplx_MulF(tF32Cmplx num, tF32 flt);
tF32Cmplx tF32Cmplx_DivF(tF32Cmplx num, tF32 flt);
tF32 tF32Cmplx_Arg_iter(tF32Cmplx num, tUSz itr);
tF32 tF32Cmplx_Arg(tF32Cmplx num);
tF32Cmplx tF32Cmplx_FromPolar_fast(tF32 mag, tF32 ang);
tF32Cmplx tF32Cmplx_FromPolar_iter(tF32 mag, tF32 ang, tUSz itr);
tF32Cmplx tF32Cmplx_FromPolar(tF32 mag, tF32 ang);
tF32Cmplx tF32Cmplx_Sqrt_iter(tF32Cmplx num, tUSz itr);
tF32Cmplx tF32Cmplx_Sqrt(tF32Cmplx num);
tF32Cmplx tF32Cmplx_Exp_iter(tF32Cmplx num, tUSz itr);
tF32Cmplx tF32Cmplx_Exp(tF32Cmplx num);
tF32Cmplx tF32Cmplx_Ln_iter(tF32Cmplx num, tUSz itr);
tF32Cmplx tF32Cmplx_Ln(tF32Cmplx num);
tF32Cmplx tF32Cmplx_PowI(tF32Cmplx num, tSSz exp);
tF32Cmplx tF32Cmplx_Pow_iter(tF32Cmplx base, tF32Cmplx exp, tUSz itr);
tF32Cmplx tF32Cmplx_Pow(tF32Cmplx base, tF32Cmplx exp);
tBln tF32Cmplx_Eq(tF32Cmplx num1, tF32Cmplx num2);
tBln tF32Cmplx_Nearby(tF32Cmplx num1, tF32Cmplx num2);
tF32Cmplx tF32Cmplx_Neg(tF32Cmplx num);
tF32Cmplx tF32Cmplx_One(void);
tF32Cmplx tF32Cmplx_I(void);
tF32Cmplx tF32Cmplx_Recip(tF32Cmplx num);
#ifdef BQSELAYER_IMPL
LINK_C_Begin
FORCEINLINE tF32Cmplx tF32Cmplx_Make(tF32 real, tF32 imag)
{
	tF32Cmplx num;
	num.real = (tF32Real)real;
	num.imag = (tF32Imag)imag;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Zero(void)
{
	tF32Cmplx num;
	num.real = (tF32Real)0.0F;
	num.imag = (tF32Imag)0.0F;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Add(tF32Cmplx num1, tF32Cmplx num2)
{
	num1.real += num2.real;
	num1.imag += num2.imag;
	return num1;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Sub(tF32Cmplx lhs, tF32Cmplx rhs)
{
	lhs.real -= rhs.real;
	lhs.imag -= rhs.imag;
	return lhs;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Mul(tF32Cmplx num1, tF32Cmplx num2)
{
	tF32Cmplx num;
	num.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	num.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
	return num;
}
tF32Cmplx tF32Cmplx_Div(tF32Cmplx lhs, tF32Cmplx rhs)
{
	tF32Cmplx num;
#ifndef BQSELAYER_DBG
	if (tF32_Nearby(rhs.real, 0.0F) && tF32_Nearby(rhs.imag, 0.0F))
	{
		num.real = tF32_SigNaN();
		num.imag = tF32_SigNaN();
		return num;
	}
#else
	Assertion(!tF32_Nearby(rhs.real, 0.0F) || !tF32_Nearby(rhs.imag, 0.0F));
#endif/*BQSELAYER_DBG*/
	tF32 commonDenom = tF32_Recip(tF32_Sq(rhs.real) + tF32_Sq(rhs.imag));
	num.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) * commonDenom;
	num.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) * commonDenom;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Conj(tF32Cmplx num)
{
	num.imag = tF32_Neg(num.imag);
	return num;
}
FORCEINLINE tF32 tF32Cmplx_MagSq(tF32Cmplx num)
{
	return tF32_Sq(num.real) + tF32_Sq(num.imag);
}
FORCEINLINE tF32 tF32Cmplx_Mag_iter(tF32Cmplx num, tUSz itr)
{
	return tF32_Sqrt_iter(tF32Cmplx_MagSq(num), itr);
}
FORCEINLINE tF32 tF32Cmplx_Mag(tF32Cmplx num)
{
	return tF32_Sqrt(tF32Cmplx_MagSq(num));
}
FORCEINLINE tF32Cmplx tF32Cmplx_AddF(tF32Cmplx num, tF32 flt)
{
	num.real += flt;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_SubF(tF32Cmplx num, tF32 flt)
{
	num.real -= flt;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_MulF(tF32Cmplx num, tF32 flt)
{
	num.real *= flt;
	num.imag *= flt;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_DivF(tF32Cmplx num, tF32 flt)
{
#ifndef BQSELAYER_DBG
	if (tF32_Nearby(flt, 0.0F))
	{
		num.real = tF32_SigNaN();
		num.imag = tF32_SigNaN();
		return num;
	}
#else
	Assertion(!tF32_Nearby(flt, 0.0F));
#endif/*BQSELAYER_DBG*/
	num.real /= flt;
	num.imag /= flt;
	return num;
}
FORCEINLINE tF32 tF32Cmplx_Arg_iter(tF32Cmplx num, tUSz itr)
{
	return tF32_ArcTangent2_iter(num.imag, num.real, itr);
}
FORCEINLINE tF32 tF32Cmplx_Arg(tF32Cmplx num)
{
	return tF32_ArcTangent2(num.imag, num.real);
}
tF32Cmplx tF32Cmplx_FromPolar_fast(tF32 mag, tF32 ang)
{
	tF32Cmplx num;
	num.real = tF32_Cosine_fast(ang) * mag;
	num.imag = tF32_Sine_fast(ang) * mag;
	return num;
}
tF32Cmplx tF32Cmplx_FromPolar_iter(tF32 mag, tF32 ang, tUSz itr)
{
	tF32Cmplx num;
	num.real = tF32_Cosine_iter(ang, itr) * mag;
	num.imag = tF32_Sine_iter(ang, itr) * mag;
	return num;
}
tF32Cmplx tF32Cmplx_FromPolar(tF32 mag, tF32 ang)
{
	tF32Cmplx num;
	num.real = tF32_Cosine(ang) * mag;
	num.imag = tF32_Sine(ang) * mag;
	return num;
}
tF32Cmplx tF32Cmplx_Sqrt_iter(tF32Cmplx num, tUSz itr)
{
	tF32 mag = tF32Cmplx_Mag_iter(num, itr);
#define BQSELAYER_RECIPSQRT2 0.707106781187F
	tBln neg = tF32_IsNeg(num.imag);
	num.imag = tF32_Sqrt_iter(mag - num.real, itr) * BQSELAYER_RECIPSQRT2;
	num.real = tF32_Sqrt_iter(mag + num.real, itr) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tF32_Neg(num.imag);
	return num;
}
tF32Cmplx tF32Cmplx_Sqrt(tF32Cmplx num)
{
	tF32 mag = tF32Cmplx_Mag(num);
#define BQSELAYER_RECIPSQRT2 0.707106781187F
	tBln neg = tF32_IsNeg(num.imag);
	num.imag = tF32_Sqrt(mag - num.real) * BQSELAYER_RECIPSQRT2;
	num.real = tF32_Sqrt(mag + num.real) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tF32_Neg(num.imag);
	return num;
}
tF32Cmplx tF32Cmplx_Exp_iter(tF32Cmplx num, tUSz itr)
{
	tF32 scale = tF32_Exp_iter(num.real, itr);
	tF32Cmplx result;
	result.real = scale * tF32_Cosine_iter(num.imag, itr);
	result.imag = scale * tF32_Sine_iter(num.imag, itr);
	return result;
}
tF32Cmplx tF32Cmplx_Exp(tF32Cmplx num)
{
	tF32 scale = tF32_Exp(num.real);
	tF32Cmplx result;
	result.real = scale * tF32_Cosine(num.imag);
	result.imag = scale * tF32_Sine(num.imag);
	return result;
}
tF32Cmplx tF32Cmplx_Ln_iter(tF32Cmplx num, tUSz itr)
{
	tF32Cmplx result;
	result.real = tF32_Ln_iter(tF32Cmplx_Mag_iter(num, itr), itr);
	result.imag = tF32Cmplx_Arg_iter(num, itr);
	return result;
}
tF32Cmplx tF32Cmplx_Ln(tF32Cmplx num)
{
	tF32Cmplx result;
	result.real = tF32_Ln(tF32Cmplx_Mag(num));
	result.imag = tF32Cmplx_Arg(num);
	return result;
}
tF32Cmplx tF32Cmplx_PowI(tF32Cmplx num, tSSz exp)
{
	if (exp == 0) return tF32Cmplx_Make(1.0F, 0.0F);
	if (exp < 0)
	{
		tF32Cmplx inv;
		inv.real = 1.0F;
		inv.imag = 0.0F;
		return tF32Cmplx_Div(inv, tF32Cmplx_PowI(num, -exp));
	}
	tF32Cmplx result;
	result.real = 1.0F;
	result.imag = 0.0F;
	while (exp != 0)
	{
		if (exp & 1) result = tF32Cmplx_Mul(result, num);
		num = tF32Cmplx_Mul(num, num);
		exp >>= 1U;
	}
	return result;
}
tF32Cmplx tF32Cmplx_Pow_iter(tF32Cmplx base, tF32Cmplx exp, tUSz itr)
{
	return tF32Cmplx_Exp_iter(tF32Cmplx_Mul(exp, tF32Cmplx_Ln_iter(base, itr)), itr);
}
tF32Cmplx tF32Cmplx_Pow(tF32Cmplx base, tF32Cmplx exp)
{
	return tF32Cmplx_Exp(tF32Cmplx_Mul(exp, tF32Cmplx_Ln(base)));
}
FORCEINLINE tBln tF32Cmplx_Eq(tF32Cmplx num1, tF32Cmplx num2)
{
	return num1.real == num2.real && num1.imag == num2.imag;
}
FORCEINLINE tBln tF32Cmplx_Nearby(tF32Cmplx num1, tF32Cmplx num2)
{
	return tF32_Nearby(num1.real, num2.real) && tF32_Nearby(num1.imag, num2.imag);
}
FORCEINLINE tF32Cmplx tF32Cmplx_Neg(tF32Cmplx num)
{
	num.real = tF32_Neg(num.real);
	num.imag = tF32_Neg(num.imag);
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_One(void)
{
	tF32Cmplx num;
	num.real = 1.0F;
	num.imag = 0.0F;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_I(void)
{
	tF32Cmplx num;
	num.real = 0.0F;
	num.imag = 1.0F;
	return num;
}
tF32Cmplx tF32Cmplx_Recip(tF32Cmplx num)
{
	return tF32Cmplx_DivF(tF32Cmplx_Conj(num), tF32Cmplx_MagSq(num));
}
LINK_C_End
#endif/*BQSELAYER_IMPL*/
typedef tF64 tF64Real;
typedef tF64 tF64Imag;
typedef struct { tF64Real real; tF64Imag imag; } tF64Cmplx;
tF64Cmplx tF64Cmplx_Make(tF64 real, tF64 imag);
tF64Cmplx tF64Cmplx_Zero(void);
tF64Cmplx tF64Cmplx_Add(tF64Cmplx num1, tF64Cmplx num2);
tF64Cmplx tF64Cmplx_Sub(tF64Cmplx lhs, tF64Cmplx rhs);
tF64Cmplx tF64Cmplx_Mul(tF64Cmplx num1, tF64Cmplx num2);
tF64Cmplx tF64Cmplx_Div(tF64Cmplx lhs, tF64Cmplx rhs);
tF64Cmplx tF64Cmplx_Conj(tF64Cmplx num);
tF64 tF64Cmplx_MagSq(tF64Cmplx num);
tF64 tF64Cmplx_Mag_iter(tF64Cmplx num, tUSz itr);
tF64 tF64Cmplx_Mag(tF64Cmplx num);
tF64Cmplx tF64Cmplx_AddF(tF64Cmplx num, tF64 flt);
tF64Cmplx tF64Cmplx_SubF(tF64Cmplx num, tF64 flt);
tF64Cmplx tF64Cmplx_MulF(tF64Cmplx num, tF64 flt);
tF64Cmplx tF64Cmplx_DivF(tF64Cmplx num, tF64 flt);
tF64 tF64Cmplx_Arg_iter(tF64Cmplx num, tUSz itr);
tF64 tF64Cmplx_Arg(tF64Cmplx num);
tF64Cmplx tF64Cmplx_FromPolar_fast(tF64 mag, tF64 ang);
tF64Cmplx tF64Cmplx_FromPolar_iter(tF64 mag, tF64 ang, tUSz itr);
tF64Cmplx tF64Cmplx_FromPolar(tF64 mag, tF64 ang);
tF64Cmplx tF64Cmplx_Sqrt_iter(tF64Cmplx num, tUSz itr);
tF64Cmplx tF64Cmplx_Sqrt(tF64Cmplx num);
tF64Cmplx tF64Cmplx_Exp_iter(tF64Cmplx num, tUSz itr);
tF64Cmplx tF64Cmplx_Exp(tF64Cmplx num);
tF64Cmplx tF64Cmplx_Ln_iter(tF64Cmplx num, tUSz itr);
tF64Cmplx tF64Cmplx_Ln(tF64Cmplx num);
tF64Cmplx tF64Cmplx_PowI(tF64Cmplx num, tSSz exp);
tF64Cmplx tF64Cmplx_Pow_iter(tF64Cmplx base, tF64Cmplx exp, tUSz itr);
tF64Cmplx tF64Cmplx_Pow(tF64Cmplx base, tF64Cmplx exp);
tBln tF64Cmplx_Eq(tF64Cmplx num1, tF64Cmplx num2);
tBln tF64Cmplx_Nearby(tF64Cmplx num1, tF64Cmplx num2);
tF64Cmplx tF64Cmplx_Neg(tF64Cmplx num);
tF64Cmplx tF64Cmplx_One(void);
tF64Cmplx tF64Cmplx_I(void);
tF64Cmplx tF64Cmplx_Recip(tF64Cmplx num);
#ifdef BQSELAYER_IMPL
LINK_C_Begin
FORCEINLINE tF64Cmplx tF64Cmplx_Make(tF64 real, tF64 imag)
{
	tF64Cmplx num;
	num.real = (tF64Real)real;
	num.imag = (tF64Imag)imag;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_Zero(void)
{
	tF64Cmplx num;
	num.real = (tF64Real)0.0;
	num.imag = (tF64Imag)0.0;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_Add(tF64Cmplx num1, tF64Cmplx num2)
{
	num1.real += num2.real;
	num1.imag += num2.imag;
	return num1;
}
FORCEINLINE tF64Cmplx tF64Cmplx_Sub(tF64Cmplx lhs, tF64Cmplx rhs)
{
	lhs.real -= rhs.real;
	lhs.imag -= rhs.imag;
	return lhs;
}
FORCEINLINE tF64Cmplx tF64Cmplx_Mul(tF64Cmplx num1, tF64Cmplx num2)
{
	tF64Cmplx num;
	num.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	num.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
	return num;
}
tF64Cmplx tF64Cmplx_Div(tF64Cmplx lhs, tF64Cmplx rhs)
{
	tF64Cmplx num;
#ifndef BQSELAYER_DBG
	if (tF64_Nearby(rhs.real, 0.0) && tF64_Nearby(rhs.imag, 0.0))
	{
		num.real = tF64_SigNaN();
		num.imag = tF64_SigNaN();
		return num;
	}
#else
	Assertion(!tF64_Nearby(rhs.real, 0.0) || !tF64_Nearby(rhs.imag, 0.0));
#endif/*BQSELAYER_DBG*/
	tF64 commonDenom = tF64_Recip(tF64_Sq(rhs.real) + tF64_Sq(rhs.imag));
	num.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) * commonDenom;
	num.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) * commonDenom;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_Conj(tF64Cmplx num)
{
	num.imag = tF64_Neg(num.imag);
	return num;
}
FORCEINLINE tF64 tF64Cmplx_MagSq(tF64Cmplx num)
{
	return tF64_Sq(num.real) + tF64_Sq(num.imag);
}
FORCEINLINE tF64 tF64Cmplx_Mag_iter(tF64Cmplx num, tUSz itr)
{
	return tF64_Sqrt_iter(tF64Cmplx_MagSq(num), itr);
}
FORCEINLINE tF64 tF64Cmplx_Mag(tF64Cmplx num)
{
	return tF64_Sqrt(tF64Cmplx_MagSq(num));
}
FORCEINLINE tF64Cmplx tF64Cmplx_AddF(tF64Cmplx num, tF64 flt)
{
	num.real += flt;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_SubF(tF64Cmplx num, tF64 flt)
{
	num.real -= flt;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_MulF(tF64Cmplx num, tF64 flt)
{
	num.real *= flt;
	num.imag *= flt;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_DivF(tF64Cmplx num, tF64 flt)
{
#ifndef BQSELAYER_DBG
	if (tF64_Nearby(flt, 0.0))
	{
		num.real = tF64_SigNaN();
		num.imag = tF64_SigNaN();
		return num;
	}
#else
	Assertion(!tF64_Nearby(flt, 0.0));
#endif/*BQSELAYER_DBG*/
	num.real /= flt;
	num.imag /= flt;
	return num;
}
FORCEINLINE tF64 tF64Cmplx_Arg_iter(tF64Cmplx num, tUSz itr)
{
	return tF64_ArcTangent2_iter(num.imag, num.real, itr);
}
FORCEINLINE tF64 tF64Cmplx_Arg(tF64Cmplx num)
{
	return tF64_ArcTangent2(num.imag, num.real);
}
tF64Cmplx tF64Cmplx_FromPolar_fast(tF64 mag, tF64 ang)
{
	tF64Cmplx num;
	num.real = tF64_Cosine_fast(ang) * mag;
	num.imag = tF64_Sine_fast(ang) * mag;
	return num;
}
tF64Cmplx tF64Cmplx_FromPolar_iter(tF64 mag, tF64 ang, tUSz itr)
{
	tF64Cmplx num;
	num.real = tF64_Cosine_iter(ang, itr) * mag;
	num.imag = tF64_Sine_iter(ang, itr) * mag;
	return num;
}
tF64Cmplx tF64Cmplx_FromPolar(tF64 mag, tF64 ang)
{
	tF64Cmplx num;
	num.real = tF64_Cosine(ang) * mag;
	num.imag = tF64_Sine(ang) * mag;
	return num;
}
tF64Cmplx tF64Cmplx_Sqrt_iter(tF64Cmplx num, tUSz itr)
{
	tF64 mag = tF64Cmplx_Mag_iter(num, itr);
#define BQSELAYER_RECIPSQRT2 0.707106781187
	tBln neg = tF64_IsNeg(num.imag);
	num.imag = tF64_Sqrt_iter(mag - num.real, itr) * BQSELAYER_RECIPSQRT2;
	num.real = tF64_Sqrt_iter(mag + num.real, itr) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tF64_Neg(num.imag);
	return num;
}
tF64Cmplx tF64Cmplx_Sqrt(tF64Cmplx num)
{
	tF64 mag = tF64Cmplx_Mag(num);
#define BQSELAYER_RECIPSQRT2 0.707106781187
	tBln neg = tF64_IsNeg(num.imag);
	num.imag = tF64_Sqrt(mag - num.real) * BQSELAYER_RECIPSQRT2;
	num.real = tF64_Sqrt(mag + num.real) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tF64_Neg(num.imag);
	return num;
}
tF64Cmplx tF64Cmplx_Exp_iter(tF64Cmplx num, tUSz itr)
{
	tF64 scale = tF64_Exp_iter(num.real, itr);
	tF64Cmplx result;
	result.real = scale * tF64_Cosine_iter(num.imag, itr);
	result.imag = scale * tF64_Sine_iter(num.imag, itr);
	return result;
}
tF64Cmplx tF64Cmplx_Exp(tF64Cmplx num)
{
	tF64 scale = tF64_Exp(num.real);
	tF64Cmplx result;
	result.real = scale * tF64_Cosine(num.imag);
	result.imag = scale * tF64_Sine(num.imag);
	return result;
}
tF64Cmplx tF64Cmplx_Ln_iter(tF64Cmplx num, tUSz itr)
{
	tF64Cmplx result;
	result.real = tF64_Ln_iter(tF64Cmplx_Mag_iter(num, itr), itr);
	result.imag = tF64Cmplx_Arg_iter(num, itr);
	return result;
}
tF64Cmplx tF64Cmplx_Ln(tF64Cmplx num)
{
	tF64Cmplx result;
	result.real = tF64_Ln(tF64Cmplx_Mag(num));
	result.imag = tF64Cmplx_Arg(num);
	return result;
}
tF64Cmplx tF64Cmplx_PowI(tF64Cmplx num, tSSz exp)
{
	if (exp == 0) return tF64Cmplx_Make(1.0, 0.0);
	if (exp < 0)
	{
		tF64Cmplx inv;
		inv.real = 1.0;
		inv.imag = 0.0;
		return tF64Cmplx_Div(inv, tF64Cmplx_PowI(num, -exp));
	}
	tF64Cmplx result;
	result.real = 1.0;
	result.imag = 0.0;
	while (exp != 0)
	{
		if (exp & 1) result = tF64Cmplx_Mul(result, num);
		num = tF64Cmplx_Mul(num, num);
		exp >>= 1U;
	}
	return result;
}
tF64Cmplx tF64Cmplx_Pow_iter(tF64Cmplx base, tF64Cmplx exp, tUSz itr)
{
	return tF64Cmplx_Exp_iter(tF64Cmplx_Mul(exp, tF64Cmplx_Ln_iter(base, itr)), itr);
}
tF64Cmplx tF64Cmplx_Pow(tF64Cmplx base, tF64Cmplx exp)
{
	return tF64Cmplx_Exp(tF64Cmplx_Mul(exp, tF64Cmplx_Ln(base)));
}
FORCEINLINE tBln tF64Cmplx_Eq(tF64Cmplx num1, tF64Cmplx num2)
{
	return num1.real == num2.real && num1.imag == num2.imag;
}
FORCEINLINE tBln tF64Cmplx_Nearby(tF64Cmplx num1, tF64Cmplx num2)
{
	return tF64_Nearby(num1.real, num2.real) && tF64_Nearby(num1.imag, num2.imag);
}
FORCEINLINE tF64Cmplx tF64Cmplx_Neg(tF64Cmplx num)
{
	num.real = tF64_Neg(num.real);
	num.imag = tF64_Neg(num.imag);
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_One(void)
{
	tF64Cmplx num;
	num.real = 1.0;
	num.imag = 0.0;
	return num;
}
FORCEINLINE tF64Cmplx tF64Cmplx_I(void)
{
	tF64Cmplx num;
	num.real = 0.0;
	num.imag = 1.0;
	return num;
}
tF64Cmplx tF64Cmplx_Recip(tF64Cmplx num)
{
	return tF64Cmplx_DivF(tF64Cmplx_Conj(num), tF64Cmplx_MagSq(num));
}
LINK_C_End
#endif/*BQSELAYER_IMPL*/
#endif/*BQSELAYER_CMPLX_H*/