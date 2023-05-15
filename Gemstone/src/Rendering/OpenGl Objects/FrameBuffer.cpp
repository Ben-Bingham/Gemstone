#include "pch.h"
#include "FrameBuffer.h"

#include "Core/Engine.h"

namespace Gem {
	FrameBuffer::FrameBuffer()
		: m_Handle(g_Engine.openGlContext.GenerateFrameBuffer()) { }

	FrameBuffer::~FrameBuffer() {
		g_Engine.openGlContext.DeleteBuffer(m_Handle);
	}
}