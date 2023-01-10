#pragma once
#include "ECS/Component.h"

#include "Utility/Transform.h"

namespace Emerald {
	class TransformComponent : public Component {
	public:
		TransformComponent() = default;

		Malachite::Transform& transform() { return m_Transform; }

	private:
		Malachite::Transform m_Transform;
	};
}