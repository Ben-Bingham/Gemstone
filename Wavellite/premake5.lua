function project_Wavellite(workspaceDir)
	project "Wavellite"
		kind "StaticLib"
		location(workspaceDir .."Wavellite")
		language "C++"

		cppdialect "C++17"

		filter "configurations:Debug"
			defines { "DEBUG", "GLEW_STATIC", "WAVELLITE_DEBUG"}
			symbols "On"
		
		filter "configurations:Release"
			defines { "NDEBUG", "GLEW_STATIC", "WAVELLITE_RELEASE" }
			optimize "On"

		filter {}

		targetdir (workspaceDir .. "build/bin/%{prj.name}")
		objdir (workspaceDir .. "build/bin-int/%{prj.name}")

		files {
			workspaceDir .. "Wavellite/src/**.h",
			workspaceDir .. "Wavellite/src/**.cpp",
			workspaceDir .. "vendor/imgui/*.h"
		}

		includedirs {
			workspaceDir .. "Wavellite/src",
			-- Vendor
			workspaceDir .. "vendor/GLFW/include",
			workspaceDir .. "vendor/glew-2.1.0/include",
			workspaceDir .. "vendor/stb_image",
			workspaceDir .. "vendor/imgui",
			-- Dependencies
			workspaceDir .. "Lazuli/src",
			workspaceDir .. "Malachite/src"
		}

		libdirs {
			workspaceDir .. "vendor/GLFW/lib-vc2022",
			workspaceDir .. "vendor/glew-2.1.0/lib/Release/x64",
			workspaceDir .. "vendor/imgui/build"
		}

		links {
			-- Vendor
			"glfw3",
			"glew32s",
			"opengl32",
			"ImGui",
			-- Dependencies
			"Lazuli",
			"Malachite"
		}
end