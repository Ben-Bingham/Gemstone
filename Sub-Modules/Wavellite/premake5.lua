--require (workspaceDir .. "vendor/imgui/premake5")
require "vendor/imgui/premake5"

project "Wavellite"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	filter "configurations:Debug"
		defines { "WAVELLITE_DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines { "WAVELLITE_RELEASE" }
		optimize "On"

	filter {}

	targetdir ("build/bin/%{prj.name}")
	objdir ("build/bin-int/%{prj.name}")

	files {
		"Wavellite/src/**.h",
		"Wavellite/src/**.cpp"
	}

	includedirs {
		workspaceDir .. "Wavellite/src",
		-- Vendor
		workspaceDir .. "vendor/GLFW/include",
		workspaceDir .. "vendor/glew-2.1.0/include",
		-- workspaceDir .. "vendor/stb_image",
		-- workspaceDir .. "vendor/imgui/src",
		-- Dependencies
		-- workspaceDir .. "Lazuli/src",
		-- workspaceDir .. "Malachite/src"
	}

	libdirs {
		workspaceDir .. "vendor/GLFW/lib-vc2022",
		workspaceDir .. "vendor/glew-2.1.0/lib/Release/x64",
		-- workspaceDir .. "vendor/imgui/build"
	}

	-- group "Vendor"
	-- 	project_ImGui("")
	-- group ""

	links {
		-- Vendor
		"glfw3",
		"glew32s",
		"opengl32",
		"ImGui"
		-- Dependencies
		-- "Lazuli",
		-- "Malachite"
	}
