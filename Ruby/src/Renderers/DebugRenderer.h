#pragma once

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "Window.h"

namespace Ruby {
	class DebugRenderer {
	public:
		DebugRenderer();

		void queue(const std::vector<Malachite::Vector3f>& points);

		void render();

	private:
		std::vector<Malachite::Vector3f> m_Points;
		VertexAttributeObject m_VAO{ };
		VertexBufferObject m_VBO{ };

		size_t m_VBOSize{ 512 * sizeof(float) };
	};
}