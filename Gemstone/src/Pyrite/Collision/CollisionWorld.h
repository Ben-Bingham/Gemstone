#pragma once

#include <vector>

#include "Pyrite/Collision/Colliders/Collider.h"

namespace Pyrite {
	class CollisionWorld {
	public:
		CollisionWorld();
		
		void step() const;
		void addCollider(Collider& collider);

	private:
		std::vector<Collider*> colliders;
	};
}