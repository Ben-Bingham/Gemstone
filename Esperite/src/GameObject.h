#pragma once
#include <vector>

#include "Component.h"
#include "Pointer.h"

namespace Esperite {
	class GameObject {
	public:
		GameObject() = default;

		void addComponent(const Celestite::Ptr<Component>& component);

	private:
		std::vector<Celestite::Ptr<Component>> m_Components;
	};
}