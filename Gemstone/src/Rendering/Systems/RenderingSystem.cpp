#include "pch.h"
#include "RenderingSystem.h"


#include "Core/Engine.h"

#include "Entity Component System/ComponentView.h"

#include "Rendering/Components/Camera.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/Material/Material.h"

#include "Utility/Transform.h"

namespace Gem {
	void RenderingSystem::Step(EntityManager& entityManager, float dt) {
		for (auto [transform, material, mesh] : ComponentView<Transform, Material, Mesh>{entityManager}) {
			g_Engine.renderer.Queue(mesh.m_InternalMesh, material.iMaterial, transform.Matrix());
		}

		for (auto& camera : ComponentView<Camera>{ entityManager }) {
			g_Engine.renderer.AddCamera(camera);
		}
	}

	void RenderingSystem::HandleEvent(const WindowEvents::Resize& event) {
		g_Engine.openGlContext.SetViewportSize(event.size);
	}
}