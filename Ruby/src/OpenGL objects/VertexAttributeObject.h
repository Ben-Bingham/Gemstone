#pragma once
#include <GL/glew.h>
#include <vector>

#include "Shaders/VertexShader.h"

namespace Ruby {
	using Attribute = unsigned int;

	class VertexAttributeObject {
	public:
		VertexAttributeObject() { glGenVertexArrays(1, &m_VAO); }
		VertexAttributeObject(VertexAttributeObject&) = delete;
		VertexAttributeObject& operator=(VertexAttributeObject&) = delete;
		VertexAttributeObject& operator=(VertexAttributeObject&& other) noexcept {
			m_VAO = std::move(other.m_VAO);
			other.m_VAO = 0;

			m_LastAttributeWidth = std::move(other.m_LastAttributeWidth);
			other.m_LastAttributeWidth = 0;

			return *this;
		}

		VertexAttributeObject(VertexAttributeObject&& other) noexcept
			: m_VAO(std::move(other.m_VAO)), 
			m_LastAttributeWidth(std::move(other.m_LastAttributeWidth)) {

			other.m_VAO = 0;
			other.m_LastAttributeWidth = 0;
		}

		~VertexAttributeObject() { glDeleteBuffers(1, &m_VAO); }

		void bind() const { 
			glBindVertexArray(m_VAO); 
		}

		static void unbind() { glBindVertexArray(0); }


		void configureForLayout(VertexShader::LayoutData layoutData) {
			std::vector<Attribute> attributes;
			switch (layoutData.location1.type) {
			default:
			case VertexShader::LayoutDataElement::DataType::NONE: break;
			case VertexShader::LayoutDataElement::DataType::VECTOR_3F:
				attributes.push_back(3);
				break;
			case VertexShader::LayoutDataElement::DataType::VECTOR_2F:
				attributes.push_back(2);
				break;
			}

			switch (layoutData.location2.type) {
			default:
			case VertexShader::LayoutDataElement::DataType::NONE: break;
			case VertexShader::LayoutDataElement::DataType::VECTOR_3F:
				attributes.push_back(3);
				break;
			case VertexShader::LayoutDataElement::DataType::VECTOR_2F:
				attributes.push_back(2);
				break;
			}

			switch (layoutData.location3.type) {
			default:
			case VertexShader::LayoutDataElement::DataType::NONE: break;
			case VertexShader::LayoutDataElement::DataType::VECTOR_3F:
				attributes.push_back(3);
				break;
			case VertexShader::LayoutDataElement::DataType::VECTOR_2F:
				attributes.push_back(2);
				break;
			}

			compileAttributes(attributes);
		}

	private:
		void compileAttributes(std::vector<Attribute> attributes) {
			unsigned int stride{ 0 };

			for (Attribute& attribute : attributes) {
				stride += attribute * sizeof(float);
			}

			unsigned int i = 0;
			for (Attribute& attribute : attributes) {
				enableAttributePointer(i, attribute, stride);
				i++;
			}
		}

		void enableAttributePointer(unsigned int index, Attribute attribute, unsigned int stride) {
			glVertexAttribPointer(index, attribute, GL_FLOAT, GL_FALSE, stride, (void*)m_LastAttributeWidth);
			glEnableVertexAttribArray(index);
			m_LastAttributeWidth = attribute * sizeof(float) + m_LastAttributeWidth;
		}

		unsigned int m_VAO;
		uint64_t m_LastAttributeWidth{ 0 };
	};
}