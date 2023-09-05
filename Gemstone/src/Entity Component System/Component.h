#pragma once

#include <bitset>

#include "ECSConstants.h"

#include "Utility/Log.h"

namespace Gem {
	inline size_t g_ComponentIdCounter{ 0 };

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
		static inline const size_t id{ g_ComponentIdCounter++ };
		static inline const ComponentMask mask{ GetMaskWithIndexSet(id) };
	};

	// class ComponentParent {
	// public:
	// 	ComponentParent();
	// 	~ComponentParent();
	//
	// 	ComponentParent(const ComponentParent& other) = default;
	// 	ComponentParent(ComponentParent&& other) noexcept = default;
	// 	ComponentParent& operator=(const ComponentParent& other) = default;
	// 	ComponentParent& operator=(ComponentParent&& other) noexcept = default;
	//
	// 	ComponentMask validMask;
	// 	static inline const size_t id{ g_ComponentIdCounter++ };
	// };
}