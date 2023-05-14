#include "pch.h"

#include "Renderer.h"
#include "imgui.h"

#include "Core/Engine.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/Components/Material.h"

namespace Gem {
	void Renderer::StartUp() {
		
	}

	void Renderer::ShutDown() {
		
	}

	void Renderer::Render() {
		RenderSetup();

#ifdef GEMSTONE_DEBUG
		if (m_Cameras.empty()) {
			LOG("No cameras provided, dont expect an image.", LogLevel::WARNING);
		}
#endif

		for (auto& camera : m_Cameras) {
			for (auto& [mesh, material, modelMatrix] : m_Renderables) {
				mesh->vao.Bind();

				material->shader->Bind();

				Texture::ActivateUnit(0);
				material->diffuse.Bind();
				material->shader->Upload("u_Diffuse", 0);

				Texture::ActivateUnit(1);
				material->specular.Bind();
				material->shader->Upload("u_Specular", 1);

				// Matrix4f mvp = camera.Cam()->projection * camera.Cam()->view * modelMatrix;
				Matrix4f mvp = modelMatrix * camera.Cam()->view * camera.Cam()->projection;
				material->shader->Upload("u_MVP", mvp);

				g_Engine.openGlContext.DrawElements(mesh->indexCount);
			}
		}

		g_Engine.imGuiContext.RenderUi();

		RenderCleanup();
	}

	void Renderer::Queue(const Ptr<InternalMesh>& mesh, const Ptr<InternalMaterial>& material, Matrix4f modelMatrix) {
		m_Renderables.emplace_back(Renderable{ mesh, material, modelMatrix });
	}

	void Renderer::AddCamera(const Camera& camera) {
		m_Cameras.push_back(camera);
	}

	void Renderer::RenderSetup() {
		g_Engine.openGlContext.Clear();
	}

	void Renderer::RenderCleanup() {
		g_Engine.window.SwapBuffers();
		m_Renderables.clear();
		m_Cameras.clear();
	}
}