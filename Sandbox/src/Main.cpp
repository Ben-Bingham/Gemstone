#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Phong/PhongCube.h"
#include "Renderable Objects/Solid/SolidCube.h"
#include "Renderable Objects/Image/ImageQuad.h"

#include "OpenGL objects/Framebuffer.h"

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

int main() {
	Ruby::Window window{ };
	Ruby::Mouse* mouse = &window.ioManger.mouse;
	Ruby::Keyboard* keyboard = &window.ioManger.keyboard;

	mouse->addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Ruby::Renderer renderer{ };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 3.0f };

	//Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	std::vector<Ruby::DirectionalLight*> directionalLights;

	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	Ruby::DirectionalLight directionalLight1{ Malachite::Vector3f{ -3.0f, -3.0f, -0.5f } };
	directionalLights.push_back(&directionalLight1);

	// Cube setup
	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };

	Ruby::PhongMaterial cubeMaterial{ contianerTexture, containerSpecularTexture };
	Ruby::PhongCube cube{ cubeMaterial };

	Ruby::PhongCube cube1{ cubeMaterial };
	cube1.model.translate(Malachite::Vector3f{ -2.0f, -1.0f, -0.5f });

	Ruby::PhongCube floor{ cubeMaterial };
	floor.model.translate(Malachite::Vector3f{ 0.0f, -2.0f, 0.0f });
	floor.model.scale(Malachite::Vector3f{ 10.0f, 1.0f, 10.0f });

	// LightCube setup
	Ruby::SolidMaterial lightMaterial{ Malachite::Vector3f(1.0f) };

	Ruby::SolidCube lightCube{ lightMaterial };
	lightCube.model.scale(0.2f);

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("pointLights", std::vector<Ruby::PointLight*>{ }); // Shader specific
	Ruby::ShaderProgram::upload("directionalLights", 2, directionalLights);  // Shader specific

	renderer.shaders.solidShader.use();

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODo

	// Renderer setup
	renderer.init(window.getProjectionMatrix());

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

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Lighting
				renderer.directionalLightRenderingPrep();
				
				for (Ruby::DirectionalLight* dirLight : directionalLights) {
					dirLight->framebuffer.bind();
					dirLight->calculateSpaceMatrix();
					Ruby::ShaderProgram::upload("lightSpaceMatrix", dirLight->spaceMatrix); // Light Specific

					glViewport(0, 0, Ruby::DirectionalLight::SHADOW_WIDTH, Ruby::DirectionalLight::SHADOW_HEIGHT);
					glClear(GL_DEPTH_BUFFER_BIT);

					renderer.directionalLightRender(cube);
					renderer.directionalLightRender(cube1);
					renderer.directionalLightRender(floor);

					Ruby::Framebuffer::unbind();
				}

				renderer.directionalLightRenderingEnd(window.getWidth(), window.getHeight());
			}

			{ // Normal Rendering
				renderer.normalRenderingPrep();

				// Cube
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				unsigned int i{ 0 };
				for (Ruby::DirectionalLight* dirLight : directionalLights) {
					Ruby::ShaderProgram::upload("directionalLights[" + std::to_string(i) + "].lightSpaceMatrix", dirLight->spaceMatrix); // Light Specific

					i++;
				}

				cube.model = Malachite::Matrix4f{ 1.0f };
				cube.model.rotate(Malachite::degreesToRadians(90.0f), Malachite::Vector3f((float)sin(glfwGetTime()), 1.0f, 0.0f));

				renderer.normalRender(cube);
				renderer.normalRender(cube1);
				renderer.normalRender(floor);

				renderer.normalRenderingEnd();
			}

			{ // Solid Rendering
				renderer.solidRenderingPrep();

				lightCube.model = Malachite::Matrix4f{ 1.0f };
				lightCube.model.translate(directionalLight.position);
				lightCube.model.scale(0.2f);

				renderer.solidRender(lightCube);

				renderer.solidRenderingEnd();
			}

			renderer.end();
		}

		window.swapBuffers();
	}
}