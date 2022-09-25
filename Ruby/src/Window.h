#pragma once
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Input/IOManager.h"
#include "Matrix.h"

namespace Ruby {
	class Window {
	public:
		Window(unsigned int width = 640, unsigned int height = 480, std::string name = "Window");
		Window(Window&) = delete;
		Window& operator=(Window&) = delete;
		Window(Window&& other) noexcept
			: m_Window(std::move(other.m_Window)) {
			other.m_Window = nullptr;
		}

		Window& operator=(Window&& other) noexcept {
			m_Window = std::move(other.m_Window);
			other.m_Window = nullptr;
		}

		~Window() {
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}

		GLFWwindow* getWindow() const { return m_Window; }
		Malachite::Matrix4f getProjectionMatrix() const { return m_ProjectionMatrix; }

		bool isOpen() { return !glfwWindowShouldClose(m_Window); }
		void pollEvents() { glfwPollEvents(); }
		void swapBuffers() { glfwSwapBuffers(m_Window); }

		void disableCursor() { glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
		void close() { glfwSetWindowShouldClose(m_Window, true); }

		// Callbacks
		void setKeyCallback(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods)) { glfwSetKeyCallback(m_Window, callback); }
		void setFrameBufferSizeCallback(void (*callback)(GLFWwindow* window, int width, int height)) { glfwSetFramebufferSizeCallback(m_Window, callback); }
		void setScrollWheelCallback(void (*callback)(GLFWwindow* window, double xOffset, double yOffset)) { glfwSetScrollCallback(m_Window, callback); }
		void setMouseButtonCallback(void (*callback)(GLFWwindow* window, int button, int action, int mods)) { glfwSetMouseButtonCallback(m_Window, callback); }
		void setCursorEntersCallback(void (*callback)(GLFWwindow* window, int entered)) { glfwSetCursorEnterCallback(m_Window, callback);  }
		void setMousePositionCallback(void (*callback)(GLFWwindow* window, double xpos, double ypos)) { glfwSetCursorPosCallback(m_Window, callback); }

		IOManager ioManger{ };

	private:
		GLFWwindow* m_Window;
		Malachite::Matrix4f m_ProjectionMatrix;
	};
}