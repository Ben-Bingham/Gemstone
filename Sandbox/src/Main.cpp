#include <iostream>

#include "Window.h"
#include "Log.h"

int main() {
	Ruby::Window window{ };

	Ruby::CubeRenderable cube{/*position, width, height, depth*/};

	Ruby::Renderer renderer{/*maybe window?*/};

	while (window.isOpen()) {
		window.pollEvents();

		{ // Rendering
			renderer.prep();

			{ // Lighting

				renderer.prepLightingPass();

				renderer.drawLightingPass(cube);

				renderer.finishLightingPass();
			}
			
			{ // Normal Rendering
				renderer.prepNormalPass();

				renderer.drawNormalPass(cube);

				renderer.finishNormalPass();
			}

			renderer.finish();
		}

		window.swapBuffers();
	}
}