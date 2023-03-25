#pragma once

#include "Malachite/Vector.h"
#include "Malachite/Matrix.h"

namespace Ruby {
	enum RenderingTarget {
// TODO, add more targets like framebuffer, or texture
		// TODO also need to add multi window support, this can be done quite easily by making a base class "Rendering Target"
		// that window could derive from, this wont work now because Wavellite does not depend on Ruby.
		WINDOW,
		NONE
	};

	class Camera {
	public:
		Camera(Malachite::Vector3f pos = Malachite::Vector3f(0.0f, 0.0f, 0.0f), float fov = 45.0f)
			: m_FOV(fov) { }

		Malachite::Vector3f forward{ Malachite::Vector3f::north };
		RenderingTarget target{ WINDOW };
		Malachite::Matrix4f viewMatrix{ 1.0f };

	private:
		float m_FOV;
	};
}