require "../Malachite/premake5"
require "../Lazuli/premake5"
require "../vendor/GLFW/premake5"
require "../vendor/ImGui/premake5"
require "../vendor/GLEW/premake5"

function useWavellite()
	links "Wavellite"

	includedirs "%{wks.location}/Wavellite/src"

	defines { 
        "WAVELLITE_DEBUG",
        "WAVELLITE_RELEASE"
    }

	useMalachite()
	useLazuli()
	useGLFW()
	useImGui()
	useGLEW()
end

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

	print "Wavellite Initialized"
