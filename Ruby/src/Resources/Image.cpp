#include "Image.h"

namespace Ruby {
	Image::Image(std::string path, bool flipVertically)
		: m_Path(std::move(path)) {
		stbi_set_flip_vertically_on_load(flipVertically);
		int width, height, channels;
		unsigned char* data = stbi_load(m_Path.c_str(), &width, &height, &channels, 0);
		m_Width = width;
		m_Height = height;
		m_Channels = channels;

		if (!data) {
			LOG("Image: " + m_Path + "Failed to load. ", Lazuli::LogLevel::ERROR);
		}

		m_Content.resize(m_Width * m_Height * m_Channels);

		memcpy(m_Content.data(), data, m_Content.size());

		stbi_image_free(data);
	}

	Image::Image(const Malachite::Vector3f& colour, const unsigned int width, const unsigned int height)
		: m_Width(width)
		, m_Height(height)
		, m_Channels(3) {

		const auto r = static_cast<unsigned char>(colour.x * 255);
		const auto g = static_cast<unsigned char>(colour.y * 255);
		const auto b = static_cast<unsigned char>(colour.z * 255);

		m_Content.resize(m_Width * m_Height * m_Channels);

		for (unsigned int i = 0; i < width * height * m_Channels; i += 3) {
			m_Content[i + 0u] = r;
			m_Content[i + 1u] = g;
			m_Content[i + 2u] = b;
		}
	}

	Image::Image(const Malachite::Vector4f& colour, const unsigned int width, const unsigned int height)
		: m_Width(width)
		, m_Height(height)
		, m_Channels(4) {

		const auto r = static_cast<unsigned char>(colour.x * 255);
		const auto g = static_cast<unsigned char>(colour.y * 255);
		const auto b = static_cast<unsigned char>(colour.z * 255);
		const auto a = static_cast<unsigned char>(colour.w * 255);

		m_Content.resize(m_Width * m_Height * 4);

		for (unsigned int i = 0; i < width * height * m_Channels; i += 4) {
			m_Content[i + 0u] = r;
			m_Content[i + 1u] = g;
			m_Content[i + 2u] = b;
			m_Content[i + 3u] = a;
		}
	}

	Image::Image(std::vector<unsigned char> content, const unsigned int width, const unsigned int height, const unsigned int channels)
		: m_Content(std::move(content))
		, m_Width(width)
		, m_Height(height)
		, m_Channels(channels) { }

	const Image Image::noImage{std::string(RUBY_ASSETS) + "\\images\\noTexture.png"};
}