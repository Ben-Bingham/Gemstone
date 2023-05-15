#include "TestLevel.h"
#include "Core/Game Flow/Application.h"

using namespace Gem;

/*
 * Ordered TODO list:
 * TODO Rendering
 * TODO Get ImGui to use Gem's openGl state functions
 * TODO Settings class (maybe split into rendering settings and other settings?)
 * TODO multiple usage of the same level, and other things with switching levels
 * TODO Debug Rendering
 * TODO Physics
 */

int main() {
	constexpr Application app{};

	app.Load(CreatePtr<TestLevel>());
}