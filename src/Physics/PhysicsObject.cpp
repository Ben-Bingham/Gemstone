#include "pch.h"
#include "Physics/PhysicsObject.h"

namespace Gem {
	using namespace Literals;

	PhysicsObject::PhysicsObject(/*Kilogram Mass, */Point3D Position/*, Velocity Velocity, Newton3D NetForce*/)
		: /*mass(Mass), netForce(NetForce), velocity(Velocity), */position(Position) {

	}

	//void PhysicsObject::addForce(Newton3D force) {
	//	netForce += force;
	//}

	//void PhysicsObject::calcVelocity(Second deltaTime) {
	//	velocity += (netForce / mass) * deltaTime;
	//}

	//void PhysicsObject::calcPosition(Second deltaTime) {
	//	position += velocity * deltaTime;
	//}
}