#pragma once
#include "Core/Event System/EventSystem.h"
#include "Gem.h"

namespace Gem {
	template<typename EventType>
	class EventHandler {
	public:
		EventHandler() {
			GetEventId<EventType>();
			EventSystem::Get().GetEventTypeManager<EventType>()->AddHandler(this);
		}

		virtual ~EventHandler() {
			EventSystem::Get().GetEventTypeManager<EventType>()->RemoveHandler(this);
		}

		EventHandler(const EventHandler& other) = default;
		EventHandler(EventHandler&& other) noexcept = default;
		EventHandler& operator=(const EventHandler& other) = default;
		EventHandler& operator=(EventHandler&& other) noexcept = default;
	
		virtual void HandleEvent(const EventType& event) = 0;
	};
}
