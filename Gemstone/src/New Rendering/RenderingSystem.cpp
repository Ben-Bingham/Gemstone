#include "pch.h"
#include "RenderingSystem.h"
#include "Components/Material.h"
#include "Components/Mesh.h"

#include "Core/Engine.h"

#include "Entity Component System/ComponentView.h"
#include "Utility/Transform.h"

namespace Gem {
	void RenderingSystem::Step(EntityManager& entityManager) {
		for (auto [transform, material, mesh] : ComponentView<Transform, Material, Mesh>{entityManager}) {
			MeshComponents& meshComponents = m_MeshComponents[mesh.id];

			// if (std::get<0>(meshComponents).Handle() == 0) {
			// 	m_Vaos[mesh->id] = g_Engine.openGlContext.GenerateVertexAttributeObject();
			// 	g_Engine.openGlContext.BindVertexAttributeObject(m_Vaos[mesh->id]);
			//
			// 	BufferHandle vbBuffer = g_Engine.openGlContext.GenerateBuffer();
			// 	g_Engine.openGlContext.BindBuffer(vbBuffer, OpenGlContext::BufferType::VERTEX_BUFFER);
			// 	g_Engine.openGlContext.
			// }

			g_Engine.renderer.Queue(&transform, &material, &mesh);
		}
	}
}