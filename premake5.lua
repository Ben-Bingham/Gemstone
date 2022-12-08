workspace "Gemstone"
	print "Initializing Gemstone"

	configurations { "Debug", "Release" }
	platforms { "x64" }

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter ""

	include "Gemstone"

	print "Gemstone Initialized"
