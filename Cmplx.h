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
LINK_C_End
#endif/*BQSELAYER_IMPL*/
// TODO: tF64Cmplx declarations & implementations.
#endif/*BQSELAYER_CMPLX_H*/