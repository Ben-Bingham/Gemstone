#pragma once

#include "Geometry/GeometryData.h"
#include "PhongRenderable.h"

namespace Ruby {
	class PhongGeometry : public PhongRenderable {
	public:
		PhongGeometry(std::unique_ptr<GeometryData> geometryObject, PhongMaterial& material);

		void render() const override;
	};
}