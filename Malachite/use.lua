require "../Lazuli/use"
require "../Celestite/use"

function useMalachite(dir)
	dir = dir or ""
	links "Malachite"

	includedirs(dir .. "Malachite/src")

	filter "configurations:Debug"
		defines "MALACHITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "MALACHITE_RELEASE"
	filter {}
	
	useLazuli(dir)
	useCelestite(dir)
end