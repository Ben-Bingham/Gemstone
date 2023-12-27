#pragma once
#include "BaseMaterial.h"
#include "Utility/Pointer.h"

namespace Gem {
	// Component
	class Material {
	public:
		Material(const Ptr<BaseMaterial>& material);

		//Material(const Colour& colour);
		//Material(const Image& diffuse, const Image& specular); // TODO

		Ptr<BaseMaterial> material;
	};
}