require "../Malachite/use"
require "../Lazuli/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../Celestite/use"

function useWavellite()
	links "Wavellite"

	includedirs "%{wks.location}/Wavellite/src"

	defines { 
        "WAVELLITE_DEBUG",
        "WAVELLITE_RELEASE"
    }

	useMalachite()
	useLazuli()
	useGLFW()
	useImGui()
	useGLEW()
	useCelestite()
end
