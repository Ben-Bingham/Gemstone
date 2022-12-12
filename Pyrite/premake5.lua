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

    defines {
        "PYRITE_DEBUG",
        "PYRITE_RELEASE"
    }

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	useLazuli()
	useMalachite()
	useCelestite()

	print "Pyrite Initialized"
