workspace "rog"
	configurations { "Debug", "Release" }
	architecture "x86_64"
	
	location "build"

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"
		optimize "Off"

	filter "configurations:Release"
		symbols "Off"
		optimize "Full"

	filter {}

project "rog"
	language "C++"

	location "%{wks.location}/%{prj.name}"
	targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"

	defines "BEARLIBTERMINAL_STATIC_BUILD"

	kind "WindowedApp"
	entrypoint "mainCRTStartup"

	vpaths
	{
		["Header Files/*"] = { "%{prj.name}/include/**.h" },
		["Source Files/*"] = { "%{prj.name}/source/**.cpp" }
	}
	files { "%{prj.name}/include/**.h", "%{prj.name}/source/**.cpp" }

	filter "system:windows"
		vpaths
		{
			["Resources/*"] = { "%{prj.name}/resource/**.ico", "%{prj.name}/resource/%{prj.name}.rc" }
		}
		files { "%{prj.name}/resource/**.ico", "%{prj.name}/resource/%{prj.name}.rc" }
	filter {}

	includedirs
	{
		"%{prj.name}/include",
		"depend/bearlibterminal/include"
	}

	libdirs
	{
		"depend/bearlibterminal/lib"
	}

	links { "bearlibterminal", "freetype2", "picopng" }

	filter "system:windows"
		defines { "_WIN32" }
		links { "winmm", "opengl32", "gdi32" }

	filter "system:linux"
		links { "pthread", "GL" }

	filter{ }