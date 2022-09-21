#pragma once

#include "Vector.h"

namespace Ruby {
	struct PointLight {
		Malachite::Vector3f position{ 0.0f };

		Malachite::Vector3f ambient{ 0.2f };
		Malachite::Vector3f diffuse{ 0.5f };
		Malachite::Vector3f specular{ 1.0f };

		float constant{ 1.0f };
		float linear{ 0.09f };
		float quadratic{ 0.032f };
	};

	struct DirectionalLight {
		Malachite::Vector3f direction{ 0.0f, -1.0f, 0.0f };

		Malachite::Vector3f ambient{ 0.2f };
		Malachite::Vector3f diffuse{ 0.5f };
		Malachite::Vector3f specular{ 1.0f };
	};
}