#include "Entity Component System/View.h"
#include "Rendering/RenderingSystem.h"
#include "Rendering/CameraObject.h"
#include "Rendering/Renderable.h"
#include "Rendering/Renderer.h"
#include "Rendering/Materials/Material.h"
#include "Rendering/Meshes/Mesh.h"
#include "Utility/Transform.h"
#include "Utility/Log.h"

namespace Gem {
	void RenderingSystem(EntityComponentSystem& ecs) {
		std::vector<Renderable> renderables;

		for (auto [ent, mesh, material, transform] : View<Mesh, Material, Transform>(ecs)) {
			renderables.push_back(Renderable{ Mesh::meshRegister.GetMesh(mesh.hash), material.material, transform.Matrix() });
		}

		// Reassign the list, because it makes future optimizations easier to implement;
		Renderer::Get().renderables = renderables;

		std::vector<CameraObject> cameraObjects;

		for (auto [ent, camera, transform] : View<Camera, Transform>(ecs)) {
			cameraObjects.push_back(CameraObject{ camera, transform });
		}

		if (cameraObjects.empty()) {
			LOG("No cameras found.", LogLevel::ERROR);
		}
		else if (cameraObjects.size() > 1) {
			LOG("Too many cameras found.", LogLevel::ERROR);
		}

		Renderer::Get().camera = cameraObjects[0];
	}
}