require "../Lazuli/use"
require "../Celestite/use"

project "Esperite"
	print "Initializing Esperite"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	filter "configurations:Debug"
		symbols "On"
		defines "ESPERITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		optimize "On"
		defines "ESPERITE_RELEASE"
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

	print "Esperite Initialized"
