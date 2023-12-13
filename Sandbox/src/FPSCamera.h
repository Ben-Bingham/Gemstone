#pragma once
#include "Camera.h"

class FPSCamera : public Ruby::Camera {
public:
	bool firstMouse{ true };
	int lastX{ 0 };
	int lastY{ 0 };
	float mouseSensitivity{ 0.1f };
	Malachite::Degree yaw{ -90.0f };
	Malachite::Degree pitch{ 0.0f };
};

void mousePositionCallback(int xpos, int ypos, void* data) {
	FPSCamera* camera = (FPSCamera*)data;

	if (camera->firstMouse) {
		camera->lastX = (int)xpos;
		camera->lastY = (int)ypos;
		camera->firstMouse = false;
	}

	float xOffset = (float)(xpos - camera->lastX);
	float yOffset = (float)(camera->lastY - ypos);
	camera->lastX = (int)xpos;
	camera->lastY = (int)ypos;

	xOffset *= camera->mouseSensitivity;
	yOffset *= camera->mouseSensitivity;

	camera->yaw += xOffset;
	camera->pitch += yOffset;

	if (camera->pitch > 89.0f)
		camera->pitch = 89.0f;
	if (camera->pitch < -89.0f)
		camera->pitch = -89.0f;

	Malachite::Vector3f direction;
	direction.x = cos(Malachite::degreesToRadians(camera->yaw)) * cos(Malachite::degreesToRadians(camera->pitch));
	direction.y = sin(Malachite::degreesToRadians(camera->pitch));
	direction.z = sin(Malachite::degreesToRadians(camera->yaw)) * cos(Malachite::degreesToRadians(camera->pitch));

	camera->front = direction.normalize();
	camera->updateCameraVectors();
}