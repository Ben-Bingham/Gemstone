#pragma once

#include "Renderer.h"

namespace Ruby {
	class DebugRenderer : public Renderer {
	public:
		DebugRenderer(Camera& camera, Wavellite::Window& window);

		void queue(const std::vector<Malachite::Vector3f>& points);

		void render();

	private:
		std::vector<Malachite::Vector3f> m_Points;
		VertexAttributeObject m_VAO{ };
		VertexBufferObject m_VBO{ };

		size_t m_VBOSize{ 512 * sizeof(float) };
	};
}