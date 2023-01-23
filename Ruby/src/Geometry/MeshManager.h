#pragma once
#include "Mesh.h"

namespace Ruby {
	class MeshManager {
	public:
		MeshManager(const MeshManager& other) = delete;
		MeshManager(MeshManager&& other) noexcept = delete;
		MeshManager& operator=(const MeshManager& other) = delete;
		MeshManager& operator=(MeshManager&& other) noexcept = delete;
		static MeshManager& Get();

		Celestite::Ptr<MeshData> NewMesh(Shape shape);
		// Celestite::Ptr<Mesh> NewMesh(std::string& filePath); //TODO custom models

	private:
		MeshManager() = default;

		std::vector<Celestite::Ptr<MeshData>> m_Meshes;
	};
}