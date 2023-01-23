#pragma once
#include "MaterialData.h"

namespace Ruby {
	class Material {
	public:
		Material() = default;

		Celestite::Ptr<MaterialData> material;
	};
}