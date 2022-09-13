#include <iostream>
#include "Window.h"

int main() {
	Ruby::Window window{ };

	while (true) {
		window.pollEvents();

		window.swapBuffers();
	}
}