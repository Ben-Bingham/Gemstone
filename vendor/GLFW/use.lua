function useGLFW(dir)
    dir = dir or ""

    libdirs(dir .. "vendor/GLFW/lib-vc2022")
    links "glfw3"
    includedirs(dir .. "vendor/GLFW/include")
end