#pragma once

namespace Gem {
	enum RenderingTarget {
// TODO, add more targets like framebuffer, or texture
		// TODO also need to add multi window support, this can be done quite easily by making a base class "Rendering Target"
		// that window could derive from, this wont work now because Gem does not depend on Gem.
		WINDOW,
		NONE
	};

	class Camera {
	public:
		Camera(Vector3f pos = Vector3f(0.0f, 0.0f, 0.0f), float fov = 45.0f)
			: m_FOV(fov) { }

		Vector3f forward{ Vector3f::north };
		RenderingTarget target{ WINDOW };
		Matrix4f viewMatrix{ 1.0f };

	private:
		float m_FOV;
	};
}