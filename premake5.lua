workspace "Gemstone"
	configurations {"Debug", "Release"}
	platforms {"x64"}

	startproject "Sandbox"

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		symbols "On"
		
	filter "configurations:Release"
		optimize "On"


	filter {}

	group "Dependencies"
		include "Malachite"
		include "Lazuli"
		include "Ruby"
		--include "Pyrite"
		--include "Emerald"
		include "Sandbox"

	group ""