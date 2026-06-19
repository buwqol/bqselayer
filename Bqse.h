#ifndef BQSELAYER_H
#define BQSELAYER_H

// Language
#ifdef __cplusplus
#define LANG_Cpp 1
#else
#define LANG_C 1
#endif

// Language version
#ifdef LANG_C
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 202311L
#define LANG_Ver 2023
#elif __STDC_VERSION__ >= 201710L
#define LANG_Ver 2017
#elif __STDC_VERSION__ >= 201112L
#define LANG_Ver 2011
#elif __STDC_VERSION__ >= 199901L
#define LANG_Ver 1999
#elif __STDC_VERSION__ >= 199409L
#define LANG_Ver 1994
#endif
#elif defined(__STDC__)
#define LANG_Ver 1990
#else
#error "Unknown C standard"
#endif
#elif defined(LANG_Cpp)
#if __cplusplus >= 202302L
#define LANG_Ver 2023
#elif __cplusplus >= 202002L
#define LANG_Ver 2020
#elif __cplusplus >= 201703L
#define LANG_Ver 2017
#elif __cplusplus >= 201402L
#define LANG_Ver 2014
#elif __cplusplus >= 201103L
#define LANG_Ver 2011
#elif __cplusplus >= 199711L
#define LANG_Ver 1998
#else
#error "Unknown CPP standard"
#endif
#endif

// Compiler
#if defined(__clang__)
#define COMP_Clang 1
#define COMP_Curr eCompiler_Clang
#elif defined(_MSC_VER)
#define COMP_MSVC 1
#define COMP_Curr eCompiler_MSVC
#elif defined(__GNUC__)
#define COMP_GNUC 1
#define COMP_Curr eCompiler_GNUC
#else
#error "Unknown compiler"
#endif

// Operating system
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define OS_FreeBSD 1
#define OS_Curr eOperatingSystem_FreeBSD
#elif defined(__linux__) || defined(__gnu_linux__) || defined(linux) || defined(__linux)
#define OS_Linux 1
#define OS_Curr eOperatingSystem_Linux
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#define OS_Windows 1
#define OS_Curr eOperatingSystem_Windows
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define OS_MacOS 1
#define OS_Curr eOperatingSystem_MacOS
#elif defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#define OS_MSDOS 1
#define OS_Curr eOperatingSystem_MSDOS
#elif defined(__unix__) || defined(__unix)
#define OS_Unix 1
#define OS_Curr eOperatingSystem_Unix
#else
#error "Unknown operating system"
#endif

// Architecture
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#define ARCH_AMD64 1
#define ARCH_Curr eArchitecture_AMD64
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(__i386) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#define ARCH_Intel86 1
#define ARCH_Curr eArchitecture_Intel86
#elif defined(__aarch64__)
#define ARCH_Arm64 1
#define ARCH_Curr eArchitecture_Arm64
#elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
#define ARCH_Arm 1
#define ARCH_Curr eArchitecture_Arm
#else
#error "Unknown architecture"
#endif

// Bitness
#if defined(ARCH_AMD64) || defined(ARCH_Arm64)
#define ARCH_Bitness 64
#else
#define ARCH_Bitness 32
#endif

#ifndef Min
#define Min(Num1, Num2) (((Num1)<(Num2))?(Num1):(Num2))
#endif
#ifndef Max
#define Max(Num1, Num2) (((Num1)>(Num2))?(Num1):(Num2))
#endif
#ifndef Clamp
#define Clamp(Lo, Num, Hi) (((Num)<(Lo))?(Lo):((Hi)<(Num))?(Hi):(Num))
#endif
#define ClampTop(Num1, Num2) Min(Num1, Num2)
#define ClampBot(Num1, Num2) Max(Num1, Num2)

