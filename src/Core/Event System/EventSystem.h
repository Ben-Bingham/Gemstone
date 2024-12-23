#pragma once
#include <vector>

#include "Utility/Pointer.h"
#include "EventTypeManager.h"
#include "Event.h"

namespace Gem {
	class EventSystem {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		EventSystem() = default;
		~EventSystem() = default;

		static inline bool m_Started{ false };

	public:
		static EventSystem& Get();

		EventSystem(const EventSystem& other) = delete;
		EventSystem(EventSystem&& other) noexcept = default;
		EventSystem& operator=(const EventSystem& other) = delete;
		EventSystem& operator=(EventSystem&& other) noexcept = default;

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

	private:
		std::vector<Ptr<IEventTypeManager>> m_EventTypeManagers{ };
	};
}