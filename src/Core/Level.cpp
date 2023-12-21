#include "Core/Level.h"
#include "Core/Engine.h"

namespace Gem {
	Level::Level(Engine& engine)
		: engine(engine), ecs(engine) { }
}