// Types
#if defined(LANG_Cpp)
typedef bool tBln;
#elif defined(LANG_C) && LANG_Ver >= 1999
typedef _Bool tBln;
#else
typedef char unsigned tBln;
#endif
#ifndef True
#define True ((tBln)1)
#endif
#ifndef False
#define False ((tBln)0)
#endif
#define tNone void
#define tGen void
#define tInt int
typedef tNone tFnc(tNone);
typedef tFnc *tFncPtr;
typedef tGen *tPtr;
typedef char tChr;
#define BQSE_DECLARE_MINMAXCLAMPS(tType)			\
tType tType##_MinOf(tType Num1, tType Num2);		\
tType tType##_MaxOf(tType Num1, tType Num2);		\
tType tType##_Clamp(tType Lo, tType Num, tType Hi);	\
tType tType##_ClampTop(tType Num1, tType Num2);		\
tType tType##_ClampBot(tType Num1, tType Num2);		
#define BQSE_DEFINE_MINMAXCLAMPS(tType)				\
tType tType##_MinOf(tType Num1, tType Num2)			\
{													\
	return Min(Num1, Num2);							\
}													\
tType tType##_MaxOf(tType Num1, tType Num2)			\
{													\
	return Max(Num1, Num2);							\
}													\
tType tType##_Clamp(tType Lo, tType Num, tType Hi)	\
{													\
	return Clamp(Lo, Num, Hi);						\
}													\
tType tType##_ClampTop(tType Num1, tType Num2)		\
{													\
	return ClampTop(Num1, Num2);					\
}													\
tType tType##_ClampBot(tType Num1, tType Num2)		\
{													\
	return ClampBot(Num1, Num2);					\
}
typedef signed char tS8;
typedef char Bqse_StaticAssert_tS8[(sizeof(tS8) == 1U) ? 1U : -1];
#define tS8_Max 127
#define tS8_Min (-128)
BQSE_DECLARE_MINMAXCLAMPS(tS8);
typedef unsigned char tU8;
typedef char Bqse_StaticAssert_tU8[(sizeof(tU8) == 1U) ? 1U : -1];
#define tU8_Max 255
#define tU8_Min 0
BQSE_DECLARE_MINMAXCLAMPS(tU8);
typedef signed short tS16;
typedef char Bqse_StaticAssert_tS16[(sizeof(tS16) == 2U) ? 1U : -1];
#define tS16_Max 32767
#define tS16_Min (-32768)
BQSE_DECLARE_MINMAXCLAMPS(tS16);
typedef unsigned short tU16;
typedef char Bqse_StaticAssert_tU16[(sizeof(tU16) == 2U) ? 1U : -1];
#define tU16_Max 65535
#define tU16_Min 0
BQSE_DECLARE_MINMAXCLAMPS(tU16);
typedef signed int tS32;
typedef char Bqse_StaticAssert_tS32[(sizeof(tS32) == 4U) ? 1U : -1];
#define tS32_Max 2147483647
#define tS32_Min (-2147483647-1)
BQSE_DECLARE_MINMAXCLAMPS(tS32);
typedef unsigned int tU32;
typedef char Bqse_StaticAssert_tU32[(sizeof(tU32) == 4U) ? 1U : -1];
#define tU32_Max 4294967295U
#define tU32_Min 0U
BQSE_DECLARE_MINMAXCLAMPS(tU32);
typedef signed long long tS64;
typedef char Bqse_StaticAssert_tS64[(sizeof(tS64) == 8U) ? 1U : -1];
#define tS64_Max 9223372036854775807LL
#define tS64_Min (-9223372036854775807LL-1)
BQSE_DECLARE_MINMAXCLAMPS(tS64);
typedef unsigned long long tU64;
typedef char Bqse_StaticAssert_tU64[(sizeof(tU64) == 8U) ? 1U : -1];
#define tU64_Max 18446744073709551615LLU
#define tU64_Min 0LLU
BQSE_DECLARE_MINMAXCLAMPS(tU64);
#ifdef BQSE_MASTER
BQSE_DEFINE_MINMAXCLAMPS(tS8);
BQSE_DEFINE_MINMAXCLAMPS(tU8);
BQSE_DEFINE_MINMAXCLAMPS(tS16);
BQSE_DEFINE_MINMAXCLAMPS(tU16);
BQSE_DEFINE_MINMAXCLAMPS(tS32);
BQSE_DEFINE_MINMAXCLAMPS(tU32);
BQSE_DEFINE_MINMAXCLAMPS(tS64);
BQSE_DEFINE_MINMAXCLAMPS(tU64);
#endif
#undef BQSE_DECLARE_MINMAXCLAMPS
#undef BQSE_DEFINE_MINMAXCLAMPS
// TODO: tF16 half precision floating point type.
typedef float tF32;
typedef char Bqse_StaticAssert_IEEE754_tF32[(sizeof(tF32) == 4U) ? 1U : -1];
#define tF32_Pi 3.141592653589793F
#define tF32_Eps 1.19209290E-7F
#define tF32_Tol 1E-5F
#define tF32_EulNum 2.718281828459045F
#define tF32_EulCnst 0.577215664901532F
tF32 tF32_Inf(tNone);
tF32 tF32_Abs(tF32 flt);
tF32 tF32_Neg(tF32 flt);
tF32 tF32_NegInf(tNone);
tF32 tF32_QuiNaN(tNone);
tF32 tF32_SigNaN(tNone);
tF32 tF32_Sine(tF32 ang);
tF32 tF32_Cosine(tF32 ang);
tF32 tF32_Tangent(tF32 ang);
tF32 tF32_SineInv(tF32 num);
tF32 tF32_CosineInv(tF32 num);
tF32 tF32_TangentInv(tF32 num);
tF32 tF32_TangentInv2(tF32 opp, tF32 adj);
tF32 tF32_HypSine(tF32 ang);
tF32 tF32_HypCosine(tF32 ang);
tF32 tF32_HypTangent(tF32 ang);
tF32 tF32_Sqrt(tF32 num);
tF32 tF32_InvSqrt(tF32 num);
tF32 tF32_Ln(tF32 num);
tF32 tF32_Log(tF32 num, tF32 btm);
tF32 tF32_Min(tF32 flt1, tF32 flt2);
tF32 tF32_Max(tF32 flt1, tF32 flt2);
tF32 tF32_Clamp(tF32 lo, tF32 flt, tF32 hi);
tF32 tF32_ClampTop(tF32 flt1, tF32 flt2);
tF32 tF32_ClampBot(tF32 flt1, tF32 flt2);
tF32 tF32_Lerp(tF32 strt, tF32 stp, tF32 fnsh);
tF32 tF32_Unlerp(tF32 strt, tF32 curr, tF32 fnsh);
#define tF32_SignMask 0X80000000U
#define tF32_ExpoMask 0X7F800000U
#define tF32_FracMask 0X007FFFFFU
typedef union
{
	tF32 flt;
	tU32 raw;
}
tF32Bits;
#ifdef BQSE_MASTER
tF32 tF32_Inf(tNone)
{
	tF32Bits num;
	num.raw = 0X7F800000U;
	return num.flt;
}
tF32 tF32_Abs(tF32 flt)
{
	tF32Bits num;
	num.flt = flt;
	num.raw &= 0X7FFFFFFFU;
	return num.flt;
}
tF32 tF32_Neg(tF32 flt)
{
	tF32Bits num;
	num.flt = flt;
	num.raw ^= 0X80000000U;
	return num.flt;
}
tF32 tF32_NegInf(tNone)
{
	tF32Bits num;
	num.raw = 0XFF800000U;
	return num.flt;
}
tF32 tF32_QuiNaN(tNone)
{
	tF32Bits num;
	num.raw = 0XFFC00001U;
	return num.flt;
}
tF32 tF32_SigNaN(tNone)
{
	tF32Bits num;
	num.raw = 0XFF800001U;
	return num.flt;
}
#include <math.h> // TODO: Move away from this eventually.
tF32 tF32_Sine(tF32 ang)
{
	return sinf(ang);
}
tF32 tF32_Cosine(tF32 ang)
{
	return cosf(ang);
}
tF32 tF32_Tangent(tF32 ang)
{
	return tanf(ang);
}
tF32 tF32_SineInv(tF32 num)
{
	return asinf(num);
}
tF32 tF32_CosineInv(tF32 num)
{
	return acosf(num);
}
tF32 tF32_TangentInv(tF32 num)
{
	return atanf(num);
}
tF32 tF32_TangentInv2(tF32 opp, tF32 adj)
{
	return atan2(opp, adj);
}
tF32 tF32_HypSine(tF32 ang)
{
	return sinhf(ang);
}
tF32 tF32_HypCosine(tF32 ang)
{
	return coshf(ang);
}
tF32 tF32_HypTangent(tF32 ang)
{
	return tanhf(ang);
}
tF32 tF32_Sqrt(tF32 num)
{
	return sqrtf(num);
}
tF32 tF32_InvSqrt(tF32 num) // Fast inverse sqrt from Quake 3.
{
	static const tF32 threeHalfs = 1.5F;
	tF32Bits number;
	number.flt = num;
	tF32 halfNum = number.flt * 0.5F;
	number.raw = 0X5F3759DFU - (number.raw >> 1U);
	number.flt = number.flt * (threeHalfs - (halfNum * number.flt * number.flt));
	// number.flt = number.flt * (threeHalf - (halfNum * number.flt * number.flt)); // Enable this if you need the precision.
	return number.flt;
}
tF32 tF32_Ln(tF32 num)
{
	return logf(num);
}
tF32 tF32_Log(tF32 num, tF32 btm)
{
	return tF32_Ln(num) / tF32_Ln(btm);
}
tF32 tF32_Min(tF32 flt1, tF32 flt2)
{
	return Min(flt1, flt2);
}
tF32 tF32_Max(tF32 flt1, tF32 flt2)
{
	return Max(flt1, flt2);
}
tF32 tF32_Clamp(tF32 lo, tF32 flt, tF32 hi)
{
	return Clamp(lo, flt, hi);
}
tF32 tF32_ClampTop(tF32 flt1, tF32 flt2)
{
	return ClampTop(flt1, flt2);
}
tF32 tF32_ClampBot(tF32 flt1, tF32 flt2)
{
	return ClampBot(flt1, flt2);
}
tF32 tF32_Lerp(tF32 strt, tF32 stp, tF32 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
tF32 tF32_Unlerp(tF32 strt, tF32 curr, tF32 fnsh)
{
	if (strt == fnsh) return 0.0F;
	return (curr - strt) / (fnsh - strt);
}
#endif//BQSE_MASTER
typedef double tF64;
typedef char Bqse_StaticAssert_IEEE754_tF64[(sizeof(tF64) == 8U) ? 1U : -1];
#define tF64_Pi 3.141592653589793
#define tF64_Eps 2.2204460492503131E-16
#define tF64_Tol 1E-5
#define tF64_EulNum 2.718281828459045
#define tF64_EulCnst 0.577215664901532
tF64 tF64_Inf(tNone);
tF64 tF64_Abs(tF64 dbl);
tF64 tF64_Neg(tF64 dbl);
tF64 tF64_NegInf(tNone);
tF64 tF64_QuiNaN(tNone);
tF64 tF64_SigNaN(tNone);
tF64 tF64_Sine(tF64 ang);
tF64 tF64_Cosine(tF64 ang);
tF64 tF64_Tangent(tF64 ang);
tF64 tF64_SineInv(tF64 num);
tF64 tF64_CosineInv(tF64 num);
tF64 tF64_TangentInv(tF64 num);
tF64 tF64_TangentInv2(tF64 opp, tF64 adj);
tF64 tF64_HypSine(tF64 ang);
tF64 tF64_HypCosine(tF64 ang);
tF64 tF64_HypTangent(tF64 ang);
tF64 tF64_Sqrt(tF64 num);
tF64 tF64_InvSqrt(tF64 num);
tF64 tF64_Ln(tF64 num);
tF64 tF64_Log(tF64 num, tF64 btm);
tF64 tF64_Min(tF64 dbl1, tF64 dbl2);
tF64 tF64_Max(tF64 dbl1, tF64 dbl2);
tF64 tF64_Clamp(tF64 lo, tF64 dbl, tF64 hi);
tF64 tF64_ClampTop(tF64 dbl1, tF64 dbl2);
tF64 tF64_ClampBot(tF64 dbl1, tF64 dbl2);
tF64 tF64_Lerp(tF64 strt, tF64 stp, tF64 fnsh);
tF64 tF64_Unlerp(tF64 strt, tF64 curr, tF64 fnsh);
#define tF64_SignMask 0X8000000000000000LLU
#define tF64_ExpoMask 0X7FF0000000000000LLU
#define tF64_FracMask 0X000FFFFFFFFFFFFFLLU
typedef union
{
	tF64 dbl;
	tU64 raw;
}
tF64Bits;
#ifdef BQSE_MASTER
tF64 tF64_Inf(tNone)
{
	tF64Bits num;
	num.raw = 0X7FF0000000000000LLU;
	return num.dbl;
}
tF64 tF64_Abs(tF64 dbl)
{
	tF64Bits num;
	num.dbl = dbl;
	num.raw &= 0X7FFFFFFFFFFFFFFFLLU;
	return num.dbl;
}
tF64 tF64_Neg(tF64 dbl)
{
	tF64Bits num;
	num.dbl = dbl;
	num.raw ^= 0X8000000000000000LLU;
	return num.dbl;
}
tF64 tF64_NegInf(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF0000000000000LLU;
	return num.dbl;
}
tF64 tF64_QuiNaN(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF8000000000001LLU;
	return num.dbl;
}
tF64 tF64_SigNaN(tNone)
{
	tF64Bits num;
	num.raw = 0XFFF0000000000001LLU;
	return num.dbl;
}
tF64 tF64_Sine(tF64 ang)
{
	return sin(ang);
}
tF64 tF64_Cosine(tF64 ang)
{
	return cos(ang);
}
tF64 tF64_Tangent(tF64 ang)
{
	return tan(ang);
}
tF64 tF64_SineInv(tF64 num)
{
	return asin(num);
}
tF64 tF64_CosineInv(tF64 num)
{
	return acos(num);
}
tF64 tF64_TangentInv(tF64 num)
{
	return atan(num);
}
tF64 tF64_TangentInv2(tF64 opp, tF64 adj)
{
	return atan2(opp, adj);
}
tF64 tF64_HypSine(tF64 ang)
{
	return sinh(ang);
}
tF64 tF64_HypCosine(tF64 ang)
{
	return cosh(ang);
}
tF64 tF64_HypTangent(tF64 ang)
{
	return tanh(ang);
}
tF64 tF64_Sqrt(tF64 num)
{
	return sqrt(num);
}
tF64 tF64_InvSqrt(tF64 num)
{
	static const tF64 threeHalfs = 1.5;
	tF64Bits number;
	number.dbl = num;
	tF64 halfNum = number.dbl * 0.5;
	number.raw = 0X5FE6EC85E7DE30DAULL - (number.raw >> 1U);
	number.dbl = number.dbl * (threeHalfs - (halfNum * number.dbl * number.dbl));
	// number.dbl = number.dbl * (threeHalfs - (halfNum * number.dbl * number.dbl)); // Optional second iteration.
	return number.dbl;
}
tF64 tF64_Ln(tF64 num)
{
	return log(num);
}
tF64 tF64_Log(tF64 num, tF64 btm)
{
	return tF64_Ln(num) / tF64_Ln(btm);
}
tF64 tF64_Min(tF64 dbl1, tF64 dbl2)
{
	return Min(dbl1, dbl2);
}
tF64 tF64_Max(tF64 dbl1, tF64 dbl2)
{
	return Max(dbl1, dbl2);
}
tF64 tF64_Clamp(tF64 lo, tF64 dbl, tF64 hi)
{
	return Clamp(lo, dbl, hi);
}
tF64 tF64_ClampTop(tF64 dbl1, tF64 dbl2)
{
	return ClampTop(dbl1, dbl2);
}
tF64 tF64_ClampBot(tF64 dbl1, tF64 dbl2)
{
	return ClampBot(dbl1, dbl2);
}
tF64 tF64_Lerp(tF64 strt, tF64 stp, tF64 fnsh)
{
	return strt + ((fnsh - strt) * stp);
}
tF64 tF64_Unlerp(tF64 strt, tF64 curr, tF64 fnsh)
{
	if (strt == fnsh) return 0.0;
	return (curr - strt) / (fnsh - strt);
}
#endif//BQSE_MASTER

#if ARCH_Bitness == 64
typedef tS64 tSSz;
typedef tU64 tUSz;
#else
typedef tS32 tSSz;
typedef tU32 tUSz;
#endif

#define WrapStatement(Stmnt) do{Stmnt}while(0U)
#define ForceDump() (*(voltaile long *)0U = 0U)
#define Assertion(Cnd) WrapStatement(if(!(Cnd)){ForceDump();})
#define Stringify_inner(Str) #Str
#define Stringify(Str) Stringify_inner(Str)
#define Glueify_inner(StrA, StrB) StrA##StrB
#define Glueify(StrA, StrB) Glueify_inner(StrA, StrB)
#define ArrLng(Arr) (sizeof(Arr)/sizeof(Arr[0]))
#define NumFromPtr(Ptr) (tUSz)((tU8 *)Ptr - (tU8 *)0U)
#define PtrFromNum(Num) (tPtr)((tU8 *)0U + (Num))
#define OffsetOf(tType, Memb) ((tUSz)&(((tType*)0)->Memb))
#define MemberSize(tType, Memb) (sizeof(((tType *)0U)->Memb))

#if defined(LANG_Cpp)
#define LINK_C extern "C"
#define LINK_C_Begin extern "C" {
#define LINK_C_End }
#else
#define LINK_C
#define LINK_C_Begin
#define LINK_C_End
#endif

// Compound types
typedef union { struct { tS32 x, y; }; tS32 v[2]; } tS32V2D;
tS32V2D tS32V2D_Make(tS32 x, tS32 y);
tS32V2D tS32V2D_Zero(tNone);
tS32V2D tS32V2D_Add(tS32V2D vec1, tS32V2D vec2);
tS32V2D tS32V2D_Sub(tS32V2D vec1, tS32V2D vec2);
tS32V2D tS32V2D_Mul(tS32V2D vec, tS32 mod);
/*Warn: Silently returns `tS32V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tS32V2D tS32V2D_Div(tS32V2D vec, tS32 mod);
/*Note: Returns `False` on success.*/
tBln tS32V2D_Div_safe(tS32V2D *vec, tS32 mod);
tBln tS32V2D_Eq(tS32V2D vec1, tS32V2D vec2);
tS32 tS32V2D_Dot(tS32V2D vec1, tS32V2D vec2);
#ifdef BQSE_MASTER
tS32V2D tS32V2D_Make(tS32 x, tS32 y)
{
	tS32V2D vec;
	vec.x = x;
	vec.y = y;
	return vec;
}
tS32V2D tS32V2D_Zero(tNone)
{
	tS32V2D vec;
	vec.x = 0;
	vec.y = 0;
	return vec;
}
tS32V2D tS32V2D_Add(tS32V2D vec1, tS32V2D vec2)
{
	tS32V2D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	return vec;
}
tS32V2D tS32V2D_Sub(tS32V2D vec1, tS32V2D vec2)
{
	tS32V2D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	return vec;
}
tS32V2D tS32V2D_Mul(tS32V2D vec, tS32 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	return vec;
}
tS32V2D tS32V2D_Div(tS32V2D vec, tS32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0) return tS32V2D_Zero();
#else
	Assertion(mod != 0);
#endif
	vec.x /= mod;
	vec.y /= mod;
	return vec;
}
tBln tS32V2D_Div_safe(tS32V2D *vec, tS32 mod)
{
	if (mod == 0) return True;
	vec->x /= mod;
	vec->y /= mod;
	return False;
}
tBln tS32V2D_Eq(tS32V2D vec1, tS32V2D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y);
}
tS32 tS32V2D_Dot(tS32V2D vec1, tS32V2D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}
#endif
typedef union { struct { tS64 x, y; }; tS64 v[2]; } tS64V2D;
tS64V2D tS64V2D_Make(tS64 x, tS64 y);
tS64V2D tS64V2D_Zero(tNone);
tS64V2D tS64V2D_Add(tS64V2D vec1, tS64V2D vec2);
tS64V2D tS64V2D_Sub(tS64V2D vec1, tS64V2D vec2);
tS64V2D tS64V2D_Mul(tS64V2D vec, tS64 mod);
/*Warn: Silently returns `tS64V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tS64V2D tS64V2D_Div(tS64V2D vec, tS64 mod);
/*Note: Returns `False` on success.*/
tBln tS64V2D_Div_safe(tS64V2D *vec, tS64 mod);
tBln tS64V2D_Eq(tS64V2D vec1, tS64V2D vec2);
tS64 tS64V2D_Dot(tS64V2D vec1, tS64V2D vec2);
#ifdef BQSE_MASTER
tS64V2D tS64V2D_Make(tS64 x, tS64 y)
{
	tS64V2D vec;
	vec.x = x;
	vec.y = y;
	return vec;
}
tS64V2D tS64V2D_Zero(tNone)
{
	tS64V2D vec;
	vec.x = 0;
	vec.y = 0;
	return vec;
}
tS64V2D tS64V2D_Add(tS64V2D vec1, tS64V2D vec2)
{
	tS64V2D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	return vec;
}
tS64V2D tS64V2D_Sub(tS64V2D vec1, tS64V2D vec2)
{
	tS64V2D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	return vec;
}
tS64V2D tS64V2D_Mul(tS64V2D vec, tS64 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	return vec;
}
tS64V2D tS64V2D_Div(tS64V2D vec, tS64 mod)
{
	if (mod == 0) return tS64V2D_Zero();
	vec.x /= mod;
	vec.y /= mod;
	return vec;
}
tBln tS64V2D_Div_safe(tS64V2D *vec, tS64 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0) return True;
#else
	Assertion(mod != 0);
