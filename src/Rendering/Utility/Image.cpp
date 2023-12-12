#include "pch.h"

#include <stb_image.h>

#include "Rendering/Utility/Image.h"

namespace Gem {
	Image::Image(const std::string& path)
		: path(CreatePtr<std::string>(path)) {
		stbi_set_flip_vertically_on_load(true);

		int channelsInFile{ 0 };

		unsigned char* imageData = stbi_load(path.c_str(), &dimensions.x, &dimensions.y, &channelsInFile, channels);
		
		if (imageData == nullptr) {
			LOG("Image: " + path + " Failed to load. ", LogLevel::ERROR);
		}
		
		content.resize((unsigned int)(dimensions.x * dimensions.y * channels));
		
		memcpy((void*)content.data(), imageData, content.size());
		
		stbi_image_free(imageData);
	}

	Image Image::CreateImage(const std::vector<Colour>& content, const Vector2i& dimensions, int channels) {
		if ((unsigned int)(dimensions.x * dimensions.y) != content.size()) {
			LOG("Incorrect number of colours given", LogLevel::ERROR);

			return MISSING_IMAGE;
		}

		return { content, dimensions, channels };
	}

	Image Image::CreateImage(const Colour& colour, const Vector2i& dimensions, const int channels) {
		std::vector<Colour> colours{ (unsigned int)(dimensions.x * dimensions.y) };

		for (auto& col : colours) {
			col = colour;
		}

		return CreateImage(colours, dimensions, channels);
	}

	Image::Image(const std::vector<Colour> colours, const Vector2i& dimensions, const int channels)
		: content(std::move(colours)), dimensions(dimensions), channels(channels) {

	}

	const Image Image::MISSING_IMAGE{ CreateImage(Colour{ 255, 0, 128 }, { 100, 100 }, 4) };
}