#pragma once
#include <functional>
#include <vector>

#include "Utility/Pointer.h"
#include "BaseCollider.h"

#include "Math/Vector.h"

namespace Gem {
	using CollisionCallback  = std::function<void()>;

	struct Collider {
		Collider(ColliderType type = ColliderType::FIXED_BOX);

		void Callbacks();
		void AddCallback(const CollisionCallback& callback);

		Ptr<BaseCollider> collider;

	protected:
		std::vector<CollisionCallback> m_Callbacks;
	};
}