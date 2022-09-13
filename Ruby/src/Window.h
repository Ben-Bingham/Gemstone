#pragma once
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Ruby {
	class Window {
	public:
		Window(unsigned int width = 640, unsigned int height = 480, std::string name = "Window") {
			glfwInit();

			m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

			glfwMakeContextCurrent(m_Window);
			glfwSwapInterval(1);
		}

		GLFWwindow* getWindow() const { return m_Window; }

		void swapBuffers() { glfwSwapBuffers(m_Window); }

		void pollEvents() { glfwPollEvents(); }

		void dispose() {
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}

	private:
		GLFWwindow* m_Window;
	};
}