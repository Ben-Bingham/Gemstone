#pragma once
#include "Gem.h"

namespace Gem {
	GEM_API class Settings {
	public:
		static inline unsigned int maxFPS{ 60 };
		static inline bool vSync{ false };
	};
}