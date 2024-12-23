project "Sandbox"
    -- Project specific settings
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    flags "MultiProcessorCompile"

    targetdir "%{wks.location}/build/bin/%{prj.name}"
    objdir "%{wks.location}/build/bin-int/%{prj.name}"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    -- Gemstone specific settings
    defines {
        "GLEW_STATIC"
    }

    filter "configurations:Debug"
		defines "GEM_DEBUG"
    filter {}
    
	filter "configurations:Release"
		defines "GEM_RELEASE"
	filter {}

    links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui",
        "glm",
        "Gemstone"
    }

    -- Gemstone specific settings that need to be modified based on directory structure
    includedirs {
        "src",
        "../src",
        "../3rdParty/GLEW/include",
        "../3rdParty/GLFW/include",
        "../3rdParty/stb",
        "../3rdParty/ImGui/src",
        "../3rdParty/glm"
    }

    libdirs {
        "../3rdParty/GLFW/lib-vc2022",
        "../3rdParty/GLEW/lib/Release/x64"
    }
