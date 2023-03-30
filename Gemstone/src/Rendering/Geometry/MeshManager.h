#pragma once
#include "Mesh.h"

namespace Gem {
	class MeshManager { //TODO remove class
	public:
		MeshManager(const MeshManager& other) = delete;
		MeshManager(MeshManager&& other) noexcept = delete;
		MeshManager& operator=(const MeshManager& other) = delete;
		MeshManager& operator=(MeshManager&& other) noexcept = delete;
		static MeshManager& Get();

		Ptr<MeshData> CreateMesh(const Ptr<Shape>& shape);
		// Ptr<Mesh> CreateMesh(std::string& filePath); //TODO custom models

	private:
		MeshManager() = default;

		std::vector<Ptr<MeshData>> m_Meshes;
	};
}