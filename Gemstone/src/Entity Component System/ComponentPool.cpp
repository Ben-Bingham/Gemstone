#include "pch.h"
#include "ComponentPool.h"

namespace Gem {
// 	ComponentPool::ComponentPool(const size_t componentId, const size_t componentSize)
// 		: m_ComponentId(componentId)
// 		, m_ComponentSize(componentSize)
// 		, m_Components(new unsigned char[m_ComponentSize * MAX_ENTITIES]) {
// 		
// 	}
//
// 	void* ComponentPool::Get(const Entity& entity) const {
// #ifdef GEMSTONE_DEBUG
// 		if (!Has(entity)) {
// 			LOG("Atempted to get component from Entity without component, nullptr will be returned.", LogLevel::ERROR);
// 			return nullptr;
// 		}
// #endif
// 		return m_Components + m_ComponentSize * entity.id;
// 	}
//
// 	bool ComponentPool::Has(const Entity& entity) const {
// 		return entity.componentField[m_ComponentId];
// 	}
}