#pragma once
#include "Rendering/OpenGlContext.h"

namespace Gem {
	class RenderBuffer {
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