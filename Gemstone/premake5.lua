project "Gemstone"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

	flags "MultiProcessorCompile"

    pchheader "pch.h"
    pchsource "src/pch.cpp"

	targetdir "build/bin/%{cfg.name}"
	objdir "build/obj/%{cfg.name}"

    defines { 
        "GLEW_STATIC",
        "GEM_ASSETS_STRING=\"assets\\\"",
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
		defines "GEM_DEBUG"
        symbols "On"
	filter "configurations:Release"
		defines "GEM_RELEASE"
        optimize "On"
	filter {}

    includedirs {
        "src",
        "../vendor/GLEW/include",
        "../vendor/GLFW/include",
        "../vendor/ImGui/ImGuiSrc",
        "../vendor/ImGui/ImPlotSrc",
        "../vendor/stb_image"
    }

    include "../vendor/ImGui"

    files {
        "src/**.cpp",
        "src/**.h",
    }

    links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui"
    }

    libdirs {
        "../vendor/GLFW/lib-vc2022",
        "../vendor/GLEW/lib/Release/x64"
    }
