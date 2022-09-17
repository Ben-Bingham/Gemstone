#pragma once

#include <GL/glew.h>
#include <vector>

namespace Ruby {
	class VertexBufferObject {
	public:
		VertexBufferObject() { glGenBuffers(1, &m_VBO); }

		void setData(const std::vector<float>& vertices) {
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
		}

		void bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_VBO); }
		void unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
		void dispose() { glDeleteBuffers(1, &m_VBO); }

	private:
		unsigned int m_VBO;
	};
}