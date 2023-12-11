workspace "Gemstone"
	configurations { "Debug", "Release" }

	-- startproject "Sandbox"

	-- include "Sandbox"
	include "Gemstone"
	
	group "Vendor"
		include "vendor/ImGui"
	group ""
