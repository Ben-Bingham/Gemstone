require "../Celestite/use"

project "Lazuli"
	print "Initializing Lazuli"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

    filter "configurations:Debug"
		symbols "On"
        defines "LAZULI_DEBUG"
    filter {}

    filter "configurations:Release"
		optimize "On"
        defines "LAZULI_RELEASE"
    filter {}

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}
	
    useCelestite("../")

	print "Lazuli Initialized"
