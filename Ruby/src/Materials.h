#pragma once

#include "Texture.h"

namespace Ruby {
	struct Material {
		std::unique_ptr<Texture> diffuse{ std::make_unique<Texture>(Image::noImage) };
		std::unique_ptr<Texture> specular{ std::make_unique<Texture>(Image::noImage) };
		float shininess{ 32.0f };
	};
}