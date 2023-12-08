#pragma once
#include <string>

namespace Gem {
	// const std::string GEM_ASSETS_PATH{ GEM_ASSETS_STRING }; //TODO
	const std::string GEM_ASSETS_PATH{ "..\\Dependencies\\Gemstone\\Gemstone\\assets\\" };

#ifdef GEMSTONE_DEBUG
#define GEM_ASSERT(exp, msg) assert((exp && msg))
#else
#define GEM_ASSERT 
#endif
}
