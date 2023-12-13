#pragma once
#include "IEventTypeManager.h"
#include "Gem.h"

namespace Gem {
	template<typename EventType>
	class EventHandler;

	template<typename EventType>
	class EventTypeManager final : public IEventTypeManager {
	public:
		EventTypeManager() = default;
		EventTypeManager(const EventTypeManager& other) = default;
		EventTypeManager(EventTypeManager&& other) noexcept = default;
		EventTypeManager& operator=(const EventTypeManager& other) = default;
		EventTypeManager& operator=(EventTypeManager&& other) noexcept = default;
		~EventTypeManager() override = default;

		void Distribute() override {
			for (auto& handler : m_Handlers) {
				for (auto& event : m_EventQueue) {
					handler->HandleEvent(event);
				}
			}

			m_EventQueue.clear();
		}

		void AddHandler(EventHandler<EventType>* eventHandler) {
			m_Handlers.push_back(eventHandler);
		}

		void RemoveHandler(EventHandler<EventType>* eventHandler) {
			m_Handlers.erase(std::remove(m_Handlers.begin(), m_Handlers.end(), eventHandler), m_Handlers.end());
		}

		void Post(const EventType& event) {
			m_EventQueue.push_back(event);
		}

	private:
		std::vector<EventHandler<EventType>*> m_Handlers{};
		std::vector<EventType> m_EventQueue;
	};

}