require "../Malachite/use"
require "../Lazuli/use"
require "../Wavellite/use"
require "../vendor/GLFW/use"
require "../vendor/ImGui/use"
require "../vendor/GLEW/use"
require "../vendor/stb_image/use"
require "../Celestite/use"

function useRuby(dir)
	dir = dir or ""
	links "Ruby"

	includedirs(dir .. "Ruby/src")

	windowsDir = string.gsub(dir, "/", "\\\\")

	defines {
		"RUBY_ASSETS=\"" .. windowsDir .. "Ruby\\\\assets\"" -- Quad slashes needed because premake and the compiler both remove a set
    }

	filter "configurations:Debug"
		defines "RUBY_DEBUG"
	filter {}
	
	filter "configurations:Release"
		defines "RUBY_RELEASE"
	filter {}

	useStbImage(dir)
	useLazuli(dir)
	useMalachite(dir)
	useGLFW(dir)
	useImGui(dir)
	useGLEW(dir)
	useWavellite(dir)
	useCelestite(dir)
end