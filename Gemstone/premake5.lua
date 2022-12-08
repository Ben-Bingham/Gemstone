project "Gemstone"
	print "Initializing Gemstone"

	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	filter "configurations:Debug"
		defines "GEMSTONE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "GEMSTONE_RELEASE"
		optimize "On"

	filter {}

	files { -- Code
		"src/**.cpp",
		"src/**.h"
	}

	files { -- Assets
		"assets/Ruby/shaders/**.frag",
		"assets/Ruby/shaders/**.vert"
	}

	includedirs {
		"src/**.h"
	}

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	print "Gemstone Initialized"
