#include "Entity Component System/View.h"

#include "Physics/Collisions/CollisionSystem.h"
#include "Physics/PhysicalProperties.h"
#include "Physics/Collisions/Colliders/Collider.h"
#include "Physics/Collisions/CollisionDetection.h"
#include "Physics/Collisions/Colliders/ColliderObject.h"

#include "Utility/Transform.h"
#include "Utility/Utility.h"

namespace Gem {
	void CollisionSystem(EntityComponentSystem& ecs) {
		std::vector<std::pair<int, int>> collisions;

		for (auto [entA, colliderA, transformA] : View<Collider, Transform>{ ecs }) {
			for (auto [entB, colliderB, transformB] : View<Collider, Transform>{ ecs }) {
				if (entA == entB) {
					continue;
				}

				std::pair<int, int> collision;

				// Always place lower entity in first position
				if (entA < entB) {
					collision = std::make_pair(entA, entB);
				}
				else {
					collision = std::make_pair(entB, entA);
				}

				if (std::ranges::find(collisions.begin(), collisions.end(), collision) != collisions.end()) {
					continue;
				}

				collisions.push_back(collision);

				if (Collide(ColliderObject{ colliderA.collider, transformA }, ColliderObject{ colliderB.collider, transformB })) {
					//Vector3f distanceVector = transformA.position - transformB.position;
					//float distanceMagnitude = distanceVector.Magnitude();
					//Vector3f distanceDirection = distanceVector.normalize();
					
					//Print("Distance Vector", distanceVector);
					//Print("Distance Magnitude", distanceMagnitude);
					//Print("Distance Direction", distanceDirection);

					bool aHas = ecs.componentManager.HasComponent<PhysicalProperties>(entA);
					bool bHas = ecs.componentManager.HasComponent<PhysicalProperties>(entB);

					if (aHas && bHas) {
						PhysicalProperties& aProperties = ecs.componentManager.GetComponent<PhysicalProperties>(entA);
						PhysicalProperties& bProperties = ecs.componentManager.GetComponent<PhysicalProperties>(entB);

						// TODO need to implement having collisions on only one plane
						const Vector3f v1 = aProperties.velocity;
						const Vector3f v2 = bProperties.velocity;

						const float m1 = aProperties.mass;
						const float m2 = bProperties.mass;

						constexpr float e = 1.0f;

						// v1' = (m1v1 + m2v2 - ev1m2 + ev2m2) / (m1 + m2)
						// v2' = (m1v1 + m2v2 - m1v1') / m2

						const Vector3f v1AfterMag = (m1 * v1 + m2 * v2 - e * v1 * m2) / (m1 + m2);
						const Vector3f v2AfterMag = (m1 * v1 + m2 * v2 - m1 * v1AfterMag) / m2;


						//const Vector3f v1After = (m1 * v1 + m2 * v2 + m2 * e * (v2 - v1)) / (m1 + m2);
						//const Vector3f v2After = (m1 * v1 + m2 * v2 + m1 * e * (v1 - v2)) / (m1 + m2);

						Vector3f aVelocityDir = (transformA.position - transformB.position).normalize();
						Vector3f bVelocityDir = (transformB.position - transformA.position).normalize();

						Print("=====");
						Print("AVelocityDir:", aVelocityDir);
						Print("BVelocityDir:", bVelocityDir);

						aProperties.velocity = v1AfterMag * aVelocityDir;
						bProperties.velocity = v2AfterMag * bVelocityDir;
					}
					else if (aHas && !bHas) {
						// TODO
					}
					else if (!aHas && bHas) {
						// TODO
					}

					/*colliderA.Callbacks();
					colliderB.Callbacks();*/
				}
			}
		}
	}
}