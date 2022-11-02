#pragma once

#include "Geometry/GeometryObject.h"
#include "PhongRenderable.h"

namespace Ruby {
	class PhongGeometry : public PhongRenderable {
	public:
		PhongGeometry(std::unique_ptr<GeometryObject> geometryObject, PhongMaterial& material);

		void render() const override;
	};
}