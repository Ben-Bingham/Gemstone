require "../Malachite/use"
require "../Lazuli/use"
require "../Celestite/use"
require "../Esperite/use"

function usePyrite(dir)
	dir = dir or ""
	links "Pyrite"

	includedirs(dir .. "Pyrite/src")
	
	filter "configurations:Debug"
		defines "PYRITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "PYRITE_RELEASE"
	filter {}

	useEsperite(dir)
	useLazuli(dir)
	useMalachite(dir)
	useCelestite(dir)
end