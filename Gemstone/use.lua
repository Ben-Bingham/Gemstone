function useGemstone(gemstoneRoot)
    gemstoneRoot = gemstoneRoot or ""
    includedirs {
        gemstoneRoot .. "Celestite/src",
        gemstoneRoot .. "Emerald/src",
        gemstoneRoot .. "Esperite/src",
        gemstoneRoot .. "Lazuli/src",
        gemstoneRoot .. "Malachite/src",
        gemstoneRoot .. "Pyrite/src",
        gemstoneRoot .. "Ruby/src",
        gemstoneRoot .. "Wavellite/src"
    }

    files {
        gemstoneRoot .. "**.cpp",
        gemstoneRoot .. "**.h"
    }
end