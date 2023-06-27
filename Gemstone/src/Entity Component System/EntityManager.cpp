#include "pch.h"
#include "EntityManager.h"

namespace Gem {
	Entity EntityManager::Create() {
		const unsigned int nextEntityId = (unsigned int)m_EntityDescriptions.size();

		m_EntityDescriptions.resize(nextEntityId + 1);

		m_EntityDescriptions[nextEntityId].second = true;

		return Entity{ nextEntityId };
	}

	void EntityManager::Kill(Entity& entity) {
		ThrowErrorIfDead(entity);

		if (GetMask(entity) != 0) {
			LOG("Attempting to kill entity that still has comonents.", LogLevel::ERROR);
		}

		m_EntityDescriptions[entity].second = false;
	}

	ComponentMask& EntityManager::GetMask(const Entity entity) const {
		ThrowErrorIfDead(entity);

		if (m_EntityDescriptions.size() <= entity) {
			m_EntityDescriptions.resize(entity + 1);
		}

		return m_EntityDescriptions[entity].first;
	}

	bool EntityManager::IsAlive(const Entity entity) const {
		if (m_EntityDescriptions.size() <= entity) {
			return false;
		}

		return m_EntityDescriptions[entity].second;
	}

	void EntityManager::ThrowErrorIfDead(const Entity entity) const {
		if (!IsAlive(entity)) {
			LOG("Attempting to perform action on dead Entity.", LogLevel::ERROR);
		}
	}
}