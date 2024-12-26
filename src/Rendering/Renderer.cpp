#include "Core/Window.h"
#include "Rendering/Renderer.h"
#include "Rendering/Geometry/Cube.h"
#include "Rendering/Materials/BaseMaterial.h"
#include "Rendering/Materials/MaterialFactory.h"
#include "Rendering/Meshes/MeshObject.h"
#include "Rendering/Shaders/Shader.h"

#include "Utility/Utility.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

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

	void Renderer::Debug::Add(glm::vec3 head, glm::vec3 tail, const Colour& colour) {
		debugRenderables.push_back(DebugRenderable{ { head, tail }, colour });
	}

	void Renderer::Debug::Render(glm::mat4 view, glm::mat4 projection) {

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
			glm::mat4 vp = view * projection;
			m_Shader.Upload("u_Matrix", vp);
			m_Shader.Upload("u_Colour", debug.colour.ToVec4f());

			OpenGlContext::Get().DrawArrays(floats.size(), OpenGlContext::RenderMode::LINES);
			
		}

		debugRenderables.clear();
	}

	void Renderer::Render() {
		OpenGlContext::Get().Clear();

		const glm::ivec2 windowSize = Window::Get().size;

		glm::mat4 projection = glm::perspective(glm::radians(camera.camera.fov), (float)windowSize.x / (float)windowSize.y, 0.1f, 100.0f);
		glm::mat4 view = glm::lookAt(camera.transform.position, camera.transform.position + camera.camera.forward, glm::vec3{ 0.0f, 1.0f, 0.0f });

		for (auto [mesh, material, model] : renderables) {
			material->Apply();
			mesh->mesh.Bind();

			UPtr<Shader>& shader = material->GetShader();

			glm::mat4 mvp = model * view * projection;

			shader->Upload("u_MVP", mvp);

			OpenGlContext::Get().DrawElements(mesh->mesh.indexCount);
		}

		debug.Render(view, projection);
	}
}