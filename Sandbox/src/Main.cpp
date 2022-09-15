#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"

#include "GLEW.h"
#include "GLFW.h"

#include "Vector.h"

int main() {
	Ruby::GLEW GLEW{ };
	Ruby::GLFW GLFW{ };

	GLFW.start();
	Ruby::Window window{ }; //TODO make this not have to be between the two startups
	GLEW.start();

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/};

	Ruby::Renderer renderer{/*maybe window?*/};

	while (window.isOpen()) {
		window.pollEvents();

		{ // Rendering
			//renderer.prep();

			renderer.render();

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

	GLFW.stop();
}