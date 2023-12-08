#include "pch.h"
#include "FpsCameraSystem.h"

#include "Core/Engine.h"

//#include "Entity Component System/ComponentView.h"

#include "Rendering/Components/Camera.h"

#include "Utility/Transform.h"

namespace Gem {
	//void FpsCameraSystem::StartUp() {
	//	//g_Engine.window.DisableCursor();
	//}

	//void FpsCameraSystem::Step(EntityManager& entityManager, const float dt) {
	//	//for (auto [c, transform] : ComponentView<Camera, Transform>{ entityManager }) {
	//	//	if (c.type != Camera::CameraType::FPS) { continue; }
	//	//	const Ptr<FpsCamera> cam = std::dynamic_pointer_cast<FpsCamera>(c.Cam());

	//	//	if (!cam->setUp) {
	//	//		transform.rotation.y = -90.0f;

	//	//		//cam->oldMousePosition = Vector2i{ (int)g_Engine.window.size.x / 2, (int)g_Engine.window.size.x / 2 };
	//	//		cam->setUp = true;
	//	//	}

	//	//	const float velocity = cam->movementSpeed * dt;
	//	//	//if (g_Engine.keyboard.GetKey(Key::W)) {
	//	//	//	transform.position += cam->forward * velocity;
	//	//	//}
	//	//	//if (g_Engine.keyboard.GetKey(Key::S)) {
	//	//	//	transform.position -= cam->forward * velocity;
	//	//	//}
	//	//	//if (g_Engine.keyboard.GetKey(Key::A)) {
	//	//	//	transform.position -= cam->right * velocity;
	//	//	//}
	//	//	//if (g_Engine.keyboard.GetKey(Key::D)) {
	//	//	//	transform.position += cam->right * velocity;
	//	//	//}
	//	//	//if (g_Engine.keyboard.GetKey(Key::SPACE)) {
	//	//	//	transform.position += Vector3f::up * velocity;
	//	//	//}
	//	//	//if (g_Engine.keyboard.GetKey(Key::LEFT_SHIFT)) {
	//	//	//	transform.position -= Vector3f::up * velocity;
	//	//	//}

	//	//	//const Vector2i mousePos = g_Engine.mouse.GetPosition();

	//	//	if (m_MouseInputActive) {
	//	//		//Vector2f deltaMousePosition{ (float)mousePos.x - (float)cam->oldMousePosition.x, (float)cam->oldMousePosition.y - (float)mousePos.y };
	//	//		//deltaMousePosition *= cam->mouseSensitivity;

	//	//		//transform.rotation.y += deltaMousePosition.x;
	//	//		//transform.rotation.x += deltaMousePosition.y;

	//	//		//if (transform.rotation.x > 89.9f) {
	//	//		//	transform.rotation.x = 89.9f;
	//	//		//}
	//	//		//else if (transform.rotation.x < -89.9f) {
	//	//		//	transform.rotation.x = -89.9f;
	//	//		//}
	//	//	}

	//	//	//cam->oldMousePosition = mousePos;

	//	//	Vector3f forward;
	//	//	forward.x = std::cos(degreesToRadians(transform.rotation.y)) * std::cos(degreesToRadians(transform.rotation.x));
	//	//	forward.y = std::sin(degreesToRadians(transform.rotation.x));
	//	//	forward.z = std::sin(degreesToRadians(transform.rotation.y)) * std::cos(degreesToRadians(transform.rotation.x));
	//	//	cam->forward = forward.normalize();

	//	//	cam->right = cross(cam->forward, Vector3f::up).normalize();
	//	//	cam->up = cross(cam->right, cam->forward).normalize();

	//	//	if (m_HasResized) {
	//	//		//cam->projection = perspective(degreesToRadians(cam->fov), (float)g_Engine.window.size.x / (float)g_Engine.window.size.y, 0.1f, 100.0f);
	//	//	}
	//	//	cam->view = lookAt(transform.position, transform.position + cam->forward, cam->up);
	//	//}
	//}

	//void FpsCameraSystem::HandleEvent(const KeyboardEvents::KeyDown& event) {
	//	if (event.key == Key::M) {
	//		if (m_MouseInputActive == true) {
	//			m_MouseInputActive = false;
	//			//g_Engine.window.EnableCursor();
	//		}
	//		else {
	//			m_MouseInputActive = true;
	//			//g_Engine.window.DisableCursor();
	//		}
	//	}
	//}

	//void FpsCameraSystem::HandleEvent(const WindowEvents::Resize& event) {
	//	m_HasResized = true;
	//}
}