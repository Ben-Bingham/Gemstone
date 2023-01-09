require "../Malachite/use"
require "../Lazuli/use"
require "../vendor/GLFW/use"
require "../Celestite/use"
require "../Ruby/use"
require "../Pyrite/use"

project "Emerald"
	print "Initializing Emerald"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	filter "configurations:Debug"
		symbols "On"
		defines "EMERALD_DEBUG"
	filter {}
	
	filter "configurations:Release"
		optimize "On"
		defines "EMERALD_RELEASE"
	filter {}
	
	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useLazuli("../")
	useMalachite("../")
	useWavellite("../")
	useCelestite("../")
	useRuby("../")
	usePyrite("../")

	print "Emerald Initialized"
