#pragma once

#include "Window.h"
#include "Materials/SolidMaterial.h"
#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class Renderer;

	class DebugRenderer {
	public:
		DebugRenderer(Renderer* renderer);

		void queue(const std::vector<Malachite::Vector3f>& points);

		void render();

	private:
		std::vector<Malachite::Vector3f> m_Points;
		SolidMaterial m_Material;
		//Renderable m_Renderable;
		Renderer* m_Renderer{ nullptr };

		size_t m_VBOSize{ 512 * sizeof(float) * 3 };
	};
}