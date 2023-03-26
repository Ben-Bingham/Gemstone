project "Gemstone"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    defines { 
        "GLEW_STATIC",
        "RUBY_ASSETS=\"..\\\\Gemstone\\\\assets\"",
        "GEMSTONE_OPENGL", --TODO remove
        "GEMSTONE_GLFW",
        "GLFW_INCLUDE_NONE"
    }

    includedirs {
        "src",
        "vendor/GLEW/include",
        "vendor/GLFW/include",
        "vendor/ImGui/src",
        "vendor/stb_image"
    }

    files {
        "src/**.cpp",
        "src/**.h",
    }

    links {
        "glew32s",
        "opengl32",
        "glfw3",
        "ImGui"
    }

    libdirs {
        "vendor/GLFW/lib-vc2022",
        "vendor/GLEW/lib/Release/x64"
    }