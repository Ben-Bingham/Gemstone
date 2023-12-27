#pragma once
#include <functional>

namespace Gem {
	class EntityComponentSystem;

	using System = std::function<void(EntityComponentSystem& ecs)>;
}