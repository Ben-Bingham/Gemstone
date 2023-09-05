project "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

	flags "MultiProcessorCompile"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
    filter {}

	targetdir "%{wks.location}/build/vendor/bin/%{prj.name}"
	objdir "%{wks.location}/build/vendor/bin-int/%{prj.name}"

    files {
        "ImGuiSrc/**.cpp",
        "ImGuiSrc/**.h",
        "ImPlotSrc/**.h",
        "ImPlotSrc/**.cpp"
    }

    links "glfw3"
    
    libdirs("../GLFW/lib-vc2022")

    includedirs {
        "../GLFW/include",
        "ImGuiSrc"
    }    