require "../Malachite/use"
require "../Lazuli/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../Celestite/use"

function useWavellite(dir)
	dir = dir or ""

	links "Wavellite"

	includedirs(dir .. "Wavellite/src")

	filter "configurations:Debug"
		defines "WAVELLITE_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "WAVELLITE_RELEASE"
	filter {}
	
	useMalachite(dir)
	useLazuli(dir)
	useGLFW(dir)
	useImGui(dir)
	useGLEW(dir)
	useCelestite(dir)
end
