#pragma once

#include "PhysicsObject.h"

namespace Pyrite {
	extern const float GravitationalConstant;

	namespace ForceGenerator {
		Newton3D gravitationalForce(PhysicsObject* supplier, PhysicsObject* reciever);
	}
}