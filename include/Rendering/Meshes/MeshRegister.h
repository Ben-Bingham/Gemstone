#pragma once
#include <map>

#include "MeshHash.h"
#include "RawMesh.h"
#include "Utility/Pointer.h"

namespace Gem {
	struct MeshObject;

	class MeshRegister {
	public:
		MeshRegister() = default;

		[[nodiscard]] bool HasMesh(MeshHash hash);

		MeshHash AddMesh(const RawMesh& rawMesh);
		Ptr<MeshObject> GetMesh(MeshHash hash);

	private:
		std::map<MeshHash, Ptr<MeshObject>> m_Meshes;
	};
}