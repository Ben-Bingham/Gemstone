#include "pch.h"
#include "OpenGlContext.h"
#include <GL/glew.h>

namespace Gem {
	void OpenGlContext::StartUp() {
		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to be initialized", Gem::LogLevel::TERMINAL);
		}
	}

	void OpenGlContext::ShutDown() { }
}