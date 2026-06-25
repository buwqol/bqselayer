#ifndef BQSELAYER_CMPLX_H
#define BQSELAYER_CMPLX_H
#include "BQSE_PrimTypes.h"
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
tF32 tF32Cmplx_Mag(tF32Cmplx num);
tF32Cmplx tF32Cmplx_AddF(tF32Cmplx num, tF32 flt);
tF32Cmplx tF32Cmplx_SubF(tF32Cmplx num, tF32 flt);
tF32Cmplx tF32Cmplx_MulF(tF32Cmplx num, tF32 flt);
tF32Cmplx tF32Cmplx_DivF(tF32Cmplx num, tF32 flt);
tF32 tF32Cmplx_Arg_iter(tF32Cmplx num, tUSz itr);
tF32 tF32Cmplx_Arg(tF32Cmplx num);
tF32Cmplx tF32Cmplx_FromPolar(tF32 mag, tF32 ang);
tF32Cmplx tF32Cmplx_Sqrt(tF32Cmplx num);
tF32Cmplx tF32Cmplx_Exp(tF32Cmplx num);
tF32Cmplx tF32Cmplx_Ln(tF32Cmplx num);
tF32Cmplx tF32Cmplx_PowI(tF32Cmplx num, tSSz exp);
tF32Cmplx tF32Cmplx_Pow(tF32Cmplx base, tF32Cmplx exp);
#ifdef BQSE_IMPL
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
#ifndef BQSE_DBG
	if (tF32_Nearby(rhs.real, 0.0F) && tF32_Nearby(rhs.imag, 0.0F))
	{
		num.real = tF32_SigNaN();
		num.imag = tF32_SigNaN();
		return num;
	}
#else
	Assertion(!tF32_Nearby(rhs.real, 0.0F) || !tF32_Nearby(rhs.imag, 0.0F));
#endif/*BQSE_DBG*/
	tF32 commonDenom = tF32_Recip(tF32_Sq(rhs.real) + tF32_Sq(rhs.imag));
	num.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) * commonDenom;
	num.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) * commonDenom;
	return num;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Conj(tF32Cmplx num)
{
	tF32_Swap(&num.real, &num.imag);
}
FORCEINLINE tF32 tF32Cmplx_MagSq(tF32Cmplx num)
{
	return tF32_Sq(num.real) + tF32_Sq(num.imag);
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
#ifndef BQSE_DBG
	if (tF32_Nearby(flt, 0.0F))
	{
		num.real = tF32_SigNaN();
		num.imag = tF32_SigNaN();
		return num;
	}
#else
	Assertion(!tF32_Nearby(flt, 0.0F));
#endif/*BQSE_DBG*/
	num.real /= flt;
	num.imag /= flt;
	return num;
}
tF32 tF32Cmplx_Arg_iter(tF32Cmplx num, tUSz itr)
{
	return tF32_ArcTangent2_iter(num.imag, num.real, itr);
}
tF32 tF32Cmplx_Arg(tF32Cmplx num)
{
	return tF32_ArcTangent2(num.imag, num.real);
}
LINK_C_End
#endif/*BQSE_IMPL*/
// TODO: tF64Cmplx declarations & implementations.
#endif/*BQSELAYER_CMPLX_H*/