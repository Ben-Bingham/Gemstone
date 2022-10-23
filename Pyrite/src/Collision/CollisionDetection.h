#pragma once

#include "Colliders/BoxCollider.h"

namespace Pyrite {
	namespace CollisionDetection {
		bool boxWithBox(const BoxCollider* box1, const BoxCollider* box2);
	}
}