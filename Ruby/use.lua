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
        "RUBY_DEBUG",
        "RUBY_RELEASE",
		"RUBY_ASSETS=\"..\\\\Ruby\\\\assets\"" -- Quad slashes needed because premake and the compiler both remove a set
    }

	useStbImage()
	useLazuli()
	useMalachite()
	useGLFW()
	useImGui()
	useGLEW()
	useWavellite()
	useCelestite()
end