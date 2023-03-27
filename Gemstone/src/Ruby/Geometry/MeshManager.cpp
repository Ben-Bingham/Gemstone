#include "pch.h"
#include "MeshManager.h"

namespace Ruby {
	MeshManager& MeshManager::Get() {
		static MeshManager manager;
		return manager;
	}

	Celestite::Ptr<MeshData> MeshManager::CreateMesh(const Celestite::Ptr<Shape>& shape) {
		for (auto& mesh : m_Meshes) {
			if (Equal(mesh->GetShape(), shape)) { //TODO b broken
				return mesh;
			}
		}

		m_Meshes.push_back(Celestite::CreatePtr<MeshData>(shape));
		return m_Meshes.back();
	}
}