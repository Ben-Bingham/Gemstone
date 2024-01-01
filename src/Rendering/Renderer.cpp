#include "Core/Window.h"
#include "Rendering/Renderer.h"
#include "Rendering/Geometry/Cube.h"
#include "Rendering/Materials/BaseMaterial.h"
#include "Rendering/Materials/MaterialFactory.h"
#include "Rendering/Meshes/MeshObject.h"
#include "Rendering/Shaders/Shader.h"

#include "Utility/Utility.h"

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

	Renderer::Debug::Debug()
		: m_Shader("engineAssets/shaders/Debug.vert", "engineAssets/shaders/Debug.frag") { 

		m_Vao.Bind();

		m_Vao.SetLayout({
			{ OpenGlContext::VECTOR3F, "l_Position" }
		});
	}

	void Renderer::Debug::Add(Vector3f head, Vector3f tail, const Colour& colour) {
		debugRenderables.push_back(DebugRenderable{ { head, tail }, colour });
	}

	void Renderer::Debug::Render(Matrix4f view, Matrix4f projection) {

		for (auto debug : debugRenderables) {
			m_Vao.Bind();
			m_Vb.Bind();
			std::vector<float> floats{};
			for (auto point : debug.points) {
				floats.push_back(point.x);
				floats.push_back(point.y);
				floats.push_back(point.z);
			}

			m_Vb.SetAllData(floats);

			m_Shader.Bind();
			Matrix4f vp = view * projection;
			m_Shader.Upload("u_Matrix", vp);
			m_Shader.Upload("u_Colour", debug.colour.ToVec4f());

			OpenGlContext::Get().DrawArrays(floats.size(), OpenGlContext::RenderMode::LINES);
			
		}

		debugRenderables.clear();
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

		debug.Render(view, projection);
	}
}