#pragma once

#include <string>
#include <vector>

#include <stb_image.h>

#include "Log.h"
#include "Vector.h"

namespace Ruby {
	class Image {
	public:
		explicit Image(std::string path, bool flipVertically = true);
		explicit Image(const Malachite::Vector3f& colour, unsigned int width = 1, unsigned int height = 1);
		explicit Image(const Malachite::Vector4f& colour, unsigned int width = 1, unsigned int height = 1);
		Image(std::vector<unsigned char> content, unsigned int width, unsigned int height, unsigned int channels);

		[[nodiscard]] std::vector<unsigned char> getContent() const { return m_Content; }
		std::vector<unsigned char>& getContent() { return m_Content; }
		[[nodiscard]] unsigned int getWidth() const { return m_Width; }
		[[nodiscard]] unsigned int getHeight() const { return m_Height; }
		[[nodiscard]] unsigned int getChannels() const { return m_Channels; }

		static const Image noImage;

	private:
		std::vector<unsigned char> m_Content;
		std::string m_Path;
		unsigned int m_Width;
		unsigned int m_Height;
		unsigned int m_Channels;
	};
}