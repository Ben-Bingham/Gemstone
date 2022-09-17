#pragma once
#include <GL/glew.h>
#include <vector>
#include <iostream>

#include "Log.h"

namespace Ruby {
	using Attribute = unsigned int;

	class VertexAttributeObject {
	public:
		VertexAttributeObject() {
			glGenVertexArrays(1, &m_VAO);
		}

		void dispose() { glDeleteVertexArrays(1, &m_VAO); }
		void bind() const { glBindVertexArray(m_VAO); }
		static void unbind() { glBindVertexArray(0); }

		void addAttribute(Attribute attribute) { m_Attributes.push_back(attribute); }

		void compileAttributes() {
			unsigned int stride{ 0 };

			for (Attribute& attribute : m_Attributes) {
				stride += attribute * sizeof(float);
			}

			unsigned int i = 0;
			for (Attribute& attribute : m_Attributes) {
				enableAttributePointer(i, attribute, stride);
				i++;
			}
		}

	private:
		void enableAttributePointer(unsigned int index, Attribute attribute, unsigned int stride) {
			glVertexAttribPointer(index, attribute, GL_FLOAT, GL_FALSE, stride, (void*)m_LastAttributeWidth);
			glEnableVertexAttribArray(index);
			m_LastAttributeWidth = attribute * sizeof(float) + m_LastAttributeWidth;
		}

		unsigned int m_VAO;
		unsigned __int64 m_LastAttributeWidth{ 0 };
		std::vector<Attribute> m_Attributes;
	};
}