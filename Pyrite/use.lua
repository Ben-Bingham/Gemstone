require "../Malachite/use"
require "../Lazuli/use"
require "../Celestite/use"

function usePyrite()
	links "Pyrite"

	includedirs "%{wks.location}/Pyrite/src"
	
	filter "configurations:Debug"
		defines "PYRITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "PYRITE_RELEASE"
	filter {}

	useLazuli()
	useMalachite()
	useCelestite()
end