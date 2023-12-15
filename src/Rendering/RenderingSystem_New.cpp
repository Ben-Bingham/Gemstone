#include "Entity Component System/View.h"
#include "Rendering/RenderingSystem_New.h"
#include "Rendering/Meshes/Mesh.h"
#include "Utility/Transform.h"
#include "Utility/Utility.h"

namespace Gem {
	void RenderingSystem_New(EntityComponentSystem& ecs) {
		/*for (auto [ent, mesh, material, transform] : View<Mesh, Material, Transform>(ecs)) {
			Print(mesh.hash, transform.position);
		}*/

		for (auto [ent, mesh, transform] : View<Mesh, Transform>(ecs)) {
			Print(mesh.hash, transform.position);
		}
	}
}