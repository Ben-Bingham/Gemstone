#include "Texture.h"

#include <GL/glew.h>

namespace Ruby {
	Texture::Texture(const Image& image)
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

	Texture::~Texture() { glDeleteTextures(1, &m_Texture); }

	Texture::Texture(Texture&& other) noexcept
		: m_Texture(std::move(other.m_Texture)),
		m_Image(std::move(other.m_Image)) {
		other.m_Texture = 0;
	}

	Texture& Texture::operator=(Texture&& other) noexcept {
		m_Texture = std::move(other.m_Texture);
		m_Image = std::move(other.m_Image);
		return *this;
	}

	void Texture::bind() const { glBindTexture(GL_TEXTURE_2D, m_Texture); }
	void Texture::activateUnit(const int unit) { glActiveTexture(GL_TEXTURE0 + unit); }

	unsigned int Texture::getTexture() const { return m_Texture; }

	void Texture::updateData() {
		setSubData(0, 0, *m_Image);
	}

	void Texture::setSubData(unsigned int posX, unsigned int posY, const Image& image) {
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
}