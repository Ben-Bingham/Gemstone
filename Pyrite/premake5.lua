require "../Malachite/use"
require "../Lazuli/use"
require "../Celestite/use"

project "Pyrite"
	print "Initializing Pyrite"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	filter "configurations:Debug"
		symbols "On"
		defines "PYRITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		optimize "On"
		defines "PYRITE_RELEASE"
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
	useCelestite("../")

	print "Pyrite Initialized"
