#include "Rendering/Meshes/MeshRegister.h"
#include "Rendering/Meshes/MeshData.h"
#include "Rendering/Meshes/MeshObject.h"
#include "Utility/Log.h"

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
			m_Meshes[hash] = CreatePtr<MeshObject>(rawMesh, hash);
		}

		return hash;
	}

	Ptr<MeshObject> MeshRegister::GetMesh(MeshHash hash) {
#ifdef GEM_DEBUG
		if (!HasMesh(hash)) {
			LOG("Attempting to retreive mesh, that has not been registerd.", LogLevel::ERROR);
		}
#endif

		return m_Meshes[hash];
	}
}