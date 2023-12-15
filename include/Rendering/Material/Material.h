#pragma once
#include "IMaterial.h"

namespace Gem {
	class Material {
	public:
		Material(const Ptr<IMaterial>& material);
		/*Material(const Image& diffuse = Image::MISSING_IMAGE, const Image& specular = Image::MISSING_IMAGE);
		Material(const Colour& colour = Colour::PINK);*/

		Ptr<IMaterial> iMaterial;
	};
}