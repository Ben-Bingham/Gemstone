#include "pch.h"

#include <GL/glew.h>

#include "Window.h"
#include "Lazuli/Log.h"

namespace Gem {
	Window::Window(HumanInterfaceDeviceContext& hidContext)
		: m_HidContext(hidContext) {

		m_Handle = m_HidContext.CreateWindowHandle(m_Size, "Window");
		m_HidContext.MakeGraphicsContextCurrent(m_Handle);

        if (glewInit() != GLEW_OK) { // TODO maybe make this its own class, it could also manage OpengGl state.
			LOG("GLEW failed to be initialized", Lazuli::LogLevel::TERMINAL);
        }
	}

	bool Window::IsOpen() const {
		return !m_HidContext.ShouldWindowClose(m_Handle);
	}

	void Window::Close() const {
		m_HidContext.CloseWindow(m_Handle);
	}

	WindowHandle Window::Handle() const {
		return m_Handle;
	}
}