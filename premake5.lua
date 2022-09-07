workspace "Gemstone"
	configurations {"Debug", "Release"}
	platforms {"x64"}

	startproject "Sandbox"

	filter "platforms:x64"
	architecture "x64"

	group "Dependencies"
		include "Malachite"
		include "Sandbox"
		--include "Emerald"
		--include "Pyrite"
		--include "Ruby"
	group ""