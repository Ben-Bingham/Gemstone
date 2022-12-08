project "Ruby"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	filter "configurations:Debug"
		defines { "RUBY_DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines { "RUBY_RELEASE" }
		optimize "On"

	filter {}

	targetdir ("build/bin/%{prj.name}")
	objdir ("build/bin-int/%{prj.name}")

	files {
		"Ruby/src/**.h",
		"Ruby/src/**.cpp"
	}

	includedirs {
		"Ruby/src",
		-- Vendor
		"vendor/GLFW/include",
		"vendor/glew-2.1.0/include",
		"vendor/stb_image",
		-- workspaceDir .. "vendor/imgui/src",
		-- Dependencies
		"Malachite/src",
		"Lazuli/src",
		"Wavellite/src",
	}

	libdirs {
		"vendor/GLFW/lib-vc2022",
		"vendor/glew-2.1.0/lib/Release/x64"
	}

	links {
		-- Vendor
		"glfw3",
		"glew32s",
		"opengl32",
		-- Dependencies
		"Malachite",
		"Lazuli",
		"Wavellite"
	}

	-- group "Vendor"
	-- 	project_ImGui("")
	-- group ""
