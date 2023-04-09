#pragma once
#include "Entity Component System/System.h"

namespace Gem {
	class UISystem : public System {
	public:
		UISystem() = default;
		UISystem(const UISystem& other) = default;
		UISystem(UISystem&& other) noexcept = default;
		UISystem& operator=(const UISystem& other) = default;
		UISystem& operator=(UISystem&& other) noexcept = default;
		~UISystem() override = default;

		virtual void UI() = 0;
	private:
		void Step(EntityComponentSystem& ecs) final;

		void StartUp(EntityComponentSystem& ecs) final;
		void PreStep(EntityComponentSystem& ecs) final;
		void EndStep(EntityComponentSystem& ecs) final;
		void ShutDown(EntityComponentSystem& ecs) final;
	};
}