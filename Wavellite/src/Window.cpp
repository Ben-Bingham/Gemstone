#include "Window.h"

#include "Input/IOManager.h"
#include "Log.h"

namespace Wavellite {
	Window::Window(WindowSize size, std::string name, float zFar) 
		: ioManger(this) {
		GLFWInit();
		makeWindow(size, name);
		windowSetup();

		m_ProjectionMatrix = Malachite::perspective(45.0f, (float)((float)m_Width / (float)m_Height), 0.1f, zFar);
	}

	Window::Window(unsigned int width, unsigned int height, std::string name, float zFar) 
		: m_ProjectionMatrix{Malachite::perspective(45.0f, (float)((float)width / (float)height), 0.1f, zFar)}
		, m_Width(width)
		, m_Height(height)
		, ioManger(this) {
		GLFWInit();
		makeWindow(width, height, name);
		windowSetup();
	}

	void Window::GLFWInit() {
		if (!glfwInit()) {
			LOG("GLFW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

#ifdef RUBY_DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif // RUBY_DEBUG
	}

	void Window::makeWindow(unsigned int width, unsigned int height, const std::string& name) {
		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	}

	void Window::makeWindow(WindowSize size, const std::string& name) {
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		m_Width = mode->width;
		m_Height = mode->height;

		GLFWmonitor* monitor = NULL;

		switch (size) {
		case WindowSize::FULL_SCREEN:
			monitor = glfwGetPrimaryMonitor();
			break;
		case WindowSize::HALF_SCREEN:
			m_Width /= 2u;
			m_Height /= 2u;
			break;
		case WindowSize::QUARTER_SCREEN:
			m_Width /= 4u;
			m_Height /= 4u;
			break;
		default:
			LOG("Unreckognized screen size.", Lazuli::LogLevel::TERMINAL);
			break;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, name.c_str(), monitor, NULL);
	}

	void Window::windowSetup() {
		if (!m_Window) {
			LOG("Window could not be initialized.", Lazuli::LogLevel::TERMINAL);
		}
		
		glfwMakeContextCurrent(m_Window);
		
		glfwSwapInterval(1);
		
		glfwSetWindowUserPointer(m_Window, (void*)&ioManger);
		
		// Mouse
		setMousePositionCallback(mousePositionCallback);
		setMouseButtonCallback(mouseButtonCallback);
		setScrollWheelCallback(mouseScrollWheelCallback);
		setCursorEntersCallback(cursorEnterCallback);
		
		// Keyboard
		setKeyCallback(keyCallback);

		// Framebuffer
		setFrameBufferSizeCallback(windowSizeCallBack);

		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		(void)io;

		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(getWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 330");

		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	void Window::setDimensions(unsigned int width, unsigned int height) {
		m_Width = width;
		m_Height = height;

		m_ProjectionMatrix = Malachite::perspective(45.0f, (float)((float)m_Width / (float)m_Height), 0.1f, 100.0f); //TODO renderer never knows to reupload projection matrix

		glViewport(0, 0, m_Width, m_Height);
	}

	void windowSizeCallBack(GLFWwindow* window, int width, int height) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);

		manager->window->setDimensions((unsigned int)width, (unsigned int)height);
	}
}