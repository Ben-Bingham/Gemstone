#pragma once
#include "RenderBuffer.h"
#include "Texture.h"
#include "Rendering/OpenGlContext.h"
#include "Gem.h"

namespace Gem {
	class FrameBuffer {
	public:
		FrameBuffer();
		FrameBuffer(const FrameBuffer& other) = default;
		FrameBuffer(FrameBuffer&& other) noexcept = default;
		FrameBuffer& operator=(const FrameBuffer& other) = default;
		FrameBuffer& operator=(FrameBuffer&& other) noexcept = default;
		~FrameBuffer();

		void Bind();
		static void Unbind();

		void AttachTexture(const Texture& texture);
		void AttachRenderBuffer(const RenderBuffer& renderBuffer);

		void Compile();

	private:
		FrameBufferHandle m_Handle;
	};
}