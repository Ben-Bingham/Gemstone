#pragma once
#include "Rendering/Geometry/MeshData.h"
#include "Rendering/Materials/SolidMaterial.h"

#include "Utility/Pointer.h"

namespace Gem {
	class RenderingSystem;
	class DebugRenderer {
	public:
		DebugRenderer(RenderingSystem* renderer);
	
		void queue(const std::vector<float>& points);
		void queue(const std::vector<Vector3f>& points);
		void queue(const Ptr<MeshData>& mesh, const Vector3f& position, const Vector3f& scale);

		void render();
	
	private:
		Ptr<MeshData> m_Mesh;
		Ptr<SolidMaterial> m_Material;

		//Renderable m_Renderable;

		std::vector<Vector3f> m_Points;

		RenderingSystem* m_Renderer;
	};
}