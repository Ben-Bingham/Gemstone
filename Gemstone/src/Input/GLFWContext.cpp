#include "pch.h"
#include <GLFW/glfw3.h>

#include "GLFWContext.h"

namespace Gem {
	void GLFWErrorCallback(int error, const char* description) {
		LOG("GLFW error: " + std::to_string(error) + " " + std::string(description), LogLevel::ERROR);
	}

	void GLFWContext::StartUp() {
		glfwSetErrorCallback(GLFWErrorCallback);

		if (!glfwInit()) {
			LOG("GLFW failed to init", LogLevel::TERMINAL);
		}
	}



	void GLFWContext::ShutDown() {
		glfwTerminate();
	}

	double GLFWContext::Time::GetElapsedTime() const {
		return glfwGetTime();
	}

	void GLFWContext::Time::Wait(const double seconds) const {
		const double endPoint = GetElapsedTime() + seconds;

		while (GetElapsedTime() < endPoint) {}
	}

//<<<<<<< HEAD
	GLFWContext::Time::ScopeProfiler::ScopeProfiler(Time& time, bool log)
		: m_Time(time), m_Log(log) {
		m_StartTime = time.GetElapsedTime();
	}

	GLFWContext::Time::ScopeProfiler::~ScopeProfiler() {
		if (m_Log) {
			LOG(std::to_string(m_Time.GetElapsedTime() - m_StartTime));
		}
	}
//=======

//>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e

	void GLFWContext::PollEvents() const {
		glfwPollEvents();
	}

	void GLFWContext::SwapBuffers(const WindowHandle window) const {
		glfwSwapBuffers(window);
	}

	void GLFWContext::ToggleCursor(const WindowHandle window) {
		if (m_Cursor) {
			DisableCursor(window);
			m_Cursor = false;
		}
		else {
			EnableCursor(window);
			m_Cursor = true;
		}
	}

	void GLFWContext::EnableCursor(const WindowHandle window) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void GLFWContext::DisableCursor(const WindowHandle window) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}


	bool GLFWContext::GetKeyDown(const WindowHandle window, const Key key) const {
		return glfwGetKey(window, (int)key) == GLFW_PRESS;
	}

	bool GLFWContext::GetKeyUp(const WindowHandle window, const Key key) const {
		return glfwGetKey(window, (int)key) == GLFW_RELEASE;
	}

	bool GLFWContext::GetMouseButtonDown(const WindowHandle window, const MouseButton button) const {
		return glfwGetMouseButton(window, (int)button) == GLFW_PRESS;
	}

	bool GLFWContext::GetMouseButtonUp(WindowHandle window, MouseButton button) const {
		return glfwGetMouseButton(window, (int)button) == GLFW_RELEASE;
	}

	Vector2i GLFWContext::GetMousePosition(const WindowHandle window) const {
		double x, y;

		glfwGetCursorPos(window, &x, &y);

		return Vector2i{ (int)std::floor(x), (int)std::floor(y) };
	}
}