project "Gemstone"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

	flags "MultiProcessorCompile"

    pchheader "pch.h"
    pchsource "src/pch.cpp"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

    defines { 
        "GLEW_STATIC",
        "RUBY_ASSETS=\"..\\\\Gemstone\\\\assets\"",
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
		defines "GEMSTONE_DEBUG"
	filter "configurations:Release"
		defines "GEMSTONE_RELEASE"
	filter {}

    includedirs {
        "src",
        "../vendor/GLEW/include",
        "../vendor/GLFW/include",
        "../vendor/ImGui/src",
        "../vendor/stb_image"
    }

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
