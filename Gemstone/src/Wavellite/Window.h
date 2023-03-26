#pragma once

// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Malachite/Matrix.h"

namespace Wavellite {
	void windowSizeCallBack(GLFWwindow* window, int width, int height);

	class Window {
	public:
		Window();

		[[nodiscard]] bool IsOpen() const;
		void Close() const;



		// enum class WindowSize { //TODO names should change
		// 	FULL_SCREEN,
		// 	HALF_SCREEN,
		// 	QUARTER_SCREEN
		// };


		// TODO REMOVE PAST THIS POINT
		static Window& Get();
		//
		// void Init();
		//
		GLFWwindow* getWindow() const { return nullptr; }
		Malachite::Matrix4f getProjectionMatrix() const { return Malachite::Matrix4f{}; }
		// Malachite::Matrix4f& getProjectionMatrix() { return Malachite::Matrix4f{}; }
		unsigned int getWidth() const { return 0; }
		unsigned int getHeight() const { return 0; }
		//
		void pollEvents() { glfwPollEvents(); }
		void swapBuffers() {  }
		//
		void disableCursor() {
			// glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
		void enableCursor() {
			// glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}



		// void setDimensions(unsigned int width, unsigned int height);
		//
		// void setSwapInterval(unsigned int newInterval) {
		// 	glfwSwapInterval(newInterval);
		// }


	private:
		// Window() = default;

		
		Malachite::Vector2ui m_Size{ 640, 480 };

		// unsigned int m_Width{ 640 };
		// unsigned int m_Height{ 480 };
		// bool m_Initialized;

		GLFWwindow* m_Handle{ nullptr };
		// Malachite::Matrix4f m_ProjectionMatrix;
	};
}