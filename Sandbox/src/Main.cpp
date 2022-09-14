#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"

int main() {
	Ruby::Window window{ };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/};

	Ruby::Renderer renderer{/*maybe window?*/};
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	while (window.isOpen()) {
		window.pollEvents();

		{ // Rendering
			//renderer.prep();

			//renderer.render();

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

			//renderer.finish();
		}

		window.swapBuffers();
	}
}