#endif
	vec->x /= mod;
	vec->y /= mod;
	return False;
}
tBln tS64V2D_Eq(tS64V2D vec1, tS64V2D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y);
}
tS64 tS64V2D_Dot(tS64V2D vec1, tS64V2D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}
#endif
typedef union { struct { tF32 x, y; }; tF32 v[2]; } tF32V2D;
tF32V2D tF32V2D_Make(tF32 x, tF32 y);
tF32V2D tF32V2D_Zero(tNone);
tF32V2D tF32V2D_Add(tF32V2D vec1, tF32V2D vec2);
tF32V2D tF32V2D_Sub(tF32V2D vec1, tF32V2D vec2);
tF32V2D tF32V2D_Mul(tF32V2D vec, tF32 mod);
/*Warn: Silently returns `tF32V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V2D tF32V2D_Div(tF32V2D vec, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32V2D_Div_safe(tF32V2D *vec, tF32 mod);
tF32 tF32V2D_Dot(tF32V2D vec1, tF32V2D vec2);
tBln tF32V2D_Eq(tF32V2D vec1, tF32V2D vec2);
tBln tF32V2D_Nearby(tF32V2D vec1, tF32V2D vec2, tF32 eps);
tF32 tF32V2D_LngSq(tF32V2D vec);
tF32 tF32V2D_Lng(tF32V2D vec);
/*Warn: Silently returns `tF32V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V2D tF32V2D_Norm(tF32V2D vec);
/*Note: Returns `False` on success.*/
tBln tF32V2D_Norm_safe(tF32V2D *vec);
/*Warn: Silently returns `tF32V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V2D tF32V2D_FastNorm(tF32V2D vec);
/*Note: Returns `False` on success.*/
tBln tF32V2D_FastNorm_safe(tF32V2D *vec);
tF32 tF32V2D_DistSq(tF32V2D vec1, tF32V2D vec2);
tF32 tF32V2D_Dist(tF32V2D vec1, tF32V2D vec2);
tF32V2D tF32V2D_Lerp(tF32V2D vec1, tF32V2D vec2, tF32 stp);
#ifdef BQSE_MASTER
tF32V2D tF32V2D_Make(tF32 x, tF32 y)
{
	tF32V2D vec;
	vec.x = x;
	vec.y = y;
	return vec;
}
tF32V2D tF32V2D_Zero(tNone)
{
	tF32V2D vec;
	vec.x = 0.0F;
	vec.y = 0.0F;
	return vec;
}
tF32V2D tF32V2D_Add(tF32V2D vec1, tF32V2D vec2)
{
	tF32V2D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	return vec;
}
tF32V2D tF32V2D_Sub(tF32V2D vec1, tF32V2D vec2)
{
	tF32V2D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	return vec;
}
tF32V2D tF32V2D_Mul(tF32V2D vec, tF32 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	return vec;
}
tF32V2D tF32V2D_Div(tF32V2D vec, tF32 mod)
{
	if (mod == 0.0F) return tF32V2D_Zero();
	vec.x /= mod;
	vec.y /= mod;
	return vec;
}
tBln tF32V2D_Div_safe(tF32V2D *vec, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return True;
#else
	Assertion(mod != 0.0F);
#endif
	vec->x /= mod;
	vec->y /= mod;
	return False;
}
tF32 tF32V2D_Dot(tF32V2D vec1, tF32V2D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}
tBln tF32V2D_Eq(tF32V2D vec1, tF32V2D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y);
}
tBln tF32V2D_Nearby(tF32V2D vec1, tF32V2D vec2, tF32 eps)
{
	return (tF32_Abs(vec1.x - vec2.x) <= eps) && (tF32_Abs(vec1.y - vec2.y) <= eps);
}
tF32 tF32V2D_LngSq(tF32V2D vec)
{
	return tF32V2D_Dot(vec, vec);
}
tF32 tF32V2D_Lng(tF32V2D vec)
{
	return tF32_Sqrt(tF32V2D_LngSq(vec));
}
tF32V2D tF32V2D_Norm(tF32V2D vec)
{
	tF32 lng = tF32V2D_Lng(vec);
#ifndef BQSE_DEBUG
	if (lng == 0.0F) return tF32V2D_Zero();
#else
	Assertion(len != 0.0F);
#endif
	return tF32V2D_Div(vec, lng);
}
tBln tF32V2D_Norm_safe(tF32V2D *vec)
{
	return tF32V2D_Div_safe(vec, tF32V2D_Lng(*vec));
}
tF32V2D tF32V2D_FastNorm(tF32V2D vec)
{
	tF32 lngSq = tF32V2D_LngSq(vec);
#ifndef BQSE_DEBUG
	if (lngSq == 0.0F) return tF32V2D_Zero();
#else
	Assertion(lngSq != 0.0F);
#endif
	return tF32V2D_Mul(vec, tF32_InvSqrt(lngSq));
}
tBln tF32V2D_FastNorm_safe(tF32V2D *vec)
{
	tF32 lngSq = tF32V2D_LngSq(*vec);
	if (lngSq == 0.0F) return True;
	tF32V2D_Mul(*vec, tF32_InvSqrt(lngSq));
	return False;
}
tF32 tF32V2D_DistSq(tF32V2D vec1, tF32V2D vec2)
{
	return tF32V2D_LngSq(tF32V2D_Sub(vec1, vec2));
}
tF32 tF32V2D_Dist(tF32V2D vec1, tF32V2D vec2)
{
	return tF32V2D_Lng(tF32V2D_Sub(vec1, vec2));
}
tF32V2D tF32V2D_Lerp(tF32V2D vec1, tF32V2D vec2, tF32 stp)
{
	tF32V2D vec;
	vec.x = vec1.x + (vec2.x - vec1.x) * stp;
	vec.y = vec1.y + (vec2.y - vec1.y) * stp;
	return vec;
}
#endif
typedef union { struct { tF32 x, y, z; }; tF32 v[3]; } tF32V3D;
tF32V3D tF32V3D_Make(tF32 x, tF32 y, tF32 z);
tF32V3D tF32V3D_Zero(tNone);
tF32V3D tF32V3D_Add(tF32V3D vec1, tF32V3D vec2);
tF32V3D tF32V3D_Sub(tF32V3D vec1, tF32V3D vec2);
tF32V3D tF32V3D_Mul(tF32V3D vec, tF32 mod);
/*Warn: Silently returns `tF32V3D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V3D tF32V3D_Div(tF32V3D vec, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32V3D_Div_safe(tF32V3D *vec, tF32 mod);
tF32 tF32V3D_Dot(tF32V3D vec1, tF32V3D vec2);
tBln tF32V3D_Eq(tF32V3D vec1, tF32V3D vec2);
tBln tF32V3D_Nearby(tF32V3D vec1, tF32V3D vec2, tF32 eps);
tF32 tF32V3D_LngSq(tF32V3D vec);
tF32 tF32V3D_Lng(tF32V3D vec);
/*Warn: Silently returns `tF32V3D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V3D tF32V3D_Norm(tF32V3D vec);
/*Note: Returns `False` on success.*/
tBln tF32V3D_Norm_safe(tF32V3D *vec);
/*Warn: Silently returns `tF32V3D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V3D tF32V3D_FastNorm(tF32V3D vec);
/*Note: Returns `False` on success.*/
tBln tF32V3D_FastNorm_safe(tF32V3D *vec);
tF32 tF32V3D_DistSq(tF32V3D vec1, tF32V3D vec2);
tF32 tF32V3D_Dist(tF32V3D vec1, tF32V3D vec2);
tF32V3D tF32V3D_Lerp(tF32V3D vec1, tF32V3D vec2, tF32 stp);
tF32V3D tF32V3D_Cross(tF32V3D vec1, tF32V3D vec2);
#ifdef BQSE_MASTER
tF32V3D tF32V3D_Make(tF32 x, tF32 y, tF32 z)
{
	tF32V3D vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;
}
tF32V3D tF32V3D_Zero(tNone)
{
	tF32V3D vec;
	vec.x = 0.0F;
	vec.y = 0.0F;
	vec.z = 0.0F;
	return vec;
}
tF32V3D tF32V3D_Add(tF32V3D vec1, tF32V3D vec2)
{
	tF32V3D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return vec;
}
tF32V3D tF32V3D_Sub(tF32V3D vec1, tF32V3D vec2)
{
	tF32V3D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return vec;
}
tF32V3D tF32V3D_Mul(tF32V3D vec, tF32 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	vec.z *= mod;
	return vec;
}
tF32V3D tF32V3D_Div(tF32V3D vec, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32V3D_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	vec.x /= mod;
	vec.y /= mod;
	vec.z /= mod;
	return vec;
}
tBln tF32V3D_Div_safe(tF32V3D *vec, tF32 mod)
{
	if (mod == 0.0F) return True;
	vec->x /= mod;
	vec->y /= mod;
	vec->z /= mod;
	return False;
}
tF32 tF32V3D_Dot(tF32V3D vec1, tF32V3D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}
tBln tF32V3D_Eq(tF32V3D vec1, tF32V3D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z);
}
tBln tF32V3D_Nearby(tF32V3D vec1, tF32V3D vec2, tF32 eps)
{
	return (tF32_Abs(vec1.x - vec2.x) <= eps) && (tF32_Abs(vec1.y - vec2.y) <= eps) && (tF32_Abs(vec1.z - vec2.z) <= eps);
}
tF32 tF32V3D_LngSq(tF32V3D vec)
{
	return tF32V3D_Dot(vec, vec);
}
tF32 tF32V3D_Lng(tF32V3D vec)
{
	return tF32_Sqrt(tF32V3D_LngSq(vec));
}
tF32V3D tF32V3D_Norm(tF32V3D vec)
{
	tF32 lng = tF32V3D_Lng(vec);
#ifndef BQSE_DEBUG
	if (lng == 0.0F) return tF32V3D_Zero();
#else
	Assertion(len != 0.0F);
#endif
	return tF32V3D_Div(vec, lng);
}
tBln tF32V3D_Norm_safe(tF32V3D *vec)
{
	return tF32V3D_Div_safe(vec, tF32V3D_Lng(*vec));
}
tF32V3D tF32V3D_FastNorm(tF32V3D vec)
{
	tF32 lngSq = tF32V3D_LngSq(vec);
#ifndef BQSE_DEBUG
	if (lngSq == 0.0F) return tF32V3D_Zero();
#else
	Assertion(lngSq != 0.0F);
#endif
	return tF32V3D_Mul(vec, tF32_InvSqrt(lngSq));
}
tBln tF32V3D_FastNorm_safe(tF32V3D *vec)
{
	tF32 lngSq = tF32V3D_LngSq(*vec);
	if (lngSq == 0.0F) return True;
	tF32V3D_Mul(*vec, tF32_InvSqrt(lngSq));
	return False;
}
tF32 tF32V3D_DistSq(tF32V3D vec1, tF32V3D vec2)
{
	return tF32V3D_LngSq(tF32V3D_Sub(vec1, vec2));
}
tF32 tF32V3D_Dist(tF32V3D vec1, tF32V3D vec2)
{
	return tF32V3D_Lng(tF32V3D_Sub(vec1, vec2));
}
tF32V3D tF32V3D_Lerp(tF32V3D vec1, tF32V3D vec2, tF32 stp)
{
	tF32V3D vec;
	vec.x = vec1.x + (vec2.x - vec1.x) * stp;
	vec.y = vec1.y + (vec2.y - vec1.y) * stp;
	vec.z = vec1.z + (vec2.z - vec1.z) * stp;
	return vec;
}
tF32V3D tF32V3D_Cross(tF32V3D vec1, tF32V3D vec2)
{
	tF32V3D vec;
	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return vec;
}
#endif
typedef union { struct { tF32 x, y, z, w; }; tF32 v[4]; } tF32V4D;
tF32V4D tF32V4D_Make(tF32 x, tF32 y, tF32 z, tF32 w);
tF32V4D tF32V4D_Zero(tNone);
tF32V4D tF32V4D_Add(tF32V4D vec1, tF32V4D vec2);
tF32V4D tF32V4D_Sub(tF32V4D vec1, tF32V4D vec2);
tF32V4D tF32V4D_Mul(tF32V4D vec, tF32 mod);
/*Warn: Silently returns `tF32V4D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V4D tF32V4D_Div(tF32V4D vec, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32V4D_Div_safe(tF32V4D *vec, tF32 mod);
tF32 tF32V4D_Dot(tF32V4D vec1, tF32V4D vec2);
tBln tF32V4D_Eq(tF32V4D vec1, tF32V4D vec2);
tBln tF32V4D_Nearby(tF32V4D vec1, tF32V4D vec2, tF32 eps);
tF32 tF32V4D_LngSq(tF32V4D vec);
tF32 tF32V4D_Lng(tF32V4D vec);
/*Warn: Silently returns `tF32V4D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V4D tF32V4D_Norm(tF32V4D vec);
/*Note: Returns `False` on success.*/
tBln tF32V4D_Norm_safe(tF32V4D *vec);
/*Warn: Silently returns `tF32V4D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32V4D tF32V4D_FastNorm(tF32V4D vec);
/*Note: Returns `False` on success.*/
tBln tF32V4D_FastNorm_safe(tF32V4D *vec);
tF32 tF32V4D_DistSq(tF32V4D vec1, tF32V4D vec2);
tF32 tF32V4D_Dist(tF32V4D vec1, tF32V4D vec2);
tF32V4D tF32V4D_Lerp(tF32V4D vec1, tF32V4D vec2, tF32 stp);
#ifdef BQSE_MASTER
tF32V4D tF32V4D_Make(tF32 x, tF32 y, tF32 z, tF32 w)
{
	tF32V4D vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return vec;
}
tF32V4D tF32V4D_Zero(tNone)
{
	tF32V4D vec;
	vec.x = 0.0F;
	vec.y = 0.0F;
	vec.z = 0.0F;
	vec.w = 0.0F;
	return vec;
}
tF32V4D tF32V4D_Add(tF32V4D vec1, tF32V4D vec2)
{
	tF32V4D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	vec.w = vec1.w + vec2.w;
	return vec;
}
tF32V4D tF32V4D_Sub(tF32V4D vec1, tF32V4D vec2)
{
	tF32V4D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	vec.w = vec1.w - vec2.w;
	return vec;
}
tF32V4D tF32V4D_Mul(tF32V4D vec, tF32 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	vec.z *= mod;
	vec.w *= mod;
	return vec;
}
tF32V4D tF32V4D_Div(tF32V4D vec, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32V4D_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	vec.x /= mod;
	vec.y /= mod;
	vec.z /= mod;
	vec.w /= mod;
	return vec;
}
tBln tF32V4D_Div_safe(tF32V4D *vec, tF32 mod)
{
	if (mod == 0.0F) return True;
	vec->x /= mod;
	vec->y /= mod;
	vec->z /= mod;
	vec->w /= mod;
	return False;
}
tF32 tF32V4D_Dot(tF32V4D vec1, tF32V4D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}
tBln tF32V4D_Eq(tF32V4D vec1, tF32V4D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z) && (vec1.w == vec2.w);
}
tBln tF32V4D_Nearby(tF32V4D vec1, tF32V4D vec2, tF32 eps)
{
	return (tF32_Abs(vec1.x - vec2.x) <= eps) && (tF32_Abs(vec1.y - vec2.y) <= eps) && (tF32_Abs(vec1.z - vec2.z) <= eps) && (tF32_Abs(vec1.w - vec2.w) <= eps);
}
tF32 tF32V4D_LngSq(tF32V4D vec)
{
	return tF32V4D_Dot(vec, vec);
}
tF32 tF32V4D_Lng(tF32V4D vec)
{
	return tF32_Sqrt(tF32V4D_LngSq(vec));
}
tF32V4D tF32V4D_Norm(tF32V4D vec)
{
	tF32 lng = tF32V4D_Lng(vec);
#ifndef BQSE_DEBUG
	if (lng == 0.0F) return tF32V4D_Zero();
#else
	Assertion(len != 0.0F);
#endif
	return tF32V4D_Div(vec, lng);
}
tBln tF32V4D_Norm_safe(tF32V4D *vec)
{
	return tF32V4D_Div_safe(vec, tF32V4D_Lng(*vec));
}
tF32V4D tF32V4D_FastNorm(tF32V4D vec)
{
	tF32 lngSq = tF32V4D_LngSq(vec);
#ifndef BQSE_DEBUG
	if (lngSq == 0.0F) return tF32V4D_Zero();
#else
	Assertion(lngSq != 0.0F);
#endif
	return tF32V4D_Mul(vec, tF32_InvSqrt(lngSq));
}
tBln tF32V4D_FastNorm_safe(tF32V4D *vec)
{
	tF32 lngSq = tF32V4D_LngSq(*vec);
	if (lngSq == 0.0F) return True;
	tF32V4D_Mul(*vec, tF32_InvSqrt(lngSq));
	return False;
}
tF32 tF32V4D_DistSq(tF32V4D vec1, tF32V4D vec2)
{
	return tF32V4D_LngSq(tF32V4D_Sub(vec1, vec2));
}
tF32 tF32V4D_Dist(tF32V4D vec1, tF32V4D vec2)
{
	return tF32V4D_Lng(tF32V4D_Sub(vec1, vec2));
}
tF32V4D tF32V4D_Lerp(tF32V4D vec1, tF32V4D vec2, tF32 stp)
{
	tF32V4D vec;
	vec.x = vec1.x + (vec2.x - vec1.x) * stp;
	vec.y = vec1.y + (vec2.y - vec1.y) * stp;
	vec.z = vec1.z + (vec2.z - vec1.z) * stp;
	vec.w = vec1.w + (vec2.w - vec1.w) * stp;
	return vec;
}
#endif
typedef union { struct { tF64 x, y; }; tF64 v[2]; } tF64V2D;
tF64V2D tF64V2D_Make(tF64 x, tF64 y);
tF64V2D tF64V2D_Zero(tNone);
tF64V2D tF64V2D_Add(tF64V2D vec1, tF64V2D vec2);
tF64V2D tF64V2D_Sub(tF64V2D vec1, tF64V2D vec2);
tF64V2D tF64V2D_Mul(tF64V2D vec, tF64 mod);
/*Warn: Silently returns `tF64V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V2D tF64V2D_Div(tF64V2D vec, tF64 mod);
/*Note: Returns `False` on success.*/
tBln tF64V2D_Div_safe(tF64V2D *vec, tF64 mod);
tF64 tF64V2D_Dot(tF64V2D vec1, tF64V2D vec2);
tBln tF64V2D_Eq(tF64V2D vec1, tF64V2D vec2);
tBln tF64V2D_Nearby(tF64V2D vec1, tF64V2D vec2, tF64 eps);
tF64 tF64V2D_LngSq(tF64V2D vec);
tF64 tF64V2D_Lng(tF64V2D vec);
/*Warn: Silently returns `tF64V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V2D tF64V2D_Norm(tF64V2D vec);
/*Note: Returns `False` on success.*/
tBln tF64V2D_Norm_safe(tF64V2D *vec);
/*Warn: Silently returns `tF64V2D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V2D tF64V2D_FastNorm(tF64V2D vec);
/*Note: Returns `False` on success.*/
tBln tF64V2D_FastNorm_safe(tF64V2D *vec);
tF64 tF64V2D_DistSq(tF64V2D vec1, tF64V2D vec2);
tF64 tF64V2D_Dist(tF64V2D vec1, tF64V2D vec2);
tF64V2D tF64V2D_Lerp(tF64V2D vec1, tF64V2D vec2, tF64 stp);
#ifdef BQSE_MASTER
tF64V2D tF64V2D_Make(tF64 x, tF64 y)
{
	tF64V2D vec;
	vec.x = x;
	vec.y = y;
	return vec;
}
tF64V2D tF64V2D_Zero(tNone)
{
	tF64V2D vec;
	vec.x = 0.0;
	vec.y = 0.0;
	return vec;
}
tF64V2D tF64V2D_Add(tF64V2D vec1, tF64V2D vec2)
{
	tF64V2D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	return vec;
}
tF64V2D tF64V2D_Sub(tF64V2D vec1, tF64V2D vec2)
{
	tF64V2D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	return vec;
}
tF64V2D tF64V2D_Mul(tF64V2D vec, tF64 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	return vec;
}
tF64V2D tF64V2D_Div(tF64V2D vec, tF64 mod)
{
	if (mod == 0.0) return tF64V2D_Zero();
	vec.x /= mod;
	vec.y /= mod;
	return vec;
}
tBln tF64V2D_Div_safe(tF64V2D *vec, tF64 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0) return True;
#else
	Assertion(mod != 0.0);
