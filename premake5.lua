require "Lazuli/premake5"
require "Malachite/premake5"

workspace "Gemstone"
	configurations {"Debug", "Release"}
	platforms {"x64"}

	startproject "Sandbox"

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		defines { 
			"MALACHITE_DEBUG",
			"LAZULI_DEBUG",
			"RUBY_DEBUG",
			"GLEW_STATIC"
		}
		symbols "On"
		
	filter "configurations:Release"
		defines { 
			"MALACHITE_RELEASE",
			"LAZULI_RELEASE",
			"RUBY_RELEASE",
			"GLEW_STATIC"
		}
		optimize "On"

	filter {}

	group "Dependencies"
		project_Lazuli("")
		project_Malachite("")
		--include "Malachite"
		include "Ruby"
		--include "Pyrite"
		--include "Emerald"
		include "Sandbox"

	group ""