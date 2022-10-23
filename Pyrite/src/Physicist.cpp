#include "Physicist.h"
#include "Units.h"

namespace Pyrite {
	Physicist::Physicist(Wavellite::Time& timeObj)
		: time(timeObj) {

	}

	void Physicist::addObject(PhysicsObject* object) {
		objects.push_back(object);
	}

	void Physicist::calculate(PhysicsObject* object) {
		std::vector<PhysicsObject*> interactingObjects;
		for (PhysicsObject* physObj : objects) {
			if (physObj != object) {
				interactingObjects.push_back(physObj);
			}
		}

		object->calcNetForce(interactingObjects);
		object->calcVelocity(time.deltaTime);
		object->calcPosition(time.deltaTime);
	}
}