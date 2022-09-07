project "Malachite"
	kind "StaticLib"
	language "C++"

	cppdialect "C++17"

	targetdir ("%{wks.location}/build/bin/%{prj.name}")
	objdir ("%{wks.location}/build/bin-int/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}