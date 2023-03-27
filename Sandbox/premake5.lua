require "../Gemstone/use"

project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir "%{wks.location}/build/bin/%{prj.name}"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	flags "MultiProcessorCompile"

	filter "configurations:Debug"
		defines ("GEMSTONE_DEBUG")
	filter "configurations:Release"
		defines ("GEMSTONE_RELEASE")
	filter {}

	files {
		-- Code
		"src/**.h",
		"src/**.cpp",
		-- Assets
		"assets/**.png",
		"assets/**.jpg"
	}

	includedirs {
		"src"
	}
	
	useGemstone("../")
