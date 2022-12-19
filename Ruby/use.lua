require "../Malachite/use"
require "../Lazuli/use"
require "../Wavellite/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../vendor/stb_image/use"
require "../Celestite/use"

function useRuby()
	links "Ruby"

	includedirs "%{wks.location}/Ruby/src"

	defines {
		"RUBY_ASSETS=\"..\\\\Ruby\\\\assets\"" -- Quad slashes needed because premake and the compiler both remove a set
    }

	filter "configurations:Debug"
		defines "RUBY_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "RUBY_RELEASE"
	filter {}

	useStbImage()
	useLazuli()
	useMalachite()
	useGLFW()
	useImGui()
	useGLEW()
	useWavellite()
	useCelestite()
end