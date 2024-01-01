#pragma once
#include <vector>

#include "Colliders/Collider.h"

namespace Gem {
	class CollisionWorld {
	public:
		CollisionWorld();
		
		void step() const;
		void addCollider(Collider& collider);

	private:
		std::vector<Collider*> colliders;
	};
}