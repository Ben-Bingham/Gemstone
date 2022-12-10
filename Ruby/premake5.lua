require "../Malachite/premake5"
require "../Lazuli/premake5"
require "../Wavellite/premake5"
require "../vendor/GLFW/premake5"
require "../vendor/ImGui/premake5"
require "../vendor/GLEW/premake5"
require "../vendor/stb_image/premake5"

function useRuby()
	links "Ruby"

	includedirs "%{wks.location}/Ruby/src"

	defines {
        "RUBY_DEBUG",
        "RUBY_RELEASE",
		"RUBY_ASSETS=\"..\\\\Ruby\\\\assets\"" -- Quad slashes needed because premake and the compiler both remove a set
    }

	useStbImage()
	useLazuli()
	useMalachite()
	useGLFW()
	useImGui()
	useGLEW()
	useWavellite()
end

project "Ruby"
	print "Initializing Ruby"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

    defines {
        "RUBY_DEBUG",
        "RUBY_RELEASE",
		"RUBY_ASSETS=\"..\\\\Ruby\\\\assets\"" -- Quad slashes needed because premake and the compiler both remove a set
    }

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useStbImage()
	useLazuli()
	useMalachite()
	useGLFW()
	useImGui()
	useGLEW()
	useWavellite()

	print "Ruby Initialized"
