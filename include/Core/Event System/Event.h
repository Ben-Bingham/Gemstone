#pragma once
#include "Gem.h"

namespace Gem {
	using EventId = unsigned int;
	inline EventId g_MasterId{ 0 };

	template<typename T>
	GEM_API EventId GetEventId() {
		static EventId id = g_MasterId++;
		return id;
	}
}