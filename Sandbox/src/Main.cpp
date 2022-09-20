#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"
#include "Renderable Objects/RenderableObject.h"

#include "Vector.h"

#include "Matrix/MatrixTransformations.h"

#include "Camera.h"

#include "Angles.h"

#include "Texture.h"

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

	Ruby::RenderableObject cube{ cubeVerticies, cubeIndices, renderer.solidShader.getAttributes() };

	Ruby::Texture containerTexture{ Ruby::Image{ "assets\\container2.png" } };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/};

	Malachite::Matrix4f projection = Malachite::perspective(45.0f, (640.0f / 480.0f), 0.01f, 100.0f);
	Malachite::Matrix4f model = Malachite::Matrix4f{ 1.0f };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 3.0f };

	while (window.isOpen()) {
		window.pollEvents();
		float velocity = 0.1f;

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

			renderer.testShader.use();
			renderer.testShader.setMatrix4f("model", model);
			renderer.testShader.setMatrix4f("view", camera.getViewMatrix());
			renderer.testShader.setMatrix4f("projection", projection);

			containerTexture.activateUnit(0);
			containerTexture.bind();
			renderer.testShader.setInt("ambient", 0);

			renderer.render(cube);

		//	{ // Lighting

		//		renderer.prepLightingPass();

		//		renderer.drawLightingPass(cube);

		//		renderer.finishLightingPass();
		//	}
		//	
		//	{ // Normal Rendering
		//		renderer.prepNormalPass();

		//		renderer.drawNormalPass(cube);

		//		renderer.finishNormalPass();
		//	}

			renderer.finish();
		}

		window.swapBuffers();
	}

	cube.dispose();
}