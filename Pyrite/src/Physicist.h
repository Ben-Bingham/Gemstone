#pragma once

#include <vector>

#include "Timing.h"
#include "PhysicsObject.h"

namespace Pyrite {
	class Physicist {
	public:
		Physicist(Wavellite::Time& timeObj);

		void addObject(PhysicsObject* object);

		// Per frame calls
		void calculate();

	private:
		Wavellite::Time& time;
		std::vector<PhysicsObject*> objects;
	};
}