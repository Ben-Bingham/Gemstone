#include "Rendering/Renderer_New.h"

namespace Gem {
	Renderer_New::Renderer_New(OpenGlContext& openGlContext)
		: m_Context(openGlContext) {}

	void Renderer_New::StartUp() {
		
	}

	void Renderer_New::ShutDown() {
		
	}

	void Renderer_New::Render() {
		m_Context.Clear();
	}
}