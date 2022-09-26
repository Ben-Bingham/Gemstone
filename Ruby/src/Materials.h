#pragma once

#include "Texture.h"

namespace Ruby {
	struct PhongMaterial {
		PhongMaterial() {}

		PhongMaterial(const Image& diffuseImage, const Image& specularImage) 
			: diffuse(std::make_unique<Texture>(diffuseImage)), specular(std::make_unique<Texture>(specularImage)) { }

		std::unique_ptr<Texture> diffuse{ std::make_unique<Texture>(Image::noImage) };
		std::unique_ptr<Texture> specular{ std::make_unique<Texture>(Image::noImage) };
		float shininess{ 32.0f };
	};

	struct SolidMaterial {
		SolidMaterial() {}
		SolidMaterial(Malachite::Vector3f Colour) : colour(Colour) {}

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