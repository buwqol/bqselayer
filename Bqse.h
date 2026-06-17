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
#elif defined(_MSC_VER)
#define COMP_MSVC 1
#elif defined(__GNUC__)
#define COMP_GNUC 1
#else
#error "Unknown compiler"
#endif

// Operating system
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define OS_FreeBSD 1
#elif defined(__linux__) || defined(__gnu_linux__) || defined(linux) || defined(__linux)
#define OS_Linux 1
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#define OS_Windows 1
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define OS_MacOS 1
#elif defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#define OS_MSDOS 1
#elif defined(__unix__) || defined(__unix)
#define OS_Unix 1
#else
#error "Unknown operating system"
#endif

// Architecture
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#define ARCH_AMD64 1
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(__i386) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#define ARCH_Intel86 1
#elif defined(__aarch64__)
#define ARCH_Arm64 1
#elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
#define ARCH_Arm 1
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
#define tNone void
#define tGen void
typedef tNone tFnc(tNone);
typedef tFnc *tFncPtr;
typedef tGen *tPtr;
typedef char tChr;
typedef signed char tS8;
typedef char Bqse_StaticAssert_tS8[(sizeof(tS8) == 1U) ? 1U : -1];
#define tS8_Max 127
#define tS8_Min (-128)
typedef unsigned char tU8;
typedef char Bqse_StaticAssert_tU8[(sizeof(tU8) == 1U) ? 1U : -1];
#define tU8_Max 255
#define tU8_Min 0
typedef signed short tS16;
typedef char Bqse_StaticAssert_tS16[(sizeof(tS16) == 2U) ? 1U : -1];
#define tS16_Max 32767
#define tS16_Min (-32768)
typedef unsigned short tU16;
typedef char Bqse_StaticAssert_tU16[(sizeof(tU16) == 2U) ? 1U : -1];
#define tU16_Max 65535
#define tU16_Min 0
typedef signed int tS32;
typedef char Bqse_StaticAssert_tS32[(sizeof(tS32) == 4U) ? 1U : -1];
#define tS32_Max 2147483647
#define tS32_Min (-2147483647-1)
typedef unsigned int tU32;
typedef char Bqse_StaticAssert_tU32[(sizeof(tU32) == 4U) ? 1U : -1];
#define tU32_Max 4294967295U
#define tU32_Min 0U
typedef signed long long tS64;
typedef char Bqse_StaticAssert_tS64[(sizeof(tS64) == 8U) ? 1U : -1];
#define tS64_Max 9223372036854775807LL
#define tS64_Min (-9223372036854775807LL-1)
typedef unsigned long long tU64;
typedef char Bqse_StaticAssert_tU64[(sizeof(tU64) == 8U) ? 1U : -1];
#define tU64_Max 18446744073709551615LLU
#define tU64_Min 0LLU
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
#include <math.h> // TODO: Move away from this eventually
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
tF32 tF32_Sqrt(tF32 num)
{
	return sqrtf(num);
}
tF32 tF32_InvSqrt(tF32 num) // Fast inverse sqrt from Quake 3
{
	static const tF32 threeHalfs = 1.5F;
	tF32Bits number;
	number.flt = num;
	tF32 halfNum = number.flt * 0.5F;
	number.raw = 0X5F3759DFU - (number.raw >> 1U);
	number.flt = number.flt * (threeHalfs - (halfNum * number.flt * number.flt));
	// number.flt = number.flt * (threeHalf - (halfNum * number.flt * number.flt)); // I'll enable this if I need the precision
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
	// number.dbl = number.dbl * (threeHalfs - (halfNum * number.dbl * number.dbl));
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
#define ForceDump() (*(voltaile int *)0U = 0U)
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

#endif//BQSELAYER_H