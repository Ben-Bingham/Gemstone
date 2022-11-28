#pragma once

#include "Renderable.h"
#include "Materials/SkyboxMaterial.h"
#include "Geometry/CubeGeometryData.h"

namespace Ruby {
	class SkyBox final : public Renderable {
	public:
		SkyBox(SkyBoxMaterial& skyBoxMaterial)
			: Renderable(m_SkyBoxGeometryData, skyBoxMaterial) {

		}

	private:
		static CubeGeometryData m_SkyBoxGeometryData;
	};
}