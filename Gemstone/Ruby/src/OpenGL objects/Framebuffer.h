#pragma once

#include <GL/glew.h>
#include "Texture.h"

namespace Ruby {
	class Framebuffer {
	public:
		Framebuffer() { glGenFramebuffers(1, &m_FBO); }
		Framebuffer(Framebuffer&) = delete;
		Framebuffer& operator=(Framebuffer&) = delete;
		Framebuffer& operator=(Framebuffer&& other) noexcept {
			m_FBO = std::move(other.m_FBO);
			other.m_FBO = 0;
			return *this;
		}

		Framebuffer(Framebuffer&& other) noexcept
			: m_FBO(std::move(other.m_FBO)) {
			other.m_FBO = 0;
		}

		~Framebuffer() { glDeleteFramebuffers(1, &m_FBO); }

		// All these functions seem kind of scuffed, should probably be changed
		void  checkStatus() {
			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
				LOG("Framebuffer failed to complete", Lazuli::LogLevel::ERROR);
			}

		}

		void attachTexture(const Texture& texture, GLint attachmentType) {
			glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, GL_TEXTURE_2D, texture.getTexture(), 0);
		}

		void setDrawBuffer(GLint buffer) {
			glDrawBuffer(buffer);
		}

		void setReadBuffer(GLint buffer) {
			glReadBuffer(buffer);
		}

		void bind() const { glBindFramebuffer(GL_FRAMEBUFFER, m_FBO); }
		static void unbind() { glBindFramebuffer(GL_FRAMEBUFFER, 0); }

	private:
		unsigned int m_FBO{ 0 };
	};
}