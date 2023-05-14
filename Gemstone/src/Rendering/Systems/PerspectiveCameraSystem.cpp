#include "pch.h"
#include "PerspectiveCameraSystem.h"

#include "Entity Component System/ComponentView.h"

namespace Gem {
	void PerspectiveCameraSystem::Step(EntityManager& entityManager, float dt) {
		for (auto [c, transform] : ComponentView<Camera, Transform>{ entityManager }) {
			if (c.type != Camera::CameraType::PERSPECTIVE) { continue; }
			Ptr<PerspectiveCamera> cam = std::dynamic_pointer_cast<PerspectiveCamera>(c.Cam());

			const float veloctiy = cam->movementSpeed * dt;
			for (auto& movement : m_Movements) {
				switch (movement) {
				case MovementDirections::FORWARD:
					transform.position += cam->forward * veloctiy;
					break;
				case MovementDirections::LEFT:
					transform.position -= cam->right * veloctiy;
					break;
				case MovementDirections::RIGHT:
					transform.position += cam->right * veloctiy;
					break;
				case MovementDirections::BACKWARD:
					transform.position -= cam->forward * veloctiy;
					break;
				}
			}

			Vector3f forward{ Vector3f::north.normalize() }; // TODO
			// forward.x = std::cos(degreesToRadians(transform.rotation().y)) * std::cos(degreesToRadians(transform.rotation().x));
			// forward.y = std::cos(degreesToRadians(transform.rotation().x));
			// forward.z = std::sin(degreesToRadians(transform.rotation().y)) * std::cos(degreesToRadians(transform.rotation().x));

			cam->forward = forward.normalize();
			cam->right = cross(cam->forward, cam->up).normalize();
			cam->up = cross(cam->right, cam->forward).normalize();

			cam->projection = perspective(degreesToRadians(cam->fov), (float)g_Engine.window.Size().x / (float)g_Engine.window.Size().y, 0.1f, 100.0f); // TODO only needs to change when the window is resized
			cam->view = lookAt(transform.position, transform.position + cam->forward, cam->up);
		}

		m_Movements.clear();
	}

	void PerspectiveCameraSystem::HandleEvent(const KeyboardEvents::KeyDown& event) {
		if (event.key == KeyboardEvents::Key::W) {
			m_Movements.push_back(MovementDirections::FORWARD);
		}
		if (event.key == KeyboardEvents::Key::A) {
			m_Movements.push_back(MovementDirections::LEFT);
		}
		if (event.key == KeyboardEvents::Key::S) {
			m_Movements.push_back(MovementDirections::BACKWARD);
		}
		if (event.key == KeyboardEvents::Key::D) {
			m_Movements.push_back(MovementDirections::RIGHT);
		}
	}
}