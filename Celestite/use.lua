function useCelestite(dir)
    dir = dir or ""
	links "Celestite"

	includedirs(dir .. "Celestite/src")

    filter "configurations:Debug"
        defines "CELESTITE_DEBUG"
    filter {}

    filter "configurations:Release"
        defines "CELESTITE_RELEASE"
    filter {}
end