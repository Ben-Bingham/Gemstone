require "../Lazuli/use"
require "../Malachite/use"
require "../Wavellite/use"
require "../Ruby/use"
require "../Pyrite/use"
require "../Celestite/use"

function useGemstoneWorkspace(dir)
    dir = dir or ""

    group "Gemstone/Gems"
        include(dir .. "Celestite/premake5")
        include(dir .. "Lazuli/premake5")
        include(dir .. "Malachite/premake5")
        include(dir .. "Wavellite/premake5")
        include(dir .. "Ruby/premake5")
        include(dir .. "Pyrite/premake5")
    group ""

    group "Gemstone/Vendor"
        include(dir .. "vendor/ImGui/premake5")
    group ""
end