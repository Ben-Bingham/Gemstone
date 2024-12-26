#pragma once
#include <glm/glm.hpp>

#include "Utility/Pointer.h"

namespace Gem {
	class BaseMaterial;
	struct MeshObject;

	struct Renderable {
		Ptr<MeshObject> mesh;
		Ptr<BaseMaterial> material;
		glm::mat4 modelMatrix;
	};
}