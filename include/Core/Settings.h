#pragma once
#include "Gem.h"

namespace Gem {
	class GEM_API Settings {
	public:
		static inline unsigned int maxFPS{ 60 };
		static inline bool vSync{ false };
	};
}