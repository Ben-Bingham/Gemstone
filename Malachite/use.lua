require "../Lazuli/use"
require "../Celestite/use"

function useMalachite()
	links "Malachite"

	includedirs "%{wks.location}/Malachite/src"

	filter "configurations:Debug"
		defines "MALACHITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "MALACHITE_RELEASE"
	filter {}
	
	useLazuli()
	useCelestite()
end