#pragma once

/*
Macros for OS
see https://sourceforge.net/p/predef/wiki/OperatingSystems/
*/

#if defined _WIN32
#define OS_WIN32
#elif defined __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_OSX != 0
#define OS_MACOS
#elif TARGET_OS_IOS != 0
#define OS_IOS
#endif
#elif defined __linux__
#define OS_LINUX
#elif defined __ANDROID__
#define OS_ANDROID
#endif

/*
Macros for CPU architecture
see https://sourceforge.net/p/predef/wiki/Architectures/
*/

#if defined _M_ARM || defined __arm__
#define ARCH_ARM
#elif defined _M_X64 || defined __amd64__
#define ARCH_AMD64
#elif defined _M_IX86 || defined _X86_ || defined __X86__ || defined __i386__
#define ARCH_IA32
#endif

/*
Macros for calling conventions
see https://clang.llvm.org/docs/AttributeReference.html#calling-conventions
( Note that AMD64 (x86_64) and ARM have a single unified calling convention
  see https://eli.thegreenplace.net/2011/09/06/stack-frame-layout-on-x86-64/#id8 )
*/

#ifdef ARCH_IA32
#if defined _MSC_VER
#define API
#define API_CDECL __cdecl
#define API_STDCALL __stdcall
#define API_THISCALL __thiscall
#elif defined __clang__ or defined __GNUC__
#define API
#define API_CDECL __attribute__((cdecl))
#define API_STDCALL __attribute__((stdcall))
#define API_THISCALL    __attribute__((thiscall)
#endif
#else
#define API
#define API_CDECL
#define API_STDCALL
#define API_THISCALL
#endif

#if defined _MSC_VER && !defined BUILD_STATIC_LIB
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
