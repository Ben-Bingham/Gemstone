#include "ForceGenerator.h"

#include "Powers.h"

namespace Pyrite {
	const float GravitationalConstant{ Malachite::ee(6.67430f, -11.0f) };

	namespace ForceGenerator {
		Newton3D gravitationalForce(PhysicsObject* supplier, PhysicsObject* reciever) {
			Displacement displacementBetween = supplier->position - reciever->position;
			Meter distanceBetween = displacementBetween.length();
			Newton gravForce = (Newton)(GravitationalConstant * supplier->mass * reciever->mass) / (distanceBetween * distanceBetween);
			
			Point3D direction = displacementBetween.normalize();
			Newton3D gravFoce3D = gravForce * direction;
			return gravFoce3D;
		}
	}
}