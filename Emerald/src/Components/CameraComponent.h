#pragma once

#include "Camera.h"

#include "ECS/Component.h"

namespace Emerald {
	class CameraComponent : public Component {
	public:
		CameraComponent() = default;

		[[nodiscard]] Ruby::Camera& getCamera() { return m_Camera; }

	private:
		Ruby::Camera m_Camera{};
	};
}