#pragma once
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Ruby {
	class Window {
	public:
		Window(unsigned int width = 640, unsigned int height = 480, std::string name = "Window");

		GLFWwindow* getWindow() const { return m_Window; }
		bool isOpen() { return !glfwWindowShouldClose(m_Window); }
		void pollEvents() { glfwPollEvents(); }
		void swapBuffers() { glfwSwapBuffers(m_Window); }
		void dispose();

		void disableCursor() { glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
		void close() { glfwSetWindowShouldClose(m_Window, true); }

		// Callbacks
		void setKeyCallback(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods)) { glfwSetKeyCallback(m_Window, callback); }
		void setMousePositionCallback(void (*callback)(GLFWwindow* window, double xpos, double ypos)) { glfwSetCursorPosCallback(m_Window, callback); }

	private:
		GLFWwindow* m_Window;
	};
}