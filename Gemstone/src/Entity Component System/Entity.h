#pragma once

#include "Component.h"

namespace Gem {
	// Should only store data about an Entity, eventually can be all condensed into a single 32 or 64 bit value.
	// struct Entity {
	// 	size_t id{ 0 };
	// 	ComponentMask componentMask{ 0 };
	// 	bool isAlive{ false };
	//
	// 	friend bool operator==(const Entity& lhs, const Entity& rhs) {
	// 		return lhs.id == rhs.id
	// 			&& lhs.componentMask == rhs.componentMask
	// 			&& lhs.isAlive == rhs.isAlive;
	// 	}
	//
	// 	friend bool operator!=(const Entity& lhs, const Entity& rhs) { return !(lhs == rhs); }
	// };

	using Entity = size_t;
}