#include "TestLevel.h"
#include "Core/Game Flow/Application.h"

using namespace Gem;

/*
 * Ordered TODO list:
 * TODO Rendering
 * TODO multiple usage of the same level, and other things with switching levels
 * TODO Debug Rendering
 * TODO Physics
 */

int main() {
	constexpr Application app{};

	app.Load(CreatePtr<TestLevel>());
}