#pragma once
#include "Rendering/OpenGlContext.h"

namespace Gem {
	class FrameBuffer {
	public:
		FrameBuffer();
		FrameBuffer(const FrameBuffer& other) = default;
		FrameBuffer(FrameBuffer&& other) noexcept = default;
		FrameBuffer& operator=(const FrameBuffer& other) = default;
		FrameBuffer& operator=(FrameBuffer&& other) noexcept = default;
		~FrameBuffer();

	private:
		FrameBufferHandle m_Handle;
	};
}