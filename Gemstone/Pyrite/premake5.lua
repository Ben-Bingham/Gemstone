project "Pyrite"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	filter "configurations:Debug"
		defines { "PYRITE_DEBUG"}
		symbols "On"
	
	filter "configurations:Release"
		defines { "PYRITE_RELEASE" }
		optimize "On"

	filter {}

	targetdir ("build/bin/%{prj.name}")
	objdir ("build/bin-int/%{prj.name}")

	files {
		"Pyrite/src/**.h",
		"Pyrite/src/**.cpp"
	}

	includedirs {
		"Pyrite/src",
		-- -- Vendor
		-- workspaceDir .. "vendor/GLFW/include",
		-- workspaceDir .. "vendor/glew-2.1.0/include",
		-- workspaceDir .. "vendor/stb_image",
		-- -- Dependencies
		-- workspaceDir .. "Malachite/src",
		-- workspaceDir .. "Lazuli/src",
		-- workspaceDir .. "Wavellite/src"
	}

	-- libdirs {
	-- 	-- workspaceDir .. "vendor/GLFW/lib-vc2022",
	-- 	-- workspaceDir .. "vendor/glew-2.1.0/lib/Release/x64"
	-- }

	links {
		-- -- Vendor
		-- "glfw3",
		-- "glew32s",
		-- "opengl32",
		-- Dependencies
		"Malachite",
		"Lazuli"
		-- "Wavellite"
	}
