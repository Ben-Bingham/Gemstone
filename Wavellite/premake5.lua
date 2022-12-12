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

    defines {
        "WAVELLITE_DEBUG",
        "WAVELLITE_RELEASE"
    }

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useMalachite()
	useLazuli()
	useGLFW()
	useImGui()
	useGLEW()
	useCelestite()

	print "Wavellite Initialized"
