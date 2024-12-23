#pragma once

#include <vector>

#include "PhysicsObject.h"

namespace Gem {
	class PhysicsWorld {
	public:
		PhysicsWorld();

		void step() const;
		void addObject(PhysicsObject& physicsObject);

	private:
		std::vector<PhysicsObject*> physicsObjects;
	};
}