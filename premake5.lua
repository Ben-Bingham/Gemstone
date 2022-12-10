workspace "Gemstone"
	print "---------------------------------------------"
	print "Initializing Workspace"

	configurations { "Debug", "Release" }
	platforms "x64"

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		symbols "On"
	
	filter "configurations:Release"
		optimize "On"
	filter ""

	startproject "Sandbox"

	group "Core"
		-- include "Celestite"
		include "Lazuli"
		include "Malachite"
		include "Wavellite"
		include "Ruby"
		-- include "Pyrite"
	group ""

	group "Dependencies"
		include "vendor/ImGui"
	group ""

	group "Misc"
		include "Sandbox"
	group ""

	print "Workspace Initialized"
	print "---------------------------------------------"

