#include "CollisionDetection.h"

namespace Pyrite {
	namespace CollisionDetection {
		bool boxWithBox(const BoxCollider* box1, const BoxCollider* box2) {
			// box 1
			Meter maxX1 = box1->position.x + (box1->dimensions.x / 2);
			Meter minX1 = box1->position.x - (box1->dimensions.x / 2);

			Meter maxY1 = box1->position.y + (box1->dimensions.y / 2);
			Meter minY1 = box1->position.y - (box1->dimensions.y / 2);

			Meter maxZ1 = box1->position.z + (box1->dimensions.z / 2);
			Meter minZ1 = box1->position.z - (box1->dimensions.z / 2);

			// box 2
			Meter maxX2 = box2->position.x + (box2->dimensions.x / 2);
			Meter minX2 = box2->position.x - (box2->dimensions.x / 2);

			Meter maxY2 = box2->position.y + (box2->dimensions.y / 2);
			Meter minY2 = box2->position.y - (box2->dimensions.y / 2);

			Meter maxZ2 = box2->position.z + (box2->dimensions.z / 2);
			Meter minZ2 = box2->position.z - (box2->dimensions.z / 2);

			if (maxX1 > minX2 && 
				minX1 < maxX2 &&
				maxY1 > minY2 &&
				minY1 < maxY2 &&
				maxZ1 > minZ2 &&
				minZ1 < maxZ2) {
				return true;
			}

			return false;
		}
	}
}