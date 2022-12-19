require "../Malachite/use"
require "../Lazuli/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../Celestite/use"

function useWavellite()
	links "Wavellite"

	includedirs "%{wks.location}/Wavellite/src"

	filter "configurations:Debug"
		defines "WAVELLITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "WAVELLITE_RELEASE"
	filter {}
	
	useMalachite()
	useLazuli()
	useGLFW()
	useImGui()
	useGLEW()
	useCelestite()
end
