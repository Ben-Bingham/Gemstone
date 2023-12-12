#include "pch.h"
#include "Rendering/OpenGl Objects/RenderBuffer.h"

#include "Core/Engine.h"

namespace Gem {
	RenderBuffer::RenderBuffer()
		//: m_Handle(g_Engine.openGlContext.GenerateRenderBuffer())
	{ }

	RenderBuffer::~RenderBuffer() {
		//g_Engine.openGlContext.DeleteRenderBuffer(m_Handle);
	}
}