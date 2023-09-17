#include "pch.h"
#include "EventSystem.h"

namespace Gem {
	EventSystem& EventSystem::Get() {
		static EventSystem eventSystem{};

		return eventSystem;
	}
}