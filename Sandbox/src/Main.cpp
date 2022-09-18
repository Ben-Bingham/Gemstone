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

int main() {
	Ruby::Window window{ };

	Ruby::Renderer renderer{};

	std::vector<float> verticies{
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // top left
	};

	std::vector<unsigned int> indices{
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

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

	Ruby::RenderableObject rectangle{ verticies, indices, renderer.normalShader.getAttributes() };

	Ruby::RenderableObject cube{ cubeVerticies, cubeIndices, renderer.solidShader.getAttributes() };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/};

	Malachite::Matrix4f projection = Malachite::perspective(90.0f, (640.0f / 480.0f), 0.01f, 100.0f);
	Malachite::Matrix4f model = Malachite::Matrix4f{ 1.0f };

	Ruby::Camera camera{ };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, -3.0f };

	while (window.isOpen()) {
		window.pollEvents();

		{ // Rendering
			renderer.prep();

			/*renderer.normalShader.use();
			renderer.render(rectangle);*/

			renderer.solidShader.use();
			renderer.solidShader.setMatrix4f("model", model);
			renderer.solidShader.setMatrix4f("view", camera.getViewMatrix());
			renderer.solidShader.setMatrix4f("projection", projection);
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

	rectangle.dispose();
	cube.dispose();
}