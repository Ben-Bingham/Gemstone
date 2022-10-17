#include "Window.h"

#include "Log.h"

namespace Wavellite {
	Window::Window(unsigned int width, unsigned int height, std::string name, float zFar) 
		: m_ProjectionMatrix{Malachite::perspective(45.0f, (float)((float)width / (float)height), 0.1f, zFar)}
		, m_Width(width)
		, m_Height(height) {
		if (!glfwInit()) {
			LOG("GLFW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

#ifdef RUBY_DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif // RUBY_DEBUG

		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		if (!m_Window) {
			LOG("Window could not be initialized.", Lazuli::LogLevel::TERMINAL);
		}

		glfwMakeContextCurrent(m_Window);

		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

		glfwSwapInterval(1);

		glfwSetWindowUserPointer(m_Window, (void*)&ioManger);

		// Mouse
		setMousePositionCallback(mousePositionCallback);
		setMouseButtonCallback(mouseButtonCallback);
		setScrollWheelCallback(mouseScrolWheelCallback);
		setCursorEntersCallback(cursorEnterCallback);

		// Keyboard
		setKeyCallback(keyCallback);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(getWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}
}