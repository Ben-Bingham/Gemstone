#include "Physics/Collisions/CollisionDetection.h"
#include "Physics/Collisions/Colliders/ColliderObject.h"
#include "Physics/Collisions/Colliders/ColliderType.h"
#include "Physics/Collisions/Colliders/FixedBoxCollider.h"

#include "Utility/Log.h"

namespace Gem {
	bool Collide(ColliderObject colliderA, ColliderObject colliderB) {
		if (colliderA.collider->Type() == colliderB.collider->Type()) {
			switch (colliderA.collider->Type()) {
			case ColliderType::FIXED_BOX:
				return FixedBoxFixedBox(colliderA, colliderB);
			default:
				LOG("Unknown collider type", LogLevel::ERROR);
				break;
			}
		}
		else {
			LOG("Unknown collider type", LogLevel::ERROR);
		}
	}

	bool FixedBoxFixedBox(const ColliderObject& colliderA, const ColliderObject& colliderB) {
		const Ptr<FixedBoxCollider> fixedA = std::static_pointer_cast<FixedBoxCollider>(colliderA.collider);
		const Ptr<FixedBoxCollider> fixedB = std::static_pointer_cast<FixedBoxCollider>(colliderB.collider);

		const Vector3f minA = colliderA.transform.position + fixedA->minDistances;
		const Vector3f maxA = colliderA.transform.position + fixedA->maxDistances;

		const Vector3f minB = colliderB.transform.position + fixedB->minDistances;
		const Vector3f maxB = colliderB.transform.position + fixedB->maxDistances;

		if (maxA.x > minB.x &&
			minA.x < maxB.x &&
			maxA.y > minB.y &&
			minA.y < maxB.y &&
			maxA.z > minB.z &&
			minA.z < maxB.z) {
			return true;
		}

		return false;
	}
}