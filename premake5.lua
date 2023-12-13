project "Gemstone"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    architecture "x86_64"

	flags "MultiProcessorCompile"

    targetdir "%{wks.location}/build/bin/%{cfg.name}/%{prj.name}"
	objdir "%{wks.location}/build/obj/%{cfg.name}/%{prj.name}"

    defines { 
        "GLEW_STATIC",
        "GEM_ASSETS_STRING=\"assets\\\"",
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
		defines "GEM_DEBUG"
        runtime "Debug"
        symbols "On"
	filter "configurations:Release"
		defines "GEM_RELEASE"
        runtime "Release"
        optimize "On"
	filter {}

    includedirs {
        "include",
        "dependencies/GLEW/include",
        "dependencies/GLFW/include",
        "dependencies/ImGui/include/ImGui",
        "dependencies/ImGui/include/ImPlot",
        "dependencies/stb_image"
    }

    files {
        "src/**.cpp",
        "include/**.h"
    }

    links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui"
    }

    libdirs {
        "dependencies/GLFW/lib-vc2022",
        "dependencies/GLEW/lib/Release/x64"
    }

    include "dependencies/ImGui"
