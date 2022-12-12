function useGLFW()
    libdirs "%{wks.location}/vendor/GLFW/lib-vc2022"
    links "glfw3"
    includedirs "%{wks.location}/vendor/GLFW/include"
end