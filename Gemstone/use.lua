-- GemstoneRoot should be a relative path from the premake file of the project that
-- uses it to the root of the Gemstone project that contains the premake file for
-- its workspace, NOT to the premake file that defines the Gemstone project.
-- It should end in a slash.

-- Look how it is used in this file to know where your path should lead to, 
-- includedirs is a prime example

-- TODO may need testing
function useGemstone(gemstoneRoot)
    gemstoneRoot = gemstoneRoot or ""

    includedirs {
		gemstoneRoot .. "Gemstone/src",
        gemstoneRoot .. "vendor/GLEW/include",
        gemstoneRoot .. "vendor/GLFW/include",
        gemstoneRoot .. "vendor/ImGui/src",
        gemstoneRoot .. "vendor/stb_image"
	}
    
	links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui",
		"Gemstone"
    }

    libdirs {
        gemstoneRoot .. "vendor/GLFW/lib-vc2022",
        gemstoneRoot .. "vendor/GLEW/lib/Release/x64"
    }

    quadSlashGemstoneRoot = string.gsub(gemstoneRoot, "/", "\\\\")

    print (quadSlashGemstoneRoot)

    defines { 
        "GLEW_STATIC",
        "GEM_ASSETS_STRING=\"" .. gemstoneRoot .. "Gemstone\\assets\\\"", -- Quad slashes needed because premake and the compiler both remove a set
        "GLFW_INCLUDE_NONE"
    }

end