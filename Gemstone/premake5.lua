project "Gemstone"
	print "Initializing Gemstone (Project)"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	filter "configurations:Debug"
		defines { "GEMSTONE_DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines { "GEMSTONE_RELEASE" }
		optimize "On"

	filter {}

	targetdir ("build/bin/%{prj.name}")
	objdir ("build/bin-int/%{prj.name}")

	-- includedirs {
	-- 	workspaceDir .. "Ruby/src",
	-- 	-- Vendor
	-- 	workspaceDir .. "vendor/GLFW/include",
	-- 	workspaceDir .. "vendor/glew-2.1.0/include",
	-- 	workspaceDir .. "vendor/stb_image",
	-- 	workspaceDir .. "vendor/imgui/src",
	-- 	-- Dependencies
	-- 	workspaceDir .. "Malachite/src",
	-- 	workspaceDir .. "Lazuli/src",
	-- 	workspaceDir .. "Wavellite/src"
	-- }

	-- libdirs {
	-- 	workspaceDir .. "vendor/GLFW/lib-vc2022",
	-- 	workspaceDir .. "vendor/glew-2.1.0/lib/Release/x64"
	-- }

	include {
	-- 	-- Vendor
	-- 	-- "glfw3",
	-- 	-- "glew32s",
	-- 	-- "opengl32",
	-- 	-- Dependencies
		"Malachite",
		"Lazuli",
		"Wavellite",
		"Pyrite",
		"Ruby"
	}

	-- group "Vendor"
	-- 	project_ImGui("")
	-- group ""
