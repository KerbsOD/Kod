#pragma once

#ifdef KOD_PLATFORM_WINDOWS
	
	#ifdef KOD_BUILD_DLL
		#define KOD_API __declspec(dllexport)	
	#else 
		#define KOD_API __declspec(dllimport)
	#endif  

#endif
