#ifndef BQSELAYER_COLOUR_H
#define BQSELAYER_COLOUR_H
#include "PrimTypes.h"
typedef struct { tU8 r; tU8 g; tU8 b; } tU8RGB;
typedef struct { tU8 r; tU8 g; tU8 b; tU8 a; } tU8RGBA;
typedef struct { tF32 r; tF32 g; tF32 b; } tF32RGB;
typedef struct { tF32 r; tF32 g; tF32 b; tF32 a; } tF32RGBA;
typedef struct { tF64 r; tF64 g; tF64 b; } tF64RGB;
typedef struct { tF64 r; tF64 g; tF64 b; tF64 a; } tF64RGBA;
typedef tU32 tU32ARGB;
typedef tU32 tU32RGBA;
typedef tU32 tU32BGRA;
typedef tU32 tU32ABGR;
typedef struct { tF32 h; tF32 s; tF32 v; } tF32HSV;
typedef struct { tF64 h; tF64 s; tF64 v; } tF64HSV;
typedef struct { tF32 h; tF32 s; tF32 l; } tF32HSL;
typedef struct { tF64 h; tF64 s; tF64 l; } tF64HSL;
LINK_C_Begin
ForceInline tU8RGB tU8RGB_Make(tU8 r, tU8 g, tU8 b);
ForceInline tU8RGBA tU8RGBA_Make(tU8 r, tU8 g, tU8 b, tU8 a);
ForceInline tF32RGB tF32RGB_Make(tF32 r, tF32 g, tF32 b);
ForceInline tF32RGBA tF32RGBA_Make(tF32 r, tF32 g, tF32 b, tF32 a);
ForceInline tF64RGB tF64RGB_Make(tF64 r, tF64 g, tF64 b);
ForceInline tF64RGBA tF64RGBA_Make(tF64 r, tF64 g, tF64 b, tF64 a);
ForceInline tU32ARGB tU32ARGB_Make(tU8 a, tU8 r, tU8 g, tU8 b);
ForceInline tU32RGBA tU32RGBA_Make(tU8 r, tU8 g, tU8 b, tU8 a);
ForceInline tU32BGRA tU32BGRA_Make(tU8 b, tU8 g, tU8 r, tU8 a);
ForceInline tU32ABGR tU32ABGR_Make(tU8 a, tU8 b, tU8 g, tU8 r);
ForceInline tF32HSV tF32HSV_Make(tF32 h, tF32 s, tF32 v);
ForceInline tF64HSV tF64HSV_Make(tF64 h, tF64 s, tF64 v);
ForceInline tF32HSL tF32HSL_Make(tF32 h, tF32 s, tF32 l);
ForceInline tF64HSL tF64HSL_Make(tF64 h, tF64 s, tF64 l);
ForceInline tBln tU8RGB_Eq(tU8RGB colour1, tU8RGB colour2);
ForceInline tBln tU8RGBA_Eq(tU8RGBA colour1, tU8RGBA colour2);
ForceInline tBln tF32RGB_Eq(tF32RGB colour1, tF32RGB colour2);
ForceInline tBln tF32RGBA_Eq(tF32RGBA colour1, tF32RGBA colour2);
ForceInline tBln tF64RGB_Eq(tF64RGB colour1, tF64RGB colour2);
ForceInline tBln tF64RGBA_Eq(tF64RGBA colour1, tF64RGBA colour2);
ForceInline tBln tU32ARGB_Eq(tU32ARGB colour1, tU32ARGB colour2);
ForceInline tBln tU32RGBA_Eq(tU32RGBA colour1, tU32RGBA colour2);
ForceInline tBln tU32BGRA_Eq(tU32BGRA colour1, tU32BGRA colour2);
ForceInline tBln tU32ABGR_Eq(tU32ABGR colour1, tU32ABGR colour2);
ForceInline tBln tF32HSV_Eq(tF32HSV colour1, tF32HSV colour2);
ForceInline tBln tF64HSV_Eq(tF64HSV colour1, tF64HSV colour2);
ForceInline tBln tF32HSL_Eq(tF32HSL colour1, tF32HSL colour2);
ForceInline tBln tF64HSL_Eq(tF64HSL colour1, tF64HSL colour2);
ForceInline tBln tF32RGB_Nearby(tF32RGB colour1, tF32RGB colour2);
ForceInline tBln tF32RGBA_Nearby(tF32RGBA colour1, tF32RGBA colour2);
ForceInline tBln tF64RGB_Nearby(tF64RGB colour1, tF64RGB colour2);
ForceInline tBln tF64RGBA_Nearby(tF64RGBA colour1, tF64RGBA colour2);
ForceInline tBln tF32HSV_Nearby(tF32HSV colour1, tF32HSV colour2);
ForceInline tBln tF64HSV_Nearby(tF64HSV colour1, tF64HSV colour2);
ForceInline tBln tF32HSL_Nearby(tF32HSL colour1, tF32HSL colour2);
ForceInline tBln tF64HSL_Nearby(tF64HSL colour1, tF64HSL colour2);
ForceInline tU32ARGB tU32ARGB_From_tRGBA(tU8RGBA colour);
ForceInline tU32RGBA tU32RGBA_From_tRGBA(tU8RGBA colour);
ForceInline tU32BGRA tU32BGRA_From_tRGBA(tU8RGBA colour);
ForceInline tU32ABGR tU32ABGR_From_tRGBA(tU8RGBA colour);
ForceInline tU8RGBA tU8RGBA_From_tU32ARGB(tU32ARGB colour);
ForceInline tU8RGBA tU8RGBA_From_tU32RGBA(tU32RGBA colour);
ForceInline tU8RGBA tU8RGBA_From_tU32BGRA(tU32BGRA colour);
ForceInline tU8RGBA tU8RGBA_From_tU32ABGR(tU32ABGR colour);
ForceInline tF32HSV tF32RGB_ToHSV(tF32RGB colour);
ForceInline tF32RGB tF32HSV_ToRGB(tF32HSV colour);
ForceInline tF32HSL tF32RGB_ToHSL(tF32RGB colour);
ForceInline tF32RGB tF32HSL_ToRGB(tF32HSL colour);
ForceInline tF64HSV tF64RGB_ToHSV(tF64RGB colour);
ForceInline tF64RGB tF64HSV_ToRGB(tF64HSV colour);
ForceInline tF64HSL tF64RGB_ToHSL(tF64RGB colour);
ForceInline tF64RGB tF64HSL_ToRGB(tF64HSL colour);
ForceInline tF32RGB tF32RGB_From_tU8RGB(tU8RGB colour);
ForceInline tF32RGBA tF32RGBA_From_tU8RGBA(tU8RGBA colour);
ForceInline tU8RGB tU8RGB_From_tF32RGB(tF32RGB colour);
ForceInline tU8RGBA tU8RGBA_From_tF32RGBA(tF32RGBA colour);
ForceInline tF64RGB tF64RGB_From_tU8RGB(tU8RGB colour);
ForceInline tF64RGBA tF64RGBA_From_tU8RGBA(tU8RGBA colour);
ForceInline tU8RGB tU8RGB_From_tF64RGB(tF64RGB colour);
ForceInline tU8RGBA tU8RGBA_From_tF64RGBA(tF64RGBA colour);
ForceInline tF64RGB tF64RGB_From_tF32RGB(tF32RGB colour);
ForceInline tF64RGBA tF64RGBA_From_tF32RGBA(tF32RGBA colour);
ForceInline tF32RGB tF32RGB_From_tF64RGB(tF64RGB colour);
ForceInline tF32RGBA tF32RGBA_From_tF64RGBA(tF64RGBA colour);
ForceInline tF32RGB tF32RGB_Lerp(tF32RGB strt, tF32RGB stp, tF32 fnsh);
ForceInline tF32RGBA tF32RGBA_Lerp(tF32RGBA strt, tF32RGBA stp, tF32 fnsh);
ForceInline tF64RGB tF64RGB_Lerp(tF64RGB strt, tF64RGB stp, tF64 fnsh);
ForceInline tF64RGBA tF64RGBA_Lerp(tF64RGBA strt, tF64RGBA stp, tF64 fnsh);
ForceInline tU8RGB tU8RGB_Add(tU8RGB colour1, tU8RGB colour2);
ForceInline tU8RGB tU8RGB_Sub(tU8RGB colour1, tU8RGB colour2);
ForceInline tU8RGB tU8RGB_Mul(tU8RGB colour1, tU8RGB colour2);
ForceInline tU8RGB tU8RGB_Div(tU8RGB colour1, tU8RGB colour2);
ForceInline tF32RGB tF32RGB_Add(tF32RGB colour1, tF32RGB colour2);
ForceInline tF32RGB tF32RGB_Sub(tF32RGB colour1, tF32RGB colour2);
ForceInline tF32RGB tF32RGB_Mul(tF32RGB colour1, tF32RGB colour2);
ForceInline tF32RGB tF32RGB_Div(tF32RGB colour1, tF32RGB colour2);
ForceInline tF64RGB tF64RGB_Add(tF64RGB colour1, tF64RGB colour2);
ForceInline tF64RGB tF64RGB_Sub(tF64RGB colour1, tF64RGB colour2);
ForceInline tF64RGB tF64RGB_Mul(tF64RGB colour1, tF64RGB colour2);
ForceInline tF64RGB tF64RGB_Div(tF64RGB colour1, tF64RGB colour2);
ForceInline tF32RGBA tF32RGBA_Add(tF32RGBA colour1, tF32RGBA colour2);
ForceInline tF32RGBA tF32RGBA_Sub(tF32RGBA colour1, tF32RGBA colour2);
ForceInline tF32RGBA tF32RGBA_Mul(tF32RGBA colour1, tF32RGBA colour2);
ForceInline tF32RGBA tF32RGBA_Div(tF32RGBA colour1, tF32RGBA colour2);
ForceInline tU8RGBA tU8RGBA_Add(tU8RGBA colour1, tU8RGBA colour2);
ForceInline tU8RGBA tU8RGBA_Sub(tU8RGBA colour1, tU8RGBA colour2);
ForceInline tU8RGBA tU8RGBA_Mul(tU8RGBA colour1, tU8RGBA colour2);
ForceInline tU8RGBA tU8RGBA_Div(tU8RGBA colour1, tU8RGBA colour2);
ForceInline tF64RGBA tF64RGBA_Add(tF64RGBA colour1, tF64RGBA colour2);
ForceInline tF64RGBA tF64RGBA_Sub(tF64RGBA colour1, tF64RGBA colour2);
ForceInline tF64RGBA tF64RGBA_Mul(tF64RGBA colour1, tF64RGBA colour2);
ForceInline tF64RGBA tF64RGBA_Div(tF64RGBA colour1, tF64RGBA colour2);
ForceInline tU32ARGB tU32ARGB_Add(tU32ARGB colour1, tU32ARGB colour2);
ForceInline tU32ARGB tU32ARGB_Sub(tU32ARGB colour1, tU32ARGB colour2);
ForceInline tU32ARGB tU32ARGB_Mul(tU32ARGB colour1, tU32ARGB colour2);
ForceInline tU32ARGB tU32ARGB_Div(tU32ARGB colour1, tU32ARGB colour2);
ForceInline tU32RGBA tU32RGBA_Add(tU32RGBA colour1, tU32RGBA colour2);
ForceInline tU32RGBA tU32RGBA_Sub(tU32RGBA colour1, tU32RGBA colour2);
ForceInline tU32RGBA tU32RGBA_Mul(tU32RGBA colour1, tU32RGBA colour2);
ForceInline tU32RGBA tU32RGBA_Div(tU32RGBA colour1, tU32RGBA colour2);
ForceInline tU32BGRA tU32BGRA_Add(tU32BGRA colour1, tU32BGRA colour2);
ForceInline tU32BGRA tU32BGRA_Sub(tU32BGRA colour1, tU32BGRA colour2);
ForceInline tU32BGRA tU32BGRA_Mul(tU32BGRA colour1, tU32BGRA colour2);
ForceInline tU32BGRA tU32BGRA_Div(tU32BGRA colour1, tU32BGRA colour2);
ForceInline tU32ABGR tU32ABGR_Add(tU32ABGR colour1, tU32ABGR colour2);
ForceInline tU32ABGR tU32ABGR_Sub(tU32ABGR colour1, tU32ABGR colour2);
ForceInline tU32ABGR tU32ABGR_Mul(tU32ABGR colour1, tU32ABGR colour2);
ForceInline tU32ABGR tU32ABGR_Div(tU32ABGR colour1, tU32ABGR colour2);
ForceInline tF32RGB tF32RGB_AddFlt(tF32RGB colour, tF32 flt);
ForceInline tF32RGB tF32RGB_SubFlt(tF32RGB colour, tF32 flt);
ForceInline tF32RGB tF32RGB_MulFlt(tF32RGB colour, tF32 flt);
ForceInline tF32RGB tF32RGB_DivFlt(tF32RGB colour, tF32 flt);
ForceInline tF32RGBA tF32RGBA_AddFlt(tF32RGBA colour, tF32 flt);
ForceInline tF32RGBA tF32RGBA_SubFlt(tF32RGBA colour, tF32 flt);
ForceInline tF32RGBA tF32RGBA_MulFlt(tF32RGBA colour, tF32 flt);
ForceInline tF32RGBA tF32RGBA_DivFlt(tF32RGBA colour, tF32 flt);
ForceInline tF64RGB tF64RGB_AddDbl(tF64RGB colour, tF64 dbl);
ForceInline tF64RGB tF64RGB_SubDbl(tF64RGB colour, tF64 dbl);
ForceInline tF64RGB tF64RGB_MulDbl(tF64RGB colour, tF64 dbl);
ForceInline tF64RGB tF64RGB_DivDbl(tF64RGB colour, tF64 dbl);
ForceInline tF64RGBA tF64RGBA_AddDbl(tF64RGBA colour, tF64 dbl);
ForceInline tF64RGBA tF64RGBA_SubDbl(tF64RGBA colour, tF64 dbl);
ForceInline tF64RGBA tF64RGBA_MulDbl(tF64RGBA colour, tF64 dbl);
ForceInline tF64RGBA tF64RGBA_DivDbl(tF64RGBA colour, tF64 dbl);
ForceInline tF32RGB tF32RGB_Clamp(tF32RGB colour);
ForceInline tF32RGBA tF32RGBA_Clamp(tF32RGBA colour);
ForceInline tF32RGB tF32RGB_Saturate(tF32RGB colour);
ForceInline tF32RGBA tF32RGBA_Saturate(tF32RGBA colour);
ForceInline tF32RGB tF32RGB_Blend(tF32RGB colour1, tF32RGB colour2, tF32 stp);
ForceInline tF32RGBA tF32RGBA_Blend(tF32RGBA colour1, tF32RGBA colour2, tF32 stp);
ForceInline tF64RGB tF64RGB_Clamp(tF64RGB colour);
ForceInline tF64RGBA tF64RGBA_Clamp(tF64RGBA colour);
ForceInline tF64RGB tF64RGB_Saturate(tF64RGB colour);
ForceInline tF64RGBA tF64RGBA_Saturate(tF64RGBA colour);
ForceInline tF64RGB tF64RGB_Blend(tF64RGB colour1, tF64RGB colour2, tF64 stp);
ForceInline tF64RGBA tF64RGBA_Blend(tF64RGBA colour1, tF64RGBA colour2, tF64 stp);
LINK_C_End
#ifdef BQSELAYER_COLOUR_IMPL
ForceInline tU8RGB tU8RGB_Make(tU8 r, tU8 g, tU8 b)
{
	tU8RGB colour;
	colour.r = r;
	colour.g = g;
	colour.b = b;
	return colour;
}
ForceInline tU8RGBA tU8RGBA_Make(tU8 r, tU8 g, tU8 b, tU8 a)
{
	tU8RGBA colour;
	colour.r = r;
	colour.g = g;
	colour.b = b;
	colour.a = a;
	return colour;
}
ForceInline tF32RGB tF32RGB_Make(tF32 r, tF32 g, tF32 b)
{
	tF32RGB colour;
	colour.r = tF32_Clamp(0.0F, r, 1.0F);
	colour.g = tF32_Clamp(0.0F, g, 1.0F);
	colour.b = tF32_Clamp(0.0F, b, 1.0F);
	return colour;
}
ForceInline tF32RGBA tF32RGBA_Make(tF32 r, tF32 g, tF32 b, tF32 a)
{
	tF32RGBA colour;
	colour.r = tF32_Clamp(0.0F, r, 1.0F);
	colour.g = tF32_Clamp(0.0F, g, 1.0F);
	colour.b = tF32_Clamp(0.0F, b, 1.0F);
	colour.a = tF32_Clamp(0.0F, a, 1.0F);
	return colour;
}
ForceInline tF64RGB tF64RGB_Make(tF64 r, tF64 g, tF64 b)
{
	tF64RGB colour;
	colour.r = tF64_Clamp(0.0, r, 1.0);
	colour.g = tF64_Clamp(0.0, g, 1.0);
	colour.b = tF64_Clamp(0.0, b, 1.0);
	return colour;
}
ForceInline tF64RGBA tF64RGBA_Make(tF64 r, tF64 g, tF64 b, tF64 a)
{
	tF64RGBA colour;
	colour.r = tF64_Clamp(0.0, r, 1.0);
	colour.g = tF64_Clamp(0.0, g, 1.0);
	colour.b = tF64_Clamp(0.0, b, 1.0);
	colour.a = tF64_Clamp(0.0, a, 1.0);
	return colour;
}
ForceInline tU32ARGB tU32ARGB_Make(tU8 a, tU8 r, tU8 g, tU8 b)
{
	tU32ARGB colour;
	colour = ((tU32)a << 24U) | ((tU32)r << 16U) | ((tU32)g << 8U) | (tU32)b;
	return colour;
}
ForceInline tU32RGBA tU32RGBA_Make(tU8 r, tU8 g, tU8 b, tU8 a)
{
	tU32RGBA colour;
	colour = ((tU32)r << 24U) | ((tU32)g << 16U) | ((tU32)b << 8U) | (tU32)a;
	return colour;
}
ForceInline tU32BGRA tU32BGRA_Make(tU8 b, tU8 g, tU8 r, tU8 a)
{
	tU32BGRA colour;
	colour = ((tU32)b << 24U) | ((tU32)g << 16U) | ((tU32)r << 8U) | (tU32)a;
	return colour;
}
ForceInline tU32ABGR tU32ABGR_Make(tU8 a, tU8 b, tU8 g, tU8 r)
{
	tU32ABGR colour;
	colour = ((tU32)a << 24U) | ((tU32)b << 16U) | ((tU32)g << 8U) | (tU32)r;
	return colour;
}
ForceInline tF32HSV tF32HSV_Make(tF32 h, tF32 s, tF32 v)
{
	tF32HSV colour;
	colour.h = tF32_Clamp(0.0F, h, 360.0F);
	if (colour.h == 360.0F) colour.h = 0.0F;
	colour.s = tF32_Clamp(0.0F, s, 1.0F);
	colour.v = tF32_Clamp(0.0F, v, 1.0F);
	return colour;
}
ForceInline tF64HSV tF64HSV_Make(tF64 h, tF64 s, tF64 v)
{
	tF64HSV colour;
	colour.h = tF64_Clamp(0.0, h, 360.0);
	if (colour.h == 360.0) colour.h = 0.0;
	colour.s = tF64_Clamp(0.0, s, 1.0);
	colour.v = tF64_Clamp(0.0, v, 1.0);
	return colour;
}
ForceInline tF32HSL tF32HSL_Make(tF32 h, tF32 s, tF32 l)
{
	tF32HSL colour;
	colour.h = tF32_Clamp(0.0F, h, 360.0F);
	if (colour.h == 360.0F) colour.h = 0.0F;
	colour.s = tF32_Clamp(0.0F, s, 1.0F);
	colour.l = tF32_Clamp(0.0F, l, 1.0F);
	return colour;
}
ForceInline tF64HSL tF64HSL_Make(tF64 h, tF64 s, tF64 l)
{
	tF64HSL colour;
	colour.h = tF64_Clamp(0.0, h, 360.0);
	if (colour.h == 360.0) colour.h = 0.0;
	colour.s = tF64_Clamp(0.0, s, 1.0);
	colour.l = tF64_Clamp(0.0, l, 1.0);
	return colour;
}
ForceInline tBln tU8RGB_Eq(tU8RGB colour1, tU8RGB colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b;
}
ForceInline tBln tU8RGBA_Eq(tU8RGBA colour1, tU8RGBA colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b && colour1.a == colour2.a;
}
ForceInline tBln tF32RGB_Eq(tF32RGB colour1, tF32RGB colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b;
}
ForceInline tBln tF32RGBA_Eq(tF32RGBA colour1, tF32RGBA colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b && colour1.a == colour2.a;
}
ForceInline tBln tF64RGB_Eq(tF64RGB colour1, tF64RGB colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b;
}
ForceInline tBln tF64RGBA_Eq(tF64RGBA colour1, tF64RGBA colour2)
{
	return colour1.r == colour2.r && colour1.g == colour2.g && colour1.b == colour2.b && colour1.a == colour2.a;
}
ForceInline tBln tU32ARGB_Eq(tU32ARGB colour1, tU32ARGB colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tU32RGBA_Eq(tU32RGBA colour1, tU32RGBA colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tU32BGRA_Eq(tU32BGRA colour1, tU32BGRA colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tU32ABGR_Eq(tU32ABGR colour1, tU32ABGR colour2)
{
	return colour1 == colour2;
}
ForceInline tBln tF32HSV_Eq(tF32HSV colour1, tF32HSV colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.v == colour2.v;
}
ForceInline tBln tF64HSV_Eq(tF64HSV colour1, tF64HSV colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.v == colour2.v;
}
ForceInline tBln tF32HSL_Eq(tF32HSL colour1, tF32HSL colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.l == colour2.l;
}
ForceInline tBln tF64HSL_Eq(tF64HSL colour1, tF64HSL colour2)
{
	return colour1.h == colour2.h && colour1.s == colour2.s && colour1.l == colour2.l;
}
ForceInline tBln tF32RGB_Nearby(tF32RGB colour1, tF32RGB colour2)
{
	return tF32_Nearby(colour1.r, colour2.r) && tF32_Nearby(colour1.g, colour2.g) && tF32_Nearby(colour1.b, colour2.b);
}
ForceInline tBln tF32RGBA_Nearby(tF32RGBA colour1, tF32RGBA colour2)
{
	return tF32_Nearby(colour1.r, colour2.r) && tF32_Nearby(colour1.g, colour2.g) && tF32_Nearby(colour1.b, colour2.b) && tF32_Nearby(colour1.a, colour2.a);
}
ForceInline tBln tF64RGB_Nearby(tF64RGB colour1, tF64RGB colour2)
{
	return tF64_Nearby(colour1.r, colour2.r) && tF64_Nearby(colour1.g, colour2.g) && tF64_Nearby(colour1.b, colour2.b);
}
ForceInline tBln tF64RGBA_Nearby(tF64RGBA colour1, tF64RGBA colour2)
{
	return tF64_Nearby(colour1.r, colour2.r) && tF64_Nearby(colour1.g, colour2.g) && tF64_Nearby(colour1.b, colour2.b) && tF64_Nearby(colour1.a, colour2.a);
}
ForceInline tBln tF32HSV_Nearby(tF32HSV colour1, tF32HSV colour2)
{
	return tF32_Nearby(colour1.h, colour2.h) && tF32_Nearby(colour1.s, colour2.s) && tF32_Nearby(colour1.v, colour2.v);
}
ForceInline tBln tF64HSV_Nearby(tF64HSV colour1, tF64HSV colour2)
{
	return tF64_Nearby(colour1.h, colour2.h) && tF64_Nearby(colour1.s, colour2.s) && tF64_Nearby(colour1.v, colour2.v);
}
ForceInline tBln tF32HSL_Nearby(tF32HSL colour1, tF32HSL colour2)
{
	return tF32_Nearby(colour1.h, colour2.h) && tF32_Nearby(colour1.s, colour2.s) && tF32_Nearby(colour1.l, colour2.l);
}
ForceInline tBln tF64HSL_Nearby(tF64HSL colour1, tF64HSL colour2)
{
	return tF64_Nearby(colour1.h, colour2.h) && tF64_Nearby(colour1.s, colour2.s) && tF64_Nearby(colour1.l, colour2.l);
}
ForceInline tU32ARGB tU32ARGB_From_tRGBA(tU8RGBA colour)
{
	return ((tU32)colour.a << 24U) | ((tU32)colour.r << 16U) | ((tU32)colour.g << 8U) | (tU32)colour.b;
}
ForceInline tU32RGBA tU32RGBA_From_tRGBA(tU8RGBA colour)
{
	return ((tU32)colour.r << 24U) | ((tU32)colour.g << 16U) | ((tU32)colour.b << 8U) | (tU32)colour.a;
}
ForceInline tU32BGRA tU32BGRA_From_tRGBA(tU8RGBA colour)
{
	return ((tU32)colour.b << 24U) | ((tU32)colour.g << 16U) | ((tU32)colour.r << 8U) | (tU32)colour.a;
}
ForceInline tU32ABGR tU32ABGR_From_tRGBA(tU8RGBA colour)
{
	return ((tU32)colour.a << 24U) | ((tU32)colour.b << 16U) | ((tU32)colour.g << 8U) | (tU32)colour.r;
}
ForceInline tU8RGBA tU8RGBA_From_tU32ARGB(tU32ARGB colour)
{
	tU8RGBA ret;
	ret.a = (tU8)(colour >> 24U);
	ret.r = (tU8)(colour >> 16U);
	ret.g = (tU8)(colour >> 8U);
	ret.b = (tU8)colour;
	return ret;
}
ForceInline tU8RGBA tU8RGBA_From_tU32RGBA(tU32RGBA colour)
{
	tU8RGBA ret;
	ret.r = (tU8)(colour >> 24U);
	ret.g = (tU8)(colour >> 16U);
	ret.b = (tU8)(colour >> 8U);
	ret.a = (tU8)colour;
	return ret;
}
ForceInline tU8RGBA tU8RGBA_From_tU32BGRA(tU32BGRA colour)
{
	tU8RGBA ret;
	ret.b = (tU8)(colour >> 24U);
	ret.g = (tU8)(colour >> 16U);
	ret.r = (tU8)(colour >> 8U);
	ret.a = (tU8)colour;
	return ret;
}
ForceInline tU8RGBA tU8RGBA_From_tU32ABGR(tU32ABGR colour)
{
	tU8RGBA ret;
	ret.a = (tU8)(colour >> 24U);
	ret.b = (tU8)(colour >> 16U);
	ret.g = (tU8)(colour >> 8U);
	ret.r = (tU8)colour;
	return ret;
}
ForceInline tF32HSV tF32RGB_ToHSV(tF32RGB colour)
{
	tF32 r = colour.r;
	tF32 g = colour.g;
	tF32 b = colour.b;
	tF32 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tF32 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tF32 delta = max - min;
	tF32HSV hsv;
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
ForceInline tF32RGB tF32HSV_ToRGB(tF32HSV colour)
{
	tF32 h = colour.h;
	tF32 s = colour.s;
	tF32 v = colour.v;
	tF32 cval = v * s;
	tF32 x = cval * (1.0F - tF32_Abs(tF32_Mod(h / 60.0F, 2.0F) - 1.0F));
	tF32 m = v - cval;
	tF32 r, g, b;
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
	tF32RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tF32HSL tF32RGB_ToHSL(tF32RGB colour)
{
	tF32 r = colour.r;
	tF32 g = colour.g;
	tF32 b = colour.b;
	tF32 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tF32 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tF32 delta = max - min;
	tF32HSL hsl;
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
ForceInline tF32RGB tF32HSL_ToRGB(tF32HSL colour)
{
	tF32 h = colour.h;
	tF32 s = colour.s;
	tF32 l = colour.l;
	tF32 cval = (1.0F - tF32_Abs(2.0F * l - 1.0F)) * s;
	tF32 x = cval * (1.0F - tF32_Abs(tF32_Mod(h / 60.0F, 2.0F) - 1.0F));
	tF32 m = l - cval * 0.5F;
	tF32 r, g, b;
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
	tF32RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tF64HSV tF64RGB_ToHSV(tF64RGB colour)
{
	tF64 r = colour.r;
	tF64 g = colour.g;
	tF64 b = colour.b;
	tF64 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tF64 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tF64 delta = max - min;
	tF64HSV hsv;
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
ForceInline tF64RGB tF64HSV_ToRGB(tF64HSV colour)
{
	tF64 h = colour.h;
	tF64 s = colour.s;
	tF64 v = colour.v;
	tF64 cval = v * s;
	tF64 x = cval * (1.0 - tF64_Abs(tF64_Mod(h / 60.0, 2.0) - 1.0));
	tF64 m = v - cval;
	tF64 r, g, b;
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
	tF64RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tF64HSL tF64RGB_ToHSL(tF64RGB colour)
{
	tF64 r = colour.r;
	tF64 g = colour.g;
	tF64 b = colour.b;
	tF64 max = r;
	if (g > max) max = g;
	if (b > max) max = b;
	tF64 min = r;
	if (g < min) min = g;
	if (b < min) min = b;
	tF64 delta = max - min;
	tF64HSL hsl;
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
ForceInline tF64RGB tF64HSL_ToRGB(tF64HSL colour)
{
	tF64 h = colour.h;
	tF64 s = colour.s;
	tF64 l = colour.l;
	tF64 cval = (1.0 - tF64_Abs(2.0 * l - 1.0)) * s;
	tF64 x = cval * (1.0 - tF64_Abs(tF64_Mod(h / 60.0, 2.0) - 1.0));
	tF64 m = l - cval * 0.5;
	tF64 r, g, b;
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
	tF64RGB out;
	out.r = r + m;
	out.g = g + m;
	out.b = b + m;
	return out;
}
ForceInline tF32RGB tF32RGB_From_tU8RGB(tU8RGB colour)
{
	tF32RGB out;
	out.r = (tF32)colour.r / 255.0F;
	out.g = (tF32)colour.g / 255.0F;
	out.b = (tF32)colour.b / 255.0F;
	return out;
}
ForceInline tF32RGBA tF32RGBA_From_tU8RGBA(tU8RGBA colour)
{
	tF32RGBA out;
	out.r = (tF32)colour.r / 255.0F;
	out.g = (tF32)colour.g / 255.0F;
	out.b = (tF32)colour.b / 255.0F;
	out.a = (tF32)colour.a / 255.0F;
	return out;
}
ForceInline tU8RGB tU8RGB_From_tF32RGB(tF32RGB colour)
{
	tU8RGB out;
	out.r = (tU8)tF32_Clamp(0.0F, colour.r, 1.0F) * 255U;
	out.g = (tU8)tF32_Clamp(0.0F, colour.g, 1.0F) * 255U;
	out.b = (tU8)tF32_Clamp(0.0F, colour.b, 1.0F) * 255U;
	return out;
}
ForceInline tU8RGBA tU8RGBA_From_tF32RGBA(tF32RGBA colour)
{
	tU8RGBA out;
	out.r = (tU8)tF32_Clamp(0.0F, colour.r, 1.0F) * 255U;
	out.g = (tU8)tF32_Clamp(0.0F, colour.g, 1.0F) * 255U;
	out.b = (tU8)tF32_Clamp(0.0F, colour.b, 1.0F) * 255U;
	out.a = (tU8)tF32_Clamp(0.0F, colour.a, 1.0F) * 255U;
	return out;
}
ForceInline tF64RGB tF64RGB_From_tU8RGB(tU8RGB colour)
{
	tF64RGB out;
	out.r = (tF64)colour.r / 255.0;
	out.g = (tF64)colour.g / 255.0;
	out.b = (tF64)colour.b / 255.0;
	return out;
}
ForceInline tF64RGBA tF64RGBA_From_tU8RGBA(tU8RGBA colour)
{
	tF64RGBA out;
	out.r = (tF64)colour.r / 255.0;
	out.g = (tF64)colour.g / 255.0;
	out.b = (tF64)colour.b / 255.0;
	out.a = (tF64)colour.a / 255.0;
	return out;
}
ForceInline tU8RGB tU8RGB_From_tF64RGB(tF64RGB colour)
{
	tU8RGB out;
	out.r = (tU8)tF64_Clamp(0.0, colour.r, 1.0) * 255U;
	out.g = (tU8)tF64_Clamp(0.0, colour.g, 1.0) * 255U;
	out.b = (tU8)tF64_Clamp(0.0, colour.b, 1.0) * 255U;
	return out;
}
ForceInline tU8RGBA tU8RGBA_From_tF64RGBA(tF64RGBA colour)
{
	tU8RGBA out;
	out.r = (tU8)tF64_Clamp(0.0, colour.r, 1.0) * 255U;
	out.g = (tU8)tF64_Clamp(0.0, colour.g, 1.0) * 255U;
	out.b = (tU8)tF64_Clamp(0.0, colour.b, 1.0) * 255U;
	out.a = (tU8)tF64_Clamp(0.0, colour.a, 1.0) * 255U;
	return out;
}
ForceInline tF64RGB tF64RGB_From_tF32RGB(tF32RGB colour)
{
	tF64RGB out;
	out.r = (tF64)colour.r;
	out.g = (tF64)colour.g;
	out.b = (tF64)colour.b;
	return out;
}
ForceInline tF64RGBA tF64RGBA_From_tF32RGBA(tF32RGBA colour)
{
	tF64RGBA out;
	out.r = (tF64)colour.r;
	out.g = (tF64)colour.g;
	out.b = (tF64)colour.b;
	out.a = (tF64)colour.a;
	return out;
}
ForceInline tF32RGB tF32RGB_From_tF64RGB(tF64RGB colour)
{
	tF32RGB out;
	out.r = (tF32)colour.r;
	out.g = (tF32)colour.g;
	out.b = (tF32)colour.b;
	return out;
}
ForceInline tF32RGBA tF32RGBA_From_tF64RGBA(tF64RGBA colour)
{
	tF32RGBA out;
	out.r = (tF32)colour.r;
	out.g = (tF32)colour.g;
	out.b = (tF32)colour.b;
	out.a = (tF32)colour.a;
	return out;
}
ForceInline tF32RGB tF32RGB_Lerp(tF32RGB strt, tF32RGB stp, tF32 fnsh)
{
	tF32RGB out;
	out.r = tF32_Lerp(strt.r, stp.r, fnsh);
	out.g = tF32_Lerp(strt.g, stp.g, fnsh);
	out.b = tF32_Lerp(strt.b, stp.b, fnsh);
	return out;
}
ForceInline tF32RGBA tF32RGBA_Lerp(tF32RGBA strt, tF32RGBA stp, tF32 fnsh)
{
	tF32RGBA out;
	out.r = tF32_Lerp(strt.r, stp.r, fnsh);
	out.g = tF32_Lerp(strt.g, stp.g, fnsh);
	out.b = tF32_Lerp(strt.b, stp.b, fnsh);
	out.a = tF32_Lerp(strt.a, stp.a, fnsh);
	return out;
}
ForceInline tF64RGB tF64RGB_Lerp(tF64RGB strt, tF64RGB stp, tF64 fnsh)
{
	tF64RGB out;
	out.r = tF64_Lerp(strt.r, stp.r, fnsh);
	out.g = tF64_Lerp(strt.g, stp.g, fnsh);
	out.b = tF64_Lerp(strt.b, stp.b, fnsh);
	return out;
}
ForceInline tF64RGBA tF64RGBA_Lerp(tF64RGBA strt, tF64RGBA stp, tF64 fnsh)
{
	tF64RGBA out;
	out.r = tF64_Lerp(strt.r, stp.r, fnsh);
	out.g = tF64_Lerp(strt.g, stp.g, fnsh);
	out.b = tF64_Lerp(strt.b, stp.b, fnsh);
	out.a = tF64_Lerp(strt.a, stp.a, fnsh);
	return out;
}
ForceInline tU8RGB tU8RGB_Add(tU8RGB colour1, tU8RGB colour2)
{
	tU8RGB out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	return out;
}
ForceInline tU8RGB tU8RGB_Sub(tU8RGB colour1, tU8RGB colour2)
{
	tU8RGB out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	return out;
}
ForceInline tU8RGB tU8RGB_Mul(tU8RGB colour1, tU8RGB colour2)
{
	tU8RGB out;
	out.r = (tU8)(((tU16)colour1.r * (tU16)colour2.r) / 255U);
	out.g = (tU8)(((tU16)colour1.g * (tU16)colour2.g) / 255U);
	out.b = (tU8)(((tU16)colour1.b * (tU16)colour2.b) / 255U);
	return out;
}
ForceInline tU8RGB tU8RGB_Div(tU8RGB colour1, tU8RGB colour2)
{
	tU8RGB out;
	out.r = (colour2.r == 0U) ? 0U : (tU8)(((tU16)colour1.r * 255U) / colour2.r);
	out.g = (colour2.g == 0U) ? 0U : (tU8)(((tU16)colour1.g * 255U) / colour2.g);
	out.b = (colour2.b == 0U) ? 0U : (tU8)(((tU16)colour1.b * 255U) / colour2.b);
	return out;
}
ForceInline tF32RGB tF32RGB_Add(tF32RGB colour1, tF32RGB colour2)
{
	tF32RGB out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	return out;
}
ForceInline tF32RGB tF32RGB_Sub(tF32RGB colour1, tF32RGB colour2)
{
	tF32RGB out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	return out;
}
ForceInline tF32RGB tF32RGB_Mul(tF32RGB colour1, tF32RGB colour2)
{
	tF32RGB out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	return out;
}
ForceInline tF32RGB tF32RGB_Div(tF32RGB colour1, tF32RGB colour2)
{
	tF32RGB out;
	out.r = colour2.r == 0.0F ? 0.0F : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0F ? 0.0F : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0F ? 0.0F : (colour1.b / colour2.b);
	return out;
}
ForceInline tF64RGB tF64RGB_Add(tF64RGB colour1, tF64RGB colour2)
{
	tF64RGB out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	return out;
}
ForceInline tF64RGB tF64RGB_Sub(tF64RGB colour1, tF64RGB colour2)
{
	tF64RGB out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	return out;
}
ForceInline tF64RGB tF64RGB_Mul(tF64RGB colour1, tF64RGB colour2)
{
	tF64RGB out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	return out;
}
ForceInline tF64RGB tF64RGB_Div(tF64RGB colour1, tF64RGB colour2)
{
	tF64RGB out;
	out.r = colour2.r == 0.0 ? 0.0 : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0 ? 0.0 : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0 ? 0.0 : (colour1.b / colour2.b);
	return out;
}
ForceInline tF32RGBA tF32RGBA_Add(tF32RGBA colour1, tF32RGBA colour2)
{
	tF32RGBA out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	out.a = colour1.a + colour2.a;
	return out;
}
ForceInline tF32RGBA tF32RGBA_Sub(tF32RGBA colour1, tF32RGBA colour2)
{
	tF32RGBA out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	out.a = colour1.a - colour2.a;
	return out;
}
ForceInline tF32RGBA tF32RGBA_Mul(tF32RGBA colour1, tF32RGBA colour2)
{
	tF32RGBA out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	out.a = colour1.a * colour2.a;
	return out;
}
ForceInline tF32RGBA tF32RGBA_Div(tF32RGBA colour1, tF32RGBA colour2)
{
	tF32RGBA out;
	out.r = colour2.r == 0.0F ? 0.0F : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0F ? 0.0F : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0F ? 0.0F : (colour1.b / colour2.b);
	out.a = colour2.a == 0.0F ? 0.0F : (colour1.a / colour2.a);
	return out;
}
ForceInline tU8RGBA tU8RGBA_Add(tU8RGBA colour1, tU8RGBA colour2)
{
	tU8RGBA out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	out.a = colour1.a + colour2.a;
	return out;
}
ForceInline tU8RGBA tU8RGBA_Sub(tU8RGBA colour1, tU8RGBA colour2)
{
	tU8RGBA out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	out.a = colour1.a - colour2.a;
	return out;
}
ForceInline tU8RGBA tU8RGBA_Mul(tU8RGBA colour1, tU8RGBA colour2)
{
	tU8RGBA out;
	out.r = (tU8)(((tU16)colour1.r * (tU16)colour2.r) / 255U);
	out.g = (tU8)(((tU16)colour1.g * (tU16)colour2.g) / 255U);
	out.b = (tU8)(((tU16)colour1.b * (tU16)colour2.b) / 255U);
	out.a = (tU8)(((tU16)colour1.a * (tU16)colour2.a) / 255U);
	return out;
}
ForceInline tU8RGBA tU8RGBA_Div(tU8RGBA colour1, tU8RGBA colour2)
{
	tU8RGBA out;
	out.r = colour2.r == 0U ? 0U : (tU8)(((tU16)colour1.r * 255U) / colour2.r);
	out.g = colour2.g == 0U ? 0U : (tU8)(((tU16)colour1.g * 255U) / colour2.g);
	out.b = colour2.b == 0U ? 0U : (tU8)(((tU16)colour1.b * 255U) / colour2.b);
	out.a = colour2.a == 0U ? 0U : (tU8)(((tU16)colour1.a * 255U) / colour2.a);
	return out;
}
ForceInline tF64RGBA tF64RGBA_Add(tF64RGBA colour1, tF64RGBA colour2)
{
	tF64RGBA out;
	out.r = colour1.r + colour2.r;
	out.g = colour1.g + colour2.g;
	out.b = colour1.b + colour2.b;
	out.a = colour1.a + colour2.a;
	return out;
}
ForceInline tF64RGBA tF64RGBA_Sub(tF64RGBA colour1, tF64RGBA colour2)
{
	tF64RGBA out;
	out.r = colour1.r - colour2.r;
	out.g = colour1.g - colour2.g;
	out.b = colour1.b - colour2.b;
	out.a = colour1.a - colour2.a;
	return out;
}
ForceInline tF64RGBA tF64RGBA_Mul(tF64RGBA colour1, tF64RGBA colour2)
{
	tF64RGBA out;
	out.r = colour1.r * colour2.r;
	out.g = colour1.g * colour2.g;
	out.b = colour1.b * colour2.b;
	out.a = colour1.a * colour2.a;
	return out;
}
ForceInline tF64RGBA tF64RGBA_Div(tF64RGBA colour1, tF64RGBA colour2)
{
	tF64RGBA out;
	out.r = colour2.r == 0.0 ? 0.0 : (colour1.r / colour2.r);
	out.g = colour2.g == 0.0 ? 0.0 : (colour1.g / colour2.g);
	out.b = colour2.b == 0.0 ? 0.0 : (colour1.b / colour2.b);
	out.a = colour2.a == 0.0 ? 0.0 : (colour1.a / colour2.a);
	return out;
}
ForceInline tU32ARGB tU32ARGB_Add(tU32ARGB colour1, tU32ARGB colour2)
{
	tU32ARGB out;
	out = colour1 | colour2;
	return out;
}
ForceInline tU32ARGB tU32ARGB_Sub(tU32ARGB colour1, tU32ARGB colour2)
{
	tU32ARGB out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tU32ARGB tU32ARGB_Mul(tU32ARGB colour1, tU32ARGB colour2)
{
	tU32ARGB out;
	out = colour1 & colour2;
	return out;
}
ForceInline tU32ARGB tU32ARGB_Div(tU32ARGB colour1, tU32ARGB colour2)
{
	tU32ARGB out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tU32RGBA tU32RGBA_Add(tU32RGBA colour1, tU32RGBA colour2)
{
	tU32RGBA out;
	out = colour1 | colour2;
	return out;
}
ForceInline tU32RGBA tU32RGBA_Sub(tU32RGBA colour1, tU32RGBA colour2)
{
	tU32RGBA out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tU32RGBA tU32RGBA_Mul(tU32RGBA colour1, tU32RGBA colour2)
{
	tU32RGBA out;
	out = colour1 & colour2;
	return out;
}
ForceInline tU32RGBA tU32RGBA_Div(tU32RGBA colour1, tU32RGBA colour2)
{
	tU32RGBA out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tU32BGRA tU32BGRA_Add(tU32BGRA colour1, tU32BGRA colour2)
{
	tU32BGRA out;
	out = colour1 | colour2;
	return out;
}
ForceInline tU32BGRA tU32BGRA_Sub(tU32BGRA colour1, tU32BGRA colour2)
{
	tU32BGRA out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tU32BGRA tU32BGRA_Mul(tU32BGRA colour1, tU32BGRA colour2)
{
	tU32BGRA out;
	out = colour1 & colour2;
	return out;
}
ForceInline tU32BGRA tU32BGRA_Div(tU32BGRA colour1, tU32BGRA colour2)
{
	tU32BGRA out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tU32ABGR tU32ABGR_Add(tU32ABGR colour1, tU32ABGR colour2)
{
	tU32ABGR out;
	out = colour1 | colour2;
	return out;
}
ForceInline tU32ABGR tU32ABGR_Sub(tU32ABGR colour1, tU32ABGR colour2)
{
	tU32ABGR out;
	out = colour1 & ~colour2;
	return out;
}
ForceInline tU32ABGR tU32ABGR_Mul(tU32ABGR colour1, tU32ABGR colour2)
{
	tU32ABGR out;
	out = colour1 & colour2;
	return out;
}
ForceInline tU32ABGR tU32ABGR_Div(tU32ABGR colour1, tU32ABGR colour2)
{
	tU32ABGR out;
	out = colour2 == 0U ? 0U : colour1;
	return out;
}
ForceInline tF32RGB tF32RGB_AddFlt(tF32RGB colour, tF32 flt)
{
	tF32RGB out;
	out.r = colour.r + flt;
	out.g = colour.g + flt;
	out.b = colour.b + flt;
	return out;
}
ForceInline tF32RGB tF32RGB_SubFlt(tF32RGB colour, tF32 flt)
{
	tF32RGB out;
	out.r = colour.r - flt;
	out.g = colour.g - flt;
	out.b = colour.b - flt;
	return out;
}
ForceInline tF32RGB tF32RGB_MulFlt(tF32RGB colour, tF32 flt)
{
	tF32RGB out;
	out.r = colour.r * flt;
	out.g = colour.g * flt;
	out.b = colour.b * flt;
	return out;
}
ForceInline tF32RGB tF32RGB_DivFlt(tF32RGB colour, tF32 flt)
{
	tF32RGB out;
	out.r = flt == 0.0F ? 0.0F : (colour.r / flt);
	out.g = flt == 0.0F ? 0.0F : (colour.g / flt);
	out.b = flt == 0.0F ? 0.0F : (colour.b / flt);
	return out;
}
ForceInline tF32RGBA tF32RGBA_AddFlt(tF32RGBA colour, tF32 flt)
{
	tF32RGBA out;
	out.r = colour.r + flt;
	out.g = colour.g + flt;
	out.b = colour.b + flt;
	out.a = colour.a + flt;
	return out;
}
ForceInline tF32RGBA tF32RGBA_SubFlt(tF32RGBA colour, tF32 flt)
{
	tF32RGBA out;
	out.r = colour.r - flt;
	out.g = colour.g - flt;
	out.b = colour.b - flt;
	out.a = colour.a - flt;
	return out;
}
ForceInline tF32RGBA tF32RGBA_MulFlt(tF32RGBA colour, tF32 flt)
{
	tF32RGBA out;
	out.r = colour.r * flt;
	out.g = colour.g * flt;
	out.b = colour.b * flt;
	out.a = colour.a * flt;
	return out;
}
ForceInline tF32RGBA tF32RGBA_DivFlt(tF32RGBA colour, tF32 flt)
{
	tF32RGBA out;
	out.r = flt == 0.0F ? 0.0F : (colour.r / flt);
	out.g = flt == 0.0F ? 0.0F : (colour.g / flt);
	out.b = flt == 0.0F ? 0.0F : (colour.b / flt);
	out.a = flt == 0.0F ? 0.0F : (colour.a / flt);
	return out;
}
ForceInline tF64RGB tF64RGB_AddDbl(tF64RGB colour, tF64 dbl)
{
	tF64RGB out;
	out.r = colour.r + dbl;
	out.g = colour.g + dbl;
	out.b = colour.b + dbl;
	return out;
}
ForceInline tF64RGB tF64RGB_SubDbl(tF64RGB colour, tF64 dbl)
{
	tF64RGB out;
	out.r = colour.r - dbl;
	out.g = colour.g - dbl;
	out.b = colour.b - dbl;
	return out;
}
ForceInline tF64RGB tF64RGB_MulDbl(tF64RGB colour, tF64 dbl)
{
	tF64RGB out;
	out.r = colour.r * dbl;
	out.g = colour.g * dbl;
	out.b = colour.b * dbl;
	return out;
}
ForceInline tF64RGB tF64RGB_DivDbl(tF64RGB colour, tF64 dbl)
{
	tF64RGB out;
	out.r = dbl == 0.0 ? 0.0 : (colour.r / dbl);
	out.g = dbl == 0.0 ? 0.0 : (colour.g / dbl);
	out.b = dbl == 0.0 ? 0.0 : (colour.b / dbl);
	return out;
}
ForceInline tF64RGBA tF64RGBA_AddDbl(tF64RGBA colour, tF64 dbl)
{
	tF64RGBA out;
	out.r = colour.r + dbl;
	out.g = colour.g + dbl;
	out.b = colour.b + dbl;
	out.a = colour.a + dbl;
	return out;
}
ForceInline tF64RGBA tF64RGBA_SubDbl(tF64RGBA colour, tF64 dbl)
{
	tF64RGBA out;
	out.r = colour.r - dbl;
	out.g = colour.g - dbl;
	out.b = colour.b - dbl;
	out.a = colour.a - dbl;
	return out;
}
ForceInline tF64RGBA tF64RGBA_MulDbl(tF64RGBA colour, tF64 dbl)
{
	tF64RGBA out;
	out.r = colour.r * dbl;
	out.g = colour.g * dbl;
	out.b = colour.b * dbl;
	out.a = colour.a * dbl;
	return out;
}
ForceInline tF64RGBA tF64RGBA_DivDbl(tF64RGBA colour, tF64 dbl)
{
	tF64RGBA out;
	out.r = dbl == 0.0 ? 0.0 : (colour.r / dbl);
	out.g = dbl == 0.0 ? 0.0 : (colour.g / dbl);
	out.b = dbl == 0.0 ? 0.0 : (colour.b / dbl);
	out.a = dbl == 0.0 ? 0.0 : (colour.a / dbl);
	return out;
}
ForceInline tF32RGB tF32RGB_Clamp(tF32RGB colour)
{
	tF32RGB out;
	out.r = tF32_Clamp(0.0F, colour.r, 1.0F);
	out.g = tF32_Clamp(0.0F, colour.g, 1.0F);
	out.b = tF32_Clamp(0.0F, colour.b, 1.0F);
	return out;
}
ForceInline tF32RGBA tF32RGBA_Clamp(tF32RGBA colour)
{
	tF32RGBA out;
	out.r = tF32_Clamp(0.0F, colour.r, 1.0F);
	out.g = tF32_Clamp(0.0F, colour.g, 1.0F);
	out.b = tF32_Clamp(0.0F, colour.b, 1.0F);
	out.a = tF32_Clamp(0.0F, colour.a, 1.0F);
	return out;
}
ForceInline tF32RGB tF32RGB_Saturate(tF32RGB colour)
{
	return tF32RGB_Clamp(colour);
}
ForceInline tF32RGBA tF32RGBA_Saturate(tF32RGBA colour)
{
	return tF32RGBA_Clamp(colour);
}
ForceInline tF32RGB tF32RGB_Blend(tF32RGB colour1, tF32RGB colour2, tF32 stp)
{
	tF32RGB out;
	out.r = tF32_Lerp(colour1.r, colour2.r, stp);
	out.g = tF32_Lerp(colour1.g, colour2.g, stp);
	out.b = tF32_Lerp(colour1.b, colour2.b, stp);
	return out;
}
ForceInline tF32RGBA tF32RGBA_Blend(tF32RGBA colour1, tF32RGBA colour2, tF32 stp)
{
	tF32RGBA out;
	out.r = tF32_Lerp(colour1.r, colour2.r, stp);
	out.g = tF32_Lerp(colour1.g, colour2.g, stp);
	out.b = tF32_Lerp(colour1.b, colour2.b, stp);
	out.a = tF32_Lerp(colour1.a, colour2.a, stp);
	return out;
}
ForceInline tF64RGB tF64RGB_Clamp(tF64RGB colour)
{
	tF64RGB out;
	out.r = tF64_Clamp(0.0, colour.r, 1.0);
	out.g = tF64_Clamp(0.0, colour.g, 1.0);
	out.b = tF64_Clamp(0.0, colour.b, 1.0);
	return out;
}
ForceInline tF64RGBA tF64RGBA_Clamp(tF64RGBA colour)
{
	tF64RGBA out;
	out.r = tF64_Clamp(0.0, colour.r, 1.0);
	out.g = tF64_Clamp(0.0, colour.g, 1.0);
	out.b = tF64_Clamp(0.0, colour.b, 1.0);
	out.a = tF64_Clamp(0.0, colour.a, 1.0);
	return out;
}
ForceInline tF64RGB tF64RGB_Saturate(tF64RGB colour)
{
	return tF64RGB_Clamp(colour);
}
ForceInline tF64RGBA tF64RGBA_Saturate(tF64RGBA colour)
{
	return tF64RGBA_Clamp(colour);
}
ForceInline tF64RGB tF64RGB_Blend(tF64RGB colour1, tF64RGB colour2, tF64 stp)
{
	tF64RGB out;
	out.r = tF64_Lerp(colour1.r, colour2.r, stp);
	out.g = tF64_Lerp(colour1.g, colour2.g, stp);
	out.b = tF64_Lerp(colour1.b, colour2.b, stp);
	return out;
}
ForceInline tF64RGBA tF64RGBA_Blend(tF64RGBA colour1, tF64RGBA colour2, tF64 stp)
{
	tF64RGBA out;
	out.r = tF64_Lerp(colour1.r, colour2.r, stp);
	out.g = tF64_Lerp(colour1.g, colour2.g, stp);
	out.b = tF64_Lerp(colour1.b, colour2.b, stp);
	out.a = tF64_Lerp(colour1.a, colour2.a, stp);
	return out;
}
#endif/*BQSELAYER_COLOUR_IMPL*/
#endif/*BQSELAYER_COLOUR_H*/