#pragma once

#include "Units.h"

namespace Pyrite {
	class PhysicsObject {
	public:
		PhysicsObject(Kilogram Mass) 
			: mass(Mass) {

		}

	protected:
		Kilogram mass;
	};
}