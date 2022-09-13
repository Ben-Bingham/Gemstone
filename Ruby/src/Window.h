#pragma once
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Ruby {
	class Window {
	public:
		Window(unsigned int width = 640, unsigned int height = 480, std::string name = "Window");

		GLFWwindow* getWindow() const { return m_Window; }

		void pollEvents() { glfwPollEvents(); }

		void swapBuffers() { glfwSwapBuffers(m_Window); }

		void dispose();

	private:
		GLFWwindow* m_Window;
	};
}