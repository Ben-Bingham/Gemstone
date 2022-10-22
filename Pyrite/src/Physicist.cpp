#include "Physicist.h"
#include "Units.h"

namespace Pyrite {
	Physicist::Physicist(Wavellite::Time& timeObj)
		: time(timeObj) {

	}

	void Physicist::addObject(PhysicsObject* object) {
		objects.push_back(object);
	}

	void Physicist::calculate() {
		for (PhysicsObject* object : objects) {
			std::vector<PhysicsObject*> interactingObjects;
			for (PhysicsObject* object2 : objects) {
				if (object != object2) {
					interactingObjects.push_back(object2);
				}
			}
			object->calcNetForce(interactingObjects);
			object->calcVelocity(time.deltaTime);
			object->calcPosition(time.deltaTime);
		}
	}
}