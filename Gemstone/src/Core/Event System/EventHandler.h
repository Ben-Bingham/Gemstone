#pragma once
#include "Core/Event System/EventSystem.h"
#include "Core/Engine.h"

namespace Gem {
	template<typename EventType>
	class EventHandler {
	public:
		EventHandler() {
			GetEventId<EventType>();
			g_Engine.eventManager.GetEventTypeManager<EventType>()->AddHandler(this);
		}

		EventHandler(const EventHandler& other) = default;
		EventHandler(EventHandler&& other) noexcept = default;
		EventHandler& operator=(const EventHandler& other) = default;
		EventHandler& operator=(EventHandler&& other) noexcept = default;

		virtual ~EventHandler() {
			g_Engine.eventManager.GetEventTypeManager<EventType>()->RemoveHandler(this);
		}
	
		virtual void HandleEvent(const EventType& event) = 0;
	};
}
