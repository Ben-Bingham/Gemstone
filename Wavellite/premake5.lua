require "../Malachite/use"
require "../Lazuli/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../Celestite/use"

project "Wavellite"
	print "Initializing Wavellite"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"
	
	filter "configurations:Debug"
		symbols "On"
		defines "WAVELLITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		optimize "On"
		defines "WAVELLITE_RELEASE"
	filter {}
	
	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useMalachite("../")
	useLazuli("../")
	useGLFW("../")
	useImGui("../")
	useGLEW("../")
	useCelestite("../")

	print "Wavellite Initialized"
