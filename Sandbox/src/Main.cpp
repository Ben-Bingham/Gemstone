#include "TestLevel.h"
#include "Core/Game Flow/Application.h"

using namespace Gem;

/*
 * Ordered TODO list:
 * TODO implement event system for keyboard and mouse inputs, than remove the reference to APP that is passed down to every system.
 * TODO also need to think of way to tell the window to close, resize, change title ect. from system classes
 *
 * TODO UI
 * TODO Rendering
 * TODO Debug Rendering
 * TODO Physics
 */

int main() {
	Application app{};

	app.Load(CreatePtr<TestLevel>(app));
}