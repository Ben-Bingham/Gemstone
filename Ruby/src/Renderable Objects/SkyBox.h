#pragma once

#include "Renderable.h"
#include "Materials/SkyboxMaterial.h"
#include "Geometry/CubeGeometryData.h"
#include "Geometry/GeometryInstances.h"

namespace Ruby {
	class SkyBox final : public Renderable {
	public:
		SkyBox(SkyBoxMaterial& skyBoxMaterial)
			: Renderable(createPtr<CubeGeometryData>(), skyBoxMaterial) {
	
		}
	};
}