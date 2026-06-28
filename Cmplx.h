#ifndef BQSELAYER_CMPLX_H
#define BQSELAYER_CMPLX_H
#include "PrimTypes.h"
typedef tFP32 tFP32Real;
typedef tFP32 tFP32Imag;
typedef struct { tFP32Real real; tFP32Imag imag; } tFP32Cmplx;
ForceInline tFP32Cmplx tFP32Cmplx_Make(tFP32 real, tFP32 imag);
ForceInline tFP32Cmplx tFP32Cmplx_Zero(void);
ForceInline tFP32Cmplx tFP32Cmplx_Add(tFP32Cmplx num1, tFP32Cmplx num2);
ForceInline tFP32Cmplx tFP32Cmplx_Sub(tFP32Cmplx lhs, tFP32Cmplx rhs);
ForceInline tFP32Cmplx tFP32Cmplx_Mul(tFP32Cmplx num1, tFP32Cmplx num2);
tFP32Cmplx tFP32Cmplx_Div(tFP32Cmplx lhs, tFP32Cmplx rhs);
ForceInline tFP32Cmplx tFP32Cmplx_Conj(tFP32Cmplx num);
ForceInline tFP32 tFP32Cmplx_MagSq(tFP32Cmplx num);
ForceInline tFP32 tFP32Cmplx_Mag_iter(tFP32Cmplx num, tIUSz itr);
ForceInline tFP32 tFP32Cmplx_Mag(tFP32Cmplx num);
ForceInline tFP32Cmplx tFP32Cmplx_AddF(tFP32Cmplx num, tFP32 flt);
ForceInline tFP32Cmplx tFP32Cmplx_SubF(tFP32Cmplx num, tFP32 flt);
ForceInline tFP32Cmplx tFP32Cmplx_MulF(tFP32Cmplx num, tFP32 flt);
ForceInline tFP32Cmplx tFP32Cmplx_DivF(tFP32Cmplx num, tFP32 flt);
ForceInline tFP32 tFP32Cmplx_Arg_iter(tFP32Cmplx num, tIUSz itr);
ForceInline tFP32 tFP32Cmplx_Arg(tFP32Cmplx num);
tFP32Cmplx tFP32Cmplx_FromPolar_fast(tFP32 mag, tFP32 ang);
tFP32Cmplx tFP32Cmplx_FromPolar_iter(tFP32 mag, tFP32 ang, tIUSz itr);
tFP32Cmplx tFP32Cmplx_FromPolar(tFP32 mag, tFP32 ang);
tFP32Cmplx tFP32Cmplx_Sqrt_iter(tFP32Cmplx num, tIUSz itr);
tFP32Cmplx tFP32Cmplx_Sqrt(tFP32Cmplx num);
tFP32Cmplx tFP32Cmplx_Exp_iter(tFP32Cmplx num, tIUSz itr);
tFP32Cmplx tFP32Cmplx_Exp(tFP32Cmplx num);
tFP32Cmplx tFP32Cmplx_Ln_iter(tFP32Cmplx num, tIUSz itr);
tFP32Cmplx tFP32Cmplx_Ln(tFP32Cmplx num);
tFP32Cmplx tFP32Cmplx_PowI(tFP32Cmplx num, tISSz exp);
tFP32Cmplx tFP32Cmplx_Pow_iter(tFP32Cmplx base, tFP32Cmplx exp, tIUSz itr);
tFP32Cmplx tFP32Cmplx_Pow(tFP32Cmplx base, tFP32Cmplx exp);
ForceInline tBln tFP32Cmplx_Eq(tFP32Cmplx num1, tFP32Cmplx num2);
ForceInline tBln tFP32Cmplx_Nearby(tFP32Cmplx num1, tFP32Cmplx num2);
ForceInline tFP32Cmplx tFP32Cmplx_Neg(tFP32Cmplx num);
ForceInline tFP32Cmplx tFP32Cmplx_One(void);
ForceInline tFP32Cmplx tFP32Cmplx_I(void);
tFP32Cmplx tFP32Cmplx_Recip(tFP32Cmplx num);
#ifdef BQSELAYER_CMPLX_IMPL
LINK_C_Begin
ForceInline tFP32Cmplx tFP32Cmplx_Make(tFP32 real, tFP32 imag)
{
	tFP32Cmplx num;
	num.real = (tFP32Real)real;
	num.imag = (tFP32Imag)imag;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_Zero(void)
{
	tFP32Cmplx num;
	num.real = (tFP32Real)0.0F;
	num.imag = (tFP32Imag)0.0F;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_Add(tFP32Cmplx num1, tFP32Cmplx num2)
{
	num1.real += num2.real;
	num1.imag += num2.imag;
	return num1;
}
ForceInline tFP32Cmplx tFP32Cmplx_Sub(tFP32Cmplx lhs, tFP32Cmplx rhs)
{
	lhs.real -= rhs.real;
	lhs.imag -= rhs.imag;
	return lhs;
}
ForceInline tFP32Cmplx tFP32Cmplx_Mul(tFP32Cmplx num1, tFP32Cmplx num2)
{
	tFP32Cmplx num;
	num.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	num.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
	return num;
}
tFP32Cmplx tFP32Cmplx_Div(tFP32Cmplx lhs, tFP32Cmplx rhs)
{
	tFP32Cmplx num;
#ifndef BQSELAYER_DBG
	if (tFP32_Nearby(rhs.real, 0.0F) && tFP32_Nearby(rhs.imag, 0.0F))
	{
		num.real = tFP32_SigNaN();
		num.imag = tFP32_SigNaN();
		return num;
	}
#else
	Assertion(!tFP32_Nearby(rhs.real, 0.0F) || !tFP32_Nearby(rhs.imag, 0.0F));
#endif/*BQSELAYER_DBG*/
	tFP32 commonDenom = tFP32_Recip(tFP32_Sq(rhs.real) + tFP32_Sq(rhs.imag));
	num.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) * commonDenom;
	num.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) * commonDenom;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_Conj(tFP32Cmplx num)
{
	num.imag = tFP32_Neg(num.imag);
	return num;
}
ForceInline tFP32 tFP32Cmplx_MagSq(tFP32Cmplx num)
{
	return tFP32_Sq(num.real) + tFP32_Sq(num.imag);
}
ForceInline tFP32 tFP32Cmplx_Mag_iter(tFP32Cmplx num, tIUSz itr)
{
	return tFP32_Sqrt_iter(tFP32Cmplx_MagSq(num), itr);
}
ForceInline tFP32 tFP32Cmplx_Mag(tFP32Cmplx num)
{
	return tFP32_Sqrt(tFP32Cmplx_MagSq(num));
}
ForceInline tFP32Cmplx tFP32Cmplx_AddF(tFP32Cmplx num, tFP32 flt)
{
	num.real += flt;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_SubF(tFP32Cmplx num, tFP32 flt)
{
	num.real -= flt;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_MulF(tFP32Cmplx num, tFP32 flt)
{
	num.real *= flt;
	num.imag *= flt;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_DivF(tFP32Cmplx num, tFP32 flt)
{
#ifndef BQSELAYER_DBG
	if (tFP32_Nearby(flt, 0.0F))
	{
		num.real = tFP32_SigNaN();
		num.imag = tFP32_SigNaN();
		return num;
	}
#else
	Assertion(!tFP32_Nearby(flt, 0.0F));
#endif/*BQSELAYER_DBG*/
	num.real /= flt;
	num.imag /= flt;
	return num;
}
ForceInline tFP32 tFP32Cmplx_Arg_iter(tFP32Cmplx num, tIUSz itr)
{
	return tFP32_ArcTangent2_iter(num.imag, num.real, itr);
}
ForceInline tFP32 tFP32Cmplx_Arg(tFP32Cmplx num)
{
	return tFP32_ArcTangent2(num.imag, num.real);
}
tFP32Cmplx tFP32Cmplx_FromPolar_fast(tFP32 mag, tFP32 ang)
{
	tFP32Cmplx num;
	num.real = tFP32_Cosine_fast(ang) * mag;
	num.imag = tFP32_Sine_fast(ang) * mag;
	return num;
}
tFP32Cmplx tFP32Cmplx_FromPolar_iter(tFP32 mag, tFP32 ang, tIUSz itr)
{
	tFP32Cmplx num;
	num.real = tFP32_Cosine_iter(ang, itr) * mag;
	num.imag = tFP32_Sine_iter(ang, itr) * mag;
	return num;
}
tFP32Cmplx tFP32Cmplx_FromPolar(tFP32 mag, tFP32 ang)
{
	tFP32Cmplx num;
	num.real = tFP32_Cosine(ang) * mag;
	num.imag = tFP32_Sine(ang) * mag;
	return num;
}
tFP32Cmplx tFP32Cmplx_Sqrt_iter(tFP32Cmplx num, tIUSz itr)
{
	tFP32 mag = tFP32Cmplx_Mag_iter(num, itr);
#define BQSELAYER_RECIPSQRT2 0.707106781187F
	tBln neg = tFP32_IsNeg(num.imag);
	num.imag = tFP32_Sqrt_iter(mag - num.real, itr) * BQSELAYER_RECIPSQRT2;
	num.real = tFP32_Sqrt_iter(mag + num.real, itr) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tFP32_Neg(num.imag);
	return num;
}
tFP32Cmplx tFP32Cmplx_Sqrt(tFP32Cmplx num)
{
	tFP32 mag = tFP32Cmplx_Mag(num);
#define BQSELAYER_RECIPSQRT2 0.707106781187F
	tBln neg = tFP32_IsNeg(num.imag);
	num.imag = tFP32_Sqrt(mag - num.real) * BQSELAYER_RECIPSQRT2;
	num.real = tFP32_Sqrt(mag + num.real) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tFP32_Neg(num.imag);
	return num;
}
tFP32Cmplx tFP32Cmplx_Exp_iter(tFP32Cmplx num, tIUSz itr)
{
	tFP32 scale = tFP32_Exp_iter(num.real, itr);
	tFP32Cmplx result;
	result.real = scale * tFP32_Cosine_iter(num.imag, itr);
	result.imag = scale * tFP32_Sine_iter(num.imag, itr);
	return result;
}
tFP32Cmplx tFP32Cmplx_Exp(tFP32Cmplx num)
{
	tFP32 scale = tFP32_Exp(num.real);
	tFP32Cmplx result;
	result.real = scale * tFP32_Cosine(num.imag);
	result.imag = scale * tFP32_Sine(num.imag);
	return result;
}
tFP32Cmplx tFP32Cmplx_Ln_iter(tFP32Cmplx num, tIUSz itr)
{
	tFP32Cmplx result;
	result.real = tFP32_Ln_iter(tFP32Cmplx_Mag_iter(num, itr), itr);
	result.imag = tFP32Cmplx_Arg_iter(num, itr);
	return result;
}
tFP32Cmplx tFP32Cmplx_Ln(tFP32Cmplx num)
{
	tFP32Cmplx result;
	result.real = tFP32_Ln(tFP32Cmplx_Mag(num));
	result.imag = tFP32Cmplx_Arg(num);
	return result;
}
tFP32Cmplx tFP32Cmplx_PowI(tFP32Cmplx num, tISSz exp)
{
	if (exp == 0) return tFP32Cmplx_Make(1.0F, 0.0F);
	if (exp < 0)
	{
		tFP32Cmplx inv;
		inv.real = 1.0F;
		inv.imag = 0.0F;
		return tFP32Cmplx_Div(inv, tFP32Cmplx_PowI(num, -exp));
	}
	tFP32Cmplx result;
	result.real = 1.0F;
	result.imag = 0.0F;
	while (exp != 0)
	{
		if (exp & 1) result = tFP32Cmplx_Mul(result, num);
		num = tFP32Cmplx_Mul(num, num);
		exp >>= 1U;
	}
	return result;
}
tFP32Cmplx tFP32Cmplx_Pow_iter(tFP32Cmplx base, tFP32Cmplx exp, tIUSz itr)
{
	return tFP32Cmplx_Exp_iter(tFP32Cmplx_Mul(exp, tFP32Cmplx_Ln_iter(base, itr)), itr);
}
tFP32Cmplx tFP32Cmplx_Pow(tFP32Cmplx base, tFP32Cmplx exp)
{
	return tFP32Cmplx_Exp(tFP32Cmplx_Mul(exp, tFP32Cmplx_Ln(base)));
}
ForceInline tBln tFP32Cmplx_Eq(tFP32Cmplx num1, tFP32Cmplx num2)
{
	return num1.real == num2.real && num1.imag == num2.imag;
}
ForceInline tBln tFP32Cmplx_Nearby(tFP32Cmplx num1, tFP32Cmplx num2)
{
	return tFP32_Nearby(num1.real, num2.real) && tFP32_Nearby(num1.imag, num2.imag);
}
ForceInline tFP32Cmplx tFP32Cmplx_Neg(tFP32Cmplx num)
{
	num.real = tFP32_Neg(num.real);
	num.imag = tFP32_Neg(num.imag);
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_One(void)
{
	tFP32Cmplx num;
	num.real = 1.0F;
	num.imag = 0.0F;
	return num;
}
ForceInline tFP32Cmplx tFP32Cmplx_I(void)
{
	tFP32Cmplx num;
	num.real = 0.0F;
	num.imag = 1.0F;
	return num;
}
tFP32Cmplx tFP32Cmplx_Recip(tFP32Cmplx num)
{
	return tFP32Cmplx_DivF(tFP32Cmplx_Conj(num), tFP32Cmplx_MagSq(num));
}
LINK_C_End
#endif/*BQSELAYER_CMPLX_IMPL*/
typedef tFP64 tFP64Real;
typedef tFP64 tFP64Imag;
typedef struct { tFP64Real real; tFP64Imag imag; } tFP64Cmplx;
ForceInline tFP64Cmplx tFP64Cmplx_Make(tFP64 real, tFP64 imag);
ForceInline tFP64Cmplx tFP64Cmplx_Zero(void);
ForceInline tFP64Cmplx tFP64Cmplx_Add(tFP64Cmplx num1, tFP64Cmplx num2);
ForceInline tFP64Cmplx tFP64Cmplx_Sub(tFP64Cmplx lhs, tFP64Cmplx rhs);
ForceInline tFP64Cmplx tFP64Cmplx_Mul(tFP64Cmplx num1, tFP64Cmplx num2);
tFP64Cmplx tFP64Cmplx_Div(tFP64Cmplx lhs, tFP64Cmplx rhs);
ForceInline tFP64Cmplx tFP64Cmplx_Conj(tFP64Cmplx num);
ForceInline tFP64 tFP64Cmplx_MagSq(tFP64Cmplx num);
ForceInline tFP64 tFP64Cmplx_Mag_iter(tFP64Cmplx num, tIUSz itr);
ForceInline tFP64 tFP64Cmplx_Mag(tFP64Cmplx num);
ForceInline tFP64Cmplx tFP64Cmplx_AddF(tFP64Cmplx num, tFP64 dbl);
ForceInline tFP64Cmplx tFP64Cmplx_SubF(tFP64Cmplx num, tFP64 dbl);
ForceInline tFP64Cmplx tFP64Cmplx_MulF(tFP64Cmplx num, tFP64 dbl);
ForceInline tFP64Cmplx tFP64Cmplx_DivF(tFP64Cmplx num, tFP64 dbl);
ForceInline tFP64 tFP64Cmplx_Arg_iter(tFP64Cmplx num, tIUSz itr);
ForceInline tFP64 tFP64Cmplx_Arg(tFP64Cmplx num);
tFP64Cmplx tFP64Cmplx_FromPolar_fast(tFP64 mag, tFP64 ang);
tFP64Cmplx tFP64Cmplx_FromPolar_iter(tFP64 mag, tFP64 ang, tIUSz itr);
tFP64Cmplx tFP64Cmplx_FromPolar(tFP64 mag, tFP64 ang);
tFP64Cmplx tFP64Cmplx_Sqrt_iter(tFP64Cmplx num, tIUSz itr);
tFP64Cmplx tFP64Cmplx_Sqrt(tFP64Cmplx num);
tFP64Cmplx tFP64Cmplx_Exp_iter(tFP64Cmplx num, tIUSz itr);
tFP64Cmplx tFP64Cmplx_Exp(tFP64Cmplx num);
tFP64Cmplx tFP64Cmplx_Ln_iter(tFP64Cmplx num, tIUSz itr);
tFP64Cmplx tFP64Cmplx_Ln(tFP64Cmplx num);
tFP64Cmplx tFP64Cmplx_PowI(tFP64Cmplx num, tISSz exp);
tFP64Cmplx tFP64Cmplx_Pow_iter(tFP64Cmplx base, tFP64Cmplx exp, tIUSz itr);
tFP64Cmplx tFP64Cmplx_Pow(tFP64Cmplx base, tFP64Cmplx exp);
ForceInline tBln tFP64Cmplx_Eq(tFP64Cmplx num1, tFP64Cmplx num2);
ForceInline tBln tFP64Cmplx_Nearby(tFP64Cmplx num1, tFP64Cmplx num2);
ForceInline tFP64Cmplx tFP64Cmplx_Neg(tFP64Cmplx num);
ForceInline tFP64Cmplx tFP64Cmplx_One(void);
ForceInline tFP64Cmplx tFP64Cmplx_I(void);
tFP64Cmplx tFP64Cmplx_Recip(tFP64Cmplx num);
#ifdef BQSELAYER_CMPLX_IMPL
LINK_C_Begin
ForceInline tFP64Cmplx tFP64Cmplx_Make(tFP64 real, tFP64 imag)
{
	tFP64Cmplx num;
	num.real = (tFP64Real)real;
	num.imag = (tFP64Imag)imag;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_Zero(void)
{
	tFP64Cmplx num;
	num.real = (tFP64Real)0.0;
	num.imag = (tFP64Imag)0.0;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_Add(tFP64Cmplx num1, tFP64Cmplx num2)
{
	num1.real += num2.real;
	num1.imag += num2.imag;
	return num1;
}
ForceInline tFP64Cmplx tFP64Cmplx_Sub(tFP64Cmplx lhs, tFP64Cmplx rhs)
{
	lhs.real -= rhs.real;
	lhs.imag -= rhs.imag;
	return lhs;
}
ForceInline tFP64Cmplx tFP64Cmplx_Mul(tFP64Cmplx num1, tFP64Cmplx num2)
{
	tFP64Cmplx num;
	num.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	num.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
	return num;
}
tFP64Cmplx tFP64Cmplx_Div(tFP64Cmplx lhs, tFP64Cmplx rhs)
{
	tFP64Cmplx num;
#ifndef BQSELAYER_DBG
	if (tFP64_Nearby(rhs.real, 0.0) && tFP64_Nearby(rhs.imag, 0.0))
	{
		num.real = tFP64_SigNaN();
		num.imag = tFP64_SigNaN();
		return num;
	}
#else
	Assertion(!tFP64_Nearby(rhs.real, 0.0) || !tFP64_Nearby(rhs.imag, 0.0));
#endif/*BQSELAYER_DBG*/
	tFP64 commonDenom = tFP64_Recip(tFP64_Sq(rhs.real) + tFP64_Sq(rhs.imag));
	num.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) * commonDenom;
	num.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) * commonDenom;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_Conj(tFP64Cmplx num)
{
	num.imag = tFP64_Neg(num.imag);
	return num;
}
ForceInline tFP64 tFP64Cmplx_MagSq(tFP64Cmplx num)
{
	return tFP64_Sq(num.real) + tFP64_Sq(num.imag);
}
ForceInline tFP64 tFP64Cmplx_Mag_iter(tFP64Cmplx num, tIUSz itr)
{
	return tFP64_Sqrt_iter(tFP64Cmplx_MagSq(num), itr);
}
ForceInline tFP64 tFP64Cmplx_Mag(tFP64Cmplx num)
{
	return tFP64_Sqrt(tFP64Cmplx_MagSq(num));
}
ForceInline tFP64Cmplx tFP64Cmplx_AddF(tFP64Cmplx num, tFP64 dbl)
{
	num.real += dbl;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_SubF(tFP64Cmplx num, tFP64 dbl)
{
	num.real -= dbl;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_MulF(tFP64Cmplx num, tFP64 dbl)
{
	num.real *= dbl;
	num.imag *= dbl;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_DivF(tFP64Cmplx num, tFP64 dbl)
{
#ifndef BQSELAYER_DBG
	if (tFP64_Nearby(dbl, 0.0))
	{
		num.real = tFP64_SigNaN();
		num.imag = tFP64_SigNaN();
		return num;
	}
#else
	Assertion(!tFP64_Nearby(dbl, 0.0));
#endif/*BQSELAYER_DBG*/
	num.real /= dbl;
	num.imag /= dbl;
	return num;
}
ForceInline tFP64 tFP64Cmplx_Arg_iter(tFP64Cmplx num, tIUSz itr)
{
	return tFP64_ArcTangent2_iter(num.imag, num.real, itr);
}
ForceInline tFP64 tFP64Cmplx_Arg(tFP64Cmplx num)
{
	return tFP64_ArcTangent2(num.imag, num.real);
}
tFP64Cmplx tFP64Cmplx_FromPolar_fast(tFP64 mag, tFP64 ang)
{
	tFP64Cmplx num;
	num.real = tFP64_Cosine_fast(ang) * mag;
	num.imag = tFP64_Sine_fast(ang) * mag;
	return num;
}
tFP64Cmplx tFP64Cmplx_FromPolar_iter(tFP64 mag, tFP64 ang, tIUSz itr)
{
	tFP64Cmplx num;
	num.real = tFP64_Cosine_iter(ang, itr) * mag;
	num.imag = tFP64_Sine_iter(ang, itr) * mag;
	return num;
}
tFP64Cmplx tFP64Cmplx_FromPolar(tFP64 mag, tFP64 ang)
{
	tFP64Cmplx num;
	num.real = tFP64_Cosine(ang) * mag;
	num.imag = tFP64_Sine(ang) * mag;
	return num;
}
tFP64Cmplx tFP64Cmplx_Sqrt_iter(tFP64Cmplx num, tIUSz itr)
{
	tFP64 mag = tFP64Cmplx_Mag_iter(num, itr);
#define BQSELAYER_RECIPSQRT2 0.707106781187
	tBln neg = tFP64_IsNeg(num.imag);
	num.imag = tFP64_Sqrt_iter(mag - num.real, itr) * BQSELAYER_RECIPSQRT2;
	num.real = tFP64_Sqrt_iter(mag + num.real, itr) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tFP64_Neg(num.imag);
	return num;
}
tFP64Cmplx tFP64Cmplx_Sqrt(tFP64Cmplx num)
{
	tFP64 mag = tFP64Cmplx_Mag(num);
#define BQSELAYER_RECIPSQRT2 0.707106781187
	tBln neg = tFP64_IsNeg(num.imag);
	num.imag = tFP64_Sqrt(mag - num.real) * BQSELAYER_RECIPSQRT2;
	num.real = tFP64_Sqrt(mag + num.real) * BQSELAYER_RECIPSQRT2;
#undef BQSELAYER_RECIPSQRT2
	if (neg) num.imag = tFP64_Neg(num.imag);
	return num;
}
tFP64Cmplx tFP64Cmplx_Exp_iter(tFP64Cmplx num, tIUSz itr)
{
	tFP64 scale = tFP64_Exp_iter(num.real, itr);
	tFP64Cmplx result;
	result.real = scale * tFP64_Cosine_iter(num.imag, itr);
	result.imag = scale * tFP64_Sine_iter(num.imag, itr);
	return result;
}
tFP64Cmplx tFP64Cmplx_Exp(tFP64Cmplx num)
{
	tFP64 scale = tFP64_Exp(num.real);
	tFP64Cmplx result;
	result.real = scale * tFP64_Cosine(num.imag);
	result.imag = scale * tFP64_Sine(num.imag);
	return result;
}
tFP64Cmplx tFP64Cmplx_Ln_iter(tFP64Cmplx num, tIUSz itr)
{
	tFP64Cmplx result;
	result.real = tFP64_Ln_iter(tFP64Cmplx_Mag_iter(num, itr), itr);
	result.imag = tFP64Cmplx_Arg_iter(num, itr);
	return result;
}
tFP64Cmplx tFP64Cmplx_Ln(tFP64Cmplx num)
{
	tFP64Cmplx result;
	result.real = tFP64_Ln(tFP64Cmplx_Mag(num));
	result.imag = tFP64Cmplx_Arg(num);
	return result;
}
tFP64Cmplx tFP64Cmplx_PowI(tFP64Cmplx num, tISSz exp)
{
	if (exp == 0) return tFP64Cmplx_Make(1.0, 0.0);
	if (exp < 0)
	{
		tFP64Cmplx inv;
		inv.real = 1.0;
		inv.imag = 0.0;
		return tFP64Cmplx_Div(inv, tFP64Cmplx_PowI(num, -exp));
	}
	tFP64Cmplx result;
	result.real = 1.0;
	result.imag = 0.0;
	while (exp != 0)
	{
		if (exp & 1) result = tFP64Cmplx_Mul(result, num);
		num = tFP64Cmplx_Mul(num, num);
		exp >>= 1U;
	}
	return result;
}
tFP64Cmplx tFP64Cmplx_Pow_iter(tFP64Cmplx base, tFP64Cmplx exp, tIUSz itr)
{
	return tFP64Cmplx_Exp_iter(tFP64Cmplx_Mul(exp, tFP64Cmplx_Ln_iter(base, itr)), itr);
}
tFP64Cmplx tFP64Cmplx_Pow(tFP64Cmplx base, tFP64Cmplx exp)
{
	return tFP64Cmplx_Exp(tFP64Cmplx_Mul(exp, tFP64Cmplx_Ln(base)));
}
ForceInline tBln tFP64Cmplx_Eq(tFP64Cmplx num1, tFP64Cmplx num2)
{
	return num1.real == num2.real && num1.imag == num2.imag;
}
ForceInline tBln tFP64Cmplx_Nearby(tFP64Cmplx num1, tFP64Cmplx num2)
{
	return tFP64_Nearby(num1.real, num2.real) && tFP64_Nearby(num1.imag, num2.imag);
}
ForceInline tFP64Cmplx tFP64Cmplx_Neg(tFP64Cmplx num)
{
	num.real = tFP64_Neg(num.real);
	num.imag = tFP64_Neg(num.imag);
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_One(void)
{
	tFP64Cmplx num;
	num.real = 1.0;
	num.imag = 0.0;
	return num;
}
ForceInline tFP64Cmplx tFP64Cmplx_I(void)
{
	tFP64Cmplx num;
	num.real = 0.0;
	num.imag = 1.0;
	return num;
}
tFP64Cmplx tFP64Cmplx_Recip(tFP64Cmplx num)
{
	return tFP64Cmplx_DivF(tFP64Cmplx_Conj(num), tFP64Cmplx_MagSq(num));
}
LINK_C_End
#endif/*BQSELAYER_CMPLX_IMPL*/
#endif/*BQSELAYER_CMPLX_H*/