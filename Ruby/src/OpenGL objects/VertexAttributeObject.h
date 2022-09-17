#pragma once
#include <GL/glew.h>
#include <vector>
#include <iostream>

#include "Log.h"

namespace Ruby {
	enum class AttributeType {
		FLOAT,
		INT,
		UNSIGNED_INT
	};

	class VertexAttributeObject {
	public:
		VertexAttributeObject() {
			glGenVertexArrays(1, &m_VAO);
		}

		void dispose() { glDeleteVertexArrays(1, &m_VAO); }
		void bind() const { glBindVertexArray(m_VAO); }
		static void unbind() { glBindVertexArray(0); }

		void enableAttributePointer(unsigned int size, AttributeType type, unsigned int stride) {
			int glType;
			unsigned int bytesInType;

			switch (type) {
			default:
				LOG("Unknown type given during attribute pointer creation. Float assumed.", Lazuli::LogLevel::WARNING);
				__fallthrough;
			case AttributeType::FLOAT: 
				glType = GL_FLOAT;
				bytesInType = sizeof(float);
				break;
			case AttributeType::INT: 
				glType = GL_INT;
				bytesInType = sizeof(int);
				break;
			case AttributeType::UNSIGNED_INT: 
				glType = GL_UNSIGNED_INT;
				bytesInType = sizeof(unsigned int);
				break;
			}

			glVertexAttribPointer(numberOfAttributes, size, glType, GL_FALSE, stride, (void*)lastAttributeStride);
			glEnableVertexAttribArray(numberOfAttributes);
			numberOfAttributes++;
			lastAttributeStride = size * sizeof(char) * bytesInType + lastAttributeStride;
		}

	private:
		unsigned int m_VAO;
		unsigned int numberOfAttributes{ 0 };
		unsigned int lastAttributeStride{ 0 };
	};
}