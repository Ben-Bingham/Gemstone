function project_Malachite(workspaceDir)
	project "Malachite"
		kind "StaticLib"
		location "Malachite"
		language "C++"
		
		cppdialect "C++17"
		
		filter "configurations:Debug"
			defines { "DEBUG", "GLEW_STATIC", "MALACHITE_DEBUG"}
			symbols "On"
			
		filter "configurations:Release"
			defines { "NDEBUG", "GLEW_STATIC", "MALACHITE_RELEASE" }
			optimize "On"
		
		filter {}
		
		targetdir (workspaceDir .. "build/bin/%{prj.name}")
		objdir (workspaceDir .. "build/bin-int/%{prj.name}")
		
		files {
			"Malachite/src/**.h",
			"Malachite/src/**.cpp"
		}
		
		includedirs {
			"Malachite/src"
		}
end