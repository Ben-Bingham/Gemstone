#pragma once

#include "PhysicsObject.h"

namespace Gem {
	extern const float GravitationalConstant;

	namespace ForceGenerator {
		Newton3D gravitationalForce(PhysicsObject* supplier, PhysicsObject* reciever);
	}
}