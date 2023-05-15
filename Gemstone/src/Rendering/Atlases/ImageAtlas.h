#pragma once
#include "Rendering/Utility/Image.h"

namespace Gem {
	class ImageAtlas : public Image {
	public:
		ImageAtlas();

		void AddImage(const Image& addedImage);

	private:
		size_t m_NumberOfImages{ 0 };
		size_t m_NumberOfPixels{ 0 };
	};
}