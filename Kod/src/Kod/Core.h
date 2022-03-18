#pragma once

#ifdef KOD_PLATFORM_WINDOWS
	
	#ifdef KOD_BUILD_DLL
		#define KOD_API __declspec(dllexport)	
	#else 
		#define KOD_API __declspec(dllimport)
	#endif  

#endif

#ifdef KOD_ENABLE_ASSERTS
	#define KOD_CLIENT_ASSERT(x, ...) {if(!(x)) { KOD_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define KOD_CORE_ASSERT(x, ...) {if(!(x)) { KOD_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define KOD_CLIENT_ASSERT(x, ...)
	#define KOD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
