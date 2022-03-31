workspace "DuskGameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}--%{cfg.system}--%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "DuskGameEngine/vendor/GLFW/include"

include "DuskGameEngine/vendor/GLFW/premake5.lua"

project "DuskGameEngine"
	location "DuskGameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dkpch.h"
	pchsource "DuskGameEngine/src/dkpch.cpp"

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
			"DK_PLATFORM_WINDOWS",
			"DK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "DK_DIST"
		symbols "On"

project "SandBox"
	location "SandBox"
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
		"DuskGameEngine/vendor/spdlog/include",
		"DuskGameEngine/src"
	}
	
	links
	{
		"DuskGameEngine"
	}

	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "DK_DIST"
		symbols "On"