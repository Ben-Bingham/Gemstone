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
		
		// Cleans up duplicate collisions //TODO should happen before collision is even calculated
		std::vector<Collider::Collision>::iterator it;
		for (it = collisions.begin(); it != collisions.end(); it++) {
			for (Collider::Collision& collision2 : collisions) {
				if (*it == collision2) {
					it = collisions.erase(it);
					break;
				}
			}
		}

		//LOG(std::to_string(collisions.size()));

		// TODO resolve all collisions in collisions vector
		for (Collider::Collision& collision : collisions) {
			/*Pyrite::Speed speed = Malachite::dot(collision.normal, movingObject.velocity - staticObject.velocity);
			if (speed > 0) {
				Pyrite::KilogramMeterPerSeconds impulse = 2 * speed / (movingObject.mass + staticObject.mass);

				movingObject.velocity -= (impulse * staticObject.mass * collision.normal);
				staticObject.velocity += (impulse * staticObject.mass * collision.normal);
			}*/
		}
	}

	void CollisionWorld::addCollider(Collider& collider) {
		colliders.push_back(&collider);
	}
}