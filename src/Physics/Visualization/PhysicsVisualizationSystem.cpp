#include "Entity Component System/View.h"

#include "Physics/Visualization/PhysicsVisualizationSystem.h"
#include "Physics/PhysicalProperties.h"
#include "Physics/Visualization/PhysicsVisualizationComponent.h"

#include "Rendering/Renderer.h"

#include "Utility/Transform.h"

namespace Gem {
	void PhysicsVisualizationSystem(EntityComponentSystem& ecs) {
		for (auto [ent, transform, properties, vc] : View<Transform, PhysicalProperties, PhysicsVisualizationComponent>{ ecs }) {
			Renderer::Debug& debug = Renderer::Get().debug;

			if (vc.velocity) {
				debug.Add(transform.position, transform.position + properties.velocity, Colour::Green);
			}

			if (vc.acceleration) {
				debug.Add(transform.position, transform.position + properties.acceleration, Colour::Yellow);
			}

			if (vc.netForce) {
				debug.Add(transform.position, transform.position + properties.netForce, Colour::Blue);
			}
		}
	}
}