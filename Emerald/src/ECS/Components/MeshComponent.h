#pragma once
#include "Pointer.h"

#include "ECS/Component.h"

#include "Geometry/Mesh.h"

namespace Emerald {
	class MeshComponent : public Component {
	public:
		template<typename ... Args>
		MeshComponent(Args&& ... args)
			: m_Mesh(Celestite::createPtr<Ruby::Mesh>(std::forward<Args>(args)...)) {

		}

		MeshComponent(Celestite::Ptr<Ruby::Mesh> mesh);

	private:
		Celestite::Ptr<Ruby::Mesh> m_Mesh;
	};
}