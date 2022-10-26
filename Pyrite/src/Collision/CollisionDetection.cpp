#include "CollisionDetection.h"

namespace Pyrite {
	namespace CollisionDetection {
		bool boxWithBox(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2) { //TODO optimize
			if (box1->max.x > box2->min.x &&		
				box1->min.x < box2->max.x &&
				box1->max.y > box2->min.y &&
				box1->min.y < box2->max.y &&
				box1->max.z > box2->min.z &&
				box1->min.z < box2->max.z) {
				return true;
			}

			return false;
		}

		Collider::Collision boxWithBoxInfo(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2) {
			Collider::Collision collision;

			Point3D originDisplacement = box1->getOrigin() - box2->getOrigin();

			Meter xPenetration = originDisplacement.x;
			Meter yPenetration = originDisplacement.y;
			Meter zPenetration = originDisplacement.z;

			if (xPenetration < yPenetration && xPenetration < zPenetration) {
				collision.normal = Direction{ xPenetration }.normalize();
			}
			else if (yPenetration < zPenetration && yPenetration < xPenetration) {
				collision.normal = Direction{ yPenetration }.normalize();
			}
			else {
				collision.normal = Direction{ zPenetration }.normalize();
			}

			return collision;
		}
	}
}