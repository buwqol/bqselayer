#ifndef BQSELAYER_COLOUR_H
#define BQSELAYER_COLOUR_H
#include "PrimTypes.h"
/*
	*_Make
	*_Eq
	*_Nearby
	tU32ARGB_FromRGBA
	tU32RGBA_FromRGBA
	tU32BGRA_FromRGBA
	tU32ABGR_FromRGBA
	tU8RGBA_FromU32ARGB
	tU8RGBA_FromU32RGBA
	tU8RGBA_FromU32BGRA
	tU8RGBA_FromU32ABGR
	tF32RGB_ToHSV
	tF32HSV_ToRGB
	tF32RGB_ToHSL
	tF32HSL_ToRGB
	tF64RGB_ToHSV
	tF64HSV_ToRGB
	tF64RGB_ToHSL
	tF64HSL_ToRGB
	tF32RGB_FromU8RGB
	tF32RGBA_FromU8RGBA
	tU8RGB_FromF32RGB
	tU8RGBA_FromF32RGBA
	tF64RGB_FromU8RGB
	tF64RGBA_FromU8RGBA
	tU8RGB_FromF64RGB
	tU8RGBA_FromF64RGBA
	tF64RGB_FromF32RGB
	tF64RGBA_FromF32RGBA
	tF32RGB_FromF64RGB
	tF32RGBA_FromF64RGBA
	tF32RGB_Lerp
	tF32RGBA_Lerp
	tF64RGB_Lerp
	tF64RGBA_Lerp
	*_Add
	*_Sub
	*_Mul
	*_Div
	*_AddFlt
	*_SubFlt
	*_MulFlt
	*_DivFlt
	*_Clamp
	*_Saturate
	*_Blend
*/
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
#endif/*BQSELAYER_COLOUR_H*/