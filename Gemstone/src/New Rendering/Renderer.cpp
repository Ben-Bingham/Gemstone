#include "pch.h"

#include "Renderer.h"
#include "imgui.h"

#include "Core/Engine.h"
#include "New Rendering/Components/Mesh.h"
#include "New Rendering/Components/Material.h"

namespace Gem {
	void Renderer::StartUp() {
		
	}

	void Renderer::ShutDown() {
		
	}

	void Renderer::Render() {
		RenderSetup();

		for (auto& [transform, material, mesh] : m_Renderables) {
			if (transform == nullptr || material == nullptr || mesh == nullptr) {
				LOG("Invalid Resources.", LogLevel::ERROR);
				continue;
			}

			// mesh->Bind();
			material->Bind();

			// g_Engine.openGlContext.DrawElements(mesh->indexCount);
			g_Engine.openGlContext.DrawElements(0);
		}

		// g_Engine.imGuiContext.RenderUi();

		RenderCleanup();
	}

	void Renderer::Queue(Transform* transform, Material* material, Mesh* mesh) {
		m_Renderables.emplace_back(Renderable{ transform, material, mesh });
	}

	void Renderer::RenderSetup() {
		g_Engine.openGlContext.Clear();
	}

	void Renderer::RenderCleanup() {
		g_Engine.window.SwapBuffers();
		m_Renderables.clear();
	}
}