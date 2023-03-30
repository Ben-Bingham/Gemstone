#include "pch.h"
#include "RenderingSystem.h"

#include "Rendering/OpenGLState.h"
#include "Rendering/Geometry/Mesh.h"
#include "Rendering/Materials/Material.h"

namespace Gem {
	RenderingSystem::RenderingSystem(Gem::Window& window, Camera* camera)
		: m_Camera(camera), m_Window(&window) {

		int flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
			LOG("OpenGL debug context available.", LogLevel::INFO);
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(glDebugOutput, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}

		// OpenGlState::get().setDepthTesting(true);
		// OpenGlState::get().setDepthBufferWriting(true);
		// OpenGlState::get().setDepthFunction(OpenGlState::Comparison::LESS_THAN);
		// OpenGlState::get().setFaceToCull(OpenGlState::Face::BACK);
		// OpenGlState::get().setFrontFaceDirection(OpenGlState::Direction::CLOCKWISE);

		m_Renderables.reserve(100);
		m_Cameras.reserve(100);
	}

	void RenderingSystem::beginFrame() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

#ifdef RUBY_DEBUG
		if (m_Camera == nullptr) {
			LOG("Camera is null, please set a camera.", LogLevel::ERROR);
		}
#endif

		// m_ViewMatrix = m_Camera->getViewMatrix();
	}

	// void RenderingSystem::PreStep(Gem::Scene* scene) { //TODO multi camera and window support
	// 	beginFrame();
	// }
	//
	// void RenderingSystem::Step(Gem::Scene* scene) {
	// 	// for (auto& gb : scene->gameObjects) {
	// 	// 	if (scene->HasComponent<Camera>(gb)) {
	// 	// 		Camera* cam = scene->GetComponent<Camera>(gb);
	// 	//
	// 	// 		if (cam->target == WINDOW) {
	// 	// 			setCamera(cam);
	// 	// 			beginFrame();
	// 	//
	// 	// 			for (const auto& renderable : scene->gameObjects) {
	// 	// 				if (scene->HasComponent<Mesh>(renderable) &&
	// 	// 					scene->HasComponent<Material>(renderable) &&
	// 	// 					scene->HasComponent<Transform>(renderable)) {
	// 	//
	// 	// 					const Mesh* mesh = scene->GetComponent<Mesh>(renderable);
	// 	// 					const Material* material = scene->GetComponent<Material>(renderable);
	// 	// 					Transform* transform = scene->GetComponent<Transform>(renderable);
	// 	//
	// 	// 					// m_Renderables.emplace_back(Renderable(*mesh->mesh, *material->material, *transform));
	// 	// 					Render(Renderable(*mesh->mesh, *material->material, *transform), cam);
	// 	// 				}
	// 	// 			}
	// 	//
	// 	// 			for (const auto& function : m_RenderFunctions) {
	// 	// 				function(scene, cam);
	// 	// 			}
	// 	//
	// 	// 			endFrame();
	// 	// 			m_Window->swapBuffers();
	// 	// 		}
	// 	// 	}
	// 	// }
	//
	// 	defaultRenderFunction(scene, m_Camera);
	//
	// 	for (const auto& function : renderFunctions) {
	// 		function(scene, m_Camera);
	// 	}
	// }
	//
	// void RenderingSystem::EndStep(Gem::Scene* scene) {
	// 	endFrame();
	// }

	// void RenderingSystem::SubmitRenderCall(Gem::Scene* scene, Gem::InternalGameObject gb) {
	// 	
	// }

	void RenderingSystem::Render(const Renderable& renderable, Camera* camera) {
		m_Renderables.emplace_back(renderable);
		m_Cameras.emplace_back(camera);
	}

	void RenderingSystem::endFrame() {
		// m_Window->swapBuffers();
		// int i = 0;
		// for (Renderable renderable : m_Renderables) {
		// 	renderable.mesh().bind();
		//
		// 	renderable.material().use(renderable.transform().getModelMatrix(), m_Cameras[i]->viewMatrix, m_Window->getProjectionMatrix());
		// 	glDrawElements((GLenum)(int)renderable.mesh().getDrawMode(), (GLsizei)renderable.mesh().getIndexCount(), GL_UNSIGNED_INT, 0);
		// 	renderable.material().end();
		//
		// 	i++;
		// }
		//
		// m_Renderables.clear();
		// m_Cameras.clear();

		// ========== Debug RenderingSystem ==========
		// const bool depthTesting = OpenGlState::get().getDepthTesting();
		//
		// OpenGlState::get().setDepthTesting(false);
		//
		// m_DebugRenderer.render();
		//
		// OpenGlState::get().setDepthTesting(depthTesting);
	}

	// void RenderingSystem::AddRenderFunction(void (*renderFunction)(Gem::Scene* scene, Camera* camera)) {
	// 	m_RenderFunctions.push_back(renderFunction);
	// }

	void RenderingSystem::GUI::StartUp() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::StyleColorsDark();

		// ImGui_ImplGlfw_InitForOpenGL(Gem::Window::Get().getWindow(), true);
		ImGui_ImplOpenGL3_Init(nullptr);
	}

	void RenderingSystem::GUI::Begin() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void RenderingSystem::GUI::End() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context); //TODO this has got to be expensive
	}

	void RenderingSystem::GUI::ShutDown() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void DefaultRenderFunction(Gem::Scene* scene, Camera* camera) {
		// int i = 0;
		// for (Renderable renderable : m_Renderables) {
		// 	renderable.mesh().bind();
		//
		// 	renderable.material().use(renderable.transform().getModelMatrix(), m_Cameras[i]->viewMatrix, m_Window->getProjectionMatrix());
		// 	glDrawElements((GLenum)(int)renderable.mesh().getDrawMode(), (GLsizei)renderable.mesh().getIndexCount(), GL_UNSIGNED_INT, 0);
		// 	renderable.material().end();
		//
		// 	i++;
		// }
		//
		// m_Renderables.clear();
		// m_Cameras.clear();
		Camera* cam{ nullptr };
		for (auto& gb : scene->gameObjects) {
			if (scene->HasComponent<Camera>(gb)) {
				cam = scene->GetComponent<Camera>(gb);
				break;
			}
		}
		// 	if (scene->HasComponent<Camera>(gb)) {
				// Camera* cam = scene->GetComponent<Camera>(gb);

				// if (cam->target == WINDOW) {
					// setCamera(cam);
					// beginFrame();

		for (const auto& renderable : scene->gameObjects) {
			if (scene->HasComponent<Mesh>(renderable) &&
				scene->HasComponent<Material>(renderable) &&
				scene->HasComponent<Transform>(renderable)) {

				const Mesh* mesh = scene->GetComponent<Mesh>(renderable);
				const Material* material = scene->GetComponent<Material>(renderable);
				Transform* transform = scene->GetComponent<Transform>(renderable);

				// material->material->use(transform->getModelMatrix(), cam->viewMatrix, Gem::Window::Get().getProjectionMatrix());
				glDrawElements((GLenum)(int)mesh->mesh->getDrawMode(), (GLsizei)mesh->mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
				material->material->end();

				// // m_Renderables.emplace_back(Renderable(*mesh->mesh, *material->material, *transform));
				// Render(Renderable(*mesh->mesh, *material->material, *transform), cam);
			}
		}

					// for (const auto& function : m_RenderFunctions) {
					// 	function(scene, cam);
					// }
					//
					// endFrame();
					// m_Window->swapBuffers();
				// }
		// 	}
		// }
	}

#undef ERROR

	void APIENTRY glDebugOutput(
		GLenum source,
		GLenum type,
		unsigned int id,
		GLenum severity,
		GLsizei length,
		const char* message,
		const void* userParam) {
		LogLevel level;
		switch (severity) {
		default:
		case GL_DEBUG_SEVERITY_HIGH:			level = LogLevel::ERROR; break;
		case GL_DEBUG_SEVERITY_MEDIUM:			level = LogLevel::WARNING; break;
		case GL_DEBUG_SEVERITY_LOW:				level = LogLevel::WARNING; break;
		case GL_DEBUG_SEVERITY_NOTIFICATION:	level = LogLevel::INFO; break;
		}

		// ignore non-significant error/warning codes
		if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;
		LOG("---------------", level);

		std::string string = "Debug message (";
		string += std::to_string(id);
		string += "): ";
		string += message;

		LOG(string, level);

		string = "";
		switch (source) {
		case GL_DEBUG_SOURCE_API:             string += "Source: API"; break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   string += "Source: Window System"; break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: string += "Source: Shader Compiler"; break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     string += "Source: Third Party"; break;
		case GL_DEBUG_SOURCE_APPLICATION:     string += "Source: Application"; break;
		case GL_DEBUG_SOURCE_OTHER:           string += "Source: Other"; break;
		}
		LOG(string, level);

		string = "";
		switch (type) {
		case GL_DEBUG_TYPE_ERROR:               string += "Type: Error"; break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: string += "Type: Deprecated Behaviour"; break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  string += "Type: Undefined Behaviour"; break;
		case GL_DEBUG_TYPE_PORTABILITY:         string += "Type: Portability"; break;
		case GL_DEBUG_TYPE_PERFORMANCE:         string += "Type: Performance"; break;
		case GL_DEBUG_TYPE_MARKER:              string += "Type: Marker"; break;
		case GL_DEBUG_TYPE_PUSH_GROUP:          string += "Type: Push Group"; break;
		case GL_DEBUG_TYPE_POP_GROUP:           string += "Type: Pop Group"; break;
		case GL_DEBUG_TYPE_OTHER:               string += "Type: Other"; break;
		}
		LOG(string, level);
		string = "";
		switch (severity) {
		case GL_DEBUG_SEVERITY_HIGH:         string += "Severity: high"; break;
		case GL_DEBUG_SEVERITY_MEDIUM:       string += "Severity: medium"; break;
		case GL_DEBUG_SEVERITY_LOW:          string += "Severity: low"; break;
		case GL_DEBUG_SEVERITY_NOTIFICATION: string += "Severity: notification"; break;
		}
		LOG(string, level);
		LOG("---------------", level);
	}
}