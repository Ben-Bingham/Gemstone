gemstoneDirectory = gemstoneDirectory or ""
require "../Lazuli/use"
require "../Malachite/use"
require "../Wavellite/use"
require "../Ruby/use"
require "../Pyrite/use"
require "../Celestite/use"
require "../Emerald/use"
require "../Esperite/use"

function useGemstone(dir)
    dir = dir or ""
    useEsperite(dir)
    useCelestite(dir)
    useLazuli(dir)
    useMalachite(dir)
    useWavellite(dir)
    useRuby(dir)
    usePyrite(dir)
    useEmerald(dir)
end