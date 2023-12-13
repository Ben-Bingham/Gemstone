#include "pch.h"
#include "Rendering/Atlases/ImageAtlas.h"

namespace Gem {
	ImageAtlas::ImageAtlas()
		: Image(CreateImage(std::vector{Colour::BLACK}, Vector2i(1, 1), 4)){
		
	}

	void ImageAtlas::AddImage(const Image& addedImage) {
		m_NumberOfPixels += addedImage.content.size();
		m_NumberOfImages++;

		if (m_NumberOfImages == 1) {
			content = addedImage.content;
			return;
		}

		std::vector contentBackup{ content };

		content.clear();
		const Vector2i oldDimensions = dimensions;
		const Vector2i newDimensions{ dimensions.x + addedImage.dimensions.x, dimensions.y + addedImage.dimensions.y };
		const Vector2i newTopLeftCornerForAddedImage = {};

		content.resize((unsigned int)(newDimensions.x * newDimensions.y));

		for (int x = 0; x < newDimensions.x; x++) {
			for (int y = 0; y < newDimensions.y; y++) {
				
			}
			if (x <= oldDimensions.x) {
				content[x] = contentBackup[x];
			}
			else if (x > oldDimensions.x && x <= newDimensions.x){
				
			}
		}
	}
}