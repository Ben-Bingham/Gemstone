#include "Rendering/Renderer_New.h"
#include "Rendering/Materials/BaseMaterial.h"
#include "Rendering/Meshes/MeshObject.h"
#include "Rendering/Shaders/Shader.h"

namespace Gem {
	void Renderer_New::StartUp() {
		m_Started = true;
	}

	void Renderer_New::ShutDown() {
		m_Started = false;
	}

	Renderer_New& Renderer_New::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp Renderer, before using it.", LogLevel::TERMINAL);
		}

		static Renderer_New renderer;
		return renderer;
	}

	void Renderer_New::Render() {
		OpenGlContext::Get().Clear();

		// TODO all this info needs to be non hardcoded
		Vector2ui windowSize{ 640, 480 };

		auto camPos = Vector3f::south * 3.0f;

		Matrix4f projection = perspective(degreesToRadians(90.0f), (float)windowSize.x / (float)windowSize.y, 0.1f, 100.0f);
		Matrix4f view = lookAt(camPos, camPos + Vector3f::north, Vector3f::up);

		// TODO make the renderable store the mesh and material in the same way, the matrix can be differnt tho.
		for (auto [mesh, material, model] : renderables) {
			material->Apply();
			mesh->mesh.Bind();

			Matrix4f mvp = model * view * projection;

			//Shader::Upload("u_MVP", mvp);
		}
	}
}