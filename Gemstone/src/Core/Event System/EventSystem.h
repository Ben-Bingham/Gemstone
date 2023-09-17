#pragma once
#include <algorithm>
#include <vector>

#include "Utility/Pointer.h"
#include "EventTypeManager.h"
#include "Event.h"

namespace Gem {
	class EventSystem {
	public:
		EventSystem(const EventSystem& other) = delete;
		EventSystem(EventSystem&& other) noexcept = default;
		EventSystem& operator=(const EventSystem& other) = delete;
		EventSystem& operator=(EventSystem&& other) noexcept = default;

		static EventSystem& Get();

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
		EventSystem() = default;
		~EventSystem() = default;

		std::vector<Ptr<IEventTypeManager>> m_EventTypeManagers{};
	};
}