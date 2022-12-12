require "../Celestite/use"

function useLazuli()
	links "Lazuli"

	includedirs "%{wks.location}/Lazuli/src"

    defines { 
        "LAZULI_DEBUG",
        "LAZULI_RELEASE"
    }

    useCelestite()
end