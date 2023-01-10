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
end