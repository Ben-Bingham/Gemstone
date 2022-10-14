#include <iostream>

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

	camera.front = Malachite::normalize(direction);
	camera.updateCameraVectors();
}

using namespace Pyrite::Literals;

int main() {
	Wavellite::Window window{ 640 * 2, 480 * 2 };
	Wavellite::Mouse* mouse = &window.ioManger.mouse;
	Wavellite::Keyboard* keyboard = &window.ioManger.keyboard;

	mouse->addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Ruby::Renderer renderer{ };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 3.0f };

	std::vector<Ruby::PointLight*> pointLights;

	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	pointLights.push_back(&pointLight);

	std::vector<Ruby::DirectionalLight*> directionalLights;

	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	// Cube setup
	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };

	Ruby::PhongMaterial cubeMaterial{ contianerTexture, containerSpecularTexture };
	Ruby::PhongCube cube{ cubeMaterial };
	Ruby::PhongCube earth{ cubeMaterial };
	earth.model.scale(2.0f);

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

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("pointLights", pointLights); // Shader specific
	Ruby::ShaderProgram::upload("directionalLights", 2, directionalLights);  // Shader specific

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO

	// Renderer setup
	renderer.init(window.getProjectionMatrix());


	// Physics
	using namespace Pyrite::Literals;

	Pyrite::GravitationalPhysicsObject obj1{ 10.0_m, 10.0_kg, Pyrite::Position3D{ 20.0_m, 0.0_m, 0.0_m } };
	Pyrite::GravitationalPhysicsObject earthPhysics{ 50.0_m * 1000000000000.0_m, 50.0_kg * 1000000000000.0_kg };

	Wavellite::Time time{ };

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
			directionalLight.position += Malachite::Vector3f{0, 0, -1 * spd};
		}

		if (keyboard->KEY_DOWN) {
			directionalLight.position += Malachite::Vector3f{ 0, 0, 1 * spd };
		}

		if (keyboard->KEY_LEFT) {
			directionalLight.position += Malachite::Vector3f{ -1 * spd, 0, 0 };
		}

		if (keyboard->KEY_RIGHT) {
			directionalLight.position += Malachite::Vector3f{ 1 * spd, 0, 0 };
		}

		if (keyboard->KEY_I) {
			directionalLight.position += Malachite::Vector3f{ 0, 1 * spd, 0 };
		}

		if (keyboard->KEY_K) {
			directionalLight.position += Malachite::Vector3f{ 0, -1 * spd, 0 };
		}

		{ // Physics
			if (obj1.getPosition().x > 5.0f) {
				obj1.calcPosition(std::vector<Pyrite::GravitationalPhysicsObject*>{ &earthPhysics }, time.deltaTime / 1000.0f); // Converting from miliseconds to seconds
			}
			earthPhysics.calcPosition(std::vector<Pyrite::GravitationalPhysicsObject*>{ &obj1 }, time.deltaTime / 1000.0f);

			LOG(obj1.getPosition().toString());

			earth.model = Malachite::Matrix4f{ 1.0f };
			earth.model.scale(2.0f);
			earth.model.translate(earthPhysics.getPosition());
			cube.model = Malachite::Matrix4f{ 1.0f };
			cube.model.translate(obj1.getPosition());
		}

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Normal Rendering
				renderer.phongRenderingPrep();

				// Cube
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				renderer.phongRender(cube);
				renderer.phongRender(earth);

				renderer.phongRenderingEnd();
			}

			{ // Skybox Rendering
				renderer.skyboxRenderingPrep();

				renderer.skyboxRender(skybox);

				renderer.skyboxRenderingEnd();
			}

			renderer.end();
		}

		window.swapBuffers();
		time.endFrame();
	}
}