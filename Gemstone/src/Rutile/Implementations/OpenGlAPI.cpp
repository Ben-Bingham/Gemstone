#include "pch.h"
#include "OpenGlAPI.h"

#include "Lazuli/Log.h"

namespace Rutile {
	void OpenGlAPI::StartUp() {
		
	}

	void OpenGlAPI::ShutDown() {
		
	}

	void OpenGlAPI::CreateContext() {
		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}
	}

	void OpenGlAPI::ClearColour(const Ruby::Colour& colour) {
		glClearColor(colour.colour.x, colour.colour.y, colour.colour.z, colour.colour.w);
	}

	void OpenGlAPI::ClearColorBit() {
		glClear(GL_COLOR_BUFFER_BIT);

	}

	void OpenGlAPI::ClearDepthBit() {
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	void OpenGlAPI::DrawMesh() {
		
	}
}