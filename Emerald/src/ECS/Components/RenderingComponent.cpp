#include "RenderingComponent.h"

namespace Emerald {
	RenderingComponent::RenderingComponent(
		Celestite::Ptr<TransformComponent> transform,
		Celestite::Ptr<MeshComponent> mesh,
		Celestite::Ptr<MaterialComponent> material
	) : m_Transform(std::move(transform)), m_Mesh(std::move(mesh)), m_Material(std::move(material))
	{
	}
}