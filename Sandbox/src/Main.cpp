#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"
#include "Renderable Objects/RenderableObject.h"
#include "Renderable Objects/Phong/PhongRenderable.h"
#include "Vector.h"
#include "Matrix/MatrixTransformations.h"
#include "Camera.h"
#include "Angles.h"
#include "Texture.h"
#include "Lights.h"
#include "Materials.h"
#include "Renderable Objects/Phong/Cube.h"

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

	std::vector<float> cubeVerticies{
		-0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
							   
		 0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
							  
		-0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0, 0.0f, 0.0,
		-0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0, 0.0f, 1.0,
		-0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0, 1.0f, 0.0,
		-0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0, 1.0f, 1.0,
							  
		-0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
							   
		 0.5f, -0.5f, -0.5f,   0.0f,  0.0f,  -1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,   0.0f,  0.0f,  -1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f,  0.0f,  -1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,   0.0f,  0.0f,  -1.0f, 1.0f, 1.0f,
							   
		-0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f, 1.0f, 1.0f
	};

	std::vector<unsigned int> cubeIndices{
		0,  1,  2,
		1,  3,  2,
		4,  5,  6,
		5,  7,  6,
		8,  9, 10,
		9, 11, 10,
		12, 13, 14,
		13, 15, 14,
		16, 17, 18,
		17, 19, 18,
		20, 21, 22,
		21, 23, 22,
	};

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 3.0f };
	Malachite::Matrix4f projection = Malachite::perspective(45.0f, (640.0f / 480.0f), 0.01f, 100.0f);
	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	Ruby::DirectionalLight directionalLight{ };

	// Cube setup
	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::PhongMaterial cubeMaterial{ containerImage, containerSpecularImage };
	Ruby::Phong::Cube cube{ cubeMaterial };

	// LightCube setup
	Ruby::RenderableObject lightCube{ cubeVerticies, cubeIndices, renderer.solidShader.getAttributes() };

	Malachite::Matrix4f lightModel = Malachite::Matrix4f{ 1.0f };
	lightModel.scale(0.2f);
	lightModel.translate(pointLight.position);

	// Shader setup
	renderer.phongShader.use();
	Ruby::ShaderProgram::upload("projection", projection);
	Ruby::ShaderProgram::upload("pointLights", std::vector<Ruby::PointLight>{ pointLight });
	Ruby::ShaderProgram::upload("directionalLights", std::vector<Ruby::DirectionalLight>{ directionalLight });

	renderer.solidShader.use();
	Ruby::ShaderProgram::upload("projection", projection);

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
				renderer.phongShader.use();

				cube.model = Malachite::Matrix4f{ 1.0f };
				cube.model.rotate(Malachite::degreesToRadians(90.0f), Malachite::Vector3f((float)sin(glfwGetTime()), 1.0f, 0.0f));

				Ruby::ShaderProgram::upload("view", camera.getViewMatrix());
				Ruby::ShaderProgram::upload("cameraPosition", camera.position);

				renderer.normalRender(cube);

				renderer.normalRenderingEnd();
			}

			{ // Non default rendering
				// Light
				renderer.solidShader.use();
				Ruby::ShaderProgram::upload("view", camera.getViewMatrix());
				Ruby::ShaderProgram::upload("model", lightModel);
				Ruby::ShaderProgram::upload("objectColour", Malachite::Vector4f(1.0f, 1.0f, 1.0f, 1.0f));

				renderer.render(lightCube);
			}

			renderer.end();
		}

		window.swapBuffers();
	}
}