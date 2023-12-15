#include "Rendering/Meshes/MeshRegister.h"

namespace Gem {
	bool MeshRegister::HasMesh(const MeshHash hash) {
		if (m_Meshes.contains(hash)) {
			if (m_Meshes[hash] != nullptr) {
				return true;
			}
			m_Meshes.erase(hash);
		}

		return false;
	}

	MeshHash MeshRegister::AddMesh(const RawMesh& rawMesh) {
		MeshHash hash = HashMesh(VertexToFloat(rawMesh.vertices), rawMesh.indices);

		if (!HasMesh(hash)) {
			m_Meshes[hash] = CreatePtr<MeshObject>(MeshData{ rawMesh }, hash);
		}

		return hash;
	}

	Ptr<MeshObject> MeshRegister::GetMesh(const MeshHash hash) {
#ifdef GEM_DEBUG
		if (!HasMesh(hash)) {
			LOG("Attempting to retreive mesh, that has not been registerd.", LogLevel::ERROR);
		}
#endif

		return m_Meshes[hash];
	}
}