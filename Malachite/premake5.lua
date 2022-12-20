require "../Lazuli/use"
require "../Celestite/use"

project "Malachite"
	print "Initializing Malachite"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	filter "configurations:Debug"
		symbols "On"
		defines "MALACHITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		optimize "On"
		defines "MALACHITE_RELEASE"
	filter {}
	
	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useLazuli("../")
	useCelestite("../")

	print "Malachite Initialized"
