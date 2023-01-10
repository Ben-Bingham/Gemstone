#include "MeshComponent.h"

namespace Emerald {
	MeshComponent::MeshComponent(Celestite::Ptr<Ruby::Mesh> mesh)
		: m_Mesh(std::move(mesh)) {

	}
}