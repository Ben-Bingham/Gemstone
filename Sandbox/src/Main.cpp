#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"
#include "Renderable Objects/Renderable.h"
#include "Renderable Objects/Phong/PhongRenderable.h"
#include "Vector.h"
#include "Matrix/MatrixTransformations.h"
#include "Camera.h"
#include "Angles.h"
#include "Texture.h"
#include "Lights.h"
#include "Materials.h"
#include "Renderable Objects/Phong/PhongCube.h"
#include "Renderable Objects/Solid/SolidRenderable.h"
#include "Renderable Objects/Solid/SolidCube.h"

Ruby::Camera camera{ };
bool firstMouse = true;
int lastX = 0;
int lastY = 0;
float mouseSensitivity = 0.1f;
Malachite::Degree yaw = -90.0f;
Malachite::Degree pitch;

bool keyW;
bool keyA;
bool keyS;
bool keyD;
bool keySpace;
bool keyShift;
bool keyEscape;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) {
			keyW = true;
		}
		else if (action == GLFW_RELEASE) {
			keyW = false;
		}
	}

	if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
			keyA = true;
		}
		else if (action == GLFW_RELEASE) {
			keyA = false;
		}
	}

	if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) {
			keyS = true;
		}
		else if (action == GLFW_RELEASE) {
			keyS = false;
		}
	}

	if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) {
			keyD = true;
		}
		else if (action == GLFW_RELEASE) {
			keyD = false;
		}
	}
	
	if (key == GLFW_KEY_SPACE) {
		if (action == GLFW_PRESS) {
			keySpace = true;
		}
		else if (action == GLFW_RELEASE) {
			keySpace = false;
		}
	}

	if (key == GLFW_KEY_LEFT_SHIFT) {
		if (action == GLFW_PRESS) {
			keyShift = true;
		}
		else if (action == GLFW_RELEASE) {
			keyShift = false;
		}
	}

	if (key == GLFW_KEY_ESCAPE) {
		if (action == GLFW_PRESS) {
			keyEscape = true;
		}
		else if (action == GLFW_RELEASE) {
			keyEscape = false;
		}
	}
}

void mousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = (int)xpos;
		lastY = (int)ypos;
		firstMouse = false;
	}

	float xOffset = (float)(xpos - lastX);
	float yOffset = (float)(lastY - ypos);
	lastX = (int)xpos;
	lastY = (int)ypos;

	xOffset *= mouseSensitivity;
	yOffset *= mouseSensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	Malachite::Vector3f direction;
	direction.x = cos(Malachite::degreesToRadians(yaw)) * cos(Malachite::degreesToRadians(pitch));
	direction.y = sin(Malachite::degreesToRadians(pitch));
	direction.z = sin(Malachite::degreesToRadians(yaw)) * cos(Malachite::degreesToRadians(pitch));

	camera.front = Malachite::normalize(direction);
	camera.updateCameraVectors();
}

int main() {
	Ruby::Window window{ };
	window.setKeyCallback(keyCallback);
	window.setMousePositionCallback(mousePositionCallback);
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
		 
		if (keyW) {
			camera.position += camera.front * velocity;
		}

		if (keyA) {
			camera.position -= camera.right * velocity;
		}

		if (keyS) {
			camera.position -= camera.front * velocity;
		}

		if (keyD) {
			camera.position += camera.right * velocity;
		}

		if (keySpace) {
			camera.position += Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyShift) {
			camera.position -= Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyEscape) {
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