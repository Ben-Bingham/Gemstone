#include "pch.h"
#include "System.h"
#include "EntityComponentSystem.h"

namespace Gem {
	void System::StartUp(EntityComponentSystem& ecs) {}
	void System::PreStep(EntityComponentSystem& ecs) {}
	void System::Step(EntityComponentSystem& ecs) {}
	void System::EndStep(EntityComponentSystem& ecs) {}
	void System::ShutDown(EntityComponentSystem& ecs) {}

	void System::UIRender() {}
}