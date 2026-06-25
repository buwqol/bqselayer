#ifndef BQSELAYER_CTXCRACK_H
#define BQSELAYER_CTXCRACK_H
/*Language*/
#ifdef __cplusplus
#define LANG_Cpp 1
#else
#define LANG_C 1
#endif
/*Language version*/
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
/*Compiler*/
enum eCompiler
{
	eCompiler_None,
	eCompiler_MSC,
	eCompiler_GNUC,
	eCompiler_LLVM,
	eCompiler_COUNT
};
#if defined(__LLVM__)
#define COMP_LLVM 1
#define COMP_Curr eCompiler_LLVM
#elif defined(_MSC_VER)
#define COMP_MSC 1
#define COMP_Curr eCompiler_MSC
#elif defined(__GNUC__)
#define COMP_GNUC 1
#define COMP_Curr eCompiler_GNUC
#else
#error "Unknown compiler"
#endif
/*Operating system*/
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
/*Architecture*/
enum eArchitecture
{
	eArchitecture_None,
	eArchitecture_AMD64,
	eArchitecture_Intel86,
	eArchitecture_Arm64,
	eArchitecture_Arm,
	eArchitecture_COUNT
};
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
/*Bitness*/
#if defined(ARCH_AMD64) || defined(ARCH_Arm64)
#define ARCH_Bitness 64
#else
#define ARCH_Bitness 32
#endif
/*Linking*/
#if defined(LANG_Cpp)
#define LINK_C extern "C"
#define LINK_C_Begin extern "C" {
#define LINK_C_End }
#else
#define LINK_C
#define LINK_C_Begin
#define LINK_C_End
#endif
/*Function prefixes*/
#if defined(COMP_MSC)
#define FORCEINLINE __forceinline
#define BQSE_NOINLINE __declspec(noinline)
#define BQSE_DLLEXPORT __declspec(dllexport)
#define BQSE_DLLIMPORT __declspec(dllimport)
#define BQSE_RESTRICT __restrict
#elif defined(COMP_GNUC) || defined(COMP_LLVM)
#define FORCEINLINE inline __attribute__((always_inline))
#define BQSE_NOINLINE __attribute__((noinline))
#define BQSE_DLLEXPORT __attribute__((visibility("default")))
#define BQSE_DLLIMPORT
#define BQSE_RESTRICT __restrict__
#else
#define FORCEINLINE inline
#define BQSE_NOINLINE
#define BQSE_DLLEXPORT
#define BQSE_DLLIMPORT
#define BQSE_RESTRICT
#endif
#if defined(COMP_GNUC) || defined(COMP_LLVM)
#define BQSE_LIKELY(Cnd)   __builtin_expect(!!(Cnd), 1)
#define BQSE_UNLIKELY(Cnd) __builtin_expect(!!(Cnd), 0)
#else
#define BQSE_LIKELY(Cnd)   (Cnd)
#define BQSE_UNLIKELY(Cnd) (Cnd)
#endif
#endif/*BQSELAYER_CTXCRACK_H*/