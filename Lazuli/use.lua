require "../Celestite/use"

function useLazuli(dir)
    dir = dir or ""
	links "Lazuli"

	includedirs(dir .. "Lazuli/src")

    filter "configurations:Debug"
        defines "LAZULI_DEBUG"
    filter {}

    filter "configurations:Release"
        defines "LAZULI_RELEASE"
    filter {}

    useCelestite(dir)
end