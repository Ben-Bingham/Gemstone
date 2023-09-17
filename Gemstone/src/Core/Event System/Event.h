#pragma once

namespace Gem {
	using EventId = unsigned int;
	inline EventId g_MasterId{ 0 };

	template<typename T>
	EventId GetEventId() {
		static EventId id = g_MasterId++;
		return id;
	}
}