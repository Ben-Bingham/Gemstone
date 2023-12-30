#pragma once
#include <map>

#include "MeshHash.h"
#include "RawMesh.h"
#include "Utility/Pointer.h"

namespace Gem {
	struct MeshObject;

	class MeshRegister {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		MeshRegister() = default;
		~MeshRegister() = default;

		static inline bool m_Started{ false };

	public:
		static MeshRegister& Get();

		[[nodiscard]] bool HasMesh(MeshHash hash);

		MeshHash AddMesh(const RawMesh& rawMesh);
		Ptr<MeshObject> GetMesh(MeshHash hash);

	private:
		std::map<MeshHash, Ptr<MeshObject>> m_Meshes;
	};
}