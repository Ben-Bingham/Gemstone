workspace "Gemstone"
	print "---------------------------------------------"
	print "Initializing Workspace"

	configurations { "Debug", "Release" }
	platforms "x64"
	architecture "x64"

	filter "configurations:Debug"
		symbols "On"
	
	filter "configurations:Release"
		optimize "On"
	filter ""

	startproject "Sandbox"

	-- group "Gems"
	-- 	-- include "Celestite"
	-- 	-- include "Lazuli"
	-- 	-- include "Malachite"
	-- 	-- include "Wavellite"
	-- 	-- include "Ruby"
	-- 	-- include "Pyrite"
	-- 	-- include "Emerald"
	-- 	-- include "Esperite"
	-- group ""

	-- group "Misc"
	include "Sandbox"
	include "Gemstone"
	include "Gemstone/vendor/ImGui"
	-- include "Unit Testing"
	-- group ""

	-- group "Dependencies"
		-- include "vendor/ImGui"
	-- group ""

	print "Workspace Initialized"
	print "---------------------------------------------"