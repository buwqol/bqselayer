#ifndef BQSELAYER_COLOUR_H
#define BQSELAYER_COLOUR_H
#include "PrimTypes.h"
typedef struct { tIU8 r; tIU8 g; tIU8 b; } tIU8RGB;
typedef struct { tIU8 r; tIU8 g; tIU8 b; tIU8 a; } tIU8RGBA;
typedef struct { tFP32 r; tFP32 g; tFP32 b; } tFP32RGB;
typedef struct { tFP32 r; tFP32 g; tFP32 b; tFP32 a; } tFP32RGBA;
typedef struct { tFP64 r; tFP64 g; tFP64 b; } tFP64RGB;
typedef struct { tFP64 r; tFP64 g; tFP64 b; tFP64 a; } tFP64RGBA;
typedef tIU32 tIU32ARGB;
typedef tIU32 tIU32RGBA;
typedef tIU32 tIU32BGRA;
typedef tIU32 tIU32ABGR;
typedef struct { tFP32 h; tFP32 s; tFP32 v; } tFP32HSV;
typedef struct { tFP64 h; tFP64 s; tFP64 v; } tFP64HSV;
typedef struct { tFP32 h; tFP32 s; tFP32 l; } tFP32HSL;
typedef struct { tFP64 h; tFP64 s; tFP64 l; } tFP64HSL;
LINK_C_Begin
ForceInline tIU8RGB tIU8RGB_Make(tIU8 r, tIU8 g, tIU8 b);
ForceInline tIU8RGBA tIU8RGBA_Make(tIU8 r, tIU8 g, tIU8 b, tIU8 a);
ForceInline tFP32RGB tFP32RGB_Make(tFP32 r, tFP32 g, tFP32 b);
ForceInline tFP32RGBA tFP32RGBA_Make(tFP32 r, tFP32 g, tFP32 b, tFP32 a);
ForceInline tFP64RGB tFP64RGB_Make(tFP64 r, tFP64 g, tFP64 b);
ForceInline tFP64RGBA tFP64RGBA_Make(tFP64 r, tFP64 g, tFP64 b, tFP64 a);
ForceInline tIU32ARGB tIU32ARGB_Make(tIU8 a, tIU8 r, tIU8 g, tIU8 b);
ForceInline tIU32RGBA tIU32RGBA_Make(tIU8 r, tIU8 g, tIU8 b, tIU8 a);
ForceInline tIU32BGRA tIU32BGRA_Make(tIU8 b, tIU8 g, tIU8 r, tIU8 a);
ForceInline tIU32ABGR tIU32ABGR_Make(tIU8 a, tIU8 b, tIU8 g, tIU8 r);
ForceInline tFP32HSV tFP32HSV_Make(tFP32 h, tFP32 s, tFP32 v);
ForceInline tFP64HSV tFP64HSV_Make(tFP64 h, tFP64 s, tFP64 v);
ForceInline tFP32HSL tFP32HSL_Make(tFP32 h, tFP32 s, tFP32 l);
ForceInline tFP64HSL tFP64HSL_Make(tFP64 h, tFP64 s, tFP64 l);
ForceInline tBln tIU8RGB_Eq(tIU8RGB colour1, tIU8RGB colour2);
ForceInline tBln tIU8RGBA_Eq(tIU8RGBA colour1, tIU8RGBA colour2);
ForceInline tBln tFP32RGB_Eq(tFP32RGB colour1, tFP32RGB colour2);
ForceInline tBln tFP32RGBA_Eq(tFP32RGBA colour1, tFP32RGBA colour2);
ForceInline tBln tFP64RGB_Eq(tFP64RGB colour1, tFP64RGB colour2);
ForceInline tBln tFP64RGBA_Eq(tFP64RGBA colour1, tFP64RGBA colour2);
ForceInline tBln tIU32ARGB_Eq(tIU32ARGB colour1, tIU32ARGB colour2);
ForceInline tBln tIU32RGBA_Eq(tIU32RGBA colour1, tIU32RGBA colour2);
ForceInline tBln tIU32BGRA_Eq(tIU32BGRA colour1, tIU32BGRA colour2);
ForceInline tBln tIU32ABGR_Eq(tIU32ABGR colour1, tIU32ABGR colour2);
ForceInline tBln tFP32HSV_Eq(tFP32HSV colour1, tFP32HSV colour2);
ForceInline tBln tFP64HSV_Eq(tFP64HSV colour1, tFP64HSV colour2);
ForceInline tBln tFP32HSL_Eq(tFP32HSL colour1, tFP32HSL colour2);
ForceInline tBln tFP64HSL_Eq(tFP64HSL colour1, tFP64HSL colour2);
ForceInline tBln tFP32RGB_Nearby(tFP32RGB colour1, tFP32RGB colour2);
ForceInline tBln tFP32RGBA_Nearby(tFP32RGBA colour1, tFP32RGBA colour2);
ForceInline tBln tFP64RGB_Nearby(tFP64RGB colour1, tFP64RGB colour2);
ForceInline tBln tFP64RGBA_Nearby(tFP64RGBA colour1, tFP64RGBA colour2);
ForceInline tBln tFP32HSV_Nearby(tFP32HSV colour1, tFP32HSV colour2);
ForceInline tBln tFP64HSV_Nearby(tFP64HSV colour1, tFP64HSV colour2);
ForceInline tBln tFP32HSL_Nearby(tFP32HSL colour1, tFP32HSL colour2);
ForceInline tBln tFP64HSL_Nearby(tFP64HSL colour1, tFP64HSL colour2);
ForceInline tIU32ARGB tIU32ARGB_From_tRGBA(tIU8RGBA colour);
ForceInline tIU32RGBA tIU32RGBA_From_tRGBA(tIU8RGBA colour);
ForceInline tIU32BGRA tIU32BGRA_From_tRGBA(tIU8RGBA colour);
ForceInline tIU32ABGR tIU32ABGR_From_tRGBA(tIU8RGBA colour);
ForceInline tIU8RGBA tIU8RGBA_From_tIU32ARGB(tIU32ARGB colour);
ForceInline tIU8RGBA tIU8RGBA_From_tIU32RGBA(tIU32RGBA colour);
ForceInline tIU8RGBA tIU8RGBA_From_tIU32BGRA(tIU32BGRA colour);
ForceInline tIU8RGBA tIU8RGBA_From_tIU32ABGR(tIU32ABGR colour);
ForceInline tFP32HSV tFP32RGB_ToHSV(tFP32RGB colour);
ForceInline tFP32RGB tFP32HSV_ToRGB(tFP32HSV colour);
ForceInline tFP32HSL tFP32RGB_ToHSL(tFP32RGB colour);
ForceInline tFP32RGB tFP32HSL_ToRGB(tFP32HSL colour);
ForceInline tFP64HSV tFP64RGB_ToHSV(tFP64RGB colour);
ForceInline tFP64RGB tFP64HSV_ToRGB(tFP64HSV colour);
ForceInline tFP64HSL tFP64RGB_ToHSL(tFP64RGB colour);
ForceInline tFP64RGB tFP64HSL_ToRGB(tFP64HSL colour);
ForceInline tFP32RGB tFP32RGB_From_tIU8RGB(tIU8RGB colour);
ForceInline tFP32RGBA tFP32RGBA_From_tIU8RGBA(tIU8RGBA colour);
ForceInline tIU8RGB tIU8RGB_From_tFP32RGB(tFP32RGB colour);
ForceInline tIU8RGBA tIU8RGBA_From_tFP32RGBA(tFP32RGBA colour);
ForceInline tFP64RGB tFP64RGB_From_tIU8RGB(tIU8RGB colour);
ForceInline tFP64RGBA tFP64RGBA_From_tIU8RGBA(tIU8RGBA colour);
ForceInline tIU8RGB tIU8RGB_From_tFP64RGB(tFP64RGB colour);
ForceInline tIU8RGBA tIU8RGBA_From_tFP64RGBA(tFP64RGBA colour);
ForceInline tFP64RGB tFP64RGB_From_tFP32RGB(tFP32RGB colour);
ForceInline tFP64RGBA tFP64RGBA_From_tFP32RGBA(tFP32RGBA colour);
ForceInline tFP32RGB tFP32RGB_From_tFP64RGB(tFP64RGB colour);
ForceInline tFP32RGBA tFP32RGBA_From_tFP64RGBA(tFP64RGBA colour);
ForceInline tFP32RGB tFP32RGB_Lerp(tFP32RGB strt, tFP32RGB stp, tFP32 fnsh);
ForceInline tFP32RGBA tFP32RGBA_Lerp(tFP32RGBA strt, tFP32RGBA stp, tFP32 fnsh);
ForceInline tFP64RGB tFP64RGB_Lerp(tFP64RGB strt, tFP64RGB stp, tFP64 fnsh);
ForceInline tFP64RGBA tFP64RGBA_Lerp(tFP64RGBA strt, tFP64RGBA stp, tFP64 fnsh);
ForceInline tIU8RGB tIU8RGB_Add(tIU8RGB colour1, tIU8RGB colour2);
ForceInline tIU8RGB tIU8RGB_Sub(tIU8RGB colour1, tIU8RGB colour2);
ForceInline tIU8RGB tIU8RGB_Mul(tIU8RGB colour1, tIU8RGB colour2);
ForceInline tIU8RGB tIU8RGB_Div(tIU8RGB colour1, tIU8RGB colour2);
ForceInline tFP32RGB tFP32RGB_Add(tFP32RGB colour1, tFP32RGB colour2);
ForceInline tFP32RGB tFP32RGB_Sub(tFP32RGB colour1, tFP32RGB colour2);
ForceInline tFP32RGB tFP32RGB_Mul(tFP32RGB colour1, tFP32RGB colour2);
ForceInline tFP32RGB tFP32RGB_Div(tFP32RGB colour1, tFP32RGB colour2);
ForceInline tFP64RGB tFP64RGB_Add(tFP64RGB colour1, tFP64RGB colour2);
ForceInline tFP64RGB tFP64RGB_Sub(tFP64RGB colour1, tFP64RGB colour2);
ForceInline tFP64RGB tFP64RGB_Mul(tFP64RGB colour1, tFP64RGB colour2);
ForceInline tFP64RGB tFP64RGB_Div(tFP64RGB colour1, tFP64RGB colour2);
ForceInline tFP32RGBA tFP32RGBA_Add(tFP32RGBA colour1, tFP32RGBA colour2);
ForceInline tFP32RGBA tFP32RGBA_Sub(tFP32RGBA colour1, tFP32RGBA colour2);
ForceInline tFP32RGBA tFP32RGBA_Mul(tFP32RGBA colour1, tFP32RGBA colour2);
ForceInline tFP32RGBA tFP32RGBA_Div(tFP32RGBA colour1, tFP32RGBA colour2);
ForceInline tIU8RGBA tIU8RGBA_Add(tIU8RGBA colour1, tIU8RGBA colour2);
ForceInline tIU8RGBA tIU8RGBA_Sub(tIU8RGBA colour1, tIU8RGBA colour2);
ForceInline tIU8RGBA tIU8RGBA_Mul(tIU8RGBA colour1, tIU8RGBA colour2);
ForceInline tIU8RGBA tIU8RGBA_Div(tIU8RGBA colour1, tIU8RGBA colour2);
ForceInline tFP64RGBA tFP64RGBA_Add(tFP64RGBA colour1, tFP64RGBA colour2);
ForceInline tFP64RGBA tFP64RGBA_Sub(tFP64RGBA colour1, tFP64RGBA colour2);
ForceInline tFP64RGBA tFP64RGBA_Mul(tFP64RGBA colour1, tFP64RGBA colour2);
ForceInline tFP64RGBA tFP64RGBA_Div(tFP64RGBA colour1, tFP64RGBA colour2);
ForceInline tIU32ARGB tIU32ARGB_Add(tIU32ARGB colour1, tIU32ARGB colour2);
ForceInline tIU32ARGB tIU32ARGB_Sub(tIU32ARGB colour1, tIU32ARGB colour2);
ForceInline tIU32ARGB tIU32ARGB_Mul(tIU32ARGB colour1, tIU32ARGB colour2);
ForceInline tIU32ARGB tIU32ARGB_Div(tIU32ARGB colour1, tIU32ARGB colour2);
ForceInline tIU32RGBA tIU32RGBA_Add(tIU32RGBA colour1, tIU32RGBA colour2);
ForceInline tIU32RGBA tIU32RGBA_Sub(tIU32RGBA colour1, tIU32RGBA colour2);
ForceInline tIU32RGBA tIU32RGBA_Mul(tIU32RGBA colour1, tIU32RGBA colour2);
ForceInline tIU32RGBA tIU32RGBA_Div(tIU32RGBA colour1, tIU32RGBA colour2);
ForceInline tIU32BGRA tIU32BGRA_Add(tIU32BGRA colour1, tIU32BGRA colour2);
ForceInline tIU32BGRA tIU32BGRA_Sub(tIU32BGRA colour1, tIU32BGRA colour2);
ForceInline tIU32BGRA tIU32BGRA_Mul(tIU32BGRA colour1, tIU32BGRA colour2);
ForceInline tIU32BGRA tIU32BGRA_Div(tIU32BGRA colour1, tIU32BGRA colour2);
ForceInline tIU32ABGR tIU32ABGR_Add(tIU32ABGR colour1, tIU32ABGR colour2);
ForceInline tIU32ABGR tIU32ABGR_Sub(tIU32ABGR colour1, tIU32ABGR colour2);
ForceInline tIU32ABGR tIU32ABGR_Mul(tIU32ABGR colour1, tIU32ABGR colour2);
ForceInline tIU32ABGR tIU32ABGR_Div(tIU32ABGR colour1, tIU32ABGR colour2);
ForceInline tFP32RGB tFP32RGB_AddFlt(tFP32RGB colour, tFP32 flt);
ForceInline tFP32RGB tFP32RGB_SubFlt(tFP32RGB colour, tFP32 flt);
ForceInline tFP32RGB tFP32RGB_MulFlt(tFP32RGB colour, tFP32 flt);
ForceInline tFP32RGB tFP32RGB_DivFlt(tFP32RGB colour, tFP32 flt);
ForceInline tFP32RGBA tFP32RGBA_AddFlt(tFP32RGBA colour, tFP32 flt);
ForceInline tFP32RGBA tFP32RGBA_SubFlt(tFP32RGBA colour, tFP32 flt);
ForceInline tFP32RGBA tFP32RGBA_MulFlt(tFP32RGBA colour, tFP32 flt);
ForceInline tFP32RGBA tFP32RGBA_DivFlt(tFP32RGBA colour, tFP32 flt);
ForceInline tFP64RGB tFP64RGB_AddDbl(tFP64RGB colour, tFP64 dbl);
ForceInline tFP64RGB tFP64RGB_SubDbl(tFP64RGB colour, tFP64 dbl);
ForceInline tFP64RGB tFP64RGB_MulDbl(tFP64RGB colour, tFP64 dbl);
ForceInline tFP64RGB tFP64RGB_DivDbl(tFP64RGB colour, tFP64 dbl);
ForceInline tFP64RGBA tFP64RGBA_AddDbl(tFP64RGBA colour, tFP64 dbl);
ForceInline tFP64RGBA tFP64RGBA_SubDbl(tFP64RGBA colour, tFP64 dbl);
ForceInline tFP64RGBA tFP64RGBA_MulDbl(tFP64RGBA colour, tFP64 dbl);
ForceInline tFP64RGBA tFP64RGBA_DivDbl(tFP64RGBA colour, tFP64 dbl);
ForceInline tFP32RGB tFP32RGB_Clamp(tFP32RGB colour);
ForceInline tFP32RGBA tFP32RGBA_Clamp(tFP32RGBA colour);
ForceInline tFP32RGB tFP32RGB_Saturate(tFP32RGB colour);
ForceInline tFP32RGBA tFP32RGBA_Saturate(tFP32RGBA colour);
ForceInline tFP32RGB tFP32RGB_Blend(tFP32RGB colour1, tFP32RGB colour2, tFP32 stp);
ForceInline tFP32RGBA tFP32RGBA_Blend(tFP32RGBA colour1, tFP32RGBA colour2, tFP32 stp);
ForceInline tFP64RGB tFP64RGB_Clamp(tFP64RGB colour);
ForceInline tFP64RGBA tFP64RGBA_Clamp(tFP64RGBA colour);
ForceInline tFP64RGB tFP64RGB_Saturate(tFP64RGB colour);
ForceInline tFP64RGBA tFP64RGBA_Saturate(tFP64RGBA colour);
ForceInline tFP64RGB tFP64RGB_Blend(tFP64RGB colour1, tFP64RGB colour2, tFP64 stp);
ForceInline tFP64RGBA tFP64RGBA_Blend(tFP64RGBA colour1, tFP64RGBA colour2, tFP64 stp);
LINK_C_End
#ifdef BQSELAYER_COLOUR_IMPL
ForceInline tIU8RGB tIU8RGB_Make(tIU8 r, tIU8 g, tIU8 b)
{
	tIU8RGB colour;
	colour.r = r;
	colour.g = g;
	colour.b = b;
	return colour;
}
ForceInline tIU8RGBA tIU8RGBA_Make(tIU8 r, tIU8 g, tIU8 b, tIU8 a)
{
	tIU8RGBA colour;
	colour.r = r;
	colour.g = g;
	colour.b = b;
	colour.a = a;
	return colour;
}
ForceInline tFP32RGB tFP32RGB_Make(tFP32 r, tFP32 g, tFP32 b)
{
	tFP32RGB colour;
	colour.r = tFP32_Clamp(0.0F, r, 1.0F);
	colour.g = tFP32_Clamp(0.0F, g, 1.0F);
	colour.b = tFP32_Clamp(0.0F, b, 1.0F);
	return colour;
}
ForceInline tFP32RGBA tFP32RGBA_Make(tFP32 r, tFP32 g, tFP32 b, tFP32 a)
{
	tFP32RGBA colour;
	colour.r = tFP32_Clamp(0.0F, r, 1.0F);
	colour.g = tFP32_Clamp(0.0F, g, 1.0F);
	colour.b = tFP32_Clamp(0.0F, b, 1.0F);
	colour.a = tFP32_Clamp(0.0F, a, 1.0F);
	return colour;
}
ForceInline tFP64RGB tFP64RGB_Make(tFP64 r, tFP64 g, tFP64 b)
{
	tFP64RGB colour;
	colour.r = tFP64_Clamp(0.0, r, 1.0);
	colour.g = tFP64_Clamp(0.0, g, 1.0);
	colour.b = tFP64_Clamp(0.0, b, 1.0);
	return colour;
}
ForceInline tFP64RGBA tFP64RGBA_Make(tFP64 r, tFP64 g, tFP64 b, tFP64 a)
{
	tFP64RGBA colour;
	colour.r = tFP64_Clamp(0.0, r, 1.0);
	colour.g = tFP64_Clamp(0.0, g, 1.0);
	colour.b = tFP64_Clamp(0.0, b, 1.0);
	colour.a = tFP64_Clamp(0.0, a, 1.0);
	return colour;
}
ForceInline tIU32ARGB tIU32ARGB_Make(tIU8 a, tIU8 r, tIU8 g, tIU8 b)
{
	tIU32ARGB colour;
	colour = ((tIU32)a << 24U) | ((tIU32)r << 16U) | ((tIU32)g << 8U) | (tIU32)b;
	return colour;
}
ForceInline tIU32RGBA tIU32RGBA_Make(tIU8 r, tIU8 g, tIU8 b, tIU8 a)
{
	tIU32RGBA colour;
	colour = ((tIU32)r << 24U) | ((tIU32)g << 16U) | ((tIU32)b << 8U) | (tIU32)a;
	return colour;
}
ForceInline tIU32BGRA tIU32BGRA_Make(tIU8 b, tIU8 g, tIU8 r, tIU8 a)
{
	tIU32BGRA colour;
	colour = ((tIU32)b << 24U) | ((tIU32)g << 16U) | ((tIU32)r << 8U) | (tIU32)a;
	return colour;
}
ForceInline tIU32ABGR tIU32ABGR_Make(tIU8 a, tIU8 b, tIU8 g, tIU8 r)
{
	tIU32ABGR colour;
	colour = ((tIU32)a << 24U) | ((tIU32)b << 16U) | ((tIU32)g << 8U) | (tIU32)r;
	return colour;
}
ForceInline tFP32HSV tFP32HSV_Make(tFP32 h, tFP32 s, tFP32 v)
{
	tFP32HSV colour;
	colour.h = tFP32_Clamp(0.0F, h, 360.0F);
	if (colour.h == 360.0F) colour.h = 0.0F;
	colour.s = tFP32_Clamp(0.0F, s, 1.0F);
	colour.v = tFP32_Clamp(0.0F, v, 1.0F);
	return colour;
}
ForceInline tFP64HSV tFP64HSV_Make(tFP64 h, tFP64 s, tFP64 v)
{
	tFP64HSV colour;
	colour.h = tFP64_Clamp(0.0, h, 360.0);
	if (colour.h == 360.0) colour.h = 0.0;
	colour.s = tFP64_Clamp(0.0, s, 1.0);
	colour.v = tFP64_Clamp(0.0, v, 1.0);
	return colour;
}
ForceInline tFP32HSL tFP32HSL_Make(tFP32 h, tFP32 s, tFP32 l)
{
	tFP32HSL colour;
	colour.h = tFP32_Clamp(0.0F, h, 360.0F);
	if (colour.h == 360.0F) colour.h = 0.0F;
	colour.s = tFP32_Clamp(0.0F, s, 1.0F);
	colour.l = tFP32_Clamp(0.0F, l, 1.0F);
	return colour;
}
ForceInline tFP64HSL tFP64HSL_Make(tFP64 h, tFP64 s, tFP64 l)
{
	tFP64HSL colour;
	colour.h = tFP64_Clamp(0.0, h, 360.0);
	if (colour.h == 360.0) colour.h = 0.0;
	colour.s = tFP64_Clamp(0.0, s, 1.0);
	colour.l = tFP64_Clamp(0.0, l, 1.0);
	return colour;
}
ForceInline tBln tIU8RGB_Eq(tIU8RGB colour1, tIU8RGB colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b;
}
ForceInline tBln tIU8RGBA_Eq(tIU8RGBA colour1, tIU8RGBA colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b && colour1.a == colour2.a;
}
ForceInline tBln tFP32RGB_Eq(tFP32RGB colour1, tFP32RGB colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b;
}
ForceInline tBln tFP32RGBA_Eq(tFP32RGBA colour1, tFP32RGBA colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b && colour1.a == colour2.a;
}
ForceInline tBln tFP64RGB_Eq(tFP64RGB colour1, tFP64RGB colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b;
}
ForceInline tBln tFP64RGBA_Eq(tFP64RGBA colour1, tFP64RGBA colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b && colour1.a == colour2.a;
}
ForceInline tBln tIU32ARGB_Eq(tIU32ARGB colour1, tIU32ARGB colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tIU32RGBA_Eq(tIU32RGBA colour1, tIU32RGBA colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tIU32BGRA_Eq(tIU32BGRA colour1, tIU32BGRA colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tIU32ABGR_Eq(tIU32ABGR colour1, tIU32ABGR colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tFP32HSV_Eq(tFP32HSV colour1, tFP32HSV colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.v == colour2.v;
}
ForceInline tBln tFP64HSV_Eq(tFP64HSV colour1, tFP64HSV colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.v == colour2.v;
}
ForceInline tBln tFP32HSL_Eq(tFP32HSL colour1, tFP32HSL colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.l == colour2.l;
}
ForceInline tBln tFP64HSL_Eq(tFP64HSL colour1, tFP64HSL colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.l == colour2.l;
}
ForceInline tBln tFP32RGB_Nearby(tFP32RGB colour1, tFP32RGB colour2)
{
	return tFP32_Nearby(colour1.r, colour2.r) && tFP32_Nearby(colour1.g, colour2.g) && tFP32_Nearby(colour1.b, colour2.b);
}
ForceInline tBln tFP32RGBA_Nearby(tFP32RGBA colour1, tFP32RGBA colour2)
{
	return tFP32_Nearby(colour1.r, colour2.r) && tFP32_Nearby(colour1.g, colour2.g) && tFP32_Nearby(colour1.b, colour2.b) && tFP32_Nearby(colour1.a, colour2.a);
}
ForceInline tBln tFP64RGB_Nearby(tFP64RGB colour1, tFP64RGB colour2)
{
	return tFP64_Nearby(colour1.r, colour2.r) && tFP64_Nearby(colour1.g, colour2.g) && tFP64_Nearby(colour1.b, colour2.b);
}
ForceInline tBln tFP64RGBA_Nearby(tFP64RGBA colour1, tFP64RGBA colour2)
{
	return tFP64_Nearby(colour1.r, colour2.r) && tFP64_Nearby(colour1.g, colour2.g) && tFP64_Nearby(colour1.b, colour2.b) && tFP64_Nearby(colour1.a, colour2.a);
}
ForceInline tBln tFP32HSV_Nearby(tFP32HSV colour1, tFP32HSV colour2)
{
	return tFP32_Nearby(colour1.h, colour2.h) && tFP32_Nearby(colour1.s, colour2.s) && tFP32_Nearby(colour1.v, colour2.v);
}
ForceInline tBln tFP64HSV_Nearby(tFP64HSV colour1, tFP64HSV colour2)
{
	return tFP64_Nearby(colour1.h, colour2.h) && tFP64_Nearby(colour1.s, colour2.s) && tFP64_Nearby(colour1.v, colour2.v);
}
ForceInline tBln tFP32HSL_Nearby(tFP32HSL colour1, tFP32HSL colour2)
{
	return tFP32_Nearby(colour1.h, colour2.h) && tFP32_Nearby(colour1.s, colour2.s) && tFP32_Nearby(colour1.l, colour2.l);
}
ForceInline tBln tFP64HSL_Nearby(tFP64HSL colour1, tFP64HSL colour2)
{
	return tFP64_Nearby(colour1.h, colour2.h) && tFP64_Nearby(colour1.s, colour2.s) && tFP64_Nearby(colour1.l, colour2.l);
}
ForceInline tIU32ARGB tIU32ARGB_From_tRGBA(tIU8RGBA colour)
{
	return ((tIU32)colour.a << 24U) | ((tIU32)colour.r << 16U) | ((tIU32)colour.g << 8U) | (tIU32)colour.b;
}
ForceInline tIU32RGBA tIU32RGBA_From_tRGBA(tIU8RGBA colour)
{
	return ((tIU32)colour.r << 24U) | ((tIU32)colour.g << 16U) | ((tIU32)colour.b << 8U) | (tIU32)colour.a;
}
ForceInline tIU32BGRA tIU32BGRA_From_tRGBA(tIU8RGBA colour)
{
	return ((tIU32)colour.b << 24U) | ((tIU32)colour.g << 16U) | ((tIU32)colour.r << 8U) | (tIU32)colour.a;
}
ForceInline tIU32ABGR tIU32ABGR_From_tRGBA(tIU8RGBA colour)
{
	return ((tIU32)colour.a << 24U) | ((tIU32)colour.b << 16U) | ((tIU32)colour.g << 8U) | (tIU32)colour.r;
}
ForceInline tIU8RGBA tIU8RGBA_From_tIU32ARGB(tIU32ARGB colour)
{
	tIU8RGBA ret;
	ret.a = (tIU8)(colour >> 24U);
	ret.r = (tIU8)(colour >> 16U);
	ret.g = (tIU8)(colour >> 8U);
	ret.b = (tIU8)colour;
	return ret;
}
ForceInline tIU8RGBA tIU8RGBA_From_tIU32RGBA(tIU32RGBA colour)
{
	tIU8RGBA ret;
	ret.r = (tIU8)(colour >> 24U);
	ret.g = (tIU8)(colour >> 16U);
	ret.b = (tIU8)(colour >> 8U);
	ret.a = (tIU8)colour;
	return ret;
}
ForceInline tIU8RGBA tIU8RGBA_From_tIU32BGRA(tIU32BGRA colour)
{
	tIU8RGBA ret;
	ret.b = (tIU8)(colour >> 24U);
	ret.g = (tIU8)(colour >> 16U);
	ret.r = (tIU8)(colour >> 8U);
	ret.a = (tIU8)colour;
	return ret;
}
ForceInline tIU8RGBA tIU8RGBA_From_tIU32ABGR(tIU32ABGR colour)
{
	tIU8RGBA ret;
	ret.a = (tIU8)(colour >> 24U);
	ret.b = (tIU8)(colour >> 16U);
	ret.g = (tIU8)(colour >> 8U);
	ret.r = (tIU8)colour;
	return ret;
}
ForceInline tFP32HSV tFP32RGB_ToHSV(tFP32RGB colour)
{
	tFP32 r = colour.r;
	tFP32 g = colour.g;
	tFP32 b = colour.b;
	tFP32 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tFP32 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tFP32 delta = max - min;
	tFP32HSV hsv;
	hsv.v = max;
	if (delta == 0.0F)
	{
		hsv.h = 0.0F;
		hsv.s = 0.0F;
		return hsv;
	}
	hsv.s = delta / max;
	if (max == r)
	{
		hsv.h = 60.0F * ((g - b) / delta);
	}
	else if (max == g)
	{
		hsv.h = 60.0F * (2.0F + (b - r) / delta);
	}
	else
	{
		hsv.h = 60.0F * (4.0F + (r - g) / delta);
	}
	if (hsv.h < 0.0F) hsv.h += 360.0F;
	return hsv;
}
ForceInline tFP32RGB tFP32HSV_ToRGB(tFP32HSV colour)
{
	tFP32 h = colour.h;
	tFP32 s = colour.s;
	tFP32 v = colour.v;
	tFP32 cval = v * s;
	tFP32 x = cval * (1.0F - tFP32_Abs(tFP32_Mod(h / 60.0F, 2.0F) - 1.0F));
	tFP32 m = v - cval;
	tFP32 r, g, b;
	if (h < 60.0F)
	{
		r = cval; g = x; b = 0.0F;
	}
	else if (h < 120.0F)
	{
		r = x; g = cval; b = 0.0F;
	}
	else if (h < 180.0F)
	{
		r = 0.0F; g = cval; b = x;
	}
	else if (h < 240.0F)
	{
		r = 0.0F; g = x; b = cval;
	}
	else if (h < 300.0F)
	{
		r = x; g = 0.0F; b = cval;
	}
	else
	{
		r = cval; g = 0.0F; b = x;
	}
	tFP32RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tFP32HSL tFP32RGB_ToHSL(tFP32RGB colour)
{
	tFP32 r = colour.r;
	tFP32 g = colour.g;
	tFP32 b = colour.b;
	tFP32 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tFP32 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tFP32 delta = max - min;
	tFP32HSL hsl;
	hsl.l = (max + min) * 0.5F;
	if (delta == 0.0F)
	{
		hsl.h = 0.0F;
		hsl.s = 0.0F;
		return hsl;
	}
	if (hsl.l < 0.5F)
	{
		hsl.s = delta / (max + min);
	}
	else
	{
		hsl.s = delta / (2.0F - max - min);
	}
	if (max == r)
	{
		hsl.h = 60.0F * ((g - b) / delta);
	}
	else if (max == g)
	{
		hsl.h = 60.0F * (2.0F + (b - r) / delta);
	}
	else
	{
		hsl.h = 60.0F * (4.0F + (r - g) / delta);
	}
	if (hsl.h < 0.0F) hsl.h += 360.0F;
	return hsl;
}
ForceInline tFP32RGB tFP32HSL_ToRGB(tFP32HSL colour)
{
	tFP32 h = colour.h;
	tFP32 s = colour.s;
	tFP32 l = colour.l;
	tFP32 cval = (1.0F - tFP32_Abs(2.0F * l - 1.0F)) * s;
	tFP32 x = cval * (1.0F - tFP32_Abs(tFP32_Mod(h / 60.0F, 2.0F) - 1.0F));
	tFP32 m = l - cval * 0.5F;
	tFP32 r, g, b;
	if (h < 60.0F)
	{
		r = cval; g = x; b = 0.0F;
	}
	else if (h < 120.0F)
	{
		r = x; g = cval; b = 0.0F;
	}
	else if (h < 180.0F)
	{
		r = 0.0F; g = cval; b = x;
	}
	else if (h < 240.0F)
	{
		r = 0.0F; g = x; b = cval;
	}
	else if (h < 300.0F)
	{
		r = x; g = 0.0F; b = cval;
	}
	else
	{
		r = cval; g = 0.0F; b = x;
	}
	tFP32RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tFP64HSV tFP64RGB_ToHSV(tFP64RGB colour)
{
	tFP64 r = colour.r;
	tFP64 g = colour.g;
	tFP64 b = colour.b;
	tFP64 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tFP64 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tFP64 delta = max - min;
	tFP64HSV hsv;
	hsv.v = max;
	if (delta == 0.0)
	{
		hsv.h = 0.0;
		hsv.s = 0.0;
		return hsv;
	}
	hsv.s = delta / max;
	if (max == r)
	{
		hsv.h = 60.0 * ((g - b) / delta);
	}
	else if (max == g)
	{
		hsv.h = 60.0 * (2.0 + (b - r) / delta);
	}
	else
	{
		hsv.h = 60.0 * (4.0 + (r - g) / delta);
	}
	if (hsv.h < 0.0) hsv.h += 360.0;
	return hsv;
}
ForceInline tFP64RGB tFP64HSV_ToRGB(tFP64HSV colour)
{
	tFP64 h = colour.h;
	tFP64 s = colour.s;
	tFP64 v = colour.v;
	tFP64 cval = v * s;
	tFP64 x = cval * (1.0 - tFP64_Abs(tFP64_Mod(h / 60.0, 2.0) - 1.0));
	tFP64 m = v - cval;
	tFP64 r, g, b;
	if (h < 60.0)
	{
		r = cval; g = x; b = 0.0;
	}
	else if (h < 120.0)
	{
		r = x; g = cval; b = 0.0;
	}
	else if (h < 180.0)
	{
		r = 0.0; g = cval; b = x;
	}
	else if (h < 240.0)
	{
		r = 0.0; g = x; b = cval;
	}
	else if (h < 300.0)
	{
		r = x; g = 0.0; b = cval;
	}
	else
	{
		r = cval; g = 0.0; b = x;
	}
	tFP64RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tFP64HSL tFP64RGB_ToHSL(tFP64RGB colour)
{
	tFP64 r = colour.r;
	tFP64 g = colour.g;
	tFP64 b = colour.b;
	tFP64 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tFP64 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tFP64 delta = max - min;
	tFP64HSL hsl;
	hsl.l = (max + min) * 0.5;
	if (delta == 0.0)
	{
		hsl.h = 0.0;
		hsl.s = 0.0;
		return hsl;
	}
	if (hsl.l < 0.5)
	{
		hsl.s = delta / (max + min);
	}
	else
	{
		hsl.s = delta / (2.0 - max - min);
	}
	if (max == r)
	{
		hsl.h = 60.0 * ((g - b) / delta);
	}
	else if (max == g)
	{
		hsl.h = 60.0 * (2.0 + (b - r) / delta);
	}
	else
	{
		hsl.h = 60.0 * (4.0 + (r - g) / delta);
	}
	if (hsl.h < 0.0) hsl.h += 360.0;
	return hsl;
}
ForceInline tFP64RGB tFP64HSL_ToRGB(tFP64HSL colour)
{
	tFP64 h = colour.h;
	tFP64 s = colour.s;
	tFP64 l = colour.l;
	tFP64 cval = (1.0 - tFP64_Abs(2.0 * l - 1.0)) * s;
	tFP64 x = cval * (1.0 - tFP64_Abs(tFP64_Mod(h / 60.0, 2.0) - 1.0));
	tFP64 m = l - cval * 0.5;
	tFP64 r, g, b;
	if (h < 60.0)
	{
		r = cval; g = x; b = 0.0;
	}
	else if (h < 120.0)
	{
		r = x; g = cval; b = 0.0;
	}
	else if (h < 180.0)
	{
		r = 0.0; g = cval; b = x;
	}
	else if (h < 240.0)
	{
		r = 0.0; g = x; b = cval;
	}
	else if (h < 300.0)
	{
		r = x; g = 0.0; b = cval;
	}
	else
	{
		r = cval; g = 0.0; b = x;
	}
	tFP64RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tFP32RGB tFP32RGB_From_tIU8RGB(tIU8RGB colour)
{
	tFP32RGB out;
	out.r = (tFP32)colour.r / 255.0F;
	out.g = (tFP32)colour.g / 255.0F;
	out.b = (tFP32)colour.b / 255.0F;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_From_tIU8RGBA(tIU8RGBA colour)
{
	tFP32RGBA out;
	out.r = (tFP32)colour.r / 255.0F;
	out.g = (tFP32)colour.g / 255.0F;
	out.b = (tFP32)colour.b / 255.0F;
	out.a = (tFP32)colour.a / 255.0F;
	return out;
}
ForceInline tIU8RGB tIU8RGB_From_tFP32RGB(tFP32RGB colour)
{
	tIU8RGB out;
	out.r = (tIU8)tFP32_Clamp(0.0F, colour.r, 1.0F) * 255U;
	out.g = (tIU8)tFP32_Clamp(0.0F, colour.g, 1.0F) * 255U;
	out.b = (tIU8)tFP32_Clamp(0.0F, colour.b, 1.0F) * 255U;
	return out;
}
ForceInline tIU8RGBA tIU8RGBA_From_tFP32RGBA(tFP32RGBA colour)
{
	tIU8RGBA out;
	out.r = (tIU8)tFP32_Clamp(0.0F, colour.r, 1.0F) * 255U;
	out.g = (tIU8)tFP32_Clamp(0.0F, colour.g, 1.0F) * 255U;
	out.b = (tIU8)tFP32_Clamp(0.0F, colour.b, 1.0F) * 255U;
	out.a = (tIU8)tFP32_Clamp(0.0F, colour.a, 1.0F) * 255U;
	return out;
}
ForceInline tFP64RGB tFP64RGB_From_tIU8RGB(tIU8RGB colour)
{
	tFP64RGB out;
	out.r = (tFP64)colour.r / 255.0;
	out.g = (tFP64)colour.g / 255.0;
	out.b = (tFP64)colour.b / 255.0;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_From_tIU8RGBA(tIU8RGBA colour)
{
	tFP64RGBA out;
	out.r = (tFP64)colour.r / 255.0;
	out.g = (tFP64)colour.g / 255.0;
	out.b = (tFP64)colour.b / 255.0;
	out.a = (tFP64)colour.a / 255.0;
	return out;
}
ForceInline tIU8RGB tIU8RGB_From_tFP64RGB(tFP64RGB colour)
{
	tIU8RGB out;
	out.r = (tIU8)tFP64_Clamp(0.0, colour.r, 1.0) * 255U;
	out.g = (tIU8)tFP64_Clamp(0.0, colour.g, 1.0) * 255U;
	out.b = (tIU8)tFP64_Clamp(0.0, colour.b, 1.0) * 255U;
	return out;
}
ForceInline tIU8RGBA tIU8RGBA_From_tFP64RGBA(tFP64RGBA colour)
{
	tIU8RGBA out;
	out.r = (tIU8)tFP64_Clamp(0.0, colour.r, 1.0) * 255U;
	out.g = (tIU8)tFP64_Clamp(0.0, colour.g, 1.0) * 255U;
	out.b = (tIU8)tFP64_Clamp(0.0, colour.b, 1.0) * 255U;
	out.a = (tIU8)tFP64_Clamp(0.0, colour.a, 1.0) * 255U;
	return out;
}
ForceInline tFP64RGB tFP64RGB_From_tFP32RGB(tFP32RGB colour)
{
	tFP64RGB out;
	out.r = (tFP64)colour.r;
	out.g = (tFP64)colour.g;
	out.b = (tFP64)colour.b;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_From_tFP32RGBA(tFP32RGBA colour)
{
	tFP64RGBA out;
	out.r = (tFP64)colour.r;
	out.g = (tFP64)colour.g;
	out.b = (tFP64)colour.b;
	out.a = (tFP64)colour.a;
	return out;
}
ForceInline tFP32RGB tFP32RGB_From_tFP64RGB(tFP64RGB colour)
{
	tFP32RGB out;
	out.r = (tFP32)colour.r;
	out.g = (tFP32)colour.g;
	out.b = (tFP32)colour.b;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_From_tFP64RGBA(tFP64RGBA colour)
{
	tFP32RGBA out;
	out.r = (tFP32)colour.r;
	out.g = (tFP32)colour.g;
	out.b = (tFP32)colour.b;
	out.a = (tFP32)colour.a;
	return out;
}
ForceInline tFP32RGB tFP32RGB_Lerp(tFP32RGB strt, tFP32RGB stp, tFP32 fnsh)
{
	tFP32RGB out;
	out.r = tFP32_Lerp(strt.r, stp.r, fnsh);
	out.g = tFP32_Lerp(strt.g, stp.g, fnsh);
	out.b = tFP32_Lerp(strt.b, stp.b, fnsh);
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Lerp(tFP32RGBA strt, tFP32RGBA stp, tFP32 fnsh)
{
	tFP32RGBA out;
	out.r = tFP32_Lerp(strt.r, stp.r, fnsh);
	out.g = tFP32_Lerp(strt.g, stp.g, fnsh);
	out.b = tFP32_Lerp(strt.b, stp.b, fnsh);
	out.a = tFP32_Lerp(strt.a, stp.a, fnsh);
	return out;
}
ForceInline tFP64RGB tFP64RGB_Lerp(tFP64RGB strt, tFP64RGB stp, tFP64 fnsh)
{
	tFP64RGB out;
	out.r = tFP64_Lerp(strt.r, stp.r, fnsh);
	out.g = tFP64_Lerp(strt.g, stp.g, fnsh);
	out.b = tFP64_Lerp(strt.b, stp.b, fnsh);
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Lerp(tFP64RGBA strt, tFP64RGBA stp, tFP64 fnsh)
{
	tFP64RGBA out;
	out.r = tFP64_Lerp(strt.r, stp.r, fnsh);
	out.g = tFP64_Lerp(strt.g, stp.g, fnsh);
	out.b = tFP64_Lerp(strt.b, stp.b, fnsh);
	out.a = tFP64_Lerp(strt.a, stp.a, fnsh);
	return out;
}
ForceInline tIU8RGB tIU8RGB_Add(tIU8RGB colour1, tIU8RGB colour2)
{
	tIU8RGB out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	return out;
}
ForceInline tIU8RGB tIU8RGB_Sub(tIU8RGB colour1, tIU8RGB colour2)
{
	tIU8RGB out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	return out;
}
ForceInline tIU8RGB tIU8RGB_Mul(tIU8RGB colour1, tIU8RGB colour2)
{
	tIU8RGB out;
	out.r = (tIU8)(((tIU16)colour1.r * (tIU16)colour2.r) / 255U);
	out.g = (tIU8)(((tIU16)colour1.g * (tIU16)colour2.g) / 255U);
	out.b = (tIU8)(((tIU16)colour1.b * (tIU16)colour2.b) / 255U);
	return out;
}
ForceInline tIU8RGB tIU8RGB_Div(tIU8RGB colour1, tIU8RGB colour2)
{
	tIU8RGB out;
	out.r = (colour2.r == 0U) ? 0U : (tIU8)(((tIU16)colour1.r * 255U) / colour2.r);
	out.g = (colour2.g == 0U) ? 0U : (tIU8)(((tIU16)colour1.g * 255U) / colour2.g);
	out.b = (colour2.b == 0U) ? 0U : (tIU8)(((tIU16)colour1.b * 255U) / colour2.b);
	return out;
}
ForceInline tFP32RGB tFP32RGB_Add(tFP32RGB colour1, tFP32RGB colour2)
{
	tFP32RGB out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	return out;
}
ForceInline tFP32RGB tFP32RGB_Sub(tFP32RGB colour1, tFP32RGB colour2)
{
	tFP32RGB out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	return out;
}
ForceInline tFP32RGB tFP32RGB_Mul(tFP32RGB colour1, tFP32RGB colour2)
{
	tFP32RGB out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	return out;
}
ForceInline tFP32RGB tFP32RGB_Div(tFP32RGB colour1, tFP32RGB colour2)
{
	tFP32RGB out;
	out.r = colour2.r == 0.0F ? 0.0F : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0F ? 0.0F : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0F ? 0.0F : (colour1.b / colour2.b);
	return out;
}
ForceInline tFP64RGB tFP64RGB_Add(tFP64RGB colour1, tFP64RGB colour2)
{
	tFP64RGB out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	return out;
}
ForceInline tFP64RGB tFP64RGB_Sub(tFP64RGB colour1, tFP64RGB colour2)
{
	tFP64RGB out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	return out;
}
ForceInline tFP64RGB tFP64RGB_Mul(tFP64RGB colour1, tFP64RGB colour2)
{
	tFP64RGB out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	return out;
}
ForceInline tFP64RGB tFP64RGB_Div(tFP64RGB colour1, tFP64RGB colour2)
{
	tFP64RGB out;
	out.r = colour2.r == 0.0 ? 0.0 : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0 ? 0.0 : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0 ? 0.0 : (colour1.b / colour2.b);
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Add(tFP32RGBA colour1, tFP32RGBA colour2)
{
	tFP32RGBA out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	out.a = colour1.a + colour2.a;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Sub(tFP32RGBA colour1, tFP32RGBA colour2)
{
	tFP32RGBA out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	out.a = colour1.a - colour2.a;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Mul(tFP32RGBA colour1, tFP32RGBA colour2)
{
	tFP32RGBA out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	out.a = colour1.a * colour2.a;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Div(tFP32RGBA colour1, tFP32RGBA colour2)
{
	tFP32RGBA out;
	out.r = colour2.r == 0.0F ? 0.0F : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0F ? 0.0F : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0F ? 0.0F : (colour1.b / colour2.b);
	out.a = colour2.a == 0.0F ? 0.0F : (colour1.a / colour2.a);
	return out;
}
ForceInline tIU8RGBA tIU8RGBA_Add(tIU8RGBA colour1, tIU8RGBA colour2)
{
	tIU8RGBA out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	out.a = colour1.a + colour2.a;
	return out;
}
ForceInline tIU8RGBA tIU8RGBA_Sub(tIU8RGBA colour1, tIU8RGBA colour2)
{
	tIU8RGBA out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	out.a = colour1.a - colour2.a;
	return out;
}
ForceInline tIU8RGBA tIU8RGBA_Mul(tIU8RGBA colour1, tIU8RGBA colour2)
{
	tIU8RGBA out;
	out.r = (tIU8)(((tIU16)colour1.r * (tIU16)colour2.r) / 255U);
	out.g = (tIU8)(((tIU16)colour1.g * (tIU16)colour2.g) / 255U);
	out.b = (tIU8)(((tIU16)colour1.b * (tIU16)colour2.b) / 255U);
	out.a = (tIU8)(((tIU16)colour1.a * (tIU16)colour2.a) / 255U);
	return out;
}
ForceInline tIU8RGBA tIU8RGBA_Div(tIU8RGBA colour1, tIU8RGBA colour2)
{
	tIU8RGBA out;
	out.r = colour2.r == 0U ? 0U : (tIU8)(((tIU16)colour1.r * 255U) / colour2.r);
	out.g = colour2.g == 0U ? 0U : (tIU8)(((tIU16)colour1.g * 255U) / colour2.g);
	out.b = colour2.b == 0U ? 0U : (tIU8)(((tIU16)colour1.b * 255U) / colour2.b);
	out.a = colour2.a == 0U ? 0U : (tIU8)(((tIU16)colour1.a * 255U) / colour2.a);
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Add(tFP64RGBA colour1, tFP64RGBA colour2)
{
	tFP64RGBA out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	out.a = colour1.a + colour2.a;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Sub(tFP64RGBA colour1, tFP64RGBA colour2)
{
	tFP64RGBA out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	out.a = colour1.a - colour2.a;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Mul(tFP64RGBA colour1, tFP64RGBA colour2)
{
	tFP64RGBA out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	out.a = colour1.a * colour2.a;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Div(tFP64RGBA colour1, tFP64RGBA colour2)
{
	tFP64RGBA out;
	out.r = colour2.r == 0.0 ? 0.0 : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0 ? 0.0 : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0 ? 0.0 : (colour1.b / colour2.b);
	out.a = colour2.a == 0.0 ? 0.0 : (colour1.a / colour2.a);
	return out;
}
ForceInline tIU32ARGB tIU32ARGB_Add(tIU32ARGB colour1, tIU32ARGB colour2)
{
	tIU32ARGB out;
	out = colour1 | colour2;
	return out;
}
ForceInline tIU32ARGB tIU32ARGB_Sub(tIU32ARGB colour1, tIU32ARGB colour2)
{
	tIU32ARGB out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tIU32ARGB tIU32ARGB_Mul(tIU32ARGB colour1, tIU32ARGB colour2)
{
	tIU32ARGB out;
	out = colour1 & colour2;
	return out;
}
ForceInline tIU32ARGB tIU32ARGB_Div(tIU32ARGB colour1, tIU32ARGB colour2)
{
	tIU32ARGB out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tIU32RGBA tIU32RGBA_Add(tIU32RGBA colour1, tIU32RGBA colour2)
{
	tIU32RGBA out;
	out = colour1 | colour2;
	return out;
}
ForceInline tIU32RGBA tIU32RGBA_Sub(tIU32RGBA colour1, tIU32RGBA colour2)
{
	tIU32RGBA out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tIU32RGBA tIU32RGBA_Mul(tIU32RGBA colour1, tIU32RGBA colour2)
{
	tIU32RGBA out;
	out = colour1 & colour2;
	return out;
}
ForceInline tIU32RGBA tIU32RGBA_Div(tIU32RGBA colour1, tIU32RGBA colour2)
{
	tIU32RGBA out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tIU32BGRA tIU32BGRA_Add(tIU32BGRA colour1, tIU32BGRA colour2)
{
	tIU32BGRA out;
	out = colour1 | colour2;
	return out;
}
ForceInline tIU32BGRA tIU32BGRA_Sub(tIU32BGRA colour1, tIU32BGRA colour2)
{
	tIU32BGRA out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tIU32BGRA tIU32BGRA_Mul(tIU32BGRA colour1, tIU32BGRA colour2)
{
	tIU32BGRA out;
	out = colour1 & colour2;
	return out;
}
ForceInline tIU32BGRA tIU32BGRA_Div(tIU32BGRA colour1, tIU32BGRA colour2)
{
	tIU32BGRA out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tIU32ABGR tIU32ABGR_Add(tIU32ABGR colour1, tIU32ABGR colour2)
{
	tIU32ABGR out;
	out = colour1 | colour2;
	return out;
}
ForceInline tIU32ABGR tIU32ABGR_Sub(tIU32ABGR colour1, tIU32ABGR colour2)
{
	tIU32ABGR out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tIU32ABGR tIU32ABGR_Mul(tIU32ABGR colour1, tIU32ABGR colour2)
{
	tIU32ABGR out;
	out = colour1 & colour2;
	return out;
}
ForceInline tIU32ABGR tIU32ABGR_Div(tIU32ABGR colour1, tIU32ABGR colour2)
{
	tIU32ABGR out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tFP32RGB tFP32RGB_AddFlt(tFP32RGB colour, tFP32 flt)
{
	tFP32RGB out;
	out.r = colour.r + flt;
	out.g = colour.g + flt;
	out.b = colour.b + flt;
	return out;
}
ForceInline tFP32RGB tFP32RGB_SubFlt(tFP32RGB colour, tFP32 flt)
{
	tFP32RGB out;
	out.r = colour.r - flt;
	out.g = colour.g - flt;
	out.b = colour.b - flt;
	return out;
}
ForceInline tFP32RGB tFP32RGB_MulFlt(tFP32RGB colour, tFP32 flt)
{
	tFP32RGB out;
	out.r = colour.r * flt;
	out.g = colour.g * flt;
	out.b = colour.b * flt;
	return out;
}
ForceInline tFP32RGB tFP32RGB_DivFlt(tFP32RGB colour, tFP32 flt)
{
	tFP32RGB out;
	out.r = flt == 0.0F ? 0.0F : (colour.r / flt);
	out.g = flt == 0.0F ? 0.0F : (colour.g / flt);
	out.b = flt == 0.0F ? 0.0F : (colour.b / flt);
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_AddFlt(tFP32RGBA colour, tFP32 flt)
{
	tFP32RGBA out;
	out.r = colour.r + flt;
	out.g = colour.g + flt;
	out.b = colour.b + flt;
	out.a = colour.a + flt;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_SubFlt(tFP32RGBA colour, tFP32 flt)
{
	tFP32RGBA out;
	out.r = colour.r - flt;
	out.g = colour.g - flt;
	out.b = colour.b - flt;
	out.a = colour.a - flt;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_MulFlt(tFP32RGBA colour, tFP32 flt)
{
	tFP32RGBA out;
	out.r = colour.r * flt;
	out.g = colour.g * flt;
	out.b = colour.b * flt;
	out.a = colour.a * flt;
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_DivFlt(tFP32RGBA colour, tFP32 flt)
{
	tFP32RGBA out;
	out.r = flt == 0.0F ? 0.0F : (colour.r / flt);
	out.g = flt == 0.0F ? 0.0F : (colour.g / flt);
	out.b = flt == 0.0F ? 0.0F : (colour.b / flt);
	out.a = flt == 0.0F ? 0.0F : (colour.a / flt);
	return out;
}
ForceInline tFP64RGB tFP64RGB_AddDbl(tFP64RGB colour, tFP64 dbl)
{
	tFP64RGB out;
	out.r = colour.r + dbl;
	out.g = colour.g + dbl;
	out.b = colour.b + dbl;
	return out;
}
ForceInline tFP64RGB tFP64RGB_SubDbl(tFP64RGB colour, tFP64 dbl)
{
	tFP64RGB out;
	out.r = colour.r - dbl;
	out.g = colour.g - dbl;
	out.b = colour.b - dbl;
	return out;
}
ForceInline tFP64RGB tFP64RGB_MulDbl(tFP64RGB colour, tFP64 dbl)
{
	tFP64RGB out;
	out.r = colour.r * dbl;
	out.g = colour.g * dbl;
	out.b = colour.b * dbl;
	return out;
}
ForceInline tFP64RGB tFP64RGB_DivDbl(tFP64RGB colour, tFP64 dbl)
{
	tFP64RGB out;
	out.r = dbl == 0.0 ? 0.0 : (colour.r / dbl);
	out.g = dbl == 0.0 ? 0.0 : (colour.g / dbl);
	out.b = dbl == 0.0 ? 0.0 : (colour.b / dbl);
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_AddDbl(tFP64RGBA colour, tFP64 dbl)
{
	tFP64RGBA out;
	out.r = colour.r + dbl;
	out.g = colour.g + dbl;
	out.b = colour.b + dbl;
	out.a = colour.a + dbl;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_SubDbl(tFP64RGBA colour, tFP64 dbl)
{
	tFP64RGBA out;
	out.r = colour.r - dbl;
	out.g = colour.g - dbl;
	out.b = colour.b - dbl;
	out.a = colour.a - dbl;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_MulDbl(tFP64RGBA colour, tFP64 dbl)
{
	tFP64RGBA out;
	out.r = colour.r * dbl;
	out.g = colour.g * dbl;
	out.b = colour.b * dbl;
	out.a = colour.a * dbl;
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_DivDbl(tFP64RGBA colour, tFP64 dbl)
{
	tFP64RGBA out;
	out.r = dbl == 0.0 ? 0.0 : (colour.r / dbl);
	out.g = dbl == 0.0 ? 0.0 : (colour.g / dbl);
	out.b = dbl == 0.0 ? 0.0 : (colour.b / dbl);
	out.a = dbl == 0.0 ? 0.0 : (colour.a / dbl);
	return out;
}
ForceInline tFP32RGB tFP32RGB_Clamp(tFP32RGB colour)
{
	tFP32RGB out;
	out.r = tFP32_Clamp(0.0F, colour.r, 1.0F);
	out.g = tFP32_Clamp(0.0F, colour.g, 1.0F);
	out.b = tFP32_Clamp(0.0F, colour.b, 1.0F);
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Clamp(tFP32RGBA colour)
{
	tFP32RGBA out;
	out.r = tFP32_Clamp(0.0F, colour.r, 1.0F);
	out.g = tFP32_Clamp(0.0F, colour.g, 1.0F);
	out.b = tFP32_Clamp(0.0F, colour.b, 1.0F);
	out.a = tFP32_Clamp(0.0F, colour.a, 1.0F);
	return out;
}
ForceInline tFP32RGB tFP32RGB_Saturate(tFP32RGB colour)
{
	return tFP32RGB_Clamp(colour);
}
ForceInline tFP32RGBA tFP32RGBA_Saturate(tFP32RGBA colour)
{
	return tFP32RGBA_Clamp(colour);
}
ForceInline tFP32RGB tFP32RGB_Blend(tFP32RGB colour1, tFP32RGB colour2, tFP32 stp)
{
	tFP32RGB out;
	out.r = tFP32_Lerp(colour1.r, colour2.r, stp);
	out.g = tFP32_Lerp(colour1.g, colour2.g, stp);
	out.b = tFP32_Lerp(colour1.b, colour2.b, stp);
	return out;
}
ForceInline tFP32RGBA tFP32RGBA_Blend(tFP32RGBA colour1, tFP32RGBA colour2, tFP32 stp)
{
	tFP32RGBA out;
	out.r = tFP32_Lerp(colour1.r, colour2.r, stp);
	out.g = tFP32_Lerp(colour1.g, colour2.g, stp);
	out.b = tFP32_Lerp(colour1.b, colour2.b, stp);
	out.a = tFP32_Lerp(colour1.a, colour2.a, stp);
	return out;
}
ForceInline tFP64RGB tFP64RGB_Clamp(tFP64RGB colour)
{
	tFP64RGB out;
	out.r = tFP64_Clamp(0.0, colour.r, 1.0);
	out.g = tFP64_Clamp(0.0, colour.g, 1.0);
	out.b = tFP64_Clamp(0.0, colour.b, 1.0);
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Clamp(tFP64RGBA colour)
{
	tFP64RGBA out;
	out.r = tFP64_Clamp(0.0, colour.r, 1.0);
	out.g = tFP64_Clamp(0.0, colour.g, 1.0);
	out.b = tFP64_Clamp(0.0, colour.b, 1.0);
	out.a = tFP64_Clamp(0.0, colour.a, 1.0);
	return out;
}
ForceInline tFP64RGB tFP64RGB_Saturate(tFP64RGB colour)
{
	return tFP64RGB_Clamp(colour);
}
ForceInline tFP64RGBA tFP64RGBA_Saturate(tFP64RGBA colour)
{
	return tFP64RGBA_Clamp(colour);
}
ForceInline tFP64RGB tFP64RGB_Blend(tFP64RGB colour1, tFP64RGB colour2, tFP64 stp)
{
	tFP64RGB out;
	out.r = tFP64_Lerp(colour1.r, colour2.r, stp);
	out.g = tFP64_Lerp(colour1.g, colour2.g, stp);
	out.b = tFP64_Lerp(colour1.b, colour2.b, stp);
	return out;
}
ForceInline tFP64RGBA tFP64RGBA_Blend(tFP64RGBA colour1, tFP64RGBA colour2, tFP64 stp)
{
	tFP64RGBA out;
	out.r = tFP64_Lerp(colour1.r, colour2.r, stp);
	out.g = tFP64_Lerp(colour1.g, colour2.g, stp);
	out.b = tFP64_Lerp(colour1.b, colour2.b, stp);
	out.a = tFP64_Lerp(colour1.a, colour2.a, stp);
	return out;
}
#endif/*BQSELAYER_COLOUR_IMPL*/
#endif/*BQSELAYER_COLOUR_H*/