#pragma once

#include <vector>

#include "PhysicsObject.h"

namespace Pyrite {
	class PhysicsWorld {
	public:
		PhysicsWorld();

		void step() const;
		void addObject(PhysicsObject& physicsObject);

	private:
		std::vector<PhysicsObject*> physicsObjects;
	};
}