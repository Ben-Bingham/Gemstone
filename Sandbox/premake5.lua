require "../Gemstone/use"

project "Sandbox"
	print "Initializing Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	files {
		-- Code
		"src/**.h",
		"src/**.cpp",
		-- Assets
		"assets/**.png",
		"assets/**.jpg"
	}

	includedirs {
		"src",
		"../Gemstone/src",
        "../Gemstone/vendor/GLEW/include",
        "../Gemstone/vendor/GLFW/include",
        "../Gemstone/vendor/ImGui/src",
        "../Gemstone/vendor/stb_image"
	}

	links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui",
		"Gemstone"
    }

    libdirs {
        "../Gemstone/vendor/GLFW/lib-vc2022",
        "../Gemstone/vendor/GLEW/lib/Release/x64"
    }

	print "Sandbox Initialized"