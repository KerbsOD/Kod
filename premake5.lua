workspace "Kod"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["GLFW"] = "Kod/vendor/GLFW/include"
include "Kod/vendor/GLFW"

project "Kod"
	
	location "Kod"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kodpch.h"
	pchsource "Kod/src/kodpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{	
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}



	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KOD_PLATFORM_WINDOWS",
			"KOD_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "KOD_DEBUG"
		symbols "On"

	filter "configurations:Release"
	defines "KOD_RELEASE"
	optimize "On"

	filter "configurations:Dist"
	defines "KOD_DIST"
	optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kod/vendor/spdlog/include",
		"Kod/src"
	}

	links
	{
		"Kod"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KOD_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "KOD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KOD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KOD_DIST"
		optimize "On"