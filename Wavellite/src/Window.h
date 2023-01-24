#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Matrix.h"

namespace Wavellite {
	void windowSizeCallBack(GLFWwindow* window, int width, int height);

	class Window {
	public:
		enum class WindowSize { //TODO names should change
			FULL_SCREEN,
			HALF_SCREEN,
			QUARTER_SCREEN
		};

		static Window& Get();

		void Init();

		GLFWwindow* getWindow() const { return m_Window; }
		Malachite::Matrix4f getProjectionMatrix() const { return m_ProjectionMatrix; }
		Malachite::Matrix4f& getProjectionMatrix() { return m_ProjectionMatrix; }
		unsigned int getWidth() const { return m_Width; }
		unsigned int getHeight() const { return m_Height; }

		bool isOpen() { return !glfwWindowShouldClose(m_Window); }
		void pollEvents() { glfwPollEvents(); }
		void swapBuffers() { glfwSwapBuffers(m_Window); }

		void disableCursor() { glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
		void enableCursor() { glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }
		void close() { glfwSetWindowShouldClose(m_Window, true); }

		void setDimensions(unsigned int width, unsigned int height);

		void setSwapInterval(unsigned int newInterval) {
			glfwSwapInterval(newInterval);
		}

	private:
		Window() = default;

		unsigned int m_Width{ 640 };
		unsigned int m_Height{ 480 };
		bool m_Initialized;

		GLFWwindow* m_Window;
		Malachite::Matrix4f m_ProjectionMatrix;
	};
}