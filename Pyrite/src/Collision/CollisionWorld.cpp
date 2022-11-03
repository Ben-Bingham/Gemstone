#include "CollisionWorld.h"
#include "Log.h"

namespace Pyrite {
	CollisionWorld::CollisionWorld() { }

	void CollisionWorld::step() const {
		std::vector<Collider::Collision> collisions;
		collisions.reserve(colliders.size() * colliders.size());

		// TODO this can be much more efficient ie. broad phase collision detection
		for (Collider* collider1 : colliders) {
			for (Collider* collider2 : colliders) {
				if (collider1 != collider2) {
					Collider::Collision collision = collider1->collidesWith(collider2);

					if (collision.hasCollision) {
						collisions.push_back(collision);
					}
				}
				
			}
		}

		// TODO resolve all collisions in collisions vector

		LOG(std::to_string(collisions.size()));
	}

	void CollisionWorld::addCollider(Collider& collider) {
		colliders.push_back(&collider);
	}
}