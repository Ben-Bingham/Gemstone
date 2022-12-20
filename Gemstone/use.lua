require "../Lazuli/use"
require "../Malachite/use"
require "../Wavellite/use"
require "../Ruby/use"
require "../Pyrite/use"
require "../Celestite/use"

function useGemstone(dir)
    dir = dir or ""
    useCelestite(dir)
    useLazuli(dir)
    useMalachite(dir)
    useWavellite(dir)
    useRuby(dir)
    usePyrite(dir)
end