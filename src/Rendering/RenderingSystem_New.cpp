#include "Entity Component System/View.h"
#include "Rendering/RenderingSystem_New.h"
#include "Rendering/Renderable.h"
#include "Rendering/Materials/Material.h"
#include "Rendering/Meshes/Mesh.h"
#include "Utility/Transform.h"
#include "Utility/Utility.h"

namespace Gem {
	void RenderingSystem_New(Engine& engine, EntityComponentSystem& ecs) {
		/*std::vector<Renderable> renderables;

		for (auto [ent, mesh, material, transform] : View<Mesh, Material, Transform>(ecs)) {
			renderables.push_back(Renderable{ Mesh::meshRegister.GetMesh(mesh.hash), material.material, transform.Matrix() });
		}

		engine.renderer.renderables = renderables;*/
	}
}