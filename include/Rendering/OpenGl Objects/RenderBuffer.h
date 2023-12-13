#pragma once
#include "Rendering/OpenGlContext.h"
#include "Gem.h"

namespace Gem {
	class RenderBuffer {
		friend class FrameBuffer;
	public:
		RenderBuffer();
		RenderBuffer(const RenderBuffer& other) = default;
		RenderBuffer(RenderBuffer&& other) noexcept = default;
		RenderBuffer& operator=(const RenderBuffer& other) = default;
		RenderBuffer& operator=(RenderBuffer&& other) noexcept = default;
		~RenderBuffer();

	private:
		RenderBufferHandle m_Handle;
	};
}