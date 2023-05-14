#pragma once
#include "Core/Event System/EventHandler.h"
#include "Entity Component System/System.h"
#include "Input/KeyboardEvents.h"

namespace Gem {
	class PerspectiveCameraSystem : public System, EventHandler<KeyboardEvents::KeyDown> {
	public:
		enum class MovementDirections {
			FORWARD,
			LEFT,
			RIGHT,
			BACKWARD
		};

		PerspectiveCameraSystem() = default;
		PerspectiveCameraSystem(const PerspectiveCameraSystem& other) = default;
		PerspectiveCameraSystem(PerspectiveCameraSystem&& other) noexcept = default;
		PerspectiveCameraSystem& operator=(const PerspectiveCameraSystem& other) = default;
		PerspectiveCameraSystem& operator=(PerspectiveCameraSystem&& other) noexcept = default;
		~PerspectiveCameraSystem() override = default;

		void Step(EntityManager& entityManager, float dt) override;
		void HandleEvent(const KeyboardEvents::KeyDown& event) override;

	private:
		std::vector<MovementDirections> m_Movements;
	};
}