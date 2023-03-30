#include "pch.h"
#include "MeshManager.h"

namespace Gem {
	MeshManager& MeshManager::Get() {
		static MeshManager manager;
		return manager;
	}

	Ptr<MeshData> MeshManager::CreateMesh(const Ptr<Shape>& shape) {
		for (auto& mesh : m_Meshes) {
			if (Equal(mesh->GetShape(), shape)) { //TODO b broken
				return mesh;
			}
		}

		m_Meshes.push_back(CreatePtr<MeshData>(shape));
		return m_Meshes.back();
	}
}