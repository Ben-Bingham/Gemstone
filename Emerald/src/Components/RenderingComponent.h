#pragma once
#include "MaterialComponent.h"
#include "MeshComponent.h"

#include "ECS/Component.h"
#include "Pointer.h"
#include "Transform.h"

namespace Emerald {
	class RenderingComponent : public Component {
	public:
		RenderingComponent(Celestite::Ptr<TransformComponent> transform, Celestite::Ptr<MeshComponent> mesh, Celestite::Ptr<MaterialComponent> material);

		Celestite::Ptr<TransformComponent>& transform() { return m_Transform; }
		Celestite::Ptr<MeshComponent>& mesh() { return m_Mesh; }
		Celestite::Ptr<MaterialComponent>& material() { return m_Material; }

	private:
		Celestite::Ptr<TransformComponent> m_Transform;
		Celestite::Ptr<MeshComponent> m_Mesh;
		Celestite::Ptr<MaterialComponent> m_Material;
	};
}