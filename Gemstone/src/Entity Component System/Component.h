#pragma once

#include <bitset>
#include <cassert>
#include "Gem.h"

namespace Gem {
	constexpr size_t MAX_ENTITIES = 16; // TODO Maybe place these in a differnt file
	constexpr size_t MAX_COMPONENT_TYPES = 32;

	inline size_t g_ComponentIdCounter{ 0 };

	using ComponentMask = std::bitset<MAX_COMPONENT_TYPES>;

	template<typename ComponentType>
	struct GEM_API ComponentInfo {
	private:
		static ComponentMask GetMaskWithIndexSet() {
			assert(id < MAX_COMPONENT_TYPES && "Index out of range, too many components exist.");

			return ComponentMask{}.set(id);
		}

	public:
		static inline const size_t id{ g_ComponentIdCounter++ };
		static inline const ComponentMask mask{ GetMaskWithIndexSet() };
	};
}