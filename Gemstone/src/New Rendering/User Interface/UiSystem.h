#pragma once
#include "Entity Component System/System.h"

namespace Gem {
	class Transform;
	class Material;

	class UiSystem : public System{
	public:
		UiSystem() = default;

		void Step(EntityManager& entityManager) override;

	private:
		void MaterialUi(Material& material) const;
		void TransformUi(Transform& transform) const;
	};
}