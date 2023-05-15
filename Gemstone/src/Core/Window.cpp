#include "pch.h"
#include "Engine.h"
#include "Window.h"

namespace Gem {
	void Window::StartUp() {
		m_Handle = g_Engine.humanInterfaceDeviceContext.CreateWindowHandle(m_Size, "Window");
		g_Engine.humanInterfaceDeviceContext.MakeGraphicsContextCurrent(m_Handle);
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