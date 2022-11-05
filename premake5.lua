require "Lazuli/premake5"
require "Malachite/premake5"
require "Pyrite/premake5"
require "Wavellite/premake5"
require "Ruby/premake5"
require "vendor/imgui/premake5"

workspace "Gemstone"
	configurations { "Debug", "Release" }
	platforms { "x64" }

	startproject "Sandbox"

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		defines { 
			"MALACHITE_DEBUG",
			"LAZULI_DEBUG",
			"RUBY_DEBUG",
			"GLEW_STATIC",
			"WAVELLITE_DEBUG"
		}

		symbols "On"

	filter "configurations:Release"
		defines { 
			"MALACHITE_RELEASE",
			"LAZULI_RELEASE",
			"RUBY_RELEASE",
			"GLEW_STATIC",
			"WAVELLITE_RELEASE"
		}

		optimize "On"

	filter {}

	defines { "RUBY_ASSETS=\"..\\\\Ruby\\\\assets\"" }

	-- group "Vendor"
	-- 	project_ImGui("")
	-- group ""

	group "Dependencies"
		project_Lazuli("")
		-- project_Ulexite("")
		project_Malachite("")
		project_Pyrite("")
		project_Wavellite("")
		project_Ruby("")
		--project_Emerald("")
		include "Sandbox"

	group ""