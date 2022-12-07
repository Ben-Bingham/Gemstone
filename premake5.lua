-- require "Lazuli/premake5"
-- require "Malachite/premake5"
-- require "Pyrite/premake5"
-- require "Wavellite/premake5"
-- require "Ruby/premake5"
--require "vendor/imgui/premake5"

workspace "Sandbox"
	print "Initializing Master Workspace"

	configurations { "Debug", "Release" }
	-- platforms { "x64" }

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		-- defines { 
		-- 	"MALACHITE_DEBUG",
		-- 	"LAZULI_DEBUG",
		-- 	"RUBY_DEBUG",
		-- 	"GLEW_STATIC",
		-- 	"WAVELLITE_DEBUG",
		-- 	"GEMSTONE_DEBUG"
		-- }

		symbols "On"

	filter "configurations:Release"
		-- defines { 
		-- 	"MALACHITE_RELEASE",
		-- 	"LAZULI_RELEASE",
		-- 	"RUBY_RELEASE",
		-- 	"GLEW_STATIC",
		-- 	"WAVELLITE_RELEASE",
		-- 	"GEMSTONE_RELEASE"
		-- }

		optimize "On"

	filter {}

	--defines { "RUBY_ASSETS=\"..\\\\Ruby\\\\assets\"" }

	-- group "Vendor"
	-- 	project_ImGui("")
	-- group ""

	-- include "Gemstone"
	include "Sandbox"
	-- links {
	-- 	"Gemstone",
	-- 	-- "Sandbox"
	-- }


	--group "Dependencies"
		-- project_Lazuli("")
		-- project_Ulexite("")
		-- project_Malachite("")
		-- project_Pyrite("")
		-- project_Wavellite("")
		-- project_Ruby("")
		--project_Emerald("")
		--include "Sandbox"
	--group ""