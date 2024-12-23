#pragma once
#include "ColliderType.h"


namespace Gem {
	class BaseCollider {
	public:
		BaseCollider() = default;
		virtual ~BaseCollider() = default;

		BaseCollider(const BaseCollider& other) = default;
		BaseCollider(BaseCollider&& other) noexcept = default;
		BaseCollider& operator=(const BaseCollider& other) = default;
		BaseCollider& operator=(BaseCollider&& other) noexcept = default;

		ColliderType Type();

	protected:
		ColliderType m_Type;
	};
}