#pragma once

#include "SolidRenderable.h"
#include "Geometry/GeometryObject.h"

namespace Ruby {
	class SolidGeometry : public SolidRenderable {
	public:
		SolidGeometry(std::unique_ptr<GeometryObject> geometryObject, Colour colour); //TODO replace unique pointer with reference

		void render() const override;
	};
}