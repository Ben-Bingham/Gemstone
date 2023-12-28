#include "Core/Window.h"
#include "..\..\include\Rendering\Renderer.h"
#include "Rendering/Materials/BaseMaterial.h"
#include "Rendering/Meshes/MeshObject.h"
#include "Rendering/Shaders/Shader.h"

namespace Gem {
	void Renderer::StartUp() {
		m_Started = true;
	}

	void Renderer::ShutDown() {
		m_Started = false;
	}

	Renderer& Renderer::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp Renderer, before using it.", LogLevel::TERMINAL);
		}

		static Renderer renderer;
		return renderer;
	}

	void Renderer::Render() {
		OpenGlContext::Get().Clear();

		const Vector2ui windowSize = Window::Get().size;

		Matrix4f projection = perspective(degreesToRadians(camera.camera.fov), (float)windowSize.x / (float)windowSize.y, 0.1f, 100.0f);
		Matrix4f view = lookAt(camera.transform.position, camera.transform.position + camera.camera.forward, Vector3f::up);

		for (auto [mesh, material, model] : renderables) {
			material->Apply();
			mesh->mesh.Bind();

			UPtr<Shader>& shader = material->GetShader();

			Matrix4f mvp = model * view * projection;

			shader->Upload("u_MVP", mvp);

			OpenGlContext::Get().DrawElements(mesh->mesh.indexCount);
		}
	}
}