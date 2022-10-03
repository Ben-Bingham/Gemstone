function project_Ruby(workspaceDir)
	project "Ruby"
		kind "StaticLib"
		location "Ruby"
		language "C++"

		cppdialect "C++17"

		filter "configurations:Debug"
			defines { "DEBUG", "GLEW_STATIC", "RUBY_DEBUG"}
			symbols "On"
		
		filter "configurations:Release"
			defines { "NDEBUG", "GLEW_STATIC", "RUBY_RELEASE" }
			optimize "On"

		filter {}

		targetdir ("%{wks.location}/build/bin/%{prj.name}")
		objdir ("%{wks.location}/build/bin-int/%{prj.name}")

		files {
			"Ruby/src/**.h",
			"Ruby/src/**.cpp"
		}

		includedirs {
			"Ruby/src",
			-- Vendor
			workspaceDir .. "vendor/GLFW/include",
			workspaceDir .. "vendor/glew-2.1.0/include",
			workspaceDir .. "vendor/stb_image",
			-- Dependencies
			workspaceDir .. "Malachite/src",
			workspaceDir .. "Lazuli/src"
		}

		libdirs {
			workspaceDir .. "vendor/GLFW/lib-vc2022",
			workspaceDir .. "vendor/glew-2.1.0/lib/Release/x64"
		}

		links {
			-- Vendor
			"glfw3",
			"glew32s",
			"opengl32",
			-- Dependencies
			"Malachite",
			"Lazuli"
		}
end