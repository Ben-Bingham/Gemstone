#pragma once
#include "Rendering/Utility/Image.h"
#include "Gem.h"

namespace Gem {
	class GEM_API ImageAtlas : public Image {
	public:
		ImageAtlas();

		void AddImage(const Image& addedImage);

	private:
		size_t m_NumberOfImages{ 0 };
		size_t m_NumberOfPixels{ 0 };
	};
}