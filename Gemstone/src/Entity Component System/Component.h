#pragma once

#include <bitset>

#include "Entity.h"
#include "Utility/Log.h"

namespace Gem {
	inline unsigned int g_ComponentIdCounter{ 0 };

	using ComponentMask = std::bitset<MAX_COMPONENT_TYPES>;

	template<typename ComponentType>
	struct ComponentInfo {
	private:
		static ComponentMask GetMaskWithIndexSet(const size_t index) {
#ifdef GEMSTONE_DEBUG
			if (index >= MAX_COMPONENT_TYPES) {
				LOG("Index out of range, too many components exist.", LogLevel::ERROR);
			}
#endif
			ComponentMask mask{};

			mask.set(index);

			return mask;
		}

	public:
		static inline const unsigned int id{ g_ComponentIdCounter++ };
		static inline const ComponentMask mask{ GetMaskWithIndexSet(id) };
	};
}