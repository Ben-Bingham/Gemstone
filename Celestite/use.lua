function useCelestite()
	links "Celestite"

	includedirs "%{wks.location}/Celestite/src"

    defines {
        "CELESTITE_DEBUG",
        "CELESTITE_DEBUG_RELEASE"
    }
end