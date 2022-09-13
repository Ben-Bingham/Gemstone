project "Ruby"
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
		"src",
		"%{wks.location}/vendor/GLFW/include",
		"%{wks.location}/vendor/glew-2.1.0/include",
		"%{wks.location}/Malachite/src"
	}

	libdirs {
		"%{wks.location}/vendor/GLFW/lib-vc2022",
		"%{wks.location}/vendor/glew-2.1.0/lib/Release/x64"
	}

	links {
		"Malachite",
		"glfw3",
		"glew32s",
		"opengl32"
	}