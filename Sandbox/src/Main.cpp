#include "TestLevel.h"
#include "Apatite/Application.h"

using namespace Gem;

/*
 * TODO implement event system for keyboard and mouse inputs, than remove the reference to APP that is passed down to every system.
 * TODO also need to think of way to tell the window to close, resize, change title ect. from system classes
 */

int main() {
	Application app{};

	app.Load(Celestite::CreatePtr<TestLevel>(app));
}