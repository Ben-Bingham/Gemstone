#pragma once
#include "Keys.h"
#include "MouseButton.h"
#include "Core/ISubSystem.h"
#include "Math/Vector.h"

namespace Gem {
	void GLFWErrorCallback(int error, const char* description);

	using WindowHandle = GLFWwindow*;

	class GLFWContext : ISubSystem {
	public:
		GLFWContext() = default;

		void StartUp() override;
		void ShutDown() override;

		void PollEvents() const;
		void SwapBuffers(WindowHandle window) const;

		// Cursor
		void ToggleCursor(WindowHandle window);

	private:
		void EnableCursor(WindowHandle window);
		void DisableCursor(WindowHandle window);

		bool m_Cursor{ true };

	public:
		// Input
		bool GetKeyDown(WindowHandle window, Key key) const;
		bool GetKeyUp(WindowHandle window, Key key) const;
		bool GetMouseButtonDown(WindowHandle window, MouseButton button) const;
		bool GetMouseButtonUp(WindowHandle window, MouseButton button) const;
		Vector2i GetMousePosition(WindowHandle window) const;
	};
}