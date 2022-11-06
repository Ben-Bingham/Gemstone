#pragma once

#include <GL/glew.h>

#include "Image.h"
#include "Log.h"

namespace Ruby {
	class Texture {
	public:
		Texture(int imageFormat, unsigned int width, unsigned int height, int wrapMode = GL_CLAMP_TO_BORDER, int filter = GL_NEAREST, bool mipmaps = false)
			: m_Image{ nullptr } {
			glGenTextures(1, &m_Texture);

			bind();

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

			if (wrapMode == GL_CLAMP_TO_BORDER) {
				float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
				glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
			}

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

			glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, width, height, 0, imageFormat, GL_FLOAT, NULL);
			if (mipmaps) {
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}

		Texture(Image& image)
			: m_Image(&image) {
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

			glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, m_Image->getWidth(), m_Image->getHeight(), 0, imageFormat, GL_UNSIGNED_BYTE, m_Image->getContent().data());

			glGenerateMipmap(GL_TEXTURE_2D);
		}

		void setSubData(unsigned int posX, unsigned int posY, Image& image) {
			GLenum imageFormat;
			if (image.getChannels() == 3) {
				imageFormat = GL_RGB;
			}
			else if (image.getChannels() == 4) {
				imageFormat = GL_RGBA;
			}
			else {
				LOG("Unrecognized number of channels", Lazuli::LogLevel::ERROR);
				imageFormat = GL_RGB;
			}

			bind();
			glTexSubImage2D(GL_TEXTURE_2D, 0, posX, posY, image.getWidth(), image.getHeight(), imageFormat, GL_UNSIGNED_BYTE, &image.getContent()[0]);
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
			return *this;
		}

		~Texture() { glDeleteTextures(1, &m_Texture); }

		void bind() const { glBindTexture(GL_TEXTURE_2D, m_Texture); }
		static void activateUnit(int unit) { glActiveTexture(GL_TEXTURE0 + unit); }

		unsigned int getTexture() const { return m_Texture; }

	private:
		unsigned int m_Texture;
		Image* m_Image;
	};
}