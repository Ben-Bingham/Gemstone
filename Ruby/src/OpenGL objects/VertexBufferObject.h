#pragma once

#include <GL/glew.h>
#include <vector>

namespace Ruby {
	class VertexBufferObject {
	public:
		VertexBufferObject() { glGenBuffers(1, &m_VBO); }
		VertexBufferObject(VertexBufferObject&) = delete;
		VertexBufferObject& operator=(VertexBufferObject&) = delete;
		VertexBufferObject& operator=(VertexBufferObject&& other) noexcept {
			m_VBO = std::move(other.m_VBO);
			other.m_VBO = 0;
		}

		VertexBufferObject(VertexBufferObject&& other) noexcept
			: m_VBO(std::move(other.m_VBO)) {
			other.m_VBO = 0;
		}

		~VertexBufferObject() { glDeleteBuffers(1, &m_VBO); }

		void setData(const std::vector<float>& vertices) {
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
		}

		void bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_VBO); }
		void unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	private:
		unsigned int m_VBO{ 0 };
	};
}