#pragma once

#include "Renderable.h"
#include "Materials/SkyboxMaterial.h"
#include "Geometry/CubeGeometryData.h"

namespace Ruby {
	class SkyBox : public Renderable {
	public:
		SkyBox(SkyBoxMaterial& skyBoxMaterial)
			: Renderable(m_SkyBoxGeometryData, skyBoxMaterial) {

		}

		void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const override;

	private:
		static CubeGeometryData m_SkyBoxGeometryData;
	};
}