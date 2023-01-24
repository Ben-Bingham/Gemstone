#pragma once

#include "Vector.h"
#include "Matrix.h"

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
			: front(Malachite::Vector3f(0.0f, 0.0f, -1.0f)), m_FOV(fov), position(pos) {

			updateCameraVectors();
		}

		Malachite::Matrix4f& getViewMatrix() {
			calculateViewMatrix();
			return m_ViewMatrix;
		}

		void updateCameraVectors() {
			right = Malachite::cross(front, Malachite::Vector3f{ 0.0f, 1.0f, 0.0f }).normalize();
			up = Malachite::cross(right, front).normalize();
		}

		void calculateViewMatrix() {
			m_ViewMatrix = Malachite::lookAt(position, position + front, up);
		}

		Malachite::Vector3f front;
		Malachite::Vector3f up;
		Malachite::Vector3f right;

		Malachite::Vector3f position;

		RenderingTarget target{ NONE };

	private:
		float m_FOV;

		Malachite::Matrix4f m_ViewMatrix;
	};
}