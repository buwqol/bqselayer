#ifndef BQSELAYER_VECT_H
#define BQSELAYER_VECT_H
#include "PrimTypes.h"
enum eAxis
{
	eAxis_X,
	eAxis_Y,
	eAxis_Z,
	eAxis_W
};
typedef union { struct { tS32 x, y; }; tS32 v[2]; } tS32V2D;
LINK_C_Begin
ForceInline tS32V2D tS32V2D_Make(tS32 x, tS32 y);
ForceInline tS32V2D tS32V2D_Zero(tNone);
ForceInline tS32V2D tS32V2D_Add(tS32V2D vect1, tS32V2D vect2);
ForceInline tS32V2D tS32V2D_Sub(tS32V2D vect1, tS32V2D vect2);
ForceInline tS32V2D tS32V2D_Mul(tS32V2D vect, tS32 mod);
/*Warn: Silently returns `tS32V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tS32V2D tS32V2D_Div(tS32V2D vect, tS32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tS32V2D_Div_safe(tS32V2D *vect, tS32 mod);
ForceInline tBln tS32V2D_Eq(tS32V2D vect1, tS32V2D vect2);
ForceInline tS32 tS32V2D_Dot(tS32V2D vect1, tS32V2D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tS32V2D tS32V2D_Make(tS32 x, tS32 y)
{
	tS32V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tS32V2D tS32V2D_Zero(tNone)
{
	tS32V2D vect;
	vect.x = 0;
	vect.y = 0;
	return vect;
}
ForceInline tS32V2D tS32V2D_Add(tS32V2D vect1, tS32V2D vect2)
{
	tS32V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tS32V2D tS32V2D_Sub(tS32V2D vect1, tS32V2D vect2)
{
	tS32V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tS32V2D tS32V2D_Mul(tS32V2D vect, tS32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tS32V2D tS32V2D_Div(tS32V2D vect, tS32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (mod == 0)
	{
		vect.x = tS32_Max;
		vect.y = tS32_Max;
		return vect;
	}
#else
	Assertion(mod != 0);
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tS32V2D_Div_safe(tS32V2D *vect, tS32 mod)
{
	if (mod == 0) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
ForceInline tBln tS32V2D_Eq(tS32V2D vect1, tS32V2D vect2)
{
	return (vect1.x == vect2.x) && (vect1.y == vect2.y);
}
ForceInline tS32 tS32V2D_Dot(tS32V2D vect1, tS32V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tS64 x, y; }; tS64 v[2]; } tS64V2D;
LINK_C_Begin
ForceInline tS64V2D tS64V2D_Make(tS64 x, tS64 y);
ForceInline tS64V2D tS64V2D_Zero(tNone);
ForceInline tS64V2D tS64V2D_Add(tS64V2D vect1, tS64V2D vect2);
ForceInline tS64V2D tS64V2D_Sub(tS64V2D vect1, tS64V2D vect2);
ForceInline tS64V2D tS64V2D_Mul(tS64V2D vect, tS64 mod);
/*Warn: Silently returns `tS64V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tS64V2D tS64V2D_Div(tS64V2D vect, tS64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tS64V2D_Div_safe(tS64V2D *vect, tS64 mod);
ForceInline tBln tS64V2D_Eq(tS64V2D vect1, tS64V2D vect2);
ForceInline tS64 tS64V2D_Dot(tS64V2D vect1, tS64V2D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tS64V2D tS64V2D_Make(tS64 x, tS64 y)
{
	tS64V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tS64V2D tS64V2D_Zero(tNone)
{
	tS64V2D vect;
	vect.x = 0;
	vect.y = 0;
	return vect;
}
ForceInline tS64V2D tS64V2D_Add(tS64V2D vect1, tS64V2D vect2)
{
	tS64V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tS64V2D tS64V2D_Sub(tS64V2D vect1, tS64V2D vect2)
{
	tS64V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tS64V2D tS64V2D_Mul(tS64V2D vect, tS64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tS64V2D tS64V2D_Div(tS64V2D vect, tS64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (mod == 0)
	{
		vect.x = tS64_Max;
		vect.y = tS64_Max;
		return vect;
	}
#else
	Assertion(mod != 0);
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tS64V2D_Div_safe(tS64V2D *vect, tS64 mod)
{
	if (mod == 0) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
ForceInline tBln tS64V2D_Eq(tS64V2D vect1, tS64V2D vect2)
{
	return (vect1.x == vect2.x) && (vect1.y == vect2.y);
}
ForceInline tS64 tS64V2D_Dot(tS64V2D vect1, tS64V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tF32 x, y; }; tF32 v[2]; } tF32V2D;
LINK_C_Begin
ForceInline tF32V2D tF32V2D_Make(tF32 x, tF32 y);
ForceInline tF32V2D tF32V2D_Zero(tNone);
ForceInline tF32V2D tF32V2D_Add(tF32V2D vect1, tF32V2D vect2);
ForceInline tF32V2D tF32V2D_Sub(tF32V2D vect1, tF32V2D vect2);
ForceInline tF32V2D tF32V2D_Mul(tF32V2D vect, tF32 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tF32V2D tF32V2D_Div(tF32V2D vect, tF32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tF32V2D_Div_safe(tF32V2D *vect, tF32 mod);
tF32 tF32V2D_Dot(tF32V2D vect1, tF32V2D vect2);
ForceInline tBln tF32V2D_Eq(tF32V2D vect1, tF32V2D vect2);
ForceInline tBln tF32V2D_Nearby(tF32V2D vect1, tF32V2D vect2, tF32 eps);
ForceInline tF32 tF32V2D_LngSq(tF32V2D vect);
ForceInline tF32 tF32V2D_Lng(tF32V2D vect);
/*Note: `rot` is in radians. A value of 0 will produce a unit vector along the positive X-axis.*/
ForceInline tF32V2D tF32V2D_Unit(tF32 rot);
/*Warn: Silently returns `tF32V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tF32V2D tF32V2D_Norm(tF32V2D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tF32V2D_Norm_safe(tF32V2D *vect);
/*Warn: Silently returns `tF32V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tF32V2D tF32V2D_Norm_fast(tF32V2D vect);
/*Note: Returns `False` on success.*/
tBln tF32V2D_Norm_fast_safe(tF32V2D *vect);
ForceInline tF32 tF32V2D_DistSq(tF32V2D vect1, tF32V2D vect2);
ForceInline tF32 tF32V2D_Dist(tF32V2D vect1, tF32V2D vect2);
ForceInline tF32V2D tF32V2D_Lerp(tF32V2D vect1, tF32V2D vect2, tF32 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tF32V2D tF32V2D_Make(tF32 x, tF32 y)
{
	tF32V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tF32V2D tF32V2D_Zero(tNone)
{
	tF32V2D vect;
	vect.x = 0.0F;
	vect.y = 0.0F;
	return vect;
}
ForceInline tF32V2D tF32V2D_Add(tF32V2D vect1, tF32V2D vect2)
{
	tF32V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tF32V2D tF32V2D_Sub(tF32V2D vect1, tF32V2D vect2)
{
	tF32V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tF32V2D tF32V2D_Mul(tF32V2D vect, tF32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tF32V2D tF32V2D_Div(tF32V2D vect, tF32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(mod, 0.0F))
	{
		vect.x = tF32_IsNeg(vect.x) ? tF32_NegInf() : tF32_Inf();
		vect.y = tF32_IsNeg(vect.y) ? tF32_NegInf() : tF32_Inf();
		return vect;
	}
#else
	Assertion(!tF32_Nearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tF32V2D_Div_safe(tF32V2D *vect, tF32 mod)
{
	if (tF32_Nearby(mod, 0.0F)) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
tF32 tF32V2D_Dot(tF32V2D vect1, tF32V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
ForceInline tBln tF32V2D_Eq(tF32V2D vect1, tF32V2D vect2)
{
	return tF32_Nearby(vect1.x, vect2.x) && tF32_Nearby(vect1.y, vect2.y);
}
ForceInline tBln tF32V2D_Nearby(tF32V2D vect1, tF32V2D vect2, tF32 eps)
{
	return (tF32_Abs(vect1.x - vect2.x) <= eps) && (tF32_Abs(vect1.y - vect2.y) <= eps);
}
ForceInline tF32 tF32V2D_LngSq(tF32V2D vect)
{
	return tF32V2D_Dot(vect, vect);
}
ForceInline tF32 tF32V2D_Lng(tF32V2D vect)
{
	return tF32_Sqrt(tF32V2D_LngSq(vect));
}
ForceInline tF32V2D tF32V2D_Unit(tF32 rot)
{
	tF32V2D vect;
	vect.x = tF32_Cosine_fast(rot);
	vect.y = tF32_Sine_fast(rot);
	return vect;
}
ForceInline tF32V2D tF32V2D_Norm(tF32V2D vect)
{
	tF32 lng = tF32V2D_Lng(vect);
	return tF32V2D_Div(vect, lng);
}
ForceInline tBln tF32V2D_Norm_safe(tF32V2D *vect)
{
	return tF32V2D_Div_safe(vect, tF32V2D_Lng(*vect));
}
ForceInline tF32V2D tF32V2D_Norm_fast(tF32V2D vect)
{
	tF32 lngSq = tF32V2D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(lngSq, 0.0F)) return tF32V2D_Zero();
#else
	Assertion(!tF32_Nearby(lngSq, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tF32V2D_Mul(vect, tF32_RecipSqrt(lngSq));
}
tBln tF32V2D_Norm_fast_safe(tF32V2D *vect)
{
	tF32 lngSq = tF32V2D_LngSq(*vect);
	if (tF32_Nearby(lngSq, 0.0F)) return True;
	tF32V2D_Mul(*vect, tF32_RecipSqrt(lngSq));
	return False;
}
ForceInline tF32 tF32V2D_DistSq(tF32V2D vect1, tF32V2D vect2)
{
	return tF32V2D_LngSq(tF32V2D_Sub(vect1, vect2));
}
ForceInline tF32 tF32V2D_Dist(tF32V2D vect1, tF32V2D vect2)
{
	return tF32V2D_Lng(tF32V2D_Sub(vect1, vect2));
}
ForceInline tF32V2D tF32V2D_Lerp(tF32V2D vect1, tF32V2D vect2, tF32 stp)
{
	tF32V2D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tF32 x, y, z; }; tF32 v[3]; } tF32V3D;
LINK_C_Begin
ForceInline tF32V3D tF32V3D_Make(tF32 x, tF32 y, tF32 z);
ForceInline tF32V3D tF32V3D_Zero(tNone);
ForceInline tF32V3D tF32V3D_Add(tF32V3D vect1, tF32V3D vect2);
ForceInline tF32V3D tF32V3D_Sub(tF32V3D vect1, tF32V3D vect2);
ForceInline tF32V3D tF32V3D_Mul(tF32V3D vect, tF32 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tF32V3D tF32V3D_Div(tF32V3D vect, tF32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tF32V3D_Div_safe(tF32V3D *vect, tF32 mod);
tF32 tF32V3D_Dot(tF32V3D vect1, tF32V3D vect2);
ForceInline tBln tF32V3D_Eq(tF32V3D vect1, tF32V3D vect2);
tBln tF32V3D_Nearby(tF32V3D vect1, tF32V3D vect2, tF32 eps);
ForceInline tF32 tF32V3D_LngSq(tF32V3D vect);
ForceInline tF32 tF32V3D_Lng(tF32V3D vect);
/*Note: `yaw` and `pitch` are in radians.*/
tF32V3D tF32V3D_Unit(tF32 yaw, tF32 pitch);
/*Warn: Silently returns `tF32V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF32V3D tF32V3D_Norm(tF32V3D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tF32V3D_Norm_safe(tF32V3D *vect);
/*Warn: Silently returns `tF32V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF32V3D tF32V3D_Norm_fast(tF32V3D vect);
/*Note: Returns `False` on success.*/
tBln tF32V3D_Norm_fast_safe(tF32V3D *vect);
ForceInline tF32 tF32V3D_DistSq(tF32V3D vect1, tF32V3D vect2);
ForceInline tF32 tF32V3D_Dist(tF32V3D vect1, tF32V3D vect2);
tF32V3D tF32V3D_Lerp(tF32V3D vect1, tF32V3D vect2, tF32 stp);
tF32V3D tF32V3D_Cross(tF32V3D vect1, tF32V3D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tF32V3D tF32V3D_Make(tF32 x, tF32 y, tF32 z)
{
	tF32V3D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	return vect;
}
ForceInline tF32V3D tF32V3D_Zero(tNone)
{
	tF32V3D vect;
	vect.x = 0.0F;
	vect.y = 0.0F;
	vect.z = 0.0F;
	return vect;
}
ForceInline tF32V3D tF32V3D_Add(tF32V3D vect1, tF32V3D vect2)
{
	tF32V3D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	return vect;
}
ForceInline tF32V3D tF32V3D_Sub(tF32V3D vect1, tF32V3D vect2)
{
	tF32V3D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return vect;
}
ForceInline tF32V3D tF32V3D_Mul(tF32V3D vect, tF32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	return vect;
}
tF32V3D tF32V3D_Div(tF32V3D vect, tF32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(mod, 0.0F))
	{
		vect.x = tF32_IsNeg(vect.x) ? tF32_NegInf() : tF32_Inf();
		vect.y = tF32_IsNeg(vect.y) ? tF32_NegInf() : tF32_Inf();
		vect.z = tF32_IsNeg(vect.z) ? tF32_NegInf() : tF32_Inf();
		return vect;
	}
#else
	Assertion(!tF32_Nearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	return vect;
}
ForceInline tBln tF32V3D_Div_safe(tF32V3D *vect, tF32 mod)
{
	if (tF32_Nearby(mod, 0.0F)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	return False;
}
tF32 tF32V3D_Dot(tF32V3D vect1, tF32V3D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
}
ForceInline tBln tF32V3D_Eq(tF32V3D vect1, tF32V3D vect2)
{
	return tF32_Nearby(vect1.x, vect2.x) && tF32_Nearby(vect1.y, vect2.y) && tF32_Nearby(vect1.z, vect2.z);
}
tBln tF32V3D_Nearby(tF32V3D vect1, tF32V3D vect2, tF32 eps)
{
	return (tF32_Abs(vect1.x - vect2.x) <= eps) && (tF32_Abs(vect1.y - vect2.y) <= eps) && (tF32_Abs(vect1.z - vect2.z) <= eps);
}
ForceInline tF32 tF32V3D_LngSq(tF32V3D vect)
{
	return tF32V3D_Dot(vect, vect);
}
ForceInline tF32 tF32V3D_Lng(tF32V3D vect)
{
	return tF32_Sqrt(tF32V3D_LngSq(vect));
}
tF32V3D tF32V3D_Unit(tF32 yaw, tF32 pitch)
{
	tF32V3D vect;
	const tF32 cosP = tF32_Cosine_fast(pitch);
	const tF32 cosY = tF32_Cosine_fast(yaw);
	const tF32 sinY = tF32_Sine_fast(yaw);
	const tF32 sinP = tF32_Sine_fast(pitch);
	vect.x = cosP * cosY;
	vect.y = sinP;
	vect.z = cosP * sinY;
	return vect;
}
tF32V3D tF32V3D_Norm(tF32V3D vect)
{
	tF32 lng = tF32V3D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(lng, 0.0F)) return tF32V3D_Zero();
#else
	Assertion(!tF32_Nearby(lng, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tF32V3D_Div(vect, lng);
}
ForceInline tBln tF32V3D_Norm_safe(tF32V3D *vect)
{
	return tF32V3D_Div_safe(vect, tF32V3D_Lng(*vect));
}
tF32V3D tF32V3D_Norm_fast(tF32V3D vect)
{
	tF32 lngSq = tF32V3D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(lngSq, 0.0F)) return tF32V3D_Zero();
#else
	Assertion(!tF32_Nearby(lngSq, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tF32V3D_Mul(vect, tF32_RecipSqrt(lngSq));
}
tBln tF32V3D_Norm_fast_safe(tF32V3D *vect)
{
	tF32 lngSq = tF32V3D_LngSq(*vect);
	if (tF32_Nearby(lngSq, 0.0F)) return True;
	tF32V3D_Mul(*vect, tF32_RecipSqrt(lngSq));
	return False;
}
ForceInline tF32 tF32V3D_DistSq(tF32V3D vect1, tF32V3D vect2)
{
	return tF32V3D_LngSq(tF32V3D_Sub(vect1, vect2));
}
ForceInline tF32 tF32V3D_Dist(tF32V3D vect1, tF32V3D vect2)
{
	return tF32V3D_Lng(tF32V3D_Sub(vect1, vect2));
}
tF32V3D tF32V3D_Lerp(tF32V3D vect1, tF32V3D vect2, tF32 stp)
{
	tF32V3D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	return vect;
}
tF32V3D tF32V3D_Cross(tF32V3D vect1, tF32V3D vect2)
{
	tF32V3D vect;
	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tF32 x, y, z, w; }; tF32 v[4]; } tF32V4D;
LINK_C_Begin
ForceInline tF32V4D tF32V4D_Make(tF32 x, tF32 y, tF32 z, tF32 w);
ForceInline tF32V4D tF32V4D_Zero(tNone);
ForceInline tF32V4D tF32V4D_Add(tF32V4D vect1, tF32V4D vect2);
ForceInline tF32V4D tF32V4D_Sub(tF32V4D vect1, tF32V4D vect2);
ForceInline tF32V4D tF32V4D_Mul(tF32V4D vect, tF32 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tF32V4D tF32V4D_Div(tF32V4D vect, tF32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tF32V4D_Div_safe(tF32V4D *vect, tF32 mod);
tF32 tF32V4D_Dot(tF32V4D vect1, tF32V4D vect2);
ForceInline tBln tF32V4D_Eq(tF32V4D vect1, tF32V4D vect2);
tBln tF32V4D_Nearby(tF32V4D vect1, tF32V4D vect2, tF32 eps);
ForceInline tF32 tF32V4D_LngSq(tF32V4D vect);
ForceInline tF32 tF32V4D_Lng(tF32V4D vect);
/*Warn: Silently returns `tF32V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF32V4D tF32V4D_Norm(tF32V4D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tF32V4D_Norm_safe(tF32V4D *vect);
/*Warn: Silently returns `tF32V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF32V4D tF32V4D_Norm_fast(tF32V4D vect);
/*Note: Returns `False` on success.*/
tBln tF32V4D_Norm_fast_safe(tF32V4D *vect);
ForceInline tF32 tF32V4D_DistSq(tF32V4D vect1, tF32V4D vect2);
ForceInline tF32 tF32V4D_Dist(tF32V4D vect1, tF32V4D vect2);
tF32V4D tF32V4D_Lerp(tF32V4D vect1, tF32V4D vect2, tF32 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tF32V4D tF32V4D_Make(tF32 x, tF32 y, tF32 z, tF32 w)
{
	tF32V4D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = w;
	return vect;
}
ForceInline tF32V4D tF32V4D_Zero(tNone)
{
	tF32V4D vect;
	vect.x = 0.0F;
	vect.y = 0.0F;
	vect.z = 0.0F;
	vect.w = 0.0F;
	return vect;
}
ForceInline tF32V4D tF32V4D_Add(tF32V4D vect1, tF32V4D vect2)
{
	tF32V4D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	vect.w = vect1.w + vect2.w;
	return vect;
}
ForceInline tF32V4D tF32V4D_Sub(tF32V4D vect1, tF32V4D vect2)
{
	tF32V4D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	vect.w = vect1.w - vect2.w;
	return vect;
}
ForceInline tF32V4D tF32V4D_Mul(tF32V4D vect, tF32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	vect.w *= mod;
	return vect;
}
tF32V4D tF32V4D_Div(tF32V4D vect, tF32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(mod, 0.0F))
	{
		vect.x = tF32_IsNeg(vect.x) ? tF32_NegInf() : tF32_Inf();
		vect.y = tF32_IsNeg(vect.y) ? tF32_NegInf() : tF32_Inf();
		vect.z = tF32_IsNeg(vect.z) ? tF32_NegInf() : tF32_Inf();
		vect.w = tF32_IsNeg(vect.w) ? tF32_NegInf() : tF32_Inf();
		return vect;
	}
#else
	Assertion(!tF32_Nearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	vect.w /= mod;
	return vect;
}
ForceInline tBln tF32V4D_Div_safe(tF32V4D *vect, tF32 mod)
{
	if (tF32_Nearby(mod, 0.0F)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	vect->w /= mod;
	return False;
}
tF32 tF32V4D_Dot(tF32V4D vect1, tF32V4D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z + vect1.w * vect2.w;
}
ForceInline tBln tF32V4D_Eq(tF32V4D vect1, tF32V4D vect2)
{
	return tF32_Nearby(vect1.x, vect2.x) && tF32_Nearby(vect1.y, vect2.y) && tF32_Nearby(vect1.z, vect2.z) && tF32_Nearby(vect1.w, vect2.w);
}
tBln tF32V4D_Nearby(tF32V4D vect1, tF32V4D vect2, tF32 eps)
{
	return (tF32_Abs(vect1.x - vect2.x) <= eps) && (tF32_Abs(vect1.y - vect2.y) <= eps) && (tF32_Abs(vect1.z - vect2.z) <= eps) && (tF32_Abs(vect1.w - vect2.w) <= eps);
}
ForceInline tF32 tF32V4D_LngSq(tF32V4D vect)
{
	return tF32V4D_Dot(vect, vect);
}
ForceInline tF32 tF32V4D_Lng(tF32V4D vect)
{
	return tF32_Sqrt(tF32V4D_LngSq(vect));
}
tF32V4D tF32V4D_Norm(tF32V4D vect)
{
	tF32 lng = tF32V4D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(lng, 0.0F)) return tF32V4D_Zero();
#else
	Assertion(!tF32_Nearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tF32V4D_Div(vect, lng);
}
ForceInline tBln tF32V4D_Norm_safe(tF32V4D *vect)
{
	return tF32V4D_Div_safe(vect, tF32V4D_Lng(*vect));
}
tF32V4D tF32V4D_Norm_fast(tF32V4D vect)
{
	tF32 lngSq = tF32V4D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tF32_Nearby(lngSq, 0.0F)) return tF32V4D_Zero();
#else
	Assertion(!tF32_Nearby(lngSq, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tF32V4D_Mul(vect, tF32_RecipSqrt(lngSq));
}
tBln tF32V4D_Norm_fast_safe(tF32V4D *vect)
{
	tF32 lngSq = tF32V4D_LngSq(*vect);
	if (tF32_Nearby(lngSq, 0.0F)) return True;
	tF32V4D_Mul(*vect, tF32_RecipSqrt(lngSq));
	return False;
}
ForceInline tF32 tF32V4D_DistSq(tF32V4D vect1, tF32V4D vect2)
{
	return tF32V4D_LngSq(tF32V4D_Sub(vect1, vect2));
}
ForceInline tF32 tF32V4D_Dist(tF32V4D vect1, tF32V4D vect2)
{
	return tF32V4D_Lng(tF32V4D_Sub(vect1, vect2));
}
tF32V4D tF32V4D_Lerp(tF32V4D vect1, tF32V4D vect2, tF32 stp)
{
	tF32V4D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	vect.w = vect1.w + (vect2.w - vect1.w) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tF64 x, y; }; tF64 v[2]; } tF64V2D;
LINK_C_Begin
ForceInline tF64V2D tF64V2D_Make(tF64 x, tF64 y);
ForceInline tF64V2D tF64V2D_Zero(tNone);
ForceInline tF64V2D tF64V2D_Add(tF64V2D vect1, tF64V2D vect2);
ForceInline tF64V2D tF64V2D_Sub(tF64V2D vect1, tF64V2D vect2);
ForceInline tF64V2D tF64V2D_Mul(tF64V2D vect, tF64 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tF64V2D tF64V2D_Div(tF64V2D vect, tF64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tF64V2D_Div_safe(tF64V2D *vect, tF64 mod);
tF64 tF64V2D_Dot(tF64V2D vect1, tF64V2D vect2);
ForceInline tBln tF64V2D_Eq(tF64V2D vect1, tF64V2D vect2);
ForceInline tBln tF64V2D_Nearby(tF64V2D vect1, tF64V2D vect2, tF64 eps);
ForceInline tF64 tF64V2D_LngSq(tF64V2D vect);
ForceInline tF64 tF64V2D_Lng(tF64V2D vect);
/*Note: `rot` is in radians. A value of 0 will produce a unit vector along the positive X-axis.*/
ForceInline tF64V2D tF64V2D_Unit(tF64 rot);
/*Warn: Silently returns `tF64V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tF64V2D tF64V2D_Norm(tF64V2D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tF64V2D_Norm_safe(tF64V2D *vect);
/*Warn: Silently returns `tF64V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tF64V2D tF64V2D_Norm_fast(tF64V2D vect);
/*Note: Returns `False` on success.*/
tBln tF64V2D_Norm_fast_safe(tF64V2D *vect);
ForceInline tF64 tF64V2D_DistSq(tF64V2D vect1, tF64V2D vect2);
ForceInline tF64 tF64V2D_Dist(tF64V2D vect1, tF64V2D vect2);
ForceInline tF64V2D tF64V2D_Lerp(tF64V2D vect1, tF64V2D vect2, tF64 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tF64V2D tF64V2D_Make(tF64 x, tF64 y)
{
	tF64V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tF64V2D tF64V2D_Zero(tNone)
{
	tF64V2D vect;
	vect.x = 0.0;
	vect.y = 0.0;
	return vect;
}
ForceInline tF64V2D tF64V2D_Add(tF64V2D vect1, tF64V2D vect2)
{
	tF64V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tF64V2D tF64V2D_Sub(tF64V2D vect1, tF64V2D vect2)
{
	tF64V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tF64V2D tF64V2D_Mul(tF64V2D vect, tF64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tF64V2D tF64V2D_Div(tF64V2D vect, tF64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(mod, 0.0))
	{
		vect.x = tF64_IsNeg(vect.x) ? tF64_NegInf() : tF64_Inf();
		vect.y = tF64_IsNeg(vect.y) ? tF64_NegInf() : tF64_Inf();
		return vect;
	}
#else
	Assertion(!tF64_Nearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tF64V2D_Div_safe(tF64V2D *vect, tF64 mod)
{
	if (tF64_Nearby(mod, 0.0)) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
tF64 tF64V2D_Dot(tF64V2D vect1, tF64V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
ForceInline tBln tF64V2D_Eq(tF64V2D vect1, tF64V2D vect2)
{
	return tF64_Nearby(vect1.x, vect2.x) && tF64_Nearby(vect1.y, vect2.y);
}
ForceInline tBln tF64V2D_Nearby(tF64V2D vect1, tF64V2D vect2, tF64 eps)
{
	return (tF64_Abs(vect1.x - vect2.x) <= eps) && (tF64_Abs(vect1.y - vect2.y) <= eps);
}
ForceInline tF64 tF64V2D_LngSq(tF64V2D vect)
{
	return tF64V2D_Dot(vect, vect);
}
ForceInline tF64 tF64V2D_Lng(tF64V2D vect)
{
	return tF64_Sqrt(tF64V2D_LngSq(vect));
}
ForceInline tF64V2D tF64V2D_Unit(tF64 rot)
{
	tF64V2D vect;
	vect.x = tF64_Cosine_fast(rot);
	vect.y = tF64_Sine_fast(rot);
	return vect;
}
ForceInline tF64V2D tF64V2D_Norm(tF64V2D vect)
{
	tF64 lng = tF64V2D_Lng(vect);
	return tF64V2D_Div(vect, lng);
}
ForceInline tBln tF64V2D_Norm_safe(tF64V2D *vect)
{
	return tF64V2D_Div_safe(vect, tF64V2D_Lng(*vect));
}
ForceInline tF64V2D tF64V2D_Norm_fast(tF64V2D vect)
{
	tF64 lngSq = tF64V2D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(lngSq, 0.0)) return tF64V2D_Zero();
#else
	Assertion(!tF64_Nearby(lngSq, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tF64V2D_Mul(vect, tF64_RecipSqrt(lngSq));
}
tBln tF64V2D_Norm_fast_safe(tF64V2D *vect)
{
	tF64 lngSq = tF64V2D_LngSq(*vect);
	if (tF64_Nearby(lngSq, 0.0)) return True;
	tF64V2D_Mul(*vect, tF64_RecipSqrt(lngSq));
	return False;
}
ForceInline tF64 tF64V2D_DistSq(tF64V2D vect1, tF64V2D vect2)
{
	return tF64V2D_LngSq(tF64V2D_Sub(vect1, vect2));
}
ForceInline tF64 tF64V2D_Dist(tF64V2D vect1, tF64V2D vect2)
{
	return tF64V2D_Lng(tF64V2D_Sub(vect1, vect2));
}
ForceInline tF64V2D tF64V2D_Lerp(tF64V2D vect1, tF64V2D vect2, tF64 stp)
{
	tF64V2D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tF64 x, y, z; }; tF64 v[3]; } tF64V3D;
LINK_C_Begin
ForceInline tF64V3D tF64V3D_Make(tF64 x, tF64 y, tF64 z);
ForceInline tF64V3D tF64V3D_Zero(tNone);
ForceInline tF64V3D tF64V3D_Add(tF64V3D vect1, tF64V3D vect2);
ForceInline tF64V3D tF64V3D_Sub(tF64V3D vect1, tF64V3D vect2);
ForceInline tF64V3D tF64V3D_Mul(tF64V3D vect, tF64 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tF64V3D tF64V3D_Div(tF64V3D vect, tF64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tF64V3D_Div_safe(tF64V3D *vect, tF64 mod);
tF64 tF64V3D_Dot(tF64V3D vect1, tF64V3D vect2);
ForceInline tBln tF64V3D_Eq(tF64V3D vect1, tF64V3D vect2);
tBln tF64V3D_Nearby(tF64V3D vect1, tF64V3D vect2, tF64 eps);
ForceInline tF64 tF64V3D_LngSq(tF64V3D vect);
ForceInline tF64 tF64V3D_Lng(tF64V3D vect);
/*Note: `yaw` and `pitch` are in radians.*/
tF64V3D tF64V3D_Unit(tF64 yaw, tF64 pitch);
/*Warn: Silently returns `tF64V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF64V3D tF64V3D_Norm(tF64V3D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tF64V3D_Norm_safe(tF64V3D *vect);
/*Warn: Silently returns `tF64V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF64V3D tF64V3D_Norm_fast(tF64V3D vect);
/*Note: Returns `False` on success.*/
tBln tF64V3D_Norm_fast_safe(tF64V3D *vect);
ForceInline tF64 tF64V3D_DistSq(tF64V3D vect1, tF64V3D vect2);
ForceInline tF64 tF64V3D_Dist(tF64V3D vect1, tF64V3D vect2);
tF64V3D tF64V3D_Lerp(tF64V3D vect1, tF64V3D vect2, tF64 stp);
tF64V3D tF64V3D_Cross(tF64V3D vect1, tF64V3D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tF64V3D tF64V3D_Make(tF64 x, tF64 y, tF64 z)
{
	tF64V3D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	return vect;
}
ForceInline tF64V3D tF64V3D_Zero(tNone)
{
	tF64V3D vect;
	vect.x = 0.0;
	vect.y = 0.0;
	vect.z = 0.0;
	return vect;
}
ForceInline tF64V3D tF64V3D_Add(tF64V3D vect1, tF64V3D vect2)
{
	tF64V3D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	return vect;
}
ForceInline tF64V3D tF64V3D_Sub(tF64V3D vect1, tF64V3D vect2)
{
	tF64V3D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return vect;
}
ForceInline tF64V3D tF64V3D_Mul(tF64V3D vect, tF64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	return vect;
}
tF64V3D tF64V3D_Div(tF64V3D vect, tF64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(mod, 0.0))
	{
		vect.x = tF64_IsNeg(vect.x) ? tF64_NegInf() : tF64_Inf();
		vect.y = tF64_IsNeg(vect.y) ? tF64_NegInf() : tF64_Inf();
		vect.z = tF64_IsNeg(vect.z) ? tF64_NegInf() : tF64_Inf();
		return vect;
	}
#else
	Assertion(!tF64_Nearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	return vect;
}
ForceInline tBln tF64V3D_Div_safe(tF64V3D *vect, tF64 mod)
{
	if (tF64_Nearby(mod, 0.0)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	return False;
}
tF64 tF64V3D_Dot(tF64V3D vect1, tF64V3D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
}
ForceInline tBln tF64V3D_Eq(tF64V3D vect1, tF64V3D vect2)
{
	return tF64_Nearby(vect1.x, vect2.x) && tF64_Nearby(vect1.y, vect2.y) && tF64_Nearby(vect1.z, vect2.z);
}
tBln tF64V3D_Nearby(tF64V3D vect1, tF64V3D vect2, tF64 eps)
{
	return (tF64_Abs(vect1.x - vect2.x) <= eps) && (tF64_Abs(vect1.y - vect2.y) <= eps) && (tF64_Abs(vect1.z - vect2.z) <= eps);
}
ForceInline tF64 tF64V3D_LngSq(tF64V3D vect)
{
	return tF64V3D_Dot(vect, vect);
}
ForceInline tF64 tF64V3D_Lng(tF64V3D vect)
{
	return tF64_Sqrt(tF64V3D_LngSq(vect));
}
tF64V3D tF64V3D_Unit(tF64 yaw, tF64 pitch)
{
	tF64V3D vect;
	const tF64 cosP = tF64_Cosine_fast(pitch);
	const tF64 cosY = tF64_Cosine_fast(yaw);
	const tF64 sinY = tF64_Sine_fast(yaw);
	const tF64 sinP = tF64_Sine_fast(pitch);
	vect.x = cosP * cosY;
	vect.y = sinP;
	vect.z = cosP * sinY;
	return vect;
}
tF64V3D tF64V3D_Norm(tF64V3D vect)
{
	tF64 lng = tF64V3D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(lng, 0.0)) return tF64V3D_Zero();
#else
	Assertion(!tF64_Nearby(lng, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tF64V3D_Div(vect, lng);
}
ForceInline tBln tF64V3D_Norm_safe(tF64V3D *vect)
{
	return tF64V3D_Div_safe(vect, tF64V3D_Lng(*vect));
}
tF64V3D tF64V3D_Norm_fast(tF64V3D vect)
{
	tF64 lngSq = tF64V3D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(lngSq, 0.0)) return tF64V3D_Zero();
#else
	Assertion(!tF64_Nearby(lngSq, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tF64V3D_Mul(vect, tF64_RecipSqrt(lngSq));
}
tBln tF64V3D_Norm_fast_safe(tF64V3D *vect)
{
	tF64 lngSq = tF64V3D_LngSq(*vect);
	if (tF64_Nearby(lngSq, 0.0)) return True;
	tF64V3D_Mul(*vect, tF64_RecipSqrt(lngSq));
	return False;
}
ForceInline tF64 tF64V3D_DistSq(tF64V3D vect1, tF64V3D vect2)
{
	return tF64V3D_LngSq(tF64V3D_Sub(vect1, vect2));
}
ForceInline tF64 tF64V3D_Dist(tF64V3D vect1, tF64V3D vect2)
{
	return tF64V3D_Lng(tF64V3D_Sub(vect1, vect2));
}
tF64V3D tF64V3D_Lerp(tF64V3D vect1, tF64V3D vect2, tF64 stp)
{
	tF64V3D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	return vect;
}
tF64V3D tF64V3D_Cross(tF64V3D vect1, tF64V3D vect2)
{
	tF64V3D vect;
	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tF64 x, y, z, w; }; tF64 v[4]; } tF64V4D;
LINK_C_Begin
ForceInline tF64V4D tF64V4D_Make(tF64 x, tF64 y, tF64 z, tF64 w);
ForceInline tF64V4D tF64V4D_Zero(tNone);
ForceInline tF64V4D tF64V4D_Add(tF64V4D vect1, tF64V4D vect2);
ForceInline tF64V4D tF64V4D_Sub(tF64V4D vect1, tF64V4D vect2);
ForceInline tF64V4D tF64V4D_Mul(tF64V4D vect, tF64 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tF64V4D tF64V4D_Div(tF64V4D vect, tF64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tF64V4D_Div_safe(tF64V4D *vect, tF64 mod);
tF64 tF64V4D_Dot(tF64V4D vect1, tF64V4D vect2);
ForceInline tBln tF64V4D_Eq(tF64V4D vect1, tF64V4D vect2);
tBln tF64V4D_Nearby(tF64V4D vect1, tF64V4D vect2, tF64 eps);
ForceInline tF64 tF64V4D_LngSq(tF64V4D vect);
ForceInline tF64 tF64V4D_Lng(tF64V4D vect);
/*Warn: Silently returns `tF64V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF64V4D tF64V4D_Norm(tF64V4D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tF64V4D_Norm_safe(tF64V4D *vect);
/*Warn: Silently returns `tF64V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tF64V4D tF64V4D_Norm_fast(tF64V4D vect);
/*Note: Returns `False` on success.*/
tBln tF64V4D_Norm_fast_safe(tF64V4D *vect);
ForceInline tF64 tF64V4D_DistSq(tF64V4D vect1, tF64V4D vect2);
ForceInline tF64 tF64V4D_Dist(tF64V4D vect1, tF64V4D vect2);
tF64V4D tF64V4D_Lerp(tF64V4D vect1, tF64V4D vect2, tF64 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tF64V4D tF64V4D_Make(tF64 x, tF64 y, tF64 z, tF64 w)
{
	tF64V4D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = w;
	return vect;
}
ForceInline tF64V4D tF64V4D_Zero(tNone)
{
	tF64V4D vect;
	vect.x = 0.0;
	vect.y = 0.0;
	vect.z = 0.0;
	vect.w = 0.0;
	return vect;
}
ForceInline tF64V4D tF64V4D_Add(tF64V4D vect1, tF64V4D vect2)
{
	tF64V4D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	vect.w = vect1.w + vect2.w;
	return vect;
}
ForceInline tF64V4D tF64V4D_Sub(tF64V4D vect1, tF64V4D vect2)
{
	tF64V4D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	vect.w = vect1.w - vect2.w;
	return vect;
}
ForceInline tF64V4D tF64V4D_Mul(tF64V4D vect, tF64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	vect.w *= mod;
	return vect;
}
tF64V4D tF64V4D_Div(tF64V4D vect, tF64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(mod, 0.0))
	{
		vect.x = tF64_IsNeg(vect.x) ? tF64_NegInf() : tF64_Inf();
		vect.y = tF64_IsNeg(vect.y) ? tF64_NegInf() : tF64_Inf();
		vect.z = tF64_IsNeg(vect.z) ? tF64_NegInf() : tF64_Inf();
		vect.w = tF64_IsNeg(vect.w) ? tF64_NegInf() : tF64_Inf();
		return vect;
	}
#else
	Assertion(!tF64_Nearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	vect.w /= mod;
	return vect;
}
ForceInline tBln tF64V4D_Div_safe(tF64V4D *vect, tF64 mod)
{
	if (tF64_Nearby(mod, 0.0)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	vect->w /= mod;
	return False;
}
tF64 tF64V4D_Dot(tF64V4D vect1, tF64V4D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z + vect1.w * vect2.w;
}
ForceInline tBln tF64V4D_Eq(tF64V4D vect1, tF64V4D vect2)
{
	return tF64_Nearby(vect1.x, vect2.x) && tF64_Nearby(vect1.y, vect2.y) && tF64_Nearby(vect1.z, vect2.z) && tF64_Nearby(vect1.w, vect2.w);
}
tBln tF64V4D_Nearby(tF64V4D vect1, tF64V4D vect2, tF64 eps)
{
	return (tF64_Abs(vect1.x - vect2.x) <= eps) && (tF64_Abs(vect1.y - vect2.y) <= eps) && (tF64_Abs(vect1.z - vect2.z) <= eps) && (tF64_Abs(vect1.w - vect2.w) <= eps);
}
ForceInline tF64 tF64V4D_LngSq(tF64V4D vect)
{
	return tF64V4D_Dot(vect, vect);
}
ForceInline tF64 tF64V4D_Lng(tF64V4D vect)
{
	return tF64_Sqrt(tF64V4D_LngSq(vect));
}
tF64V4D tF64V4D_Norm(tF64V4D vect)
{
	tF64 lng = tF64V4D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(lng, 0.0)) return tF64V4D_Zero();
#else
	Assertion(!tF64_Nearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tF64V4D_Div(vect, lng);
}
ForceInline tBln tF64V4D_Norm_safe(tF64V4D *vect)
{
	return tF64V4D_Div_safe(vect, tF64V4D_Lng(*vect));
}
tF64V4D tF64V4D_Norm_fast(tF64V4D vect)
{
	tF64 lngSq = tF64V4D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tF64_Nearby(lngSq, 0.0)) return tF64V4D_Zero();
#else
	Assertion(!tF64_Nearby(lngSq, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tF64V4D_Mul(vect, tF64_RecipSqrt(lngSq));
}
tBln tF64V4D_Norm_fast_safe(tF64V4D *vect)
{
	tF64 lngSq = tF64V4D_LngSq(*vect);
	if (tF64_Nearby(lngSq, 0.0)) return True;
	tF64V4D_Mul(*vect, tF64_RecipSqrt(lngSq));
	return False;
}
ForceInline tF64 tF64V4D_DistSq(tF64V4D vect1, tF64V4D vect2)
{
	return tF64V4D_LngSq(tF64V4D_Sub(vect1, vect2));
}
ForceInline tF64 tF64V4D_Dist(tF64V4D vect1, tF64V4D vect2)
{
	return tF64V4D_Lng(tF64V4D_Sub(vect1, vect2));
}
tF64V4D tF64V4D_Lerp(tF64V4D vect1, tF64V4D vect2, tF64 stp)
{
	tF64V4D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	vect.w = vect1.w + (vect2.w - vect1.w) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
#endif/*BQSELAYER_VECT_H*/