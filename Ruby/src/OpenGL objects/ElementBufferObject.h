#pragma once
#include <GL/glew.h>
#include <vector>

namespace Ruby {
	class ElementBufferObject {
	public:
		ElementBufferObject() { glGenBuffers(1, &m_EBO); }
		ElementBufferObject(ElementBufferObject&) = delete;
		ElementBufferObject& operator=(ElementBufferObject&) = delete;
		ElementBufferObject& operator=(ElementBufferObject&& other) noexcept {
			m_EBO = std::move(other.m_EBO);
			other.m_EBO = 0;
		}

		ElementBufferObject(ElementBufferObject&& other) noexcept
			: m_EBO(std::move(other.m_EBO)) {
			other.m_EBO = 0;
		}

		~ElementBufferObject() { glDeleteBuffers(1, &m_EBO); }

		void setData(std::vector<unsigned int> indices) {
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
			m_NumberOfIndices = (unsigned int)indices.size();
		}

		template<typename T>
		void setPartialData(const std::vector<T>& indicies, int offset) {
			glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, indicies.size() * sizeof(indicies[0]), &indicies[0]);
		}

		unsigned int getNumberOfIndices() const { return m_NumberOfIndices; }

		void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); }
		void unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

	private:
		unsigned int m_EBO;
		unsigned int m_NumberOfIndices{ 0 };
	};
}