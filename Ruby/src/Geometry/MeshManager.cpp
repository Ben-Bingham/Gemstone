#include "MeshManager.h"

namespace Ruby {
	MeshManager& MeshManager::Get() {
		static MeshManager manager;
		return manager;
	}

	Celestite::Ptr<MeshData> MeshManager::NewMesh(Shape shape) {
		Vertices shapeVertices{};

		switch (shape) {
		case CUBE:
			shapeVertices = ShapeData::getCubeVertices();
			break;
		case SPHERE:
			shapeVertices = ShapeData::getSphereVertices(36, 18); //TODO shape system needs a rework these values cannot be changed. Maybe have like a 3d object class that can be a custom model or a shape, it would store no vertex/index data purly a descriptino of what it is, ie: Circle, Backpack, ect. would also make comparisons faster
			break;
		case PLANE:
			shapeVertices = ShapeData::getPlaneVertices();
			break;
		}

		for (auto& mesh : m_Meshes) {
			if (mesh->getVertices() == shapeVertices) {
				return mesh;
			}
		}

		m_Meshes.push_back(Celestite::createPtr<MeshData>(shape));
		return m_Meshes.back();
	}
}