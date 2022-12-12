function useGLEW()
    libdirs "%{wks.location}/vendor/GLEW/lib/Release/x64"

    links { 
        "glew32s",
        "opengl32"
    }

    defines "GLEW_STATIC"

    includedirs "%{wks.location}/vendor/GLEW/include"
end