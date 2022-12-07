project "Malachite"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	
	filter "configurations:Debug"
		defines { "MALACHITE_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "MALACHITE_RELEASE" }
		optimize "On"
	
	filter {}
	
	targetdir ("build/bin/%{prj.name}")
	objdir ("build/bin-int/%{prj.name}")
	
	files {
		"Malachite/src/**.h",
		"Malachite/src/**.cpp"
	}
	
	includedirs {
		"Malachite/src"
	}
