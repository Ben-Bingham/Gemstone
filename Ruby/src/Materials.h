#pragma once

#include "Texture.h"

namespace Ruby {
	struct PhongMaterial {
		PhongMaterial(Texture& diffuseImage, Texture& specularImage)
			: diffuse(&diffuseImage), specular(&specularImage) { }

		Texture* diffuse;
		Texture* specular;
		float shininess{ 32.0f };
	};

	struct SolidMaterial {
		SolidMaterial() {}
		SolidMaterial(Malachite::Vector3f Colour) : colour(Colour) { }

		Malachite::Vector3f colour{ 0.0f };
	};

	struct ImageMaterial {
		ImageMaterial(Texture& texture)
			: texture(&texture) {
		}

		Texture* texture;
	};
}