#ifndef BQSELAYER_CMPLX_H
#define BQSELAYER_CMPLX_H
#include "BQSE_PrimTypes.h"
typedef tF32 tF32Real;
typedef tF32 tF32Imag;
typedef struct { tF32Real real; tF32Imag imag; } tF32Cmplx;
tF32Cmplx tF32Cmplx_Make(tF32 real, tF32 imag);
tF32Cmplx tF32Cmplx_Zero(void);
tF32Cmplx tF32Cmplx_Add(tF32Cmplx cmplx1, tF32Cmplx cmplx2);
tF32Cmplx tF32Cmplx_Sub(tF32Cmplx lhs, tF32Cmplx rhs);
tF32Cmplx tF32Cmplx_Mul(tF32Cmplx cmplx1, tF32Cmplx cmplx2);
tF32Cmplx tF32Cmplx_Div(tF32Cmplx lhs, tF32Cmplx rhs);
#ifdef BQSE_IMPL
LINK_C_Begin
FORCEINLINE tF32Cmplx tF32Cmplx_Make(tF32 real, tF32 imag)
{
	tF32Cmplx cmplx;
	cmplx.real = (tF32Real)real;
	cmplx.imag = (tF32Imag)imag;
	return cmplx;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Zero(void)
{
	tF32Cmplx cmplx;
	cmplx.real = (tF32Real)0.0F;
	cmplx.imag = (tF32Imag)0.0F;
	return cmplx;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Add(tF32Cmplx cmplx1, tF32Cmplx cmplx2)
{
	cmplx1.real += cmplx2.real;
	cmplx1.imag += cmplx2.imag;
	return cmplx1;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Sub(tF32Cmplx lhs, tF32Cmplx rhs)
{
	lhs.real -= rhs.real;
	lhs.imag -= rhs.imag;
	return lhs;
}
FORCEINLINE tF32Cmplx tF32Cmplx_Mul(tF32Cmplx cmplx1, tF32Cmplx cmplx2)
{
	tF32Cmplx cmplx;
	cmplx.real = (cmplx1.real * cmplx2.real) - (cmplx1.imag * cmplx2.imag);
	cmplx.imag = (cmplx1.real * cmplx2.imag) + (cmplx1.imag * cmplx2.real);
	return cmplx;
}
tF32Cmplx tF32Cmplx_Div(tF32Cmplx lhs, tF32Cmplx rhs)
{
	tF32Cmplx cmplx;
#ifndef BQSE_DBG
	if (tF32_Nearby(rhs.real, 0.0F) && tF32_Nearby(rhs.imag, 0.0F))
	{
		cmplx.real = tF32_SigNaN();
		cmplx.imag = tF32_SigNaN();
		return cmplx;
	}
#else
	Assertion(!tF32_Nearby(rhs.real, 0.0F) || !tF32_Nearby(rhs.imag, 0.0F));
#endif/*BQSE_DBG*/
	tF32 commonDenom = tF32_Recip(tF32_Sq(rhs.real) + tF32_Sq(rhs.imag));
	cmplx.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) * commonDenom;
	cmplx.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) * commonDenom;
	return cmplx;
}
LINK_C_End
#endif/*BQSE_IMPL*/
// TODO: tF64Cmplx declarations & implementations.
#endif/*BQSELAYER_CMPLX_H*/