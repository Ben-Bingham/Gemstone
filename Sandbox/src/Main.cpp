#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"
#include "Renderable Objects/RenderableObject.h"

#include "Vector.h"

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

	Ruby::FragmentShader fragmentShader{ TextFile{"..\\Ruby\\assets\\shaders\\Default.frag"} };
	Ruby::VertexShader vertexShader{ TextFile{ "..\\Ruby\\assets\\shaders\\Default.vert" } };
	Ruby::ShaderProgram shaderProgram = Ruby::ShaderProgram{ vertexShader, fragmentShader, std::vector<Ruby::Attribute>{ 3, 3 } };

	Ruby::RenderableObject rectangle{ verticies, indices, shaderProgram.getAttributes() };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/};

	while (window.isOpen()) {
		window.pollEvents();

		{ // Rendering
			renderer.prep();

			shaderProgram.use();
			renderer.render(rectangle);

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
}