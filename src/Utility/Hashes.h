#pragma once
#include <vector>

namespace Gem {
    // Code from: https://stackoverflow.com/questions/2590677/how-do-i-combine-hash-values-in-c0x
    inline void HashCombine(std::size_t& seed) { }

    template <typename T, typename... Rest>
	void HashCombine(std::size_t& seed, const T& v, Rest... rest) {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        HashCombine(seed, rest...);
    }
}

// Code form: https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector/72073933#72073933
template<>
struct std::hash<std::vector<unsigned int>> {
    std::size_t operator()(const std::vector<unsigned int>& vec) const noexcept {
        std::size_t seed = vec.size();
        for (auto x : vec) {
            constexpr size_t halfBitCount = sizeof(unsigned int) * 4;

            x = ((x >> halfBitCount) ^ x) * 0x45d9f3b;
            x = ((x >> halfBitCount) ^ x) * 0x45d9f3b;
            x = (x >> halfBitCount) ^ x;
            seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};


template<>
struct std::hash<std::vector<float>> {
	std::size_t operator()(const std::vector<float>& vec) const noexcept {
        std::size_t seed = vec.size();
        for (auto element : vec) {
            Gem::HashCombine(seed, element);
        }
        return seed;
	}
};