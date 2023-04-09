#pragma once
#include "Core/ISubSystem.h"
#include <algorithm>
#include <vector>

#include "Utility/Pointer.h"

namespace Gem {
	using EventId = unsigned int;
	inline EventId g_MasterId{ 0 };

	template<typename T>
	EventId GetEventId() {
		static EventId id = g_MasterId++;
		return id;
	}

	class IEventTypeManager {
	public:
		IEventTypeManager() = default;
		IEventTypeManager(const IEventTypeManager& other) = default;
		IEventTypeManager(IEventTypeManager&& other) noexcept = default;
		IEventTypeManager& operator=(const IEventTypeManager& other) = default;
		IEventTypeManager& operator=(IEventTypeManager&& other) noexcept = default;
		virtual ~IEventTypeManager() = default;

		virtual void Distribute() = 0;
	};

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
		std::vector<EventHandler<EventType>*> m_Handlers{}; //TODO handlers becoming nullptr
		std::vector<EventType> m_EventQueue;
	};

	class EventSystemManager : ISubSystem {
	public:
		EventSystemManager() = default;

		template <typename T>
		Ptr<EventTypeManager<T>> GetEventTypeManager() {
			const EventId id = GetEventId<T>();

			if (m_EventTypeManagers.size() <= id) {
				m_EventTypeManagers.resize(id + 1);
			}

			if (!m_EventTypeManagers[id]) {
				m_EventTypeManagers[id] = CreatePtr<EventTypeManager<T>>();
			}

			return std::dynamic_pointer_cast<EventTypeManager<T>>(m_EventTypeManagers[id]);
		}

		template <typename T>
		void Post(const T& event) {
			GetEventTypeManager<T>()->Post(event);
		}

		void Distribute() const {
			for (const auto& handler : m_EventTypeManagers) {
				handler->Distribute();
			}
		}

		void StartUp() override {}
		void ShutDown() override {}

	private:
		std::vector<Ptr<IEventTypeManager>> m_EventTypeManagers{};
	};

	// inline EventSystemManager g_GlobalEventManager{};
}