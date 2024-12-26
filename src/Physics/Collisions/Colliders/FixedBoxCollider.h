#pragma once
#include "BaseCollider.h"

#include <glm/glm.hpp>

namespace Gem {
	class FixedBoxCollider : public BaseCollider {
	public:
		FixedBoxCollider();

		glm::vec3 minDistances{ -1.0f, -1.0f, -1.0f };
		glm::vec3 maxDistances{ 1.0f, 1.0f, 1.0f };
	};
}