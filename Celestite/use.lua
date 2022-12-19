function useCelestite()
	links "Celestite"

	includedirs "%{wks.location}/Celestite/src"

    filter "configurations:Debug"
        defines "CELESTITE_DEBUG"
    filter {}

    filter "configurations:Release"
        defines "CELESTITE_RELEASE"
    filter {}
end