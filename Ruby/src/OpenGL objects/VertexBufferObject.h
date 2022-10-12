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

		template<typename T>
		void setData(const std::vector<T>& vertices, int usage = GL_STATIC_DRAW) {
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], usage);
		}

		void setNoData(unsigned int size, int usage = GL_STATIC_DRAW) {
			glBufferData(GL_ARRAY_BUFFER, size, NULL, usage);
		}

		template<typename T>
		void setPartialData(const std::vector<T>& vertices, int offset) {
			glBufferSubData(GL_ARRAY_BUFFER, offset, vertices.size() * sizeof(vertices[0]), &vertices[0]);
		}

		void bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_VBO); }
		void unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

		unsigned int getVBO() { return m_VBO; }

	private:
		unsigned int m_VBO{ 0 };
	};
}