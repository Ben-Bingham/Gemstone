#include "pch.h"
#include "UISystem.h"

namespace Gem {
	void UISystem::Step(EntityComponentSystem& ecs) {
		UI();
	}

	void UISystem::StartUp(EntityComponentSystem& ecs) { }
	void UISystem::PreStep(EntityComponentSystem& ecs) { }
	void UISystem::EndStep(EntityComponentSystem& ecs) { }
	void UISystem::ShutDown(EntityComponentSystem& ecs) { }
}