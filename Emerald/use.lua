require "../Malachite/use"
require "../Lazuli/use"
require "../vendor/GLFW/use"
require "../Celestite/use"
require "../Ruby/use"
require "../Pyrite/use"

function useEmerald(dir)
	dir = dir or ""
	links "Emerald"

	includedirs(dir .. "Emerald/src")

	filter "configurations:Debug"
		defines "EMERALD_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "EMERALD_RELEASE"
	filter {}

	useLazuli(dir)
	useMalachite(dir)
	useWavellite(dir)
	useCelestite(dir)
	useRuby(dir)
	usePyrite(dir)
end