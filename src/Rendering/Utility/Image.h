#pragma once

#include <string>
#include <vector>

#include "Utility/Colour.h"
#include "Utility/Path.h"

namespace Gem {
	class Image {
	public:
		Image(const Path& imgPath);

		static Image CreateImage(const std::vector<Colour>& content, const Vector2i& dimensions, int channels);
		static Image CreateImage(const Colour& colour, const Vector2i& dimensions = { 1, 1 }, int channels = 4);

		std::string path;
		std::vector<Colour> content{ };
		Vector2i dimensions{ };
		int channels{ 4 };

		const static Image MISSING_IMAGE;

	private:
		Image(std::vector<Colour> colours, const Vector2i& dimensions, int channels);
	};
}