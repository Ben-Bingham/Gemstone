function useImGui(dir)
    dir = dir or ""

    links "ImGui"

    includedirs(dir .. "vendor/ImGui/src")
end