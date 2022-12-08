project "Malachite"
	print "Initializing Malachite"

	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	
	filter "configurations:Debug"
		defines { "MALACHITE_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "MALACHITE_RELEASE" }
		optimize "On"
	
	filter {}
	
	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"
	
	files {
		"src/**.h",
		"src/**.cpp"
	}
	
	includedirs {
		"src"
	}

	print "Malachite Initialized"
