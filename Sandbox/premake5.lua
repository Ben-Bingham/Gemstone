project "Sandbox"
	kind "ConsoleApp"
	language "C++"

	cppdialect "C++17"

	targetdir ("build/bin/outputdir/%{prj.name}")
	objdir ("build/bin-int/outputdir/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}