#endif
	vec->x /= mod;
	vec->y /= mod;
	return False;
}
tF64 tF64V2D_Dot(tF64V2D vec1, tF64V2D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}
tBln tF64V2D_Eq(tF64V2D vec1, tF64V2D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y);
}
tBln tF64V2D_Nearby(tF64V2D vec1, tF64V2D vec2, tF64 eps)
{
	return (tF64_Abs(vec1.x - vec2.x) <= eps) && (tF64_Abs(vec1.y - vec2.y) <= eps);
}
tF64 tF64V2D_LngSq(tF64V2D vec)
{
	return tF64V2D_Dot(vec, vec);
}
tF64 tF64V2D_Lng(tF64V2D vec)
{
	return tF64_Sqrt(tF64V2D_LngSq(vec));
}
tF64V2D tF64V2D_Norm(tF64V2D vec)
{
	tF64 lng = tF64V2D_Lng(vec);
#ifndef BQSE_DEBUG
	if (lng == 0.0) return tF64V2D_Zero();
#else
	Assertion(len != 0.0);
#endif
	return tF64V2D_Div(vec, lng);
}
tBln tF64V2D_Norm_safe(tF64V2D *vec)
{
	return tF64V2D_Div_safe(vec, tF64V2D_Lng(*vec));
}
tF64V2D tF64V2D_FastNorm(tF64V2D vec)
{
	tF64 lngSq = tF64V2D_LngSq(vec);
#ifndef BQSE_DEBUG
	if (lngSq == 0.0) return tF64V2D_Zero();
#else
	Assertion(lngSq != 0.0);
#endif
	return tF64V2D_Mul(vec, tF64_InvSqrt(lngSq));
}
tBln tF64V2D_FastNorm_safe(tF64V2D *vec)
{
	tF64 lngSq = tF64V2D_LngSq(*vec);
	if (lngSq == 0.0) return True;
	tF64V2D_Mul(*vec, tF64_InvSqrt(lngSq));
	return False;
}
tF64 tF64V2D_DistSq(tF64V2D vec1, tF64V2D vec2)
{
	return tF64V2D_LngSq(tF64V2D_Sub(vec1, vec2));
}
tF64 tF64V2D_Dist(tF64V2D vec1, tF64V2D vec2)
{
	return tF64V2D_Lng(tF64V2D_Sub(vec1, vec2));
}
tF64V2D tF64V2D_Lerp(tF64V2D vec1, tF64V2D vec2, tF64 stp)
{
	tF64V2D vec;
	vec.x = vec1.x + (vec2.x - vec1.x) * stp;
	vec.y = vec1.y + (vec2.y - vec1.y) * stp;
	return vec;
}
#endif
typedef union { struct { tF64 x, y, z; }; tF64 v[3]; } tF64V3D;
tF64V3D tF64V3D_Make(tF64 x, tF64 y, tF64 z);
tF64V3D tF64V3D_Zero(tNone);
tF64V3D tF64V3D_Add(tF64V3D vec1, tF64V3D vec2);
tF64V3D tF64V3D_Sub(tF64V3D vec1, tF64V3D vec2);
tF64V3D tF64V3D_Mul(tF64V3D vec, tF64 mod);
/*Warn: Silently returns `tF64V3D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V3D tF64V3D_Div(tF64V3D vec, tF64 mod);
/*Note: Returns `False` on success.*/
tBln tF64V3D_Div_safe(tF64V3D *vec, tF64 mod);
tF64 tF64V3D_Dot(tF64V3D vec1, tF64V3D vec2);
tBln tF64V3D_Eq(tF64V3D vec1, tF64V3D vec2);
tBln tF64V3D_Nearby(tF64V3D vec1, tF64V3D vec2, tF64 eps);
tF64 tF64V3D_LngSq(tF64V3D vec);
tF64 tF64V3D_Lng(tF64V3D vec);
/*Warn: Silently returns `tF64V3D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V3D tF64V3D_Norm(tF64V3D vec);
/*Note: Returns `False` on success.*/
tBln tF64V3D_Norm_safe(tF64V3D *vec);
/*Warn: Silently returns `tF64V3D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V3D tF64V3D_FastNorm(tF64V3D vec);
/*Note: Returns `False` on success.*/
tBln tF64V3D_FastNorm_safe(tF64V3D *vec);
tF64 tF64V3D_DistSq(tF64V3D vec1, tF64V3D vec2);
tF64 tF64V3D_Dist(tF64V3D vec1, tF64V3D vec2);
tF64V3D tF64V3D_Lerp(tF64V3D vec1, tF64V3D vec2, tF64 stp);
tF64V3D tF64V3D_Cross(tF64V3D vec1, tF64V3D vec2);
#ifdef BQSE_MASTER
tF64V3D tF64V3D_Make(tF64 x, tF64 y, tF64 z)
{
	tF64V3D vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;
}
tF64V3D tF64V3D_Zero(tNone)
{
	tF64V3D vec;
	vec.x = 0.0;
	vec.y = 0.0;
	vec.z = 0.0;
	return vec;
}
tF64V3D tF64V3D_Add(tF64V3D vec1, tF64V3D vec2)
{
	tF64V3D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return vec;
}
tF64V3D tF64V3D_Sub(tF64V3D vec1, tF64V3D vec2)
{
	tF64V3D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return vec;
}
tF64V3D tF64V3D_Mul(tF64V3D vec, tF64 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	vec.z *= mod;
	return vec;
}
tF64V3D tF64V3D_Div(tF64V3D vec, tF64 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0) return tF64V3D_Zero();
#else
	Assertion(mod != 0.0);
