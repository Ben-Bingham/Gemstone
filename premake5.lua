workspace "Gemstone-Engine"
    configurations { "Debug", "Release" }
    platforms "x64"

    filter "platforms:x64"
        architecture "x64"
    filter {}

    filter "configurations:Debug"
        symbols "On"
    filter {}

    filter "configurations:Release"
        optimize "On"
    filter {}

    startproject "Sandbox"

    include "Sandbox"
    
    group "3rdParty"
        include "3rdParty/ImGui"
        include "3rdParty/glm"
    group ""

project "Gemstone"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
	flags "MultiProcessorCompile"

    targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

    defines { 
        "GLEW_STATIC"
    }

    filter "configurations:Debug"
		defines "GEM_DEBUG"
    filter {}

	filter "configurations:Release"
		defines "GEM_RELEASE"
	filter {}

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src",
        "3rdParty/GLEW/include",
        "3rdParty/GLFW/include",
        "3rdParty/ImGui/include/ImGui",
        "3rdParty/ImGui/include/ImPlot",
        "3rdParty/stb_image"
    }

    libdirs {
        "3rdParty/GLFW/lib-vc2022",
        "3rdParty/GLEW/lib/Release/x64"
    }

    links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui",
        "glm"
    }
