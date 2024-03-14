#include "Physics/Collisions/Colliders/Collider.h"
#include "Physics/Collisions/Colliders/FixedBoxCollider.h"

#include "Utility/Log.h"

namespace Gem {
	Collider::Collider(ColliderType type) {
		switch (type) {
		default:
			LOG("Unkonwn collider type", LogLevel::ERROR);
		case ColliderType::FIXED_BOX:
			collider = CreatePtr<FixedBoxCollider>();
			break;
		}
	}

	void Collider::Callbacks() {
		for (auto callback : m_Callbacks) {
			callback();
		}
	}

	void Collider::AddCallback(const CollisionCallback& callback) {
		m_Callbacks.push_back(callback);
	}
}