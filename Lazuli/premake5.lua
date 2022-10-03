function project_Lazuli()
	project "Lazuli"
		kind "StaticLib"
		location "Lazuli"
		language "C++"
		
		cppdialect "C++17"
		
		filter "configurations:Debug"
			defines { "DEBUG", "GLEW_STATIC", "LAZULI_DEBUG"}
			symbols "On"
		
		filter "configurations:Release"
			defines { "NDEBUG", "GLEW_STATIC", "LAZULI_RELEASE" }
			optimize "On"
		
		filter {}
		
		targetdir ("%{wks.location}/build/bin/%{prj.name}")
		objdir ("%{wks.location}/build/bin-int/%{prj.name}")
		
		files {
			"Lazuli/src/**.h",
			"Lazuli/src/**.cpp"
		}
		
		includedirs {
			"Lazuli/src"
		}
end