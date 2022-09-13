workspace "Gemstone"
	configurations {"Debug", "Release"}
	platforms {"x64"}

	startproject "Sandbox"

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		defines { "DEBUG", "GLEW_STATIC", "GEMSTONE_DEBUG"}
		symbols "On"
		
	filter "configurations:Release"
		defines { "NDEBUG", "GLEW_STATIC", "GEMSTONE_RELEASE" }
		optimize "On"

	filter {}

	group "Dependencies"
		include "Malachite"
		include "Ruby"
		--include "Pyrite"
		--include "Emerald"
		include "Sandbox"

	group ""