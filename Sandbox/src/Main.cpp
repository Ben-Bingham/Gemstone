#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"
#include "RenderableObject.h"

#include "Vector.h"

int main() {
	Ruby::Window window{ };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/};

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
	std::shared_ptr<Ruby::ShaderProgram> shaderProgram = std::make_shared<Ruby::ShaderProgram>(vertexShader, fragmentShader);

	std::vector<Ruby::Attribute> attributes;
	attributes.push_back(3);
	attributes.push_back(3);

	Ruby::RenderableObject renderable{ shaderProgram, verticies, indices, attributes };

	while (window.isOpen()) {
		window.pollEvents();

		{ // Rendering
			renderer.prep();

			renderer.render(renderable);

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

	renderable.dispose();
}