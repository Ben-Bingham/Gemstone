#include "CollisionDetection.h"

#include "Utility.h"
#include "Log.h"

namespace Pyrite {
	namespace CollisionDetection {
		Collider::Collision AABBWithAABB(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2) {
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

			Point3D box1Origin = box1->position;
			Point3D box2Origin = box2->position;

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

			Direction normal = (aIntoB - bIntoA).normalize();

			if (normal.x < normal.y && normal.x < normal.z) {
				normal.y = 0.0_m;
				normal.z = 0.0_m;
			}
			else if (normal.y < normal.x && normal.y < normal.z) {
				normal.x = 0.0_m;
				normal.z = 0.0_m;
			}
			else {
				normal.x = 0.0_m;
				normal.y = 0.0_m;
			}

			return Collider::Collision{ aIntoB, bIntoA, normal, (aIntoB - bIntoA).length(), collided };
		}

		Collider::Collision AABBWithSphere(const AxisAlignedBoxCollider* box, const SphereCollider* sphere) {
			Meter distanceBetween = (box->position- sphere->position).length();
			Point3D boxMeasurementsOver2 = box->getDimensions() / 2.0f;

			bool collided;
			if ((boxMeasurementsOver2.x + sphere->radius) < distanceBetween &&
				(boxMeasurementsOver2.y + sphere->radius) < distanceBetween &&
				(boxMeasurementsOver2.z + sphere->radius) < distanceBetween) {
				collided = false;
			}
			else {
				collided = true;
			}

			Point3D boxOrigin = box->position;

			Point3D boxDimensions = box->getDimensions();

			Point3D aIntoB = sphere->position - box->position;
			aIntoB.x = Malachite::clamp(aIntoB.x, -boxDimensions.x / 2.0f, boxDimensions.x / 2.0f);
			aIntoB.y = Malachite::clamp(aIntoB.y, -boxDimensions.y / 2.0f, boxDimensions.y / 2.0f);
			aIntoB.z = Malachite::clamp(aIntoB.z, -boxDimensions.z / 2.0f, boxDimensions.z / 2.0f);

			Point3D bIntoA = box->position - sphere->position;
			bIntoA = bIntoA.normalize();
			bIntoA *= sphere->radius;

			Direction normal = (aIntoB - bIntoA).normalize();

			if (normal.x < normal.y && normal.x < normal.z) {
				normal.y = 0.0_m;
				normal.z = 0.0_m;
			}
			else if (normal.y < normal.x && normal.y < normal.z) {
				normal.x = 0.0_m;
				normal.z = 0.0_m;
			}
			else {
				normal.x = 0.0_m;
				normal.y = 0.0_m;
			}

			return Collider::Collision{ aIntoB, bIntoA, normal, (aIntoB - bIntoA).length(), collided };
		}

		Collider::Collision SphereWithSphere(const SphereCollider* sphere1, const SphereCollider* sphere2) {
			Meter distanceBetween = (sphere1->position - sphere2->position).length();

			bool collided;
			if (distanceBetween < (sphere1->radius + sphere2->radius)) {
				collided = true;
			}
			else {
				collided = false;
			}

			Point3D aIntoB = sphere2->position - sphere1->position;
			aIntoB = aIntoB.normalize();
			aIntoB *= sphere1->radius;

			Point3D bIntoA = sphere1->position - sphere2->position;
			bIntoA = bIntoA.normalize();
			bIntoA *= sphere2->radius;

			return Collider::Collision{ aIntoB, bIntoA, (aIntoB - bIntoA).normalize(), (aIntoB - bIntoA).length(), collided};
		}
	}
}