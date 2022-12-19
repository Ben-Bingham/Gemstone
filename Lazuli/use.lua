require "../Celestite/use"

function useLazuli()
	links "Lazuli"

	includedirs "%{wks.location}/Lazuli/src"

    filter "configurations:Debug"
        defines "LAZULI_DEBUG"
    filter {}

    filter "configurations:Release"
        defines "LAZULI_RELEASE"
    filter {}

    useCelestite()
end