#pragma once

#include "SolidRenderable.h"
#include "Geometry/GeometryData.h"

namespace Ruby {
	class SolidGeometry : public SolidRenderable {
	public:
		SolidGeometry(std::unique_ptr<GeometryData> geometryObject, Colour colour); //TODO replace unique pointer with reference

		void render() const override;
	};
}