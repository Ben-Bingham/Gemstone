#pragma once

#include "SolidRenderable.h"
#include "Geometry/GeometryObject.h"

namespace Ruby {
	class SolidGeometry : public SolidRenderable {
	public:
		SolidGeometry(std::unique_ptr<GeometryObject> geometryObject, SolidMaterial& material);

		void render() const override;
	};
}