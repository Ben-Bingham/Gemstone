function useLazuli()
	links "Lazuli"

	includedirs "%{wks.location}/Lazuli/src"

    defines { 
        "LAZULI_DEBUG",
        "LAZULI_RELEASE"
    }
end

project "Lazuli"
	print "Initializing Lazuli"

    kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

    defines { 
        "LAZULI_DEBUG",
        "LAZULI_RELEASE"
    }

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	print "Lazuli Initialized"
