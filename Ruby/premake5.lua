require "../Malachite/use"
require "../Lazuli/use"
require "../Wavellite/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../vendor/stb_image/use"
require "../Celestite/use"

project "Ruby"
	print "Initializing Ruby"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	defines {
		"RUBY_ASSETS=\"" .. gemstoneDirectory .. "\\\\Ruby\\\\assets\"" -- Quad slashes needed because premake and the compiler both remove a set
    }

	filter "configurations:Debug"
		symbols "On"
		defines "RUBY_DEBUG"
	filter {}
	
	filter "configurations:Release"
		optimize "On"
		defines "RUBY_RELEASE"
	filter {}
	
	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useStbImage("../")
	useLazuli("../")
	useMalachite("../")
	useGLFW("../")
	useImGui("../")
	useGLEW("../")
	useWavellite("../")
	useCelestite("../")

	print "Ruby Initialized"
