#include <iostream>

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Solid/SolidCube.h"
#include "Renderable Objects/Image/ImageQuad.h"
#include "Renderable Objects/Phong/PhongCube.h"
#include "OpenGL objects/Framebuffer.h"
#include "Renderable Objects/Skybox.h"

#include "Units.h"
#include "Gravitation/GravitationalPhysicsObject.h"
#include "Timing.h"

#include "Physicist.h"

#include "Collision/Colliders/BoxCollider.h"

Ruby::Camera camera{ };
struct FPSController {
	bool firstMouse = true;
	int lastX = 0;
	int lastY = 0;
	float mouseSensitivity = 0.1f;
	Malachite::Degree yaw = -90.0f;
	Malachite::Degree pitch;
}; 
FPSController fpsController{ };
bool cursorNormal = false;

void mousePositionCallback(int xpos, int ypos, void* data) {
	FPSController* controller = (FPSController*)data;

	if (controller->firstMouse) {
		controller->lastX = (int)xpos;
		controller->lastY = (int)ypos;
		controller->firstMouse = false;
	}

	float xOffset = (float)(xpos - controller->lastX);
	float yOffset = (float)(controller->lastY - ypos);
	controller->lastX = (int)xpos;
	controller->lastY = (int)ypos;

	xOffset *= controller->mouseSensitivity;
	yOffset *= controller->mouseSensitivity;

	controller->yaw += xOffset;
	controller->pitch += yOffset;

	if (controller->pitch > 89.0f)
		controller->pitch = 89.0f;
	if (controller->pitch < -89.0f)
		controller->pitch = -89.0f;

	Malachite::Vector3f direction;
	direction.x = cos(Malachite::degreesToRadians(controller->yaw)) * cos(Malachite::degreesToRadians(controller->pitch));
	direction.y = sin(Malachite::degreesToRadians(controller->pitch));
	direction.z = sin(Malachite::degreesToRadians(controller->yaw)) * cos(Malachite::degreesToRadians(controller->pitch));

	camera.front = direction.normalize();
	camera.updateCameraVectors();
}

using namespace Pyrite::Literals;

int main() {
	Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f};
	Wavellite::Mouse* mouse = &window.ioManger.mouse;
	Wavellite::Keyboard* keyboard = &window.ioManger.keyboard;

	mouse->addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Wavellite::Time time{ };
	Ruby::Renderer renderer{ };
	Pyrite::Physicist physicist{ time };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };

	Ruby::SolidMaterial staticMat{ Malachite::Vector3f{ 0.0f, 0.0f, 1.0f } };
	Ruby::SolidMaterial defaultMat{ Malachite::Vector3f{ 1.0f, 0.0f, 0.0f } };
	Ruby::SolidMaterial collidedMat{ Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } };

	Ruby::SolidCube staticCube{ defaultMat };
	staticCube.model.scale(3.0f);
	Ruby::SolidCube movingCube{ staticMat };
	Malachite::Vector3f movingCubePos{ 5.0f, 0.0f, 0.0f };

	// Skybox setup
	std::vector<Ruby::Image> skyboxImages {
		Ruby::Image{ "assets\\Skybox\\right.jpg", false },
		Ruby::Image{ "assets\\Skybox\\left.jpg", false },
		Ruby::Image{ "assets\\Skybox\\top.jpg", false },
		Ruby::Image{ "assets\\Skybox\\bottom.jpg", false },
		Ruby::Image{ "assets\\Skybox\\front.jpg", false },
		Ruby::Image{ "assets\\Skybox\\back.jpg", false },
	};

	Ruby::Skybox skybox{ skyboxImages };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO

	// Renderer setup
	renderer.init(window.getProjectionMatrix());

	// Physics
	using namespace Pyrite::Literals;

	Pyrite::BoxCollider staticCollider{ Pyrite::Point3D{ 3.0_m } };
	Pyrite::BoxCollider movingCollider{ Pyrite::Point3D{ 1.0_m }, Pyrite::Point3D{ 5.0_m, 0.0_m, 0.0_m } };
							 
	// Rendering loop
	while (window.isOpen()) {
		window.pollEvents();
		float velocity = 0.05f;
		 
		if (keyboard->KEY_W) {
			camera.position += camera.front * velocity;
		}

		if (keyboard->KEY_A) {
			camera.position -= camera.right * velocity;
		}

		if (keyboard->KEY_S) {
			camera.position -= camera.front * velocity;
		}

		if (keyboard->KEY_D) {
			camera.position += camera.right * velocity;
		}

		if (keyboard->KEY_SPACE) {
			camera.position += Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyboard->KEY_LEFT_SHIFT) {
			camera.position -= Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyboard->KEY_ESCAPE) {
			window.close();
		}

		float spd = 0.05f;

		if (keyboard->KEY_UP) {
			movingCubePos += Malachite::Vector3f{0, 0, -1 * spd};
		}

		if (keyboard->KEY_DOWN) {
			movingCubePos += Malachite::Vector3f{ 0, 0, 1 * spd };
		}

		if (keyboard->KEY_LEFT) {
			movingCubePos += Malachite::Vector3f{ -1 * spd, 0, 0 };
		}

		if (keyboard->KEY_RIGHT) {
			movingCubePos += Malachite::Vector3f{ 1 * spd, 0, 0 };
		}

		if (keyboard->KEY_I) {
			movingCubePos += Malachite::Vector3f{ 0, 1 * spd, 0 };
		}

		if (keyboard->KEY_K) {
			movingCubePos += Malachite::Vector3f{ 0, -1 * spd, 0 };
		}

		if (keyboard->KEY_M) {
			if (cursorNormal) {
				window.disableCursor();
				cursorNormal = false;
			}
			else {
				window.enableCursor();
				cursorNormal = true;
			}
		}

		{ // Physics
			movingCollider.position = movingCubePos;
			movingCube.model = Malachite::Matrix4f{ 1.0f };
			movingCube.model.translate(movingCubePos);

			if (movingCollider.collidesWithBox(&staticCollider)) {
				staticCube.material = collidedMat;
			}
			else {
				staticCube.material = defaultMat;
			}
		}

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Solid Rendering
				renderer.solidRenderingPrep();

				renderer.solidRender(staticCube);
				renderer.solidRender(movingCube);

				renderer.solidRenderingEnd();
			}

			{ // Debug Rendering
				renderer.debugRenderingPrep();

				renderer.debugRenderingEnd();
			}

			{ // Skybox Rendering
				renderer.skyboxRenderingPrep();

				renderer.skyboxRender(skybox);

				renderer.skyboxRenderingEnd();
			}

			{ // ImGui
				renderer.imGuiPrep();

				//ImGui::ShowDemoWindow();
				{
					/*ImGui::Begin("Window");
					ImGui::Text("Mass");
					ImGui::SliderFloat("float", &speed, 0.0f, 1000.0f);
					earthPhysics.mass = Malachite::ee(1.873f, exponent);
					ImGui::End();*/
				}

				renderer.imGuiEnd();
			}

			renderer.end();
		}

		window.swapBuffers();
		time.endFrame();
	}
	renderer.imGuiTerminate();
}