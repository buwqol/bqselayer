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
typedef union { struct { tIS32 x, y; }; tIS32 v[2]; } tIS32V2D;
LINK_C_Begin
ForceInline tIS32V2D tIS32V2D_Make(tIS32 x, tIS32 y);
ForceInline tIS32V2D tIS32V2D_Zero(tNone);
ForceInline tIS32V2D tIS32V2D_Add(tIS32V2D vect1, tIS32V2D vect2);
ForceInline tIS32V2D tIS32V2D_Sub(tIS32V2D vect1, tIS32V2D vect2);
ForceInline tIS32V2D tIS32V2D_Mul(tIS32V2D vect, tIS32 mod);
/*Warn: Silently returns `tIS32V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tIS32V2D tIS32V2D_Div(tIS32V2D vect, tIS32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tIS32V2D_Div_safe(tIS32V2D *vect, tIS32 mod);
ForceInline tBln tIS32V2D_IsEq(tIS32V2D vect1, tIS32V2D vect2);
ForceInline tIS32 tIS32V2D_Dot(tIS32V2D vect1, tIS32V2D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tIS32V2D tIS32V2D_Make(tIS32 x, tIS32 y)
{
	tIS32V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tIS32V2D tIS32V2D_Zero(tNone)
{
	tIS32V2D vect;
	vect.x = 0;
	vect.y = 0;
	return vect;
}
ForceInline tIS32V2D tIS32V2D_Add(tIS32V2D vect1, tIS32V2D vect2)
{
	tIS32V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tIS32V2D tIS32V2D_Sub(tIS32V2D vect1, tIS32V2D vect2)
{
	tIS32V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tIS32V2D tIS32V2D_Mul(tIS32V2D vect, tIS32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tIS32V2D tIS32V2D_Div(tIS32V2D vect, tIS32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (mod == 0)
	{
		vect.x = tIS32_Max;
		vect.y = tIS32_Max;
		return vect;
	}
#else
	Assertion(mod != 0);
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tIS32V2D_Div_safe(tIS32V2D *vect, tIS32 mod)
{
	if (mod == 0) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
ForceInline tBln tIS32V2D_IsEq(tIS32V2D vect1, tIS32V2D vect2)
{
	return (vect1.x == vect2.x) && (vect1.y == vect2.y);
}
ForceInline tIS32 tIS32V2D_Dot(tIS32V2D vect1, tIS32V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tIS64 x, y; }; tIS64 v[2]; } tIS64V2D;
LINK_C_Begin
ForceInline tIS64V2D tIS64V2D_Make(tIS64 x, tIS64 y);
ForceInline tIS64V2D tIS64V2D_Zero(tNone);
ForceInline tIS64V2D tIS64V2D_Add(tIS64V2D vect1, tIS64V2D vect2);
ForceInline tIS64V2D tIS64V2D_Sub(tIS64V2D vect1, tIS64V2D vect2);
ForceInline tIS64V2D tIS64V2D_Mul(tIS64V2D vect, tIS64 mod);
/*Warn: Silently returns `tIS64V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tIS64V2D tIS64V2D_Div(tIS64V2D vect, tIS64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tIS64V2D_Div_safe(tIS64V2D *vect, tIS64 mod);
ForceInline tBln tIS64V2D_IsEq(tIS64V2D vect1, tIS64V2D vect2);
ForceInline tIS64 tIS64V2D_Dot(tIS64V2D vect1, tIS64V2D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tIS64V2D tIS64V2D_Make(tIS64 x, tIS64 y)
{
	tIS64V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tIS64V2D tIS64V2D_Zero(tNone)
{
	tIS64V2D vect;
	vect.x = 0;
	vect.y = 0;
	return vect;
}
ForceInline tIS64V2D tIS64V2D_Add(tIS64V2D vect1, tIS64V2D vect2)
{
	tIS64V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tIS64V2D tIS64V2D_Sub(tIS64V2D vect1, tIS64V2D vect2)
{
	tIS64V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tIS64V2D tIS64V2D_Mul(tIS64V2D vect, tIS64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tIS64V2D tIS64V2D_Div(tIS64V2D vect, tIS64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (mod == 0)
	{
		vect.x = tIS64_Max;
		vect.y = tIS64_Max;
		return vect;
	}
#else
	Assertion(mod != 0);
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tIS64V2D_Div_safe(tIS64V2D *vect, tIS64 mod)
{
	if (mod == 0) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
ForceInline tBln tIS64V2D_IsEq(tIS64V2D vect1, tIS64V2D vect2)
{
	return (vect1.x == vect2.x) && (vect1.y == vect2.y);
}
ForceInline tIS64 tIS64V2D_Dot(tIS64V2D vect1, tIS64V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tFP32 x, y; }; tFP32 v[2]; } tFP32V2D;
LINK_C_Begin
ForceInline tFP32V2D tFP32V2D_Make(tFP32 x, tFP32 y);
ForceInline tFP32V2D tFP32V2D_Zero(tNone);
ForceInline tFP32V2D tFP32V2D_Add(tFP32V2D vect1, tFP32V2D vect2);
ForceInline tFP32V2D tFP32V2D_Sub(tFP32V2D vect1, tFP32V2D vect2);
ForceInline tFP32V2D tFP32V2D_Mul(tFP32V2D vect, tFP32 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tFP32V2D tFP32V2D_Div(tFP32V2D vect, tFP32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP32V2D_Div_safe(tFP32V2D *vect, tFP32 mod);
tFP32 tFP32V2D_Dot(tFP32V2D vect1, tFP32V2D vect2);
ForceInline tBln tFP32V2D_IsEq(tFP32V2D vect1, tFP32V2D vect2);
ForceInline tBln tFP32V2D_IsNearby(tFP32V2D vect1, tFP32V2D vect2, tFP32 eps);
ForceInline tFP32 tFP32V2D_LngSq(tFP32V2D vect);
ForceInline tFP32 tFP32V2D_Lng(tFP32V2D vect);
/*Note: `rot` is in radians. A value of 0 will produce a unit vector along the positive X-axis.*/
ForceInline tFP32V2D tFP32V2D_Unit(tFP32 rot);
/*Warn: Silently returns `tFP32V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tFP32V2D tFP32V2D_Norm(tFP32V2D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP32V2D_Norm_safe(tFP32V2D *vect);
/*Warn: Silently returns `tFP32V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tFP32V2D tFP32V2D_Norm_fast(tFP32V2D vect);
/*Note: Returns `False` on success.*/
tBln tFP32V2D_Norm_fast_safe(tFP32V2D *vect);
ForceInline tFP32 tFP32V2D_DistISq(tFP32V2D vect1, tFP32V2D vect2);
ForceInline tFP32 tFP32V2D_Dist(tFP32V2D vect1, tFP32V2D vect2);
ForceInline tFP32V2D tFP32V2D_Lerp(tFP32V2D vect1, tFP32V2D vect2, tFP32 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tFP32V2D tFP32V2D_Make(tFP32 x, tFP32 y)
{
	tFP32V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tFP32V2D tFP32V2D_Zero(tNone)
{
	tFP32V2D vect;
	vect.x = 0.0F;
	vect.y = 0.0F;
	return vect;
}
ForceInline tFP32V2D tFP32V2D_Add(tFP32V2D vect1, tFP32V2D vect2)
{
	tFP32V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tFP32V2D tFP32V2D_Sub(tFP32V2D vect1, tFP32V2D vect2)
{
	tFP32V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tFP32V2D tFP32V2D_Mul(tFP32V2D vect, tFP32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tFP32V2D tFP32V2D_Div(tFP32V2D vect, tFP32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(mod, 0.0F))
	{
		vect.x = tFP32_IsNeg(vect.x) ? tFP32_NegInf() : tFP32_Inf();
		vect.y = tFP32_IsNeg(vect.y) ? tFP32_NegInf() : tFP32_Inf();
		return vect;
	}
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tFP32V2D_Div_safe(tFP32V2D *vect, tFP32 mod)
{
	if (tFP32_IsNearby(mod, 0.0F)) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
tFP32 tFP32V2D_Dot(tFP32V2D vect1, tFP32V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
ForceInline tBln tFP32V2D_IsEq(tFP32V2D vect1, tFP32V2D vect2)
{
	return tFP32_IsNearby(vect1.x, vect2.x) && tFP32_IsNearby(vect1.y, vect2.y);
}
ForceInline tBln tFP32V2D_IsNearby(tFP32V2D vect1, tFP32V2D vect2, tFP32 eps)
{
	return (tFP32_Abs(vect1.x - vect2.x) <= eps) && (tFP32_Abs(vect1.y - vect2.y) <= eps);
}
ForceInline tFP32 tFP32V2D_LngSq(tFP32V2D vect)
{
	return tFP32V2D_Dot(vect, vect);
}
ForceInline tFP32 tFP32V2D_Lng(tFP32V2D vect)
{
	return tFP32_Sqrt(tFP32V2D_LngSq(vect));
}
ForceInline tFP32V2D tFP32V2D_Unit(tFP32 rot)
{
	tFP32V2D vect;
	vect.x = tFP32_Cosine_fast(rot);
	vect.y = tFP32_Sine_fast(rot);
	return vect;
}
ForceInline tFP32V2D tFP32V2D_Norm(tFP32V2D vect)
{
	tFP32 lng = tFP32V2D_Lng(vect);
	return tFP32V2D_Div(vect, lng);
}
ForceInline tBln tFP32V2D_Norm_safe(tFP32V2D *vect)
{
	return tFP32V2D_Div_safe(vect, tFP32V2D_Lng(*vect));
}
ForceInline tFP32V2D tFP32V2D_Norm_fast(tFP32V2D vect)
{
	tFP32 lngSq = tFP32V2D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(lngSq, 0.0F)) return tFP32V2D_Zero();
#else
	Assertion(!tFP32_IsNearby(lngSq, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32V2D_Mul(vect, tFP32_RecipSqrt(lngSq));
}
tBln tFP32V2D_Norm_fast_safe(tFP32V2D *vect)
{
	tFP32 lngSq = tFP32V2D_LngSq(*vect);
	if (tFP32_IsNearby(lngSq, 0.0F)) return True;
	tFP32V2D_Mul(*vect, tFP32_RecipSqrt(lngSq));
	return False;
}
ForceInline tFP32 tFP32V2D_DistISq(tFP32V2D vect1, tFP32V2D vect2)
{
	return tFP32V2D_LngSq(tFP32V2D_Sub(vect1, vect2));
}
ForceInline tFP32 tFP32V2D_Dist(tFP32V2D vect1, tFP32V2D vect2)
{
	return tFP32V2D_Lng(tFP32V2D_Sub(vect1, vect2));
}
ForceInline tFP32V2D tFP32V2D_Lerp(tFP32V2D vect1, tFP32V2D vect2, tFP32 stp)
{
	tFP32V2D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tFP32 x, y, z; }; tFP32 v[3]; } tFP32V3D;
LINK_C_Begin
ForceInline tFP32V3D tFP32V3D_Make(tFP32 x, tFP32 y, tFP32 z);
ForceInline tFP32V3D tFP32V3D_Zero(tNone);
ForceInline tFP32V3D tFP32V3D_Add(tFP32V3D vect1, tFP32V3D vect2);
ForceInline tFP32V3D tFP32V3D_Sub(tFP32V3D vect1, tFP32V3D vect2);
ForceInline tFP32V3D tFP32V3D_Mul(tFP32V3D vect, tFP32 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tFP32V3D tFP32V3D_Div(tFP32V3D vect, tFP32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP32V3D_Div_safe(tFP32V3D *vect, tFP32 mod);
tFP32 tFP32V3D_Dot(tFP32V3D vect1, tFP32V3D vect2);
ForceInline tBln tFP32V3D_IsEq(tFP32V3D vect1, tFP32V3D vect2);
tBln tFP32V3D_IsNearby(tFP32V3D vect1, tFP32V3D vect2, tFP32 eps);
ForceInline tFP32 tFP32V3D_LngSq(tFP32V3D vect);
ForceInline tFP32 tFP32V3D_Lng(tFP32V3D vect);
/*Note: `yaw` and `pitch` are in radians.*/
tFP32V3D tFP32V3D_Unit(tFP32 yaw, tFP32 pitch);
/*Warn: Silently returns `tFP32V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP32V3D tFP32V3D_Norm(tFP32V3D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP32V3D_Norm_safe(tFP32V3D *vect);
/*Warn: Silently returns `tFP32V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP32V3D tFP32V3D_Norm_fast(tFP32V3D vect);
/*Note: Returns `False` on success.*/
tBln tFP32V3D_Norm_fast_safe(tFP32V3D *vect);
ForceInline tFP32 tFP32V3D_DistISq(tFP32V3D vect1, tFP32V3D vect2);
ForceInline tFP32 tFP32V3D_Dist(tFP32V3D vect1, tFP32V3D vect2);
tFP32V3D tFP32V3D_Lerp(tFP32V3D vect1, tFP32V3D vect2, tFP32 stp);
tFP32V3D tFP32V3D_Cross(tFP32V3D vect1, tFP32V3D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tFP32V3D tFP32V3D_Make(tFP32 x, tFP32 y, tFP32 z)
{
	tFP32V3D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	return vect;
}
ForceInline tFP32V3D tFP32V3D_Zero(tNone)
{
	tFP32V3D vect;
	vect.x = 0.0F;
	vect.y = 0.0F;
	vect.z = 0.0F;
	return vect;
}
ForceInline tFP32V3D tFP32V3D_Add(tFP32V3D vect1, tFP32V3D vect2)
{
	tFP32V3D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	return vect;
}
ForceInline tFP32V3D tFP32V3D_Sub(tFP32V3D vect1, tFP32V3D vect2)
{
	tFP32V3D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return vect;
}
ForceInline tFP32V3D tFP32V3D_Mul(tFP32V3D vect, tFP32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	return vect;
}
tFP32V3D tFP32V3D_Div(tFP32V3D vect, tFP32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(mod, 0.0F))
	{
		vect.x = tFP32_IsNeg(vect.x) ? tFP32_NegInf() : tFP32_Inf();
		vect.y = tFP32_IsNeg(vect.y) ? tFP32_NegInf() : tFP32_Inf();
		vect.z = tFP32_IsNeg(vect.z) ? tFP32_NegInf() : tFP32_Inf();
		return vect;
	}
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	return vect;
}
ForceInline tBln tFP32V3D_Div_safe(tFP32V3D *vect, tFP32 mod)
{
	if (tFP32_IsNearby(mod, 0.0F)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	return False;
}
tFP32 tFP32V3D_Dot(tFP32V3D vect1, tFP32V3D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
}
ForceInline tBln tFP32V3D_IsEq(tFP32V3D vect1, tFP32V3D vect2)
{
	return tFP32_IsNearby(vect1.x, vect2.x) && tFP32_IsNearby(vect1.y, vect2.y) && tFP32_IsNearby(vect1.z, vect2.z);
}
tBln tFP32V3D_IsNearby(tFP32V3D vect1, tFP32V3D vect2, tFP32 eps)
{
	return (tFP32_Abs(vect1.x - vect2.x) <= eps) && (tFP32_Abs(vect1.y - vect2.y) <= eps) && (tFP32_Abs(vect1.z - vect2.z) <= eps);
}
ForceInline tFP32 tFP32V3D_LngSq(tFP32V3D vect)
{
	return tFP32V3D_Dot(vect, vect);
}
ForceInline tFP32 tFP32V3D_Lng(tFP32V3D vect)
{
	return tFP32_Sqrt(tFP32V3D_LngSq(vect));
}
tFP32V3D tFP32V3D_Unit(tFP32 yaw, tFP32 pitch)
{
	tFP32V3D vect;
	const tFP32 cosP = tFP32_Cosine_fast(pitch);
	const tFP32 cosY = tFP32_Cosine_fast(yaw);
	const tFP32 sinY = tFP32_Sine_fast(yaw);
	const tFP32 sinP = tFP32_Sine_fast(pitch);
	vect.x = cosP * cosY;
	vect.y = sinP;
	vect.z = cosP * sinY;
	return vect;
}
tFP32V3D tFP32V3D_Norm(tFP32V3D vect)
{
	tFP32 lng = tFP32V3D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(lng, 0.0F)) return tFP32V3D_Zero();
#else
	Assertion(!tFP32_IsNearby(lng, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32V3D_Div(vect, lng);
}
ForceInline tBln tFP32V3D_Norm_safe(tFP32V3D *vect)
{
	return tFP32V3D_Div_safe(vect, tFP32V3D_Lng(*vect));
}
tFP32V3D tFP32V3D_Norm_fast(tFP32V3D vect)
{
	tFP32 lngSq = tFP32V3D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(lngSq, 0.0F)) return tFP32V3D_Zero();
#else
	Assertion(!tFP32_IsNearby(lngSq, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32V3D_Mul(vect, tFP32_RecipSqrt(lngSq));
}
tBln tFP32V3D_Norm_fast_safe(tFP32V3D *vect)
{
	tFP32 lngSq = tFP32V3D_LngSq(*vect);
	if (tFP32_IsNearby(lngSq, 0.0F)) return True;
	tFP32V3D_Mul(*vect, tFP32_RecipSqrt(lngSq));
	return False;
}
ForceInline tFP32 tFP32V3D_DistISq(tFP32V3D vect1, tFP32V3D vect2)
{
	return tFP32V3D_LngSq(tFP32V3D_Sub(vect1, vect2));
}
ForceInline tFP32 tFP32V3D_Dist(tFP32V3D vect1, tFP32V3D vect2)
{
	return tFP32V3D_Lng(tFP32V3D_Sub(vect1, vect2));
}
tFP32V3D tFP32V3D_Lerp(tFP32V3D vect1, tFP32V3D vect2, tFP32 stp)
{
	tFP32V3D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	return vect;
}
tFP32V3D tFP32V3D_Cross(tFP32V3D vect1, tFP32V3D vect2)
{
	tFP32V3D vect;
	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tFP32 x, y, z, w; }; tFP32 v[4]; } tFP32V4D;
LINK_C_Begin
ForceInline tFP32V4D tFP32V4D_Make(tFP32 x, tFP32 y, tFP32 z, tFP32 w);
ForceInline tFP32V4D tFP32V4D_Zero(tNone);
ForceInline tFP32V4D tFP32V4D_Add(tFP32V4D vect1, tFP32V4D vect2);
ForceInline tFP32V4D tFP32V4D_Sub(tFP32V4D vect1, tFP32V4D vect2);
ForceInline tFP32V4D tFP32V4D_Mul(tFP32V4D vect, tFP32 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tFP32V4D tFP32V4D_Div(tFP32V4D vect, tFP32 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP32V4D_Div_safe(tFP32V4D *vect, tFP32 mod);
tFP32 tFP32V4D_Dot(tFP32V4D vect1, tFP32V4D vect2);
ForceInline tBln tFP32V4D_IsEq(tFP32V4D vect1, tFP32V4D vect2);
tBln tFP32V4D_IsNearby(tFP32V4D vect1, tFP32V4D vect2, tFP32 eps);
ForceInline tFP32 tFP32V4D_LngSq(tFP32V4D vect);
ForceInline tFP32 tFP32V4D_Lng(tFP32V4D vect);
/*Warn: Silently returns `tFP32V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP32V4D tFP32V4D_Norm(tFP32V4D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP32V4D_Norm_safe(tFP32V4D *vect);
/*Warn: Silently returns `tFP32V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP32V4D tFP32V4D_Norm_fast(tFP32V4D vect);
/*Note: Returns `False` on success.*/
tBln tFP32V4D_Norm_fast_safe(tFP32V4D *vect);
ForceInline tFP32 tFP32V4D_DistISq(tFP32V4D vect1, tFP32V4D vect2);
ForceInline tFP32 tFP32V4D_Dist(tFP32V4D vect1, tFP32V4D vect2);
tFP32V4D tFP32V4D_Lerp(tFP32V4D vect1, tFP32V4D vect2, tFP32 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tFP32V4D tFP32V4D_Make(tFP32 x, tFP32 y, tFP32 z, tFP32 w)
{
	tFP32V4D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = w;
	return vect;
}
ForceInline tFP32V4D tFP32V4D_Zero(tNone)
{
	tFP32V4D vect;
	vect.x = 0.0F;
	vect.y = 0.0F;
	vect.z = 0.0F;
	vect.w = 0.0F;
	return vect;
}
ForceInline tFP32V4D tFP32V4D_Add(tFP32V4D vect1, tFP32V4D vect2)
{
	tFP32V4D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	vect.w = vect1.w + vect2.w;
	return vect;
}
ForceInline tFP32V4D tFP32V4D_Sub(tFP32V4D vect1, tFP32V4D vect2)
{
	tFP32V4D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	vect.w = vect1.w - vect2.w;
	return vect;
}
ForceInline tFP32V4D tFP32V4D_Mul(tFP32V4D vect, tFP32 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	vect.w *= mod;
	return vect;
}
tFP32V4D tFP32V4D_Div(tFP32V4D vect, tFP32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(mod, 0.0F))
	{
		vect.x = tFP32_IsNeg(vect.x) ? tFP32_NegInf() : tFP32_Inf();
		vect.y = tFP32_IsNeg(vect.y) ? tFP32_NegInf() : tFP32_Inf();
		vect.z = tFP32_IsNeg(vect.z) ? tFP32_NegInf() : tFP32_Inf();
		vect.w = tFP32_IsNeg(vect.w) ? tFP32_NegInf() : tFP32_Inf();
		return vect;
	}
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	vect.w /= mod;
	return vect;
}
ForceInline tBln tFP32V4D_Div_safe(tFP32V4D *vect, tFP32 mod)
{
	if (tFP32_IsNearby(mod, 0.0F)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	vect->w /= mod;
	return False;
}
tFP32 tFP32V4D_Dot(tFP32V4D vect1, tFP32V4D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z + vect1.w * vect2.w;
}
ForceInline tBln tFP32V4D_IsEq(tFP32V4D vect1, tFP32V4D vect2)
{
	return tFP32_IsNearby(vect1.x, vect2.x) && tFP32_IsNearby(vect1.y, vect2.y) && tFP32_IsNearby(vect1.z, vect2.z) && tFP32_IsNearby(vect1.w, vect2.w);
}
tBln tFP32V4D_IsNearby(tFP32V4D vect1, tFP32V4D vect2, tFP32 eps)
{
	return (tFP32_Abs(vect1.x - vect2.x) <= eps) && (tFP32_Abs(vect1.y - vect2.y) <= eps) && (tFP32_Abs(vect1.z - vect2.z) <= eps) && (tFP32_Abs(vect1.w - vect2.w) <= eps);
}
ForceInline tFP32 tFP32V4D_LngSq(tFP32V4D vect)
{
	return tFP32V4D_Dot(vect, vect);
}
ForceInline tFP32 tFP32V4D_Lng(tFP32V4D vect)
{
	return tFP32_Sqrt(tFP32V4D_LngSq(vect));
}
tFP32V4D tFP32V4D_Norm(tFP32V4D vect)
{
	tFP32 lng = tFP32V4D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(lng, 0.0F)) return tFP32V4D_Zero();
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32V4D_Div(vect, lng);
}
ForceInline tBln tFP32V4D_Norm_safe(tFP32V4D *vect)
{
	return tFP32V4D_Div_safe(vect, tFP32V4D_Lng(*vect));
}
tFP32V4D tFP32V4D_Norm_fast(tFP32V4D vect)
{
	tFP32 lngSq = tFP32V4D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(lngSq, 0.0F)) return tFP32V4D_Zero();
#else
	Assertion(!tFP32_IsNearby(lngSq, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	return tFP32V4D_Mul(vect, tFP32_RecipSqrt(lngSq));
}
tBln tFP32V4D_Norm_fast_safe(tFP32V4D *vect)
{
	tFP32 lngSq = tFP32V4D_LngSq(*vect);
	if (tFP32_IsNearby(lngSq, 0.0F)) return True;
	tFP32V4D_Mul(*vect, tFP32_RecipSqrt(lngSq));
	return False;
}
ForceInline tFP32 tFP32V4D_DistISq(tFP32V4D vect1, tFP32V4D vect2)
{
	return tFP32V4D_LngSq(tFP32V4D_Sub(vect1, vect2));
}
ForceInline tFP32 tFP32V4D_Dist(tFP32V4D vect1, tFP32V4D vect2)
{
	return tFP32V4D_Lng(tFP32V4D_Sub(vect1, vect2));
}
tFP32V4D tFP32V4D_Lerp(tFP32V4D vect1, tFP32V4D vect2, tFP32 stp)
{
	tFP32V4D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	vect.w = vect1.w + (vect2.w - vect1.w) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tFP64 x, y; }; tFP64 v[2]; } tFP64V2D;
LINK_C_Begin
ForceInline tFP64V2D tFP64V2D_Make(tFP64 x, tFP64 y);
ForceInline tFP64V2D tFP64V2D_Zero(tNone);
ForceInline tFP64V2D tFP64V2D_Add(tFP64V2D vect1, tFP64V2D vect2);
ForceInline tFP64V2D tFP64V2D_Sub(tFP64V2D vect1, tFP64V2D vect2);
ForceInline tFP64V2D tFP64V2D_Mul(tFP64V2D vect, tFP64 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tFP64V2D tFP64V2D_Div(tFP64V2D vect, tFP64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP64V2D_Div_safe(tFP64V2D *vect, tFP64 mod);
tFP64 tFP64V2D_Dot(tFP64V2D vect1, tFP64V2D vect2);
ForceInline tBln tFP64V2D_IsEq(tFP64V2D vect1, tFP64V2D vect2);
ForceInline tBln tFP64V2D_IsNearby(tFP64V2D vect1, tFP64V2D vect2, tFP64 eps);
ForceInline tFP64 tFP64V2D_LngSq(tFP64V2D vect);
ForceInline tFP64 tFP64V2D_Lng(tFP64V2D vect);
/*Note: `rot` is in radians. A value of 0 will produce a unit vector along the positive X-axis.*/
ForceInline tFP64V2D tFP64V2D_Unit(tFP64 rot);
/*Warn: Silently returns `tFP64V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tFP64V2D tFP64V2D_Norm(tFP64V2D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP64V2D_Norm_safe(tFP64V2D *vect);
/*Warn: Silently returns `tFP64V2D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
ForceInline tFP64V2D tFP64V2D_Norm_fast(tFP64V2D vect);
/*Note: Returns `False` on success.*/
tBln tFP64V2D_Norm_fast_safe(tFP64V2D *vect);
ForceInline tFP64 tFP64V2D_DistISq(tFP64V2D vect1, tFP64V2D vect2);
ForceInline tFP64 tFP64V2D_Dist(tFP64V2D vect1, tFP64V2D vect2);
ForceInline tFP64V2D tFP64V2D_Lerp(tFP64V2D vect1, tFP64V2D vect2, tFP64 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tFP64V2D tFP64V2D_Make(tFP64 x, tFP64 y)
{
	tFP64V2D vect;
	vect.x = x;
	vect.y = y;
	return vect;
}
ForceInline tFP64V2D tFP64V2D_Zero(tNone)
{
	tFP64V2D vect;
	vect.x = 0.0;
	vect.y = 0.0;
	return vect;
}
ForceInline tFP64V2D tFP64V2D_Add(tFP64V2D vect1, tFP64V2D vect2)
{
	tFP64V2D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	return vect;
}
ForceInline tFP64V2D tFP64V2D_Sub(tFP64V2D vect1, tFP64V2D vect2)
{
	tFP64V2D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	return vect;
}
ForceInline tFP64V2D tFP64V2D_Mul(tFP64V2D vect, tFP64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	return vect;
}
tFP64V2D tFP64V2D_Div(tFP64V2D vect, tFP64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(mod, 0.0))
	{
		vect.x = tFP64_IsNeg(vect.x) ? tFP64_NegInf() : tFP64_Inf();
		vect.y = tFP64_IsNeg(vect.y) ? tFP64_NegInf() : tFP64_Inf();
		return vect;
	}
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	return vect;
}
ForceInline tBln tFP64V2D_Div_safe(tFP64V2D *vect, tFP64 mod)
{
	if (tFP64_IsNearby(mod, 0.0)) return True;
	vect->x /= mod;
	vect->y /= mod;
	return False;
}
tFP64 tFP64V2D_Dot(tFP64V2D vect1, tFP64V2D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y;
}
ForceInline tBln tFP64V2D_IsEq(tFP64V2D vect1, tFP64V2D vect2)
{
	return tFP64_IsNearby(vect1.x, vect2.x) && tFP64_IsNearby(vect1.y, vect2.y);
}
ForceInline tBln tFP64V2D_IsNearby(tFP64V2D vect1, tFP64V2D vect2, tFP64 eps)
{
	return (tFP64_Abs(vect1.x - vect2.x) <= eps) && (tFP64_Abs(vect1.y - vect2.y) <= eps);
}
ForceInline tFP64 tFP64V2D_LngSq(tFP64V2D vect)
{
	return tFP64V2D_Dot(vect, vect);
}
ForceInline tFP64 tFP64V2D_Lng(tFP64V2D vect)
{
	return tFP64_Sqrt(tFP64V2D_LngSq(vect));
}
ForceInline tFP64V2D tFP64V2D_Unit(tFP64 rot)
{
	tFP64V2D vect;
	vect.x = tFP64_Cosine_fast(rot);
	vect.y = tFP64_Sine_fast(rot);
	return vect;
}
ForceInline tFP64V2D tFP64V2D_Norm(tFP64V2D vect)
{
	tFP64 lng = tFP64V2D_Lng(vect);
	return tFP64V2D_Div(vect, lng);
}
ForceInline tBln tFP64V2D_Norm_safe(tFP64V2D *vect)
{
	return tFP64V2D_Div_safe(vect, tFP64V2D_Lng(*vect));
}
ForceInline tFP64V2D tFP64V2D_Norm_fast(tFP64V2D vect)
{
	tFP64 lngSq = tFP64V2D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(lngSq, 0.0)) return tFP64V2D_Zero();
#else
	Assertion(!tFP64_IsNearby(lngSq, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64V2D_Mul(vect, tFP64_RecipSqrt(lngSq));
}
tBln tFP64V2D_Norm_fast_safe(tFP64V2D *vect)
{
	tFP64 lngSq = tFP64V2D_LngSq(*vect);
	if (tFP64_IsNearby(lngSq, 0.0)) return True;
	tFP64V2D_Mul(*vect, tFP64_RecipSqrt(lngSq));
	return False;
}
ForceInline tFP64 tFP64V2D_DistISq(tFP64V2D vect1, tFP64V2D vect2)
{
	return tFP64V2D_LngSq(tFP64V2D_Sub(vect1, vect2));
}
ForceInline tFP64 tFP64V2D_Dist(tFP64V2D vect1, tFP64V2D vect2)
{
	return tFP64V2D_Lng(tFP64V2D_Sub(vect1, vect2));
}
ForceInline tFP64V2D tFP64V2D_Lerp(tFP64V2D vect1, tFP64V2D vect2, tFP64 stp)
{
	tFP64V2D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tFP64 x, y, z; }; tFP64 v[3]; } tFP64V3D;
LINK_C_Begin
ForceInline tFP64V3D tFP64V3D_Make(tFP64 x, tFP64 y, tFP64 z);
ForceInline tFP64V3D tFP64V3D_Zero(tNone);
ForceInline tFP64V3D tFP64V3D_Add(tFP64V3D vect1, tFP64V3D vect2);
ForceInline tFP64V3D tFP64V3D_Sub(tFP64V3D vect1, tFP64V3D vect2);
ForceInline tFP64V3D tFP64V3D_Mul(tFP64V3D vect, tFP64 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tFP64V3D tFP64V3D_Div(tFP64V3D vect, tFP64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP64V3D_Div_safe(tFP64V3D *vect, tFP64 mod);
tFP64 tFP64V3D_Dot(tFP64V3D vect1, tFP64V3D vect2);
ForceInline tBln tFP64V3D_IsEq(tFP64V3D vect1, tFP64V3D vect2);
tBln tFP64V3D_IsNearby(tFP64V3D vect1, tFP64V3D vect2, tFP64 eps);
ForceInline tFP64 tFP64V3D_LngSq(tFP64V3D vect);
ForceInline tFP64 tFP64V3D_Lng(tFP64V3D vect);
/*Note: `yaw` and `pitch` are in radians.*/
tFP64V3D tFP64V3D_Unit(tFP64 yaw, tFP64 pitch);
/*Warn: Silently returns `tFP64V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP64V3D tFP64V3D_Norm(tFP64V3D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP64V3D_Norm_safe(tFP64V3D *vect);
/*Warn: Silently returns `tFP64V3D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP64V3D tFP64V3D_Norm_fast(tFP64V3D vect);
/*Note: Returns `False` on success.*/
tBln tFP64V3D_Norm_fast_safe(tFP64V3D *vect);
ForceInline tFP64 tFP64V3D_DistISq(tFP64V3D vect1, tFP64V3D vect2);
ForceInline tFP64 tFP64V3D_Dist(tFP64V3D vect1, tFP64V3D vect2);
tFP64V3D tFP64V3D_Lerp(tFP64V3D vect1, tFP64V3D vect2, tFP64 stp);
tFP64V3D tFP64V3D_Cross(tFP64V3D vect1, tFP64V3D vect2);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tFP64V3D tFP64V3D_Make(tFP64 x, tFP64 y, tFP64 z)
{
	tFP64V3D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	return vect;
}
ForceInline tFP64V3D tFP64V3D_Zero(tNone)
{
	tFP64V3D vect;
	vect.x = 0.0;
	vect.y = 0.0;
	vect.z = 0.0;
	return vect;
}
ForceInline tFP64V3D tFP64V3D_Add(tFP64V3D vect1, tFP64V3D vect2)
{
	tFP64V3D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	return vect;
}
ForceInline tFP64V3D tFP64V3D_Sub(tFP64V3D vect1, tFP64V3D vect2)
{
	tFP64V3D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return vect;
}
ForceInline tFP64V3D tFP64V3D_Mul(tFP64V3D vect, tFP64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	return vect;
}
tFP64V3D tFP64V3D_Div(tFP64V3D vect, tFP64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(mod, 0.0))
	{
		vect.x = tFP64_IsNeg(vect.x) ? tFP64_NegInf() : tFP64_Inf();
		vect.y = tFP64_IsNeg(vect.y) ? tFP64_NegInf() : tFP64_Inf();
		vect.z = tFP64_IsNeg(vect.z) ? tFP64_NegInf() : tFP64_Inf();
		return vect;
	}
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	return vect;
}
ForceInline tBln tFP64V3D_Div_safe(tFP64V3D *vect, tFP64 mod)
{
	if (tFP64_IsNearby(mod, 0.0)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	return False;
}
tFP64 tFP64V3D_Dot(tFP64V3D vect1, tFP64V3D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
}
ForceInline tBln tFP64V3D_IsEq(tFP64V3D vect1, tFP64V3D vect2)
{
	return tFP64_IsNearby(vect1.x, vect2.x) && tFP64_IsNearby(vect1.y, vect2.y) && tFP64_IsNearby(vect1.z, vect2.z);
}
tBln tFP64V3D_IsNearby(tFP64V3D vect1, tFP64V3D vect2, tFP64 eps)
{
	return (tFP64_Abs(vect1.x - vect2.x) <= eps) && (tFP64_Abs(vect1.y - vect2.y) <= eps) && (tFP64_Abs(vect1.z - vect2.z) <= eps);
}
ForceInline tFP64 tFP64V3D_LngSq(tFP64V3D vect)
{
	return tFP64V3D_Dot(vect, vect);
}
ForceInline tFP64 tFP64V3D_Lng(tFP64V3D vect)
{
	return tFP64_Sqrt(tFP64V3D_LngSq(vect));
}
tFP64V3D tFP64V3D_Unit(tFP64 yaw, tFP64 pitch)
{
	tFP64V3D vect;
	const tFP64 cosP = tFP64_Cosine_fast(pitch);
	const tFP64 cosY = tFP64_Cosine_fast(yaw);
	const tFP64 sinY = tFP64_Sine_fast(yaw);
	const tFP64 sinP = tFP64_Sine_fast(pitch);
	vect.x = cosP * cosY;
	vect.y = sinP;
	vect.z = cosP * sinY;
	return vect;
}
tFP64V3D tFP64V3D_Norm(tFP64V3D vect)
{
	tFP64 lng = tFP64V3D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(lng, 0.0)) return tFP64V3D_Zero();
#else
	Assertion(!tFP64_IsNearby(lng, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64V3D_Div(vect, lng);
}
ForceInline tBln tFP64V3D_Norm_safe(tFP64V3D *vect)
{
	return tFP64V3D_Div_safe(vect, tFP64V3D_Lng(*vect));
}
tFP64V3D tFP64V3D_Norm_fast(tFP64V3D vect)
{
	tFP64 lngSq = tFP64V3D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(lngSq, 0.0)) return tFP64V3D_Zero();
#else
	Assertion(!tFP64_IsNearby(lngSq, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64V3D_Mul(vect, tFP64_RecipSqrt(lngSq));
}
tBln tFP64V3D_Norm_fast_safe(tFP64V3D *vect)
{
	tFP64 lngSq = tFP64V3D_LngSq(*vect);
	if (tFP64_IsNearby(lngSq, 0.0)) return True;
	tFP64V3D_Mul(*vect, tFP64_RecipSqrt(lngSq));
	return False;
}
ForceInline tFP64 tFP64V3D_DistISq(tFP64V3D vect1, tFP64V3D vect2)
{
	return tFP64V3D_LngSq(tFP64V3D_Sub(vect1, vect2));
}
ForceInline tFP64 tFP64V3D_Dist(tFP64V3D vect1, tFP64V3D vect2)
{
	return tFP64V3D_Lng(tFP64V3D_Sub(vect1, vect2));
}
tFP64V3D tFP64V3D_Lerp(tFP64V3D vect1, tFP64V3D vect2, tFP64 stp)
{
	tFP64V3D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	return vect;
}
tFP64V3D tFP64V3D_Cross(tFP64V3D vect1, tFP64V3D vect2)
{
	tFP64V3D vect;
	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
typedef union { struct { tFP64 x, y, z, w; }; tFP64 v[4]; } tFP64V4D;
LINK_C_Begin
ForceInline tFP64V4D tFP64V4D_Make(tFP64 x, tFP64 y, tFP64 z, tFP64 w);
ForceInline tFP64V4D tFP64V4D_Zero(tNone);
ForceInline tFP64V4D tFP64V4D_Add(tFP64V4D vect1, tFP64V4D vect2);
ForceInline tFP64V4D tFP64V4D_Sub(tFP64V4D vect1, tFP64V4D vect2);
ForceInline tFP64V4D tFP64V4D_Mul(tFP64V4D vect, tFP64 mod);
/*Warn: Silently returns a vector with all components equal to either +Inf or -Inf divison by zero (depending on original component values).*/
tFP64V4D tFP64V4D_Div(tFP64V4D vect, tFP64 mod);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP64V4D_Div_safe(tFP64V4D *vect, tFP64 mod);
tFP64 tFP64V4D_Dot(tFP64V4D vect1, tFP64V4D vect2);
ForceInline tBln tFP64V4D_IsEq(tFP64V4D vect1, tFP64V4D vect2);
tBln tFP64V4D_IsNearby(tFP64V4D vect1, tFP64V4D vect2, tFP64 eps);
ForceInline tFP64 tFP64V4D_LngSq(tFP64V4D vect);
ForceInline tFP64 tFP64V4D_Lng(tFP64V4D vect);
/*Warn: Silently returns `tFP64V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP64V4D tFP64V4D_Norm(tFP64V4D vect);
/*Note: Returns `False` on success.*/
ForceInline tBln tFP64V4D_Norm_safe(tFP64V4D *vect);
/*Warn: Silently returns `tFP64V4D_Zero` on failure when BQSELAYER_DEBUG is not defined.*/
tFP64V4D tFP64V4D_Norm_fast(tFP64V4D vect);
/*Note: Returns `False` on success.*/
tBln tFP64V4D_Norm_fast_safe(tFP64V4D *vect);
ForceInline tFP64 tFP64V4D_DistISq(tFP64V4D vect1, tFP64V4D vect2);
ForceInline tFP64 tFP64V4D_Dist(tFP64V4D vect1, tFP64V4D vect2);
tFP64V4D tFP64V4D_Lerp(tFP64V4D vect1, tFP64V4D vect2, tFP64 stp);
LINK_C_End
#ifdef BQSELAYER_VECT_IMPL
ForceInline tFP64V4D tFP64V4D_Make(tFP64 x, tFP64 y, tFP64 z, tFP64 w)
{
	tFP64V4D vect;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = w;
	return vect;
}
ForceInline tFP64V4D tFP64V4D_Zero(tNone)
{
	tFP64V4D vect;
	vect.x = 0.0;
	vect.y = 0.0;
	vect.z = 0.0;
	vect.w = 0.0;
	return vect;
}
ForceInline tFP64V4D tFP64V4D_Add(tFP64V4D vect1, tFP64V4D vect2)
{
	tFP64V4D vect;
	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	vect.w = vect1.w + vect2.w;
	return vect;
}
ForceInline tFP64V4D tFP64V4D_Sub(tFP64V4D vect1, tFP64V4D vect2)
{
	tFP64V4D vect;
	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	vect.w = vect1.w - vect2.w;
	return vect;
}
ForceInline tFP64V4D tFP64V4D_Mul(tFP64V4D vect, tFP64 mod)
{
	vect.x *= mod;
	vect.y *= mod;
	vect.z *= mod;
	vect.w *= mod;
	return vect;
}
tFP64V4D tFP64V4D_Div(tFP64V4D vect, tFP64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(mod, 0.0))
	{
		vect.x = tFP64_IsNeg(vect.x) ? tFP64_NegInf() : tFP64_Inf();
		vect.y = tFP64_IsNeg(vect.y) ? tFP64_NegInf() : tFP64_Inf();
		vect.z = tFP64_IsNeg(vect.z) ? tFP64_NegInf() : tFP64_Inf();
		vect.w = tFP64_IsNeg(vect.w) ? tFP64_NegInf() : tFP64_Inf();
		return vect;
	}
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	vect.x /= mod;
	vect.y /= mod;
	vect.z /= mod;
	vect.w /= mod;
	return vect;
}
ForceInline tBln tFP64V4D_Div_safe(tFP64V4D *vect, tFP64 mod)
{
	if (tFP64_IsNearby(mod, 0.0)) return True;
	vect->x /= mod;
	vect->y /= mod;
	vect->z /= mod;
	vect->w /= mod;
	return False;
}
tFP64 tFP64V4D_Dot(tFP64V4D vect1, tFP64V4D vect2)
{
	return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z + vect1.w * vect2.w;
}
ForceInline tBln tFP64V4D_IsEq(tFP64V4D vect1, tFP64V4D vect2)
{
	return tFP64_IsNearby(vect1.x, vect2.x) && tFP64_IsNearby(vect1.y, vect2.y) && tFP64_IsNearby(vect1.z, vect2.z) && tFP64_IsNearby(vect1.w, vect2.w);
}
tBln tFP64V4D_IsNearby(tFP64V4D vect1, tFP64V4D vect2, tFP64 eps)
{
	return (tFP64_Abs(vect1.x - vect2.x) <= eps) && (tFP64_Abs(vect1.y - vect2.y) <= eps) && (tFP64_Abs(vect1.z - vect2.z) <= eps) && (tFP64_Abs(vect1.w - vect2.w) <= eps);
}
ForceInline tFP64 tFP64V4D_LngSq(tFP64V4D vect)
{
	return tFP64V4D_Dot(vect, vect);
}
ForceInline tFP64 tFP64V4D_Lng(tFP64V4D vect)
{
	return tFP64_Sqrt(tFP64V4D_LngSq(vect));
}
tFP64V4D tFP64V4D_Norm(tFP64V4D vect)
{
	tFP64 lng = tFP64V4D_Lng(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(lng, 0.0)) return tFP64V4D_Zero();
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64V4D_Div(vect, lng);
}
ForceInline tBln tFP64V4D_Norm_safe(tFP64V4D *vect)
{
	return tFP64V4D_Div_safe(vect, tFP64V4D_Lng(*vect));
}
tFP64V4D tFP64V4D_Norm_fast(tFP64V4D vect)
{
	tFP64 lngSq = tFP64V4D_LngSq(vect);
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(lngSq, 0.0)) return tFP64V4D_Zero();
#else
	Assertion(!tFP64_IsNearby(lngSq, 0.0));
#endif/*BQSELAYER_DEBUG*/
	return tFP64V4D_Mul(vect, tFP64_RecipSqrt(lngSq));
}
tBln tFP64V4D_Norm_fast_safe(tFP64V4D *vect)
{
	tFP64 lngSq = tFP64V4D_LngSq(*vect);
	if (tFP64_IsNearby(lngSq, 0.0)) return True;
	tFP64V4D_Mul(*vect, tFP64_RecipSqrt(lngSq));
	return False;
}
ForceInline tFP64 tFP64V4D_DistISq(tFP64V4D vect1, tFP64V4D vect2)
{
	return tFP64V4D_LngSq(tFP64V4D_Sub(vect1, vect2));
}
ForceInline tFP64 tFP64V4D_Dist(tFP64V4D vect1, tFP64V4D vect2)
{
	return tFP64V4D_Lng(tFP64V4D_Sub(vect1, vect2));
}
tFP64V4D tFP64V4D_Lerp(tFP64V4D vect1, tFP64V4D vect2, tFP64 stp)
{
	tFP64V4D vect;
	vect.x = vect1.x + (vect2.x - vect1.x) * stp;
	vect.y = vect1.y + (vect2.y - vect1.y) * stp;
	vect.z = vect1.z + (vect2.z - vect1.z) * stp;
	vect.w = vect1.w + (vect2.w - vect1.w) * stp;
	return vect;
}
#endif/*BQSELAYER_VECT_IMPL*/
#endif/*BQSELAYER_VECT_H*/