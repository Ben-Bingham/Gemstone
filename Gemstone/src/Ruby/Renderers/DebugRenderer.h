#pragma once

#include "Celestite/Pointer.h"

#include "Malachite/Vector.h"

#include "Ruby/Geometry/MeshData.h"
#include "Ruby/Materials/SolidMaterial.h"
#include "Ruby/Renderable Objects/Renderable.h"

namespace Ruby {
	class RenderingSystem;
	class DebugRenderer {
	public:
		DebugRenderer(RenderingSystem* renderer);
	
		void queue(const std::vector<float>& points);
		void queue(const std::vector<Malachite::Vector3f>& points);
		void queue(const Celestite::Ptr<MeshData>& mesh, const Malachite::Vector3f& position, const Malachite::Vector3f& scale);

		void render();
	
	private:
		Celestite::Ptr<MeshData> m_Mesh;
		Celestite::Ptr<SolidMaterial> m_Material;

		//Renderable m_Renderable;

		std::vector<Malachite::Vector3f> m_Points;

		RenderingSystem* m_Renderer;
	};
}