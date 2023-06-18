#include "pch.h"
#include "Engine.h"
#include "Window.h"
#include "WindowEvents.h"

#include "Input/MouseEvents.h"
#include "Core/Event System/EventHandler.h"

namespace Gem {
	void WindowSizeCallback(WindowHandle handle, const int width, const int height) {
		g_Engine.eventManager.Post(WindowEvents::Resize{ Vector2ui{(unsigned int)width, (unsigned int)height }});
	}

	void Window::StartUp() {
		m_Handle = g_Engine.humanInterfaceDeviceContext.CreateWindowHandle(m_Size, "Window");
		g_Engine.humanInterfaceDeviceContext.MakeGraphicsContextCurrent(m_Handle);

		g_Engine.humanInterfaceDeviceContext.SetWindowSizeCallback(m_Handle, WindowSizeCallback);
	}

	void Window::ShutDown() {
		
	}

	bool Window::IsOpen() const {
		return !g_Engine.humanInterfaceDeviceContext.ShouldWindowClose(m_Handle);
	}

	void Window::Close() {
		g_Engine.humanInterfaceDeviceContext.CloseWindow(m_Handle);
	}

	WindowHandle Window::Handle() const {
		return m_Handle;
	}

	void Window::SwapBuffers() {
		g_Engine.humanInterfaceDeviceContext.SwapBuffers(m_Handle);
	}

	void Window::SwapInterval(const size_t interval) {
		g_Engine.humanInterfaceDeviceContext.SetSwapInterval(interval);
	}

	void Window::DisableCursor() {
		g_Engine.humanInterfaceDeviceContext.DisableCursor(Handle());
	}

	void Window::EnableCursor() {
		g_Engine.humanInterfaceDeviceContext.EnableCursor(Handle());
	}

	Vector2ui Window::Size() const {
		return m_Size;
	}
}