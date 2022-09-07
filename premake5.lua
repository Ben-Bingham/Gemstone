workspace "Gemstone"
	configurations {"Debug", "Release"}
	platforms {"x64"}

	filter "platforms:x64"
	architecture "x64"

	group "Dependencies"
		include "Malachite"
		include "Sandbox"
		--include "Emerald"
		--include "Pyrite"
		--include "Ruby"
	group ""