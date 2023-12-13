#pragma once
#include "ECS/Component.h"

#include "Materials/Material.h"

namespace Emerald {
	class MaterialComponent : public Component {
	public:
		template<typename ... Args>
		MaterialComponent(Args&& ... args)
			: m_Material(Celestite::createPtr<Ruby::Material>(std::forward<Args>(args)...)) {
			
		}

		MaterialComponent(Celestite::Ptr<Ruby::Material> material);

	private:
		Celestite::Ptr<Ruby::Material> m_Material;
	};
}