#pragma once
#include "IMaterial.h"
#include "Gem.h"

namespace Gem {
	class GEM_API Material {
	public:
		Material(const Ptr<IMaterial>& material);
		/*Material(const Image& diffuse = Image::MISSING_IMAGE, const Image& specular = Image::MISSING_IMAGE);
		Material(const Colour& colour = Colour::PINK);*/

		Ptr<IMaterial> iMaterial;
	};
}