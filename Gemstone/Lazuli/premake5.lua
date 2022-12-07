project "Lazuli"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	
	filter "configurations:Debug"
		defines { "LAZULI_DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines { "LAZULI_RELEASE" }
		optimize "On"
	
	filter {}
	
	targetdir ("build/bin/%{prj.name}")
	objdir ("build/bin-int/%{prj.name}")
	
	files {
		"Lazuli/src/**.h",
		"Lazuli/src/**.cpp"
	}
	
	includedirs {
		"Lazuli/src"
	}
