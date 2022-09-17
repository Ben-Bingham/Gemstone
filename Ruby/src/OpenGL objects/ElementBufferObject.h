#pragma once
#include <GL/glew.h>
#include <vector>

namespace Ruby {
	class ElementBufferObject {
	public:
		ElementBufferObject(std::vector<unsigned int> indices) {
			glGenBuffers(1, &m_EBO);

			bind();

			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
		}

		void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); }
		static void unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
		void dispose() { glDeleteBuffers(1, &m_EBO); }

	private:
		unsigned int m_EBO;
	};
}