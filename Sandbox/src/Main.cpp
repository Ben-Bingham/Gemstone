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

	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	Ruby::DirectionalLight directionalLight{ };

	// Cube setup
	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::PhongMaterial cubeMaterial{ containerImage, containerSpecularImage };
	Ruby::PhongCube cube{ cubeMaterial };

	Ruby::PhongCube floor{ cubeMaterial };
	floor.model.translate(Malachite::Vector3f{ 0.0f, -2.0f, 0.0f });
	floor.model.scale(Malachite::Vector3f{ 10.0f, 1.0f, 10.0f });

	// LightCube setup
	Ruby::SolidMaterial lightMaterial{ Malachite::Vector3f(1.0f) };

	Ruby::SolidCube lightCube{ lightMaterial };
	lightCube.model.scale(0.2f);
	lightCube.model.translate(pointLight.position);

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("pointLights", std::vector<Ruby::PointLight>{ }); // Shader specific
	Ruby::ShaderProgram::upload("directionalLights", std::vector<Ruby::DirectionalLight>{ directionalLight });  // Shader specific

	renderer.shaders.solidShader.use();

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODo

	// Framebuffer setup
	const unsigned int shadowWidth = 1024, shadowHeight = 1024;
	Ruby::Texture framebufferDepthAttachment{ GL_DEPTH_COMPONENT, shadowWidth, shadowHeight };

	Ruby::Framebuffer framebuffer{ };

	framebuffer.bind();
	framebuffer.attachTexture(framebufferDepthAttachment, GL_DEPTH_ATTACHMENT);
	framebuffer.setDrawBuffer(GL_NONE);
	framebuffer.setReadBuffer(GL_NONE);
	if (!framebuffer.checkStatus()) {
		LOG("Framebuffer failed to complete", Lazuli::LogLevel::ERROR);
	}

	framebuffer.unbind();

	Malachite::Matrix4f lightProjection = Malachite::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 10.0f);
	Malachite::Matrix4f lightView = Malachite::lookAt(Malachite::Vector3f{ 1.0f, 5.0f, 0.0f }, Malachite::Vector3f{ 0.0f, 0.0f, 0.0f }, Malachite::Vector3f{ 0.0f, 1.0f, 0.0f });

	Malachite::Matrix4f lightSpaceMatrix = lightProjection * lightView;

	Ruby::ImageMaterial imgMat{ framebufferDepthAttachment };
	Ruby::ImageQuad imageQuad{ imgMat };
	imageQuad.model.translate(Malachite::Vector3f{ 0.0f, 3.0f, 0.0f });

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

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Lighting
				renderer.shaders.directionalDepthShader.use();
				Ruby::ShaderProgram::upload("lightSpaceMatrix", lightSpaceMatrix);
				
				glViewport(0, 0, shadowWidth, shadowHeight);
				framebuffer.bind();
				glClear(GL_DEPTH_BUFFER_BIT);

				renderer.render(cube);
				renderer.render(floor);

				framebuffer.unbind();

				glViewport(0, 0, window.getWidth(), window.getHeight());

				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				/*renderer.prepLightingPass();

				renderer.drawLightingPass(cube);

				renderer.finishLightingPass();*/
			}

			{ // Normal Rendering
				renderer.normalRenderingPrep();

				// Cube
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				cube.model = Malachite::Matrix4f{ 1.0f };
				cube.model.rotate(Malachite::degreesToRadians(90.0f), Malachite::Vector3f((float)sin(glfwGetTime()), 1.0f, 0.0f));

				renderer.normalRender(cube);
				renderer.normalRender(floor);

				renderer.normalRenderingEnd();
			}

			{ // Solid Rendering
				renderer.solidRenderingPrep();

				//renderer.solidRender(lightCube);

				renderer.solidRenderingEnd();
			}

			{ // Non default rendering
				renderer.shaders.imageShader.use();
				renderer.render(imageQuad);
			}

			renderer.end();
		}

		window.swapBuffers();
	}
}