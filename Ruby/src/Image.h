#pragma once

#include <string>
#include <vector>

#include <stb_image.h>

#include "Log.h"
#include "Vector.h"

namespace Ruby {
	class Image {
	public:
		Image(const std::string& path, bool flipVertically = true) : m_Path(path) {
			stbi_set_flip_vertically_on_load(flipVertically);

			unsigned char* data = stbi_load(m_Path.c_str(), &m_Width, &m_Height, &m_Channels, 0);
			m_Content.resize((size_t)(m_Width * m_Height * m_Channels));

			memcpy(&m_Content[0], data, m_Content.size());

			if (!data) {
				LOG("Image: " + m_Path + "Failed to load. ", Lazuli::LogLevel::ERROR);
			}

			stbi_image_free(data);
		}

		Image(const Malachite::Vector3f& colour, unsigned int width = 1, unsigned int height = 1, unsigned int channels = 3)
			: m_Path(""), m_Width(width), m_Height(height), m_Channels(channels) {

			unsigned char r = (unsigned char)(colour.x * 255);
			unsigned char g = (unsigned char)(colour.y * 255);
			unsigned char b = (unsigned char)(colour.z * 255);

			m_Content.resize(m_Width * m_Height * m_Channels);

			for (unsigned int i = 0; i < width * height * sizeof(unsigned char); i += 3) {
				m_Content[i + 0u] = r;
				m_Content[i + 1u] = g;
				m_Content[i + 2u] = b;
			}
		}

		Image(std::vector<unsigned char>& content, unsigned int width, unsigned int height, unsigned int channels)
			: m_Path(""), m_Content(content), m_Width(width), m_Height(height), m_Channels(channels) {
		}

		std::vector<unsigned char> getContent() const { return m_Content; }
		int getWidth() const { return m_Width; }
		int getHeight() const { return m_Height; }
		int getChannels() const { return m_Channels; }

		static const Image noImage;

	private:
		std::vector<unsigned char> m_Content;
		std::string m_Path;
		int m_Width;
		int m_Height;
		int m_Channels;
	};
}