#endif
	vec.x /= mod;
	vec.y /= mod;
	vec.z /= mod;
	return vec;
}
tBln tF64V3D_Div_safe(tF64V3D *vec, tF64 mod)
{
	if (mod == 0.0) return True;
	vec->x /= mod;
	vec->y /= mod;
	vec->z /= mod;
	return False;
}
tF64 tF64V3D_Dot(tF64V3D vec1, tF64V3D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}
tBln tF64V3D_Eq(tF64V3D vec1, tF64V3D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z);
}
tBln tF64V3D_Nearby(tF64V3D vec1, tF64V3D vec2, tF64 eps)
{
	return (tF64_Abs(vec1.x - vec2.x) <= eps) && (tF64_Abs(vec1.y - vec2.y) <= eps) && (tF64_Abs(vec1.z - vec2.z) <= eps);
}
tF64 tF64V3D_LngSq(tF64V3D vec)
{
	return tF64V3D_Dot(vec, vec);
}
tF64 tF64V3D_Lng(tF64V3D vec)
{
	return tF64_Sqrt(tF64V3D_LngSq(vec));
}
tF64V3D tF64V3D_Norm(tF64V3D vec)
{
	tF64 lng = tF64V3D_Lng(vec);
#ifndef BQSE_DEBUG
	if (lng == 0.0) return tF64V3D_Zero();
#else
	Assertion(len != 0.0);
#endif
	return tF64V3D_Div(vec, lng);
}
tBln tF64V3D_Norm_safe(tF64V3D *vec)
{
	return tF64V3D_Div_safe(vec, tF64V3D_Lng(*vec));
}
tF64V3D tF64V3D_FastNorm(tF64V3D vec)
{
	tF64 lngSq = tF64V3D_LngSq(vec);
#ifndef BQSE_DEBUG
	if (lngSq == 0.0) return tF64V3D_Zero();
#else
	Assertion(lngSq != 0.0);
#endif
	return tF64V3D_Mul(vec, tF64_InvSqrt(lngSq));
}
tBln tF64V3D_FastNorm_safe(tF64V3D *vec)
{
	tF64 lngSq = tF64V3D_LngSq(*vec);
	if (lngSq == 0.0) return True;
	tF64V3D_Mul(*vec, tF64_InvSqrt(lngSq));
	return False;
}
tF64 tF64V3D_DistSq(tF64V3D vec1, tF64V3D vec2)
{
	return tF64V3D_LngSq(tF64V3D_Sub(vec1, vec2));
}
tF64 tF64V3D_Dist(tF64V3D vec1, tF64V3D vec2)
{
	return tF64V3D_Lng(tF64V3D_Sub(vec1, vec2));
}
tF64V3D tF64V3D_Lerp(tF64V3D vec1, tF64V3D vec2, tF64 stp)
{
	tF64V3D vec;
	vec.x = vec1.x + (vec2.x - vec1.x) * stp;
	vec.y = vec1.y + (vec2.y - vec1.y) * stp;
	vec.z = vec1.z + (vec2.z - vec1.z) * stp;
	return vec;
}
tF64V3D tF64V3D_Cross(tF64V3D vec1, tF64V3D vec2)
{
	tF64V3D vec;
	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return vec;
}
#endif
typedef union { struct { tF64 x, y, z, w; }; tF64 v[4]; } tF64V4D;
tF64V4D tF64V4D_Make(tF64 x, tF64 y, tF64 z, tF64 w);
tF64V4D tF64V4D_Zero(tNone);
tF64V4D tF64V4D_Add(tF64V4D vec1, tF64V4D vec2);
tF64V4D tF64V4D_Sub(tF64V4D vec1, tF64V4D vec2);
tF64V4D tF64V4D_Mul(tF64V4D vec, tF64 mod);
/*Warn: Silently returns `tF64V4D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V4D tF64V4D_Div(tF64V4D vec, tF64 mod);
/*Note: Returns `False` on success.*/
tBln tF64V4D_Div_safe(tF64V4D *vec, tF64 mod);
tF64 tF64V4D_Dot(tF64V4D vec1, tF64V4D vec2);
tBln tF64V4D_Eq(tF64V4D vec1, tF64V4D vec2);
tBln tF64V4D_Nearby(tF64V4D vec1, tF64V4D vec2, tF64 eps);
tF64 tF64V4D_LngSq(tF64V4D vec);
tF64 tF64V4D_Lng(tF64V4D vec);
/*Warn: Silently returns `tF64V4D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V4D tF64V4D_Norm(tF64V4D vec);
/*Note: Returns `False` on success.*/
tBln tF64V4D_Norm_safe(tF64V4D *vec);
/*Warn: Silently returns `tF64V4D_Zero` on failure when BQSE_DEBUG is not defined.*/
tF64V4D tF64V4D_FastNorm(tF64V4D vec);
/*Note: Returns `False` on success.*/
tBln tF64V4D_FastNorm_safe(tF64V4D *vec);
tF64 tF64V4D_DistSq(tF64V4D vec1, tF64V4D vec2);
tF64 tF64V4D_Dist(tF64V4D vec1, tF64V4D vec2);
tF64V4D tF64V4D_Lerp(tF64V4D vec1, tF64V4D vec2, tF64 stp);
#ifdef BQSE_MASTER
tF64V4D tF64V4D_Make(tF64 x, tF64 y, tF64 z, tF64 w)
{
	tF64V4D vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return vec;
}
tF64V4D tF64V4D_Zero(tNone)
{
	tF64V4D vec;
	vec.x = 0.0;
	vec.y = 0.0;
	vec.z = 0.0;
	vec.w = 0.0;
	return vec;
}
tF64V4D tF64V4D_Add(tF64V4D vec1, tF64V4D vec2)
{
	tF64V4D vec;
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	vec.w = vec1.w + vec2.w;
	return vec;
}
tF64V4D tF64V4D_Sub(tF64V4D vec1, tF64V4D vec2)
{
	tF64V4D vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	vec.w = vec1.w - vec2.w;
	return vec;
}
tF64V4D tF64V4D_Mul(tF64V4D vec, tF64 mod)
{
	vec.x *= mod;
	vec.y *= mod;
	vec.z *= mod;
	vec.w *= mod;
	return vec;
}
tF64V4D tF64V4D_Div(tF64V4D vec, tF64 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0) return tF64V4D_Zero();
#else
	Assertion(mod != 0.0);
