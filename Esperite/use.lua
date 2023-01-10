require "../Lazuli/use"
require "../Celestite/use"

function useEsperite(dir)
    dir = dir or ""
	links "Esperite"

	includedirs(dir .. "Esperite/src")

    filter "configurations:Debug"
        defines "ESPERITE_DEBUG"
    filter {}

    filter "configurations:Release"
        defines "ESPERITE_RELEASE"
    filter {}

    useLazuli(dir)
	useCelestite(dir)
end