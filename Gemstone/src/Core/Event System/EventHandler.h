#pragma once
#include "Core/Event System/EventSystem.h"

namespace Gem {
	template<typename EventType>
	class EventHandler {
	public:
		EventHandler(EventSystem& eventSystem)
			: m_EventSystem(eventSystem) {
			GetEventId<EventType>();
			m_EventSystem.GetEventTypeManager<EventType>()->AddHandler(this);
		}

		virtual ~EventHandler() {
			m_EventSystem.GetEventTypeManager<EventType>()->RemoveHandler(this);
		}

		EventHandler(const EventHandler& other) = default;
		EventHandler(EventHandler&& other) noexcept = default;
		EventHandler& operator=(const EventHandler& other) = default;
		EventHandler& operator=(EventHandler&& other) noexcept = default;
	
		virtual void HandleEvent(const EventType& event) = 0;

	private:
		EventSystem& m_EventSystem;
	};
}
