project "Lazuli"
	kind "StaticLib"
	language "C++"

	cppdialect "C++17"

	filter "configurations:Debug"
		defines { "DEBUG", "GLEW_STATIC", "LAZULI_DEBUG"}
		symbols "On"
		
	filter "configurations:Release"
		defines { "NDEBUG", "GLEW_STATIC", "LAZULI_RELEASE" }
		optimize "On"

	filter {}

	targetdir ("%{wks.location}/build/bin/%{prj.name}")
	objdir ("%{wks.location}/build/bin-int/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}