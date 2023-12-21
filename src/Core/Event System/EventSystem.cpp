#include "Core/Event System/EventSystem.h"

#include "Utility/Log.h"

namespace Gem {
	void EventSystem::StartUp() {
		m_Started = true;
	}

	void EventSystem::ShutDown() {
		m_Started = false;
	}

	EventSystem& EventSystem::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp EventSystem, before using it.", LogLevel::TERMINAL);
		}

		static EventSystem eventSystem;
		return eventSystem;
	}
}