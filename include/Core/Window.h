#pragma once
#include "GLFWContext.h"

namespace Gem {
	class Window {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Window() = default;
		~Window() = default;

		static inline bool m_Started{ false };

	public:
		static Window& Get();

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept = default;

		void SwapBuffers();
		void SwapInterval(int interval);

		bool ShouldClose();

		void DisableCursor();
		void EnableCursor();

		// ==================== Input ====================
		bool GetMouseButton(MouseButton button);
		Vector2i GetMousePosition();
		bool GetKeyboardKey(Key key);

		// ==================== Call backs ====================
		void SetKeyboardKeyCallback(void(*callback)(WindowHandle callbackHandle, int key, int scanCode, int action, int mods));
		void SetMouseButtonCallback(void(*callback)(WindowHandle callbackHandle, int button, int action, int mods));
		void SetMousePositionCallback(void(*callback)(WindowHandle callbackHandle, double xPos, double yPos));
		void SetScrollWheelCallback(void(*callback)(WindowHandle callbackHandle, double xOffset, double yOffset));
		void SetCursorEnterCallback(void(*callback)(WindowHandle callbackHandle, int entered));
		void SetWindowResizeCallback(void(*callback)(WindowHandle callbackHandle, int width, int height));

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}