#endif
	vec.x /= mod;
	vec.y /= mod;
	vec.z /= mod;
	vec.w /= mod;
	return vec;
}
tBln tF64V4D_Div_safe(tF64V4D *vec, tF64 mod)
{
	if (mod == 0.0) return True;
	vec->x /= mod;
	vec->y /= mod;
	vec->z /= mod;
	vec->w /= mod;
	return False;
}
tF64 tF64V4D_Dot(tF64V4D vec1, tF64V4D vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}
tBln tF64V4D_Eq(tF64V4D vec1, tF64V4D vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z) && (vec1.w == vec2.w);
}
tBln tF64V4D_Nearby(tF64V4D vec1, tF64V4D vec2, tF64 eps)
{
	return (tF64_Abs(vec1.x - vec2.x) <= eps) && (tF64_Abs(vec1.y - vec2.y) <= eps) && (tF64_Abs(vec1.z - vec2.z) <= eps) && (tF64_Abs(vec1.w - vec2.w) <= eps);
}
tF64 tF64V4D_LngSq(tF64V4D vec)
{
	return tF64V4D_Dot(vec, vec);
}
tF64 tF64V4D_Lng(tF64V4D vec)
{
	return tF64_Sqrt(tF64V4D_LngSq(vec));
}
tF64V4D tF64V4D_Norm(tF64V4D vec)
{
	tF64 lng = tF64V4D_Lng(vec);
#ifndef BQSE_DEBUG
	if (lng == 0.0) return tF64V4D_Zero();
#else
	Assertion(len != 0.0);
#endif
	return tF64V4D_Div(vec, lng);
}
tBln tF64V4D_Norm_safe(tF64V4D *vec)
{
	return tF64V4D_Div_safe(vec, tF64V4D_Lng(*vec));
}
tF64V4D tF64V4D_FastNorm(tF64V4D vec)
{
	tF64 lngSq = tF64V4D_LngSq(vec);
#ifndef BQSE_DEBUG
	if (lngSq == 0.0) return tF64V4D_Zero();
#else
	Assertion(lngSq != 0.0);
#endif
	return tF64V4D_Mul(vec, tF64_InvSqrt(lngSq));
}
tBln tF64V4D_FastNorm_safe(tF64V4D *vec)
{
	tF64 lngSq = tF64V4D_LngSq(*vec);
	if (lngSq == 0.0) return True;
	tF64V4D_Mul(*vec, tF64_InvSqrt(lngSq));
	return False;
}
tF64 tF64V4D_DistSq(tF64V4D vec1, tF64V4D vec2)
{
	return tF64V4D_LngSq(tF64V4D_Sub(vec1, vec2));
}
tF64 tF64V4D_Dist(tF64V4D vec1, tF64V4D vec2)
{
	return tF64V4D_Lng(tF64V4D_Sub(vec1, vec2));
}
tF64V4D tF64V4D_Lerp(tF64V4D vec1, tF64V4D vec2, tF64 stp)
{
	tF64V4D vec;
	vec.x = vec1.x + (vec2.x - vec1.x) * stp;
	vec.y = vec1.y + (vec2.y - vec1.y) * stp;
	vec.z = vec1.z + (vec2.z - vec1.z) * stp;
	vec.w = vec1.w + (vec2.w - vec1.w) * stp;
	return vec;
}
#endif
typedef union { struct { tF32 m00, m01; tF32 m10, m11; }; tF32 m[2][2]; tF32V2D row[2]; } tF32M2x2;
tF32M2x2 tF32M2x2_Make(tF32 m00, tF32 m01, tF32 m10, tF32 m11);
tF32M2x2 tF32M2x2_Zero(tNone);
tF32M2x2 tF32M2x2_Id(tNone);
tF32M2x2 tF32M2x2_Add(tF32M2x2 mat1, tF32M2x2 mat2);
tF32M2x2 tF32M2x2_Sub(tF32M2x2 mat1, tF32M2x2 mat2);
tF32M2x2 tF32M2x2_Mul(tF32M2x2 mat1, tF32M2x2 mat2);
tF32M2x2 tF32M2x2_MulFlt(tF32M2x2 mat, tF32 mod);
/*Warn: Silently returns `tF32M2x2_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M2x2 tF32M2x2_DivFlt(tF32M2x2 mat, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M2x2_DivFlt_safe(tF32M2x2 *mat, tF32 mod);
tBln tF32M2x2_Eq(tF32M2x2 mat1, tF32M2x2 mat2);
tBln tF32M2x2_Nearby(tF32M2x2 mat1, tF32M2x2 mat2, tF32 eps);
tF32V2D tF32M2x2_MulVec(tF32M2x2 mat, tF32V2D vec);
tF32M2x2 tF32M2x2_Transp(tF32M2x2 mat);
tF32 tF32M2x2_Det(tF32M2x2 mat);
tF32M2x2 tF32M2x2_Cofact(tF32M2x2 mat);
tF32M2x2 tF32M2x2_Adj(tF32M2x2 mat);
/*Warn: Silently returns `tF32M2x2_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M2x2 tF32M2x2_Inv(tF32M2x2 mat);
/*Note: Returns `False` on success.*/
tBln tF32M2x2_Inv_safe(tF32M2x2 *mat);
tF32M2x2 tF32M2x2_Rot(tF32 ang);
tF32M2x2 tF32M2x2_Scale(tF32 x, tF32 y);
tF32 tF32M2x2_Trace(tF32M2x2 mat);
#ifdef BQSE_MASTER
tF32M2x2 tF32M2x2_Make(tF32 m00, tF32 m01, tF32 m10, tF32 m11)
{
	tF32M2x2 mat;
	mat.m00 = m00;
	mat.m01 = m01;
	mat.m10 = m10;
	mat.m11 = m11;
	return mat;
}
tF32M2x2 tF32M2x2_Zero(tNone)
{
	tF32M2x2 mat;
	mat.m00 = 0.0F;
	mat.m01 = 0.0F;
	mat.m10 = 0.0F;
	mat.m11 = 0.0F;
	return mat;
}
tF32M2x2 tF32M2x2_Id(tNone)
{
	tF32M2x2 mat;
	mat.m00 = 1.0F;
	mat.m01 = 0.0F;
	mat.m10 = 0.0F;
	mat.m11 = 1.0F;
	return mat;
}
tF32M2x2 tF32M2x2_Add(tF32M2x2 mat1, tF32M2x2 mat2)
{
	mat1.m00 += mat2.m00;
	mat1.m01 += mat2.m01;
	mat1.m10 += mat2.m10;
	mat1.m11 += mat2.m11;
	return mat1;
}
tF32M2x2 tF32M2x2_Sub(tF32M2x2 mat1, tF32M2x2 mat2)
{
	mat1.m00 -= mat2.m00;
	mat1.m01 -= mat2.m01;
	mat1.m10 -= mat2.m10;
	mat1.m11 -= mat2.m11;
	return mat1;
}
tF32M2x2 tF32M2x2_Mul(tF32M2x2 mat1, tF32M2x2 mat2)
{
	tF32M2x2 mat;
	mat.m00 = mat1.m00 * mat2.m00 + mat1.m01 * mat2.m10;
	mat.m01 = mat1.m00 * mat2.m01 + mat1.m01 * mat2.m11;
	mat.m10 = mat1.m10 * mat2.m00 + mat1.m11 * mat2.m10;
	mat.m11 = mat1.m10 * mat2.m01 + mat1.m11 * mat2.m11;
	return mat;
}
tF32M2x2 tF32M2x2_MulFlt(tF32M2x2 mat, tF32 mod)
{
	mat.m00 *= mod;
	mat.m01 *= mod;
	mat.m10 *= mod;
	mat.m11 *= mod;
	return mat;
}
tF32M2x2 tF32M2x2_DivFlt(tF32M2x2 mat, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M2x2_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mat.m00 /= mod;
	mat.m01 /= mod;
	mat.m10 /= mod;
	mat.m11 /= mod;
	return mat;
}
tBln tF32M2x2_DivFlt_safe(tF32M2x2 *mat, tF32 mod)
{
	if (mod == 0.0F) return True;
	mat->m00 /= mod;
	mat->m01 /= mod;
	mat->m10 /= mod;
	mat->m11 /= mod;
	return False;
}
tBln tF32M2x2_Eq(tF32M2x2 mat1, tF32M2x2 mat2)
{
	return (mat1.m00 == mat2.m00) && (mat1.m01 == mat2.m01) && (mat1.m10 == mat2.m10) && (mat1.m11 == mat2.m11);
}
tBln tF32M2x2_Nearby(tF32M2x2 mat1, tF32M2x2 mat2, tF32 eps)
{
	return (tF32_Abs(mat1.m00 - mat2.m00) <= eps) && (tF32_Abs(mat1.m01 - mat2.m01) <= eps) && (tF32_Abs(mat1.m10 - mat2.m10) <= eps) && (tF32_Abs(mat1.m11 - mat2.m11) <= eps);
}
tF32V2D tF32M2x2_MulVec(tF32M2x2 mat, tF32V2D vec)
{
	tF32V2D res;
	res.x = mat.m00 * vec.x + mat.m01 * vec.y;
	res.y = mat.m10 * vec.x + mat.m11 * vec.y;
	return res;
}
tF32M2x2 tF32M2x2_Transp(tF32M2x2 mat)
{
	tF32 tmp = mat.m01;
	mat.m01 = mat.m10;
	mat.m10 = tmp;
	return mat;
}
tF32 tF32M2x2_Det(tF32M2x2 mat)
{
	return (mat.m00 * mat.m11) - (mat.m01 * mat.m10);
}
tF32M2x2 tF32M2x2_Cofact(tF32M2x2 mat)
{
	tF32 tmp = mat.m00;
	mat.m00 = mat.m11;
	mat.m11 = tmp;
	mat.m01 = tF32_Neg(mat.m10);
	mat.m10 = tF32_Neg(mat.m01);
	return mat;
}
tF32M2x2 tF32M2x2_Adj(tF32M2x2 mat)
{
	tF32 tmp = mat.m00;
	mat.m00 = mat.m11;
	mat.m11 = tmp;
	mat.m01 = tF32_Neg(mat.m01);
	mat.m10 = tF32_Neg(mat.m10);
	return mat;
}
tF32M2x2 tF32M2x2_Inv(tF32M2x2 mat)
{
	tF32 det = tF32M2x2_Det(mat);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M2x2_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M2x2_DivFlt(tF32M2x2_Adj(mat), det);
}
tBln tF32M2x2_Inv_safe(tF32M2x2 *mat)
{
	tF32 det = tF32M2x2_Det(*mat);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mat = tF32M2x2_DivFlt(tF32M2x2_Adj(*mat), det);
	return False;
}
tF32M2x2 tF32M2x2_Rot(tF32 ang)
{
	tF32M2x2 mat;
	mat.m00 = mat.m11 = tF32_Cosine(ang);
	mat.m10 = tF32_Sine(ang);
	mat.m01 = tF32_Neg(mat.m10);
	return mat;
}
tF32M2x2 tF32M2x2_Scale(tF32 x, tF32 y)
{
	tF32M2x2 mat;
	mat.m00 = x;
	mat.m11 = y;
	mat.m01 = mat.m10 = 0.0F;
	return mat;
}
tF32 tF32M2x2_Trace(tF32M2x2 mat)
{
	return mat.m00 + mat.m11;
}
#endif
typedef union { struct { tF32 m00, m01, m02; tF32 m10, m11, m12; tF32 m20, m21, m22; }; tF32 m[3][3]; tF32V3D row[3]; } tF32M3x3;
tF32M3x3 tF32M3x3_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m10, tF32 m11, tF32 m12, tF32 m20, tF32 m21, tF32 m22);
tF32M3x3 tF32M3x3_Zero(tNone);
tF32M3x3 tF32M3x3_Id(tNone);
tF32M3x3 tF32M3x3_Add(tF32M3x3 mat1, tF32M3x3 mat2);
tF32M3x3 tF32M3x3_Sub(tF32M3x3 mat1, tF32M3x3 mat2);
tF32M3x3 tF32M3x3_Mul(tF32M3x3 mat1, tF32M3x3 mat2);
tF32M3x3 tF32M3x3_MulFlt(tF32M3x3 mat, tF32 mod);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M3x3_DivFlt(tF32M3x3 mat, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M3x3_DivFlt_safe(tF32M3x3 *mat, tF32 mod);
tBln tF32M3x3_Eq(tF32M3x3 mat1, tF32M3x3 mat2);
tBln tF32M3x3_Nearby(tF32M3x3 mat1, tF32M3x3 mat2, tF32 eps);
tF32V3D tF32M3x3_MulVec(tF32M3x3 mat, tF32V3D vec);
tF32M3x3 tF32M3x3_Transp(tF32M3x3 mat);
tF32 tF32M3x3_Det(tF32M3x3 mat);
tF32M3x3 tF32M3x3_Cofact(tF32M3x3 mat);
tF32M3x3 tF32M3x3_Adj(tF32M3x3 mat);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M3x3_Inv(tF32M3x3 mat);
/*Note: Returns `False` on success.*/
tBln tF32M3x3_Inv_safe(tF32M3x3 *mat);
tF32M3x3 tF32M3x3_Transl(tF32 x, tF32 y);
tF32M3x3 tF32M3x3_Scale(tF32 x, tF32 y);
tF32M3x3 tF32M3x3_Rot(tF32 ang);
tF32 tF32M3x3_Trace(tF32M3x3 mat);
tF32V2D tF32M3x3_TransfPoint(tF32M3x3 mat, tF32V2D vec);
tF32V2D tF32M3x3_TransfDir(tF32M3x3 mat, tF32V2D vec);
#ifdef BQSE_MASTER
tF32M3x3 tF32M3x3_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m10, tF32 m11, tF32 m12, tF32 m20, tF32 m21, tF32 m22)
{
	tF32M3x3 mat;
	mat.m00 = m00;
	mat.m01 = m01;
	mat.m02 = m02;
	mat.m10 = m10;
	mat.m11 = m11;
	mat.m12 = m12;
	mat.m20 = m20;
	mat.m21 = m21;
	mat.m22 = m22;
	return mat;
}
tF32M3x3 tF32M3x3_Zero(tNone)
{
	tF32M3x3 mat;
	mat.m00 = mat.m01 = mat.m02 = mat.m10 = mat.m11 = mat.m12 = mat.m20 = mat.m21 = mat.m22 = 0.0F;
	return mat;
}
tF32M3x3 tF32M3x3_Id(tNone)
{
	tF32M3x3 mat;
	mat.m01 = mat.m02 = mat.m10 = mat.m12 = mat.m20 = mat.m21 = 0.0F;
	mat.m00 = mat.m11 = mat.m22 = 1.0F;
	return mat;
}
tF32M3x3 tF32M3x3_Add(tF32M3x3 mat1, tF32M3x3 mat2)
{
	mat1.m00 += mat2.m00;
	mat1.m01 += mat2.m01;
	mat1.m02 += mat2.m02;
	mat1.m10 += mat2.m10;
	mat1.m11 += mat2.m11;
	mat1.m12 += mat2.m12;
	mat1.m20 += mat2.m20;
	mat1.m21 += mat2.m21;
	mat1.m22 += mat2.m22;
	return mat1;
}
tF32M3x3 tF32M3x3_Sub(tF32M3x3 mat1, tF32M3x3 mat2)
{
	mat1.m00 -= mat2.m00;
	mat1.m01 -= mat2.m01;
	mat1.m02 -= mat2.m02;
	mat1.m10 -= mat2.m10;
	mat1.m11 -= mat2.m11;
	mat1.m12 -= mat2.m12;
	mat1.m20 -= mat2.m20;
	mat1.m21 -= mat2.m21;
	mat1.m22 -= mat2.m22;
	return mat1;
}
tF32M3x3 tF32M3x3_Mul(tF32M3x3 mat1, tF32M3x3 mat2)
{
	tF32M3x3 res;
	res.m00 = (mat1.m00 * mat2.m00) + (mat1.m01 * mat2.m10) + (mat1.m02 * mat2.m20);
	res.m01 = (mat1.m00 * mat2.m01) + (mat1.m01 * mat2.m11) + (mat1.m02 * mat2.m21);
	res.m02 = (mat1.m00 * mat2.m02) + (mat1.m01 * mat2.m12) + (mat1.m02 * mat2.m22);
	res.m10 = (mat1.m10 * mat2.m00) + (mat1.m11 * mat2.m10) + (mat1.m12 * mat2.m20);
	res.m11 = (mat1.m10 * mat2.m01) + (mat1.m11 * mat2.m11) + (mat1.m12 * mat2.m21);
	res.m12 = (mat1.m10 * mat2.m02) + (mat1.m11 * mat2.m12) + (mat1.m12 * mat2.m22);
	res.m20 = (mat1.m20 * mat2.m00) + (mat1.m21 * mat2.m10) + (mat1.m22 * mat2.m20);
	res.m21 = (mat1.m20 * mat2.m01) + (mat1.m21 * mat2.m11) + (mat1.m22 * mat2.m21);
	res.m22 = (mat1.m20 * mat2.m02) + (mat1.m21 * mat2.m12) + (mat1.m22 * mat2.m22);
	return res;
}
tF32M3x3 tF32M3x3_MulFlt(tF32M3x3 mat, tF32 mod)
{
	mat.m00 *= mod;
	mat.m01 *= mod;
	mat.m02 *= mod;
	mat.m10 *= mod;
	mat.m11 *= mod;
	mat.m12 *= mod;
	mat.m20 *= mod;
	mat.m21 *= mod;
	mat.m22 *= mod;
	return mat;
}
tF32M3x3 tF32M3x3_DivFlt(tF32M3x3 mat, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M3x3_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mat.m00 /= mod;
	mat.m01 /= mod;
	mat.m02 /= mod;
	mat.m10 /= mod;
	mat.m11 /= mod;
	mat.m12 /= mod;
	mat.m20 /= mod;
	mat.m21 /= mod;
	mat.m22 /= mod;
	return mat;
}
tBln tF32M3x3_DivFlt_safe(tF32M3x3 *mat, tF32 mod)
{
	if (mod == 0.0F) return True;
	mat->m00 /= mod;
	mat->m01 /= mod;
	mat->m02 /= mod;
	mat->m10 /= mod;
	mat->m11 /= mod;
	mat->m12 /= mod;
	mat->m20 /= mod;
	mat->m21 /= mod;
	mat->m22 /= mod;
	return False;
}
tBln tF32M3x3_Eq(tF32M3x3 mat1, tF32M3x3 mat2)
{
	return (mat1.m00 == mat2.m00) && (mat1.m01 == mat2.m01) && (mat1.m02 == mat2.m02) && (mat1.m10 == mat2.m10) && (mat1.m11 == mat2.m11) && (mat1.m12 == mat2.m12) && (mat1.m20 == mat2.m20) && (mat1.m21 == mat2.m21) && (mat1.m22 == mat2.m22);
}
tBln tF32M3x3_Nearby(tF32M3x3 mat1, tF32M3x3 mat2, tF32 eps)
{
	return (tF32_Abs(mat1.m00 - mat2.m00) <= eps) && (tF32_Abs(mat1.m01 - mat2.m01) <= eps) && (tF32_Abs(mat1.m02 - mat2.m02) <= eps) && (tF32_Abs(mat1.m10 - mat2.m10) <= eps) && (tF32_Abs(mat1.m11 - mat2.m11) <= eps) && (tF32_Abs(mat1.m12 - mat2.m12) <= eps) && (tF32_Abs(mat1.m20 - mat2.m20) <= eps) && (tF32_Abs(mat1.m21 - mat2.m21) <= eps) && (tF32_Abs(mat1.m22 - mat2.m22) <= eps);
}
tF32V3D tF32M3x3_MulVec(tF32M3x3 mat, tF32V3D vec)
{
	tF32V3D res;
	res.x = (mat.m00 * vec.x) + (mat.m01 * vec.y) + (mat.m02 * vec.z);
	res.y = (mat.m10 * vec.x) + (mat.m11 * vec.y) + (mat.m12 * vec.z);
	res.z = (mat.m20 * vec.x) + (mat.m21 * vec.y) + (mat.m22 * vec.z);
	return res;
}
tF32M3x3 tF32M3x3_Transp(tF32M3x3 mat)
{
	tF32 tmp = mat.m01;
	mat.m01 = mat.m10;
	mat.m10 = tmp;
	tmp = mat.m02;
	mat.m02 = mat.m20;
	mat.m20 = tmp;
	tmp = mat.m12;
	mat.m12 = mat.m21;
	mat.m21 = tmp;
	return mat;
}
tF32 tF32M3x3_Det(tF32M3x3 mat)
{
	return (mat.m00 * ((mat.m11 * mat.m22) - (mat.m12 * mat.m21))) - (mat.m01 * ((mat.m10 * mat.m22) - (mat.m12 * mat.m20))) + (mat.m02 * ((mat.m10 * mat.m21) - (mat.m11 * mat.m20)));
}
tF32M3x3 tF32M3x3_Cofact(tF32M3x3 mat)
{
	tF32M3x3 cof;
	cof.m00 = mat.m11 * mat.m22 - mat.m12 * mat.m21;
	cof.m01 = tF32_Neg(mat.m10 * mat.m22 - mat.m12 * mat.m20);
	cof.m02 = mat.m10 * mat.m21 - mat.m11 * mat.m20;
	cof.m10 = tF32_Neg(mat.m01 * mat.m22 - mat.m02 * mat.m21);
	cof.m11 = mat.m00 * mat.m22 - mat.m02 * mat.m20;
	cof.m12 = tF32_Neg(mat.m00 * mat.m21 - mat.m01 * mat.m20);
	cof.m20 = mat.m01 * mat.m12 - mat.m02 * mat.m11;
	cof.m21 = tF32_Neg(mat.m00 * mat.m12 - mat.m02 * mat.m10);
	cof.m22 = mat.m00 * mat.m11 - mat.m01 * mat.m10;
	return cof;
}
tF32M3x3 tF32M3x3_Adj(tF32M3x3 mat)
{
	return tF32M3x3_Transp(tF32M3x3_Cofact(mat));
}
tF32M3x3 tF32M3x3_Inv(tF32M3x3 mat)
{
	tF32 det = tF32M3x3_Det(mat);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M3x3_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M3x3_DivFlt(tF32M3x3_Adj(mat), det);
}
tBln tF32M3x3_Inv_safe(tF32M3x3 *mat)
{
	tF32 det = tF32M3x3_Det(*mat);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mat = tF32M3x3_DivFlt(tF32M3x3_Adj(*mat), det);
	return False;
}
tF32M3x3 tF32M3x3_Transl(tF32 x, tF32 y)
{
	tF32M3x3 mat = tF32M3x3_Id();
	mat.m02 = x;
	mat.m12 = y;
	return mat;
}
tF32M3x3 tF32M3x3_Scale(tF32 x, tF32 y)
{
	tF32M3x3 mat = tF32M3x3_Id();
	mat.m00 = x;
	mat.m11 = y;
	return mat;
}
tF32M3x3 tF32M3x3_Rot(tF32 ang)
{
	tF32M3x3 mat = tF32M3x3_Id();
	mat.m00 = mat.m11 = tF32_Cosine(ang);
	mat.m10 = tF32_Sine(ang);
	mat.m01 = tF32_Neg(mat.m10);
	return mat;
}
tF32 tF32M3x3_Trace(tF32M3x3 mat)
{
	return mat.m00 + mat.m11 + mat.m22;
}
tF32V2D tF32M3x3_TransfPoint(tF32M3x3 mat, tF32V2D vec)
{
	tF32V2D res;
	res.x = mat.m00 * vec.x + mat.m01 * vec.y + mat.m02;
	res.y = mat.m10 * vec.x + mat.m11 * vec.y + mat.m12;
	return res;
}
tF32V2D tF32M3x3_TransfDir(tF32M3x3 mat, tF32V2D vec)
{
	tF32V2D res;
	res.x = mat.m00 * vec.x + mat.m01 * vec.y;
	res.y = mat.m10 * vec.x + mat.m11 * vec.y;
	return res;
}
#endif
typedef union { struct { tF32 m00, m01, m02, m03; tF32 m10, m11, m12, m13; tF32 m20, m21, m22, m23; tF32 m30, m31, m32, m33; }; tF32 m[4][4]; tF32V4D row[4]; } tF32M4x4;
tF32M4x4 tF32M4x4_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m03, tF32 m10, tF32 m11, tF32 m12, tF32 m13, tF32 m20, tF32 m21, tF32 m22, tF32 m23, tF32 m30, tF32 m31, tF32 m32, tF32 m33);
tF32M4x4 tF32M4x4_Zero(tNone);
tF32M4x4 tF32M4x4_Id(tNone);
tF32M4x4 tF32M4x4_Add(tF32M4x4 mat1, tF32M4x4 mat2);
tF32M4x4 tF32M4x4_Sub(tF32M4x4 mat1, tF32M4x4 mat2);
tF32M4x4 tF32M4x4_Mul(tF32M4x4 mat1, tF32M4x4 mat2);
tF32M4x4 tF32M4x4_MulFlt(tF32M4x4 mat, tF32 mod);
/*Warn: Silently returns `tF32M4x4_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M4x4 tF32M4x4_DivFlt(tF32M4x4 mat, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_DivFlt_safe(tF32M4x4 *mat, tF32 mod);
tBln tF32M4x4_Eq(tF32M4x4 mat1, tF32M4x4 mat2);
tBln tF32M4x4_Nearby(tF32M4x4 mat1, tF32M4x4 mat2, tF32 eps);
tF32V4D tF32M4x4_MulVec(tF32M4x4 mat, tF32V4D vec);
tF32M4x4 tF32M4x4_Transp(tF32M4x4 mat);
tF32 tF32M4x4_Det(tF32M4x4 mat);
// TODO: Do the rest of these
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M4x4_Minor(tF32M4x4 mat, tU8 row, tU8 col);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_Minor_s(tF32M3x3 *out, tF32M4x4 mat, tU8 row, tU8 col);
tF32M4x4 tF32M4x4_Cofact(tF32M4x4 mat);
tF32M4x4 tF32M4x4_Adj(tF32M4x4 mat);
/*Warn: Silently returns `tF32M4x4_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M4x4 tF32M4x4_Inv(tF32M4x4 mat);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_Inv_safe(tF32M4x4 *mat);
tF32M4x4 tF32M4x4_Transl(tF32 x, tF32 y, tF32 z);
tF32M4x4 tF32M4x4_Scale(tF32 x, tF32 y, tF32 z);
tF32M4x4 tF32M4x4_RotX(tF32 ang);
tF32M4x4 tF32M4x4_RotY(tF32 ang);
tF32M4x4 tF32M4x4_RotZ(tF32 ang);
tF32M4x4 tF32M4x4_Persp(tF32 fov, tF32 aspect, tF32 near, tF32 far);
tF32M4x4 tF32M4x4_Ortho(tF32 left, tF32 right, tF32 bottom, tF32 top, tF32 near, tF32 far);
tF32 tF32M4x4_Trace(tF32M4x4 mat);
tF32M4x4 tF32M4x4_InvAffine(tF32M4x4 mat);
tF32M4x4 tF32M4x4_RotAxis(tF32V3D axis, tF32 ang);
tF32V3D tF32M4x4_TransfPoint(tF32M4x4 mat, tF32V3D vec);
tF32V3D tF32M4x4_TransfDir(tF32M4x4 mat, tF32V3D vec);
#ifdef BQSE_MASTER
tF32M4x4 tF32M4x4_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m03, tF32 m10, tF32 m11, tF32 m12, tF32 m13, tF32 m20, tF32 m21, tF32 m22, tF32 m23, tF32 m30, tF32 m31, tF32 m32, tF32 m33)
{
	tF32M4x4 mat;
	mat.m00 = m00;
	mat.m01 = m01;
	mat.m02 = m02;
	mat.m03 = m03;
	mat.m10 = m10;
	mat.m11 = m11;
	mat.m12 = m12;
	mat.m13 = m13;
	mat.m20 = m20;
	mat.m21 = m21;
	mat.m22 = m22;
	mat.m23 = m23;
	mat.m30 = m30;
	mat.m31 = m31;
	mat.m32 = m32;
	mat.m33 = m33;
	return mat;
}
tF32M4x4 tF32M4x4_Zero(tNone)
{
	tF32M4x4 mat;
	mat.m00 = mat.m01 = mat.m02 = mat.m03 = mat.m10 = mat.m11 = mat.m12 = mat.m13 = mat.m20 = mat.m21 = mat.m22 = mat.m23 = mat.m30 = mat.m31 = mat.m32 = mat.m33 = 0.0F;
	return mat;
}
tF32M4x4 tF32M4x4_Id(tNone)
{
	tF32M4x4 mat;
	mat.m01 = mat.m02 = mat.m03 = mat.m10 = mat.m12 = mat.m13 = mat.m20 = mat.m21 = mat.m23 = mat.m30 = mat.m31 = mat.m32 = 0.0F;
	mat.m00 = mat.m11 = mat.m22 = mat.m33 = 1.0F;
	return mat;
}
tF32M4x4 tF32M4x4_Add(tF32M4x4 mat1, tF32M4x4 mat2)
{
	mat1.m00 += mat2.m00;
	mat1.m01 += mat2.m01;
	mat1.m02 += mat2.m02;
	mat1.m03 += mat2.m03;
	mat1.m10 += mat2.m10;
	mat1.m11 += mat2.m11;
	mat1.m12 += mat2.m12;
	mat1.m13 += mat2.m13;
	mat1.m20 += mat2.m20;
	mat1.m21 += mat2.m21;
	mat1.m22 += mat2.m22;
	mat1.m23 += mat2.m23;
	mat1.m30 += mat2.m30;
	mat1.m31 += mat2.m31;
	mat1.m32 += mat2.m32;
	mat1.m33 += mat2.m33;
	return mat1;
}
tF32M4x4 tF32M4x4_Sub(tF32M4x4 mat1, tF32M4x4 mat2)
{
	mat1.m00 -= mat2.m00;
	mat1.m01 -= mat2.m01;
	mat1.m02 -= mat2.m02;
	mat1.m03 -= mat2.m03;
	mat1.m10 -= mat2.m10;
	mat1.m11 -= mat2.m11;
	mat1.m12 -= mat2.m12;
	mat1.m13 -= mat2.m13;
	mat1.m20 -= mat2.m20;
	mat1.m21 -= mat2.m21;
	mat1.m22 -= mat2.m22;
	mat1.m23 -= mat2.m23;
	mat1.m30 -= mat2.m30;
	mat1.m31 -= mat2.m31;
	mat1.m32 -= mat2.m32;
	mat1.m33 -= mat2.m33;
	return mat1;
}
tF32M4x4 tF32M4x4_Mul(tF32M4x4 mat1, tF32M4x4 mat2)
{
	tF32M4x4 res;
	res.m00 = (mat1.m00 * mat2.m00) + (mat1.m01 * mat2.m10) + (mat1.m02 * mat2.m20) + (mat1.m03 * mat2.m30);
	res.m01 = (mat1.m00 * mat2.m01) + (mat1.m01 * mat2.m11) + (mat1.m02 * mat2.m21) + (mat1.m03 * mat2.m31);
	res.m02 = (mat1.m00 * mat2.m02) + (mat1.m01 * mat2.m12) + (mat1.m02 * mat2.m22) + (mat1.m03 * mat2.m32);
	res.m03 = (mat1.m00 * mat2.m03) + (mat1.m01 * mat2.m13) + (mat1.m02 * mat2.m23) + (mat1.m03 * mat2.m33);
	res.m10 = (mat1.m10 * mat2.m00) + (mat1.m11 * mat2.m10) + (mat1.m12 * mat2.m20) + (mat1.m13 * mat2.m30);
	res.m11 = (mat1.m10 * mat2.m01) + (mat1.m11 * mat2.m11) + (mat1.m12 * mat2.m21) + (mat1.m13 * mat2.m31);
	res.m12 = (mat1.m10 * mat2.m02) + (mat1.m11 * mat2.m12) + (mat1.m12 * mat2.m22) + (mat1.m13 * mat2.m32);
	res.m13 = (mat1.m10 * mat2.m03) + (mat1.m11 * mat2.m13) + (mat1.m12 * mat2.m23) + (mat1.m13 * mat2.m33);
	res.m20 = (mat1.m20 * mat2.m00) + (mat1.m21 * mat2.m10) + (mat1.m22 * mat2.m20) + (mat1.m23 * mat2.m30);
	res.m21 = (mat1.m20 * mat2.m01) + (mat1.m21 * mat2.m11) + (mat1.m22 * mat2.m21) + (mat1.m23 * mat2.m31);
	res.m22 = (mat1.m20 * mat2.m02) + (mat1.m21 * mat2.m12) + (mat1.m22 * mat2.m22) + (mat1.m23 * mat2.m32);
	res.m23 = (mat1.m20 * mat2.m03) + (mat1.m21 * mat2.m13) + (mat1.m22 * mat2.m23) + (mat1.m23 * mat2.m33);
	res.m30 = (mat1.m30 * mat2.m00) + (mat1.m31 * mat2.m10) + (mat1.m32 * mat2.m20) + (mat1.m33 * mat2.m30);
	res.m31 = (mat1.m30 * mat2.m01) + (mat1.m31 * mat2.m11) + (mat1.m32 * mat2.m21) + (mat1.m33 * mat2.m31);
	res.m32 = (mat1.m30 * mat2.m02) + (mat1.m31 * mat2.m12) + (mat1.m32 * mat2.m22) + (mat1.m33 * mat2.m32);
	res.m33 = (mat1.m30 * mat2.m03) + (mat1.m31 * mat2.m13) + (mat1.m32 * mat2.m23) + (mat1.m33 * mat2.m33);
	return res;
}
tF32M4x4 tF32M4x4_MulFlt(tF32M4x4 mat, tF32 mod)
{
	mat.m00 *= mod;
	mat.m01 *= mod;
	mat.m02 *= mod;
	mat.m03 *= mod;
	mat.m10 *= mod;
	mat.m11 *= mod;
	mat.m12 *= mod;
	mat.m13 *= mod;
	mat.m20 *= mod;
	mat.m21 *= mod;
	mat.m22 *= mod;
	mat.m23 *= mod;
	mat.m30 *= mod;
	mat.m31 *= mod;
	mat.m32 *= mod;
	mat.m33 *= mod;
	return mat;
}
tF32M4x4 tF32M4x4_DivFlt(tF32M4x4 mat, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M4x4_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mat.m00 /= mod;
	mat.m01 /= mod;
	mat.m02 /= mod;
	mat.m03 /= mod;
	mat.m10 /= mod;
	mat.m11 /= mod;
	mat.m12 /= mod;
	mat.m13 /= mod;
	mat.m20 /= mod;
	mat.m21 /= mod;
	mat.m22 /= mod;
	mat.m23 /= mod;
	mat.m30 /= mod;
	mat.m31 /= mod;
	mat.m32 /= mod;
	mat.m33 /= mod;
	return mat;
}
tBln tF32M4x4_DivFlt_safe(tF32M4x4 *mat, tF32 mod)
{
	if (mod == 0.0F) return True;
	mat->m00 /= mod;
	mat->m01 /= mod;
	mat->m02 /= mod;
	mat->m03 /= mod;
	mat->m10 /= mod;
	mat->m11 /= mod;
	mat->m12 /= mod;
	mat->m13 /= mod;
	mat->m20 /= mod;
	mat->m21 /= mod;
	mat->m22 /= mod;
	mat->m23 /= mod;
	mat->m30 /= mod;
	mat->m31 /= mod;
	mat->m32 /= mod;
	mat->m33 /= mod;
	return False;
}
tBln tF32M4x4_Eq(tF32M4x4 mat1, tF32M4x4 mat2)
{
	return mat1.m00 == mat2.m00 && mat1.m01 == mat2.m01 && mat1.m02 == mat2.m02 && mat1.m03 == mat2.m03 && mat1.m10 == mat2.m10 && mat1.m11 == mat2.m11 && mat1.m12 == mat2.m12 && mat1.m13 == mat2.m13 && mat1.m20 == mat2.m20 && mat1.m21 == mat2.m21 && mat1.m22 == mat2.m22 && mat1.m23 == mat2.m23 && mat1.m30 == mat2.m30 && mat1.m31 == mat2.m31 && mat1.m32 == mat2.m32 && mat1.m33 == mat2.m33;
}
tBln tF32M4x4_Nearby(tF32M4x4 mat1, tF32M4x4 mat2, tF32 eps)
{
	return (tF32_Abs(mat1.m00 - mat2.m00) <= eps) && (tF32_Abs(mat1.m01 - mat2.m01) <= eps) && (tF32_Abs(mat1.m02 - mat2.m02) <= eps) && (tF32_Abs(mat1.m03 - mat2.m03) <= eps) && (tF32_Abs(mat1.m10 - mat2.m10) <= eps) && (tF32_Abs(mat1.m11 - mat2.m11) <= eps) && (tF32_Abs(mat1.m12 - mat2.m12) <= eps) && (tF32_Abs(mat1.m13 - mat2.m13) <= eps) && (tF32_Abs(mat1.m20 - mat2.m20) <= eps) && (tF32_Abs(mat1.m21 - mat2.m21) <= eps) && (tF32_Abs(mat1.m22 - mat2.m22) <= eps) && (tF32_Abs(mat1.m23 - mat2.m23) <= eps) && (tF32_Abs(mat1.m30 - mat2.m30) <= eps) && (tF32_Abs(mat1.m31 - mat2.m31) <= eps) && (tF32_Abs(mat1.m32 - mat2.m32) <= eps) && (tF32_Abs(mat1.m33 - mat2.m33) <= eps);
}
tF32V4D tF32M4x4_MulVec(tF32M4x4 mat, tF32V4D vec)
{
	tF32V4D res;
	res.x = (mat.m00 * vec.x) + (mat.m01 * vec.y) + (mat.m02 * vec.z) + (mat.m03 * vec.w);
	res.y = (mat.m10 * vec.x) + (mat.m11 * vec.y) + (mat.m12 * vec.z) + (mat.m13 * vec.w);
	res.z = (mat.m20 * vec.x) + (mat.m21 * vec.y) + (mat.m22 * vec.z) + (mat.m23 * vec.w);
	res.w = (mat.m30 * vec.x) + (mat.m31 * vec.y) + (mat.m32 * vec.z) + (mat.m33 * vec.w);
	return res;
}
tF32M4x4 tF32M4x4_Transp(tF32M4x4 mat)
{
	return tF32M4x4_Make(mat.m00, mat.m10, mat.m20, mat.m30, mat.m01, mat.m11, mat.m21, mat.m31, mat.m02, mat.m12, mat.m22, mat.m32, mat.m03, mat.m13, mat.m23, mat.m33);
}
tF32 tF32M4x4_Det(tF32M4x4 mat)
{
	return (mat.m00 * (tF32M3x3_Det(tF32M3x3_Make(mat.m11, mat.m12, mat.m13, mat.m21, mat.m22, mat.m23, mat.m31, mat.m32, mat.m33)))) - (mat.m01 * (tF32M3x3_Det(tF32M3x3_Make(mat.m10, mat.m12, mat.m13, mat.m20, mat.m22, mat.m23, mat.m30, mat.m32, mat.m33)))) + (mat.m02 * (tF32M3x3_Det(tF32M3x3_Make(mat.m10, mat.m11, mat.m13, mat.m20, mat.m21, mat.m23, mat.m30, mat.m31, mat.m33)))) - (mat.m03 * (tF32M3x3_Det(tF32M3x3_Make(mat.m10, mat.m11, mat.m12, mat.m20, mat.m21, mat.m22, mat.m30, mat.m31, mat.m32))));
}
tF32M3x3 tF32M4x4_Minor(tF32M4x4 mat, tU8 row, tU8 col)
{
#ifndef BQSE_DEBUG
	if (row >= 4U) return tF32M3x3_Zero();
	if (col >= 4U) return tF32M3x3_Zero();
#else
	Assertion(row < 4U);
	Assertion(col < 4U);
#endif
	tF32M3x3 minor;
	tU8 offsetI = 0U;
	for (tU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tU8 offsetJ = 0U;
		for (tU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			minor.m[idx][jdx] = mat.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return minor;
}
tBln tF32M4x4_Minor_s(tF32M3x3 *out, tF32M4x4 mat, tU8 row, tU8 col)
{
	if (row >= 4U) return True;
	if (col >= 4U) return True;
	tU8 offsetI = 0U;
	for (tU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tU8 offsetJ = 0U;
		for (tU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			out->m[idx][jdx] = mat.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return False;
}
tF32M4x4 tF32M4x4_Cofact(tF32M4x4 mat)
{
	tF32M4x4 cof;
	for (tU8 idx = 0U; idx < 4U; ++idx)
	{
		for (tU8 jdx = 0U; jdx < 4U; ++jdx)
		{
			cof.m[idx][jdx] = tF32M3x3_Det(tF32M4x4_Minor(mat, idx, jdx));
			if ((idx + jdx) & 1U) cof.m[idx][jdx] = tF32_Neg(cof.m[idx][jdx]);
		}
	}
	return cof;
}
tF32M4x4 tF32M4x4_Adj(tF32M4x4 mat)
{
	return tF32M4x4_Transp(tF32M4x4_Cofact(mat));
}
tF32M4x4 tF32M4x4_Inv(tF32M4x4 mat)
{
	tF32 det = tF32M4x4_Det(mat);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M4x4_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M4x4_DivFlt(tF32M4x4_Adj(mat), det);
}
tBln tF32M4x4_Inv_safe(tF32M4x4 *mat)
{
	tF32 det = tF32M4x4_Det(*mat);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mat = tF32M4x4_DivFlt(tF32M4x4_Adj(*mat), det);
	return False;
}
tF32M4x4 tF32M4x4_Transl(tF32 x, tF32 y, tF32 z)
{
	return tF32M4x4_Make(1.0F, 0.0F, 0.0F, x, 0.0F, 1.0F, 0.0F, y, 0.0F, 0.0F, 1.0F, z, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_Scale(tF32 x, tF32 y, tF32 z)
{
	return tF32M4x4_Make(x, 0.0F, 0.0F, 0.0F, 0.0F, y, 0.0F, 0.0F, 0.0F, 0.0F, z, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotX(tF32 ang)
{
	const tF32 tmp_c = tF32_Cos(ang);
	const tF32 tmp_s = tF32_Sin(ang);
	return tF32M4x4_Make(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, tmp_c, -tmp_s, 0.0F, 0.0F, tmp_s, tmp_c, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotY(tF32 ang)
{
	tF32 tmp_c = tF32_Cos(ang);
	tF32 tmp_s = tF32_Sin(ang);
	return tF32M4x4_Make(tmp_c, 0.0F, tmp_s, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -tmp_s, 0.0F, tmp_c, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotZ(tF32 ang)
{
	tF32 tmp_c = tF32_Cos(ang);
	tF32 tmp_s = tF32_Sin(ang);
	return tF32M4x4_Make(tmp_c, -tmp_s, 0.0F, 0.0F, tmp_s, tmp_c, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32 tF32M4x4_Trace(tF32M4x4 mat)
{
	return mat.m00 + mat.m11 + mat.m22 + mat.m33;
}
// TODO: tF32M4x4 function implementations.
#endif
typedef union { struct { tF64 m00, m01; tF64 m10, m11; }; tF64 m[2][2]; tF64V2D row[2]; } tF64M2x2;
// TODO: tF64M2x2 function declarations.
#ifdef BQSE_MASTER
// TODO: tF64M2x2 function implementations.
#endif
typedef union { struct { tF64 m00, m01, m02; tF64 m10, m11, m12; tF64 m20, m21, m22; }; tF64 m[3][3]; tF64V3D row[3]; } tF64M3x3;
// TODO: tF64M3x3 function declarations.
#ifdef BQSE_MASTER
// TODO: tF64M3x3 function implementations.
#endif
typedef union { struct { tF64 m00, m01, m02, m03; tF64 m10, m11, m12, m13; tF64 m20, m21, m22, m23; tF64 m30, m31, m32, m33; }; tF64 m[4][4]; tF64V4D row[4]; } tF64M4x4;
// TODO: tF64M4x4 function declarations.
#ifdef BQSE_MASTER
// TODO: tF64M4x4 function implementations.
#endif
// TODO: Quaternions
enum eAxis
{
	eAxis_X,
	eAxis_Y,
	eAxis_Z,
	eAxis_W
};
enum eCompiler
{
	eCompiler_None,
	eCompiler_MSVC,
	eCompiler_GNUC,
	eCompiler_Clang,
	eCompiler_COUNT
};
const tChr *BQSE_GetCompiler(enum eCompiler comp);
#ifdef BQSE_MASTER
const tChr *BQSE_GetCompiler(enum eCompiler comp)
{
	switch (comp)
	{
	case eCompiler_MSVC: return "Microsoft Visual C";
	case eCompiler_GNUC: return "GNU Compiler";
	case eCompiler_Clang: return "Clang/LLVM";
	default: return "Unknown";
	}
}
#endif
enum eOperatingSystem
{
	eOperatingSystem_None,
	eOperatingSystem_Windows,
	eOperatingSystem_Linux,
	eOperatingSystem_MacOS,
	eOperatingSystem_FreeBSD,
	eOperatingSystem_MSDOS,
	eOperatingSystem_Unix,
	eOperatingSystem_COUNT
};
const tChr *BQSE_GetOperatingSystem(enum eOperatingSystem os);
#ifdef BQSE_MASTER
const tChr *BQSE_GetOperatingSystem(enum eOperatingSystem os)
{
	switch (os)
	{
	case eOperatingSystem_Windows: return "Windows";
	case eOperatingSystem_Linux: return "Linux";
	case eOperatingSystem_MacOS: return "MacOS";
	case eOperatingSystem_FreeBSD: return "FreeBSD";
	case eOperatingSystem_MSDOS: return "MSDOS";
	case eOperatingSystem_Unix: return "Unix";
	default: return "Unknown";
	}
}
#endif
enum eArchitecture
{
	eArchitecture_None,
	eArchitecture_AMD64,
	eArchitecture_Intel86,
	eArchitecture_Arm64,
	eArchitecture_Arm,
	eArchitecture_COUNT
};
const tChr *BQSE_GetArchitecture(enum eArchitecture arch);
#ifdef BQSE_MASTER
const tChr *BQSE_GetArchitecture(enum eArchitecture arch)
{
	switch (arch)
	{
	case eArchitecture_AMD64: return "AMD64";
	case eArchitecture_Intel86: return "Intel86";
	case eArchitecture_Arm64: return "Arm64";
	case eArchitecture_Arm: return "Arm";
	default: return "Unknown";
	}
}
#endif
enum eMonth
{
	eMonth_Jan,
	eMonth_Feb,
	eMonth_Mar,
	eMonth_Apr,
	eMonth_May,
	eMonth_Jun,
	eMonth_Jul,
	eMonth_Aug,
	eMonth_Sep,
	eMonth_Oct,
	eMonth_Nov,
	eMonth_Dec
};
const tChr *BQSE_GetMonth(enum eMonth mon);
const tChr *BQSE_GetMonthFull(enum eMonth mon);
#ifdef BQSE_MASTER
const tChr *BQSE_GetMonth(enum eMonth mon)
{
	switch (mon)
	{
	case eMonth_Jan: return "Jan";
	case eMonth_Feb: return "Feb";
	case eMonth_Mar: return "Mar";
	case eMonth_Apr: return "Apr";
	case eMonth_May: return "May";
	case eMonth_Jun: return "Jun";
	case eMonth_Jul: return "Jul";
	case eMonth_Aug: return "Aug";
	case eMonth_Sep: return "Sep";
	case eMonth_Oct: return "Oct";
	case eMonth_Nov: return "Nov";
	case eMonth_Dec: return "Dec";
	default: return "Unknown";
	}
}
const tChr *BQSE_GetMonthFull(enum eMonth mon)
{
	switch (mon)
	{
	case eMonth_Jan: return "January";
	case eMonth_Feb: return "February";
	case eMonth_Mar: return "March";
	case eMonth_Apr: return "April";
	case eMonth_May: return "May";
	case eMonth_Jun: return "June";
	case eMonth_Jul: return "July";
	case eMonth_Aug: return "August";
	case eMonth_Sep: return "September";
	case eMonth_Oct: return "October";
	case eMonth_Nov: return "November";
	case eMonth_Dec: return "December";
	default: return "Unknown";
	}
}
#endif
enum eDay
{
	eDay_Sun,
	eDay_Mon,
	eDay_Tue,
	eDay_Wed,
	eDay_Thu,
	eDay_Fri,
	eDay_Sat
};
const tChr *BQSE_GetDay(enum eDay day);
const tChr *BQSE_GetDayFull(enum eDay day);
#ifdef BQSE_MASTER
const tChr *BQSE_GetDay(enum eDay day)
{
	switch (day)
	{
	case eDay_Sun: return "Sun";
	case eDay_Mon: return "Mon";
	case eDay_Tue: return "Tue";
	case eDay_Wed: return "Wed";
	case eDay_Thu: return "Thu";
	case eDay_Fri: return "Fri";
	case eDay_Sat: return "Sat";
	default: return "Unknown";
	}
}
const tChr *BQSE_GetDayFull(enum eDay day)
{
	switch (day)
	{
	case eDay_Sun: return "Sunday";
	case eDay_Mon: return "Monday";
	case eDay_Tue: return "Tuesday";
	case eDay_Wed: return "Wednesday";
	case eDay_Thu: return "Thursday";
	case eDay_Fri: return "Friday";
	case eDay_Sat: return "Saturday";
	default: return "Unknown";
	}
}
#endif
#endif//BQSELAYER_H