#pragma once

#include <GL/glew.h>

#include "Image.h"
#include "Log.h"

namespace Ruby {
	class Texture {
	public:
		Texture(int imageFormat, int width, int height, int wrapMode = GL_CLAMP_TO_BORDER, int filter = GL_NEAREST, bool mipmaps = false) 
			: m_Image{ nullptr } {
			glGenTextures(1, &m_Texture);

			bind();

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

			glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, NULL);
			if (mipmaps) {
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}

		Texture(const Image& image)
			: m_Image(std::make_unique<Image>(image)) {
			glGenTextures(1, &m_Texture);

			bind();

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			GLenum imageFormat;
			if (m_Image->getChannels() == 3) {
				imageFormat = GL_RGB;
			}
			else if (m_Image->getChannels() == 4) {
				imageFormat = GL_RGBA;
			}
			else {
				LOG("Unrecognized number of channels", Lazuli::LogLevel::ERROR);
				imageFormat = GL_RGB;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, m_Image->getWidth(), m_Image->getHeight(), 0, imageFormat, GL_UNSIGNED_BYTE, &m_Image->getContent()[0]);

			glGenerateMipmap(GL_TEXTURE_2D);
		}

		Texture(Texture&) = delete;
		Texture& operator=(Texture&) = delete;
		Texture(Texture&& other) noexcept
			: m_Texture(std::move(other.m_Texture)),
			m_Image(std::move(other.m_Image)) {
			other.m_Texture = 0;
		}

		Texture& operator=(Texture&& other) noexcept {
			m_Texture = std::move(other.m_Texture);
			m_Image = std::move(other.m_Image);
		}

		~Texture() { glDeleteTextures(1, &m_Texture); }

		void bind() const { glBindTexture(GL_TEXTURE_2D, m_Texture); }
		static void activateUnit(int unit) { glActiveTexture(GL_TEXTURE0 + unit); }

		unsigned int getTexture() { return m_Texture; } //TODO remove

	private:
		unsigned int m_Texture;
		std::unique_ptr<Image> m_Image;
	};
}