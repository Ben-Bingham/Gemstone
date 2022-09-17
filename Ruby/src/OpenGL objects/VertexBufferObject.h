#pragma once

#include <GL/glew.h>
#include <vector>

namespace Ruby {
	class VertexBufferObject {
	public:
		VertexBufferObject(const std::vector<float>& vertices) {
			glGenBuffers(1, &m_VBO);

			bind();

			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
		}

		void bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_VBO); }
		static void unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
		void dispose() { glDeleteBuffers(1, &m_VBO); }

	private:
		unsigned int m_VBO;
	};
}