#include <iostream>
#include "Window.h"
#include "Log.h"

int main() {
	Ruby::Window window{ };

	while (true) {
		window.pollEvents();

		window.swapBuffers();
	}
}