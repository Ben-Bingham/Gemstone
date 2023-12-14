#pragma once
#include "Core/ISubSystem.h"
#include "Math/Vector.h"
#include "Input/Keys.h"
#include "Input/MouseButton.h"

namespace Gem {
	void GLFWErrorCallback(int error, const char* description);

	using WindowHandle = GLFWwindow*; //TODO replace all uses with Handle

	class GLFWContext : ISubSystem {
	public:
		GLFWContext() = default;

		void StartUp() override;
		void ShutDown() override;

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

		// ==================== Miscellaneous ====================
		double GetElapsedTime();

		// ==================== Buffers ====================
		void SwapBuffers(WindowHandle handle) const;
		void SwapInterval(int interval);
	};
}