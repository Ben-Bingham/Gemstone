#pragma once
#include "Level.h"

namespace Gem {
	class EntityComponentSystem;

	class System {
	public:
		System() = default;
		System(const System& other) = default;
		System(System&& other) noexcept = default;
		System& operator=(const System& other) = default;
		System& operator=(System&& other) noexcept = default;
		virtual ~System() = default;

		virtual void StartUp(EntityComponentSystem& ecs);
		virtual void PreStep(EntityComponentSystem& ecs);
		virtual void Step(EntityComponentSystem& ecs);
		virtual void EndStep(EntityComponentSystem& ecs);
		virtual void ShutDown(EntityComponentSystem& ecs);
	};
}