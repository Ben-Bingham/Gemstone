#pragma once

#include <vector>

#include <GL/glew.h>

#include "Resources/Image.h"
#include "Pointer.h"

namespace Ruby {
	class Cubemap {
	public:
		Cubemap(const std::initializer_list<Ptr<Image>>& faces) {
			assert(faces.size() == 6);
			glGenTextures(1, &m_Cubemap);

			bind(); 

			std::vector<Ptr<Image>> images{ faces };

			unsigned int i{ 0 };
			for (Ptr<Image> image : images) {

				GLenum imageFormat;
				if (image->getChannels() == 3) {
					imageFormat = GL_RGB;
				}
				else if (image->getChannels() == 4) {
					imageFormat = GL_RGBA;
				}
				else {
					LOG("Unrecognized number of channels", Lazuli::LogLevel::ERROR);
					imageFormat = GL_RGB;
				}

				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, imageFormat, image->getWidth(), image->getHeight(), 0, imageFormat, GL_UNSIGNED_BYTE, &image->getContent()[0]);
				i++;
			}

			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		}

		Cubemap(Cubemap&) = delete;
		Cubemap& operator=(Cubemap&) = delete;
		Cubemap& operator=(Cubemap&& other) noexcept {
			m_Cubemap = std::move(other.m_Cubemap);
			other.m_Cubemap = 0;
		}

		Cubemap(Cubemap&& other) noexcept
			: m_Cubemap(std::move(other.m_Cubemap)) {
			other.m_Cubemap = 0;
		}

		~Cubemap() { glDeleteTextures(1, &m_Cubemap); }

		static void activateUnit(int unit) { glActiveTexture(GL_TEXTURE0 + unit); }

		void bind() const { glBindTexture(GL_TEXTURE_CUBE_MAP, m_Cubemap); }
		static void unbind() { glBindTexture(GL_TEXTURE_CUBE_MAP, 0); }

	private:
		unsigned int m_Cubemap{ 0 };
	};
}