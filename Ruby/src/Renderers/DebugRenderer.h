#pragma once

#include "Materials/SolidMaterial.h"
#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class Renderer;
	
	class DebugRenderer {
	public:
		DebugRenderer(Renderer* renderer);
	
		void queue(const std::vector<float>& points);
		void queue(const std::vector<Malachite::Vector3f>& points);
		void queue(const Ptr<Mesh>& mesh, const Malachite::Vector3f& position, const Malachite::Vector3f& scale);

		void render();
	
	private:
		Ptr<Mesh> m_Mesh;
		Ptr<SolidMaterial> m_Material;

		Renderable m_Renderable;

		std::vector<Malachite::Vector3f> m_Points;

		Renderer* m_Renderer;
	};
}