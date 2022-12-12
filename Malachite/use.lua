require "../Lazuli/use"
require "../Celestite/use"

function useMalachite()
	links "Malachite"

	includedirs "%{wks.location}/Malachite/src"

	defines { 
        "MALACHITE_DEBUG",
        "MALACHITE_RELEASE"
    }

	useLazuli()
	useCelestite()
end