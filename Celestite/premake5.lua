project "Celestite"
	print "Initializing Celestite"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

    defines {
        "CELESTITE_DEBUG",
        "CELESTITE_DEBUG_RELEASE"
    }

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	print "Celestite Initialized"
