#pragma once
#include "ColourInput.h"
#include "MaterialData.h"

namespace Ruby {
	using namespace Celestite;
	class Material {
	public:
		Material() = default;

		Ptr<MaterialData> material;



		Ptr<ColourInput> diffuse; //TODO was working on last
		Ptr<ColourInput> specular;
		Ptr<ColourInput> shininess;
	};
}