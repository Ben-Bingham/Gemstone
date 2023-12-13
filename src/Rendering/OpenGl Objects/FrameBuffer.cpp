#include "pch.h"
#include "Rendering/OpenGl Objects/FrameBuffer.h"

#include "Core/Engine.h"

namespace Gem {
	FrameBuffer::FrameBuffer()
		//: m_Handle(g_Engine.openGlContext.GenerateFrameBuffer())
	{ }

	FrameBuffer::~FrameBuffer() {
		//g_Engine.openGlContext.DeleteBuffer(m_Handle);
	}

	void FrameBuffer::Bind() {
		//g_Engine.openGlContext.BindFrameBuffer(m_Handle);
	}

	void FrameBuffer::Unbind() {
		//g_Engine.openGlContext.BindFrameBuffer(0);
	}

	void FrameBuffer::AttachTexture(const Texture& texture) {
		//g_Engine.openGlContext.AttachTextureToFrameBuffer(m_Handle, texture.m_Handle);
	}

	void FrameBuffer::AttachRenderBuffer(const RenderBuffer& renderBuffer) {
		//g_Engine.openGlContext.AttachRenderBufferToFrameBuffer(m_Handle, renderBuffer.m_Handle);
	}

	void FrameBuffer::Compile() {
		/*if (!g_Engine.openGlContext.GetFrameBufferStatus(m_Handle)) {
			LOG("FrameBuffer failed to compile.", LogLevel::ERROR);
		}*/
	}
}