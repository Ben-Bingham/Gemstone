workspace "Gemstone"
	configurations { "Debug", "Release" }
	platforms "x64"
	architecture "x64"

	filter "configurations:Debug"
		symbols "On"
	filter "configurations:Release"
		optimize "On"
	filter {}

	startproject "Sandbox"

	include "Sandbox"
	include "Gemstone"
	
	group "Vendor"
		include "vendor/ImGui"
	group ""
