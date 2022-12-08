#pragma once

#include "Renderable.h"

#include "Geometry/Mesh.h"

#include "Materials/SkyboxMaterial.h"

namespace Ruby {
	class SkyBox final : public Renderable {
	public:
		SkyBox(const Ptr<SkyBoxMaterial>& skyBoxMaterial)
			: Renderable(createPtr<Mesh>(Mesh::Shape::CUBE), skyBoxMaterial) {
	
		}
	};
}