#pragma once
#include "Entity Component System/System.h"

namespace Gem {
	class Transform;
	class Material;

	class UiSystem : public System{
	public:
		UiSystem() = default;

		void Step(EntityManager& entityManager, float dt) override;

	private:
		void MaterialUi(Material& material, size_t entityId) const;
		void TransformUi(Transform& transform, size_t entityId) const;
	};
}