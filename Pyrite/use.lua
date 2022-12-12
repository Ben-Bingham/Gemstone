require "../Malachite/use"
require "../Lazuli/use"
require "../Celestite/use"

function usePyrite()
	links "Pyrite"

	includedirs "%{wks.location}/Pyrite/src"

	defines {
        "PYRITE_DEBUG",
        "PYRITE_RELEASE"
    }

	useLazuli()
	useMalachite()
	useCelestite()
end