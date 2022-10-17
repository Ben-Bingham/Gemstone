function project_ImGui(workspaceDir)
    project "ImGui"
        kind "StaticLib"
        location(workspaceDir .."vendor/imgui")
        language "C++"

        cppdialect "C++17"

        targetdir (workspaceDir .. "vendor/imgui/build/bin/%{prj.name}")
		objdir (workspaceDir .. "vendor/imgui/build/bin-int/%{prj.name}")

        files {
            workspaceDir .. "vendor/imgui/**.cpp",
            workspaceDir .. "vendor/imgui/**.h"
        }

        includedirs {
            -- Vendor
            workspaceDir .. "vendor/GLFW/include"
        }

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"
end