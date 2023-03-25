#include "RenderingContext.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Lazuli/Log.h"

namespace Ruby {
	RenderingContext& RenderingContext::Get() {
		static RenderingContext context{};
		return context;
	}

	void RenderingContext::Init() {
		if (m_Initialized) {
			return;
		}

		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

		m_Initialized = true;
	}
}