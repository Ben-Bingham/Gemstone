#include "CollisionDetection.h"

#include "Utility.h"

namespace Pyrite {
	namespace CollisionDetection {
		Collider::Collision AABBwithAABB(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2) {
			bool collided;
			if (box1->max.x > box2->min.x &&
				box1->min.x < box2->max.x &&
				box1->max.y > box2->min.y &&
				box1->min.y < box2->max.y &&
				box1->max.z > box2->min.z &&
				box1->min.z < box2->max.z) {
				collided = true;
			}
			else {
				collided = false;
			}

			Point3D box1Origin = box1->getOrigin();
			Point3D box2Origin = box2->getOrigin();

			Point3D box1Dimensions = box1->getDimensions();

			Point3D aIntoB = box1Origin - box2Origin;
			aIntoB.x = Malachite::clamp(aIntoB.x, -box1Dimensions.x / 2.0f, box1Dimensions.x / 2.0f);
			aIntoB.y = Malachite::clamp(aIntoB.y, -box1Dimensions.y / 2.0f, box1Dimensions.y / 2.0f);
			aIntoB.z = Malachite::clamp(aIntoB.z, -box1Dimensions.z / 2.0f, box1Dimensions.z / 2.0f);

			Point3D box2Dimensions = box2->getDimensions();

			Point3D bIntoA = box1Origin - box2Origin;
			bIntoA.x = Malachite::clamp(bIntoA.x, -box2Dimensions.x / 2.0f, box2Dimensions.x / 2.0f);
			bIntoA.y = Malachite::clamp(bIntoA.y, -box2Dimensions.y / 2.0f, box2Dimensions.y / 2.0f);
			bIntoA.z = Malachite::clamp(bIntoA.z, -box2Dimensions.z / 2.0f, box2Dimensions.z / 2.0f);


			return Collider::Collision{ aIntoB, bIntoA, (aIntoB - bIntoA).normalize(), (aIntoB - bIntoA).length(), collided };
		}
	}
}