#include "Entity Component System/View.h"

#include "Physics/PhysicsSystem_New.h"
#include "Physics/PhysicalProperties.h"

#include "Utility/Time.h"
#include "Utility/Transform.h"
#include "Utility/Utility.h"

namespace Gem {
	void PhysicsSystem_New(EntityComponentSystem& ecs) {
		for (auto [ent, transform, properties] : View<Transform, PhysicalProperties>{ ecs }) {
			properties.acceleration = properties.netForce / properties.mass;
			properties.velocity += properties.acceleration * Time::deltaTime;
			transform.position += properties.velocity * Time::deltaTime;

			properties.netForce = Vector3f{ 0.0f };
		}
	}
}