#pragma once

#include "Texture.h"

namespace Ruby {
	struct PhongMaterial {
		PhongMaterial() {}

		PhongMaterial(const Image& diffuseImage, const Image& specularImage) 
			: diffuse(Texture{ diffuseImage }), specular(Texture{ specularImage }) { }

		Texture diffuse{ Image::noImage };
		Texture specular{ Image::noImage };
		float shininess{ 32.0f };
	};

	struct SolidMaterial {
		SolidMaterial() {}
		SolidMaterial(Malachite::Vector3f Colour) : colour(Colour) { }

		Malachite::Vector3f colour{ 0.0f };
	};

	struct ImageMaterial {
		ImageMaterial() {}

		ImageMaterial(const Image& image) 
			: texture(image) { }

		ImageMaterial(Texture& texture)
			: texture(std::move(texture)) {
		}

		Texture texture{ Image::noImage };
	};
}