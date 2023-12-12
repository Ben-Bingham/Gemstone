project "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    architecture "x86_64"

	flags "MultiProcessorCompile"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
    filter {}

    targetdir "%{wks.location}/build/bin/%{cfg.name}/%{prj.name}"
	objdir "%{wks.location}/build/obj/%{cfg.name}/%{prj.name}"

    files {
        "include/**.h",
        "src/**.cpp"
    }

    links "glfw3"
    
    libdirs("../GLFW/lib-vc2022")

    includedirs {
        "../GLFW/include",
        "include/ImGui",
        "include/ImPlot"
    }    