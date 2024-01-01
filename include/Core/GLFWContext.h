#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "Math/Vector.h"
#include "Input/MouseButton.h"

namespace Gem {
	enum class Key;
	enum class MouseButton;
	void GLFWErrorCallback(int error, const char* description);

	using WindowHandle = GLFWwindow*; //TODO replace all uses with Handle

	class GLFWContext {
		friend class Engine;

		static void StartUp();
		static void ShutDown();
		GLFWContext() = default;
		~GLFWContext() = default;

		static inline bool m_Started{ false };

	public:
		static GLFWContext& Get();

		GLFWContext(const GLFWContext& other) = delete;
		GLFWContext(GLFWContext&& other) noexcept = default;
		GLFWContext& operator=(const GLFWContext& other) = delete;
		GLFWContext& operator=(GLFWContext&& other) noexcept = default;

		// ==================== Windows ====================
		WindowHandle CreateWindow(Vector2ui size, std::string&& name);
		void DestroyWindow(WindowHandle handle);

		bool WindowShouldClose(WindowHandle handle);

		enum class WindowHint {
			OPENGL_DEBUG_CONTEXT = GLFW_OPENGL_DEBUG_CONTEXT
		};

		void SetWindowHint(WindowHint hint, bool value);

		// ==================== Cursor ====================
		void EnableCursor(WindowHandle handle);
		void DisableCursor(WindowHandle handle);

		// ==================== Input ====================
		void PollEvents() const;

		bool GetKeyDown(WindowHandle handle, Key key) const;
		bool GetKeyUp(WindowHandle handle, Key key) const;
		bool GetMouseButtonDown(WindowHandle handle, MouseButton button) const;
		bool GetMouseButtonUp(WindowHandle handle, MouseButton button) const;
		Vector2i GetMousePosition(WindowHandle handle) const;

		// ==================== Call backs ====================
		void SetKeyboardKeyCallback(WindowHandle handle, void(*callback)(WindowHandle callbackHandle, int key, int scanCode, int action, int mods));
		void SetMouseButtonCallback(WindowHandle handle, void(*callback)(WindowHandle callbackHandle, int button, int action, int mods));
		void SetMousePositionCallback(WindowHandle handle, void(*callback)(WindowHandle callbackHandle, double xPos, double yPos));
		void SetScrollWheelCallback(WindowHandle handle, void(*callback)(WindowHandle callbackHandle, double xOffset, double yOffset));
		void SetCursorEnterCallback(WindowHandle handle, void(*callback)(WindowHandle callbackHandle, int entered));
		void SetWindowResizeCallback(WindowHandle handle, void(*callback)(WindowHandle callbackHandle, int width, int height));

	private:
		bool m_KeyCallback{ false };
		bool m_MouseButtonCallback{ false };
		bool m_MousePositionCallback{ false };
		bool m_ScrollWheelCallback{ false };
		bool m_CursorEnterCallback{ false };
		bool m_WindowResizeCallback{ false };

	public:

		// ==================== Miscellaneous ====================
		double GetElapsedTime();

		void MakeOpenGlContextCurrent(WindowHandle handle);

		// ==================== Buffers ====================
		void SwapBuffers(WindowHandle handle) const;
		void SwapInterval(int interval);
	};
}