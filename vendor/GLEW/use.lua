function useGLEW(dir)
    dir = dir or ""

    libdirs(dir .. "vendor/GLEW/lib/Release/x64")

    links { 
        "glew32s",
        "opengl32"
    }

    defines "GLEW_STATIC"

    includedirs(dir .. "vendor/GLEW/include")
end