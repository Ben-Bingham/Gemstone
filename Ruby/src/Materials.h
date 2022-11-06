#pragma once

#include "OpenGl objects/Texture.h"

namespace Ruby {
	struct PhongMaterial {
		PhongMaterial(Texture& diffuseImage, Texture& specularImage)
			: diffuse(&diffuseImage), specular(&specularImage) { }

		Texture* diffuse;
		Texture* specular;
		float shininess{ 32.0f };
	};

	struct ImageMaterial {
		ImageMaterial(Texture& texture)
			: texture(&texture) {
		}

		Texture* texture;
	};
}