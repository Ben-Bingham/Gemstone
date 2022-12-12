#pragma once

// #include <GL/glew.h>

#include "GlBuffer.h"
#include "Log.h"

namespace Ruby {
	// class BufferTexture {
	// public:
	// 	BufferTexture() { glGenTextures(1, &m_Texture); }
	//
	// 	void setData(VertexBuffer& bufferObject, GLenum dataFormat) {
	// 		glTexBuffer(GL_TEXTURE_BUFFER, dataFormat, bufferObject.getVBO());
	// 	}
	//
	// 	BufferTexture(BufferTexture&) = delete;
	// 	BufferTexture& operator=(BufferTexture&) = delete;
	// 	BufferTexture(BufferTexture&& other) noexcept
	// 		: m_Texture(std::move(other.m_Texture)) {
	// 		other.m_Texture = 0;
	// 	}
	//
	// 	BufferTexture& operator=(BufferTexture&& other) noexcept {
	// 		m_Texture = std::move(other.m_Texture);
	// 		return *this;
	// 	}
	//
	// 	~BufferTexture() { glDeleteTextures(1, &m_Texture); }
	//
	// 	void bind() const { glBindTexture(GL_TEXTURE_BUFFER, m_Texture); }
	// 	static void activateUnit(int unit) { glActiveTexture(GL_TEXTURE0 + unit); }
	//
	// 	unsigned int getTexture() const { return m_Texture; }
	//
	// private:
	// 	unsigned int m_Texture;
	// };
}