#pragma once
#include <limits>

namespace Gem {
	using Entity = size_t;
	static constexpr Entity DeadEntity{ std::numeric_limits<size_t>::max() };
}