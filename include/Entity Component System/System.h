#pragma once
#include <functional>

#include "Core/Engine.h"

namespace Gem {
	class EntityComponentSystem;

	using System = std::function<void(Engine& engine, EntityComponentSystem& ecs)>;
}