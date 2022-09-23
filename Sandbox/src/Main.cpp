#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Phong/PhongCube.h"
#include "Renderable Objects/Solid/SolidCube.h"

Ruby::Camera camera{ };
struct FPSController {
	bool firstMouse = true;
	int lastX = 0;
	int lastY = 0;
	float mouseSensitivity = 0.1f;
	Malachite::Degree yaw = -90.0f;
	Malachite::Degree pitch;
}; 
FPSController fpsController;

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

int main() {
	Ruby::Window window{ };
	Ruby::Mouse* mouse = &window.ioManger.mouse;
	mouse->addMousePositionCallback(mousePositionCallback, (void*)&fpsController);

	Ruby::Keyboard* keyboard = &window.ioManger.keyboard;
	window.disableCursor();

	Ruby::Renderer renderer{};

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 3.0f };
	Malachite::Matrix4f projection = Malachite::perspective(45.0f, (640.0f / 480.0f), 0.01f, 100.0f);
	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	Ruby::DirectionalLight directionalLight{ };

	// Cube setup
	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::PhongMaterial cubeMaterial{ containerImage, containerSpecularImage };
	Ruby::PhongCube cube{ cubeMaterial };

	// LightCube setup
	Ruby::SolidMaterial lightMaterial{ Malachite::Vector3f(1.0f) };

	Ruby::SolidCube lightCube{ lightMaterial };
	lightCube.model.scale(0.2f);
	lightCube.model.translate(pointLight.position);

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("projection", projection); // Renderer specific
	Ruby::ShaderProgram::upload("pointLights", std::vector<Ruby::PointLight>{ pointLight }); // Shader specific
	Ruby::ShaderProgram::upload("directionalLights", std::vector<Ruby::DirectionalLight>{ directionalLight });  // Shader specific

	renderer.shaders.solidShader.use();
	Ruby::ShaderProgram::upload("projection", projection); // Renderer specific

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODo

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

		{ // Rendering
			renderer.prep();

			//	{ // Lighting

			//		renderer.prepLightingPass();

			//		renderer.drawLightingPass(cube);

			//		renderer.finishLightingPass();
			//	}

			{ // Normal Rendering
				renderer.normalRenderingPrep();

				// Cube
				renderer.shaders.phongShader.use();

				cube.model = Malachite::Matrix4f{ 1.0f };
				cube.model.rotate(Malachite::degreesToRadians(90.0f), Malachite::Vector3f((float)sin(glfwGetTime()), 1.0f, 0.0f));

				Ruby::ShaderProgram::upload("view", camera.getViewMatrix()); // Renderer specific
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				renderer.normalRender(cube);

				renderer.normalRenderingEnd();
			}

			{ // Solid Rendering
				renderer.solidRenderingPrep();

				renderer.shaders.solidShader.use();
				Ruby::ShaderProgram::upload("view", camera.getViewMatrix()); // Renderer specific

				renderer.solidRender(lightCube);

				renderer.solidRenderingEnd();
			}

			renderer.end();
		}

		window.swapBuffers();
	}
}