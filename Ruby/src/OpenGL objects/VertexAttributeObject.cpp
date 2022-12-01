#include  "VertexAttributeObject.h"

namespace Ruby {
	VertexAttributeObject::VertexAttributeObject()
		: m_VAO(0) {
		glGenVertexArrays(1, &m_VAO);
	}

	VertexAttributeObject::VertexAttributeObject(VertexAttributeObject&& other) noexcept
		: m_VAO(other.m_VAO)
		, m_LastAttributeWidth(other.m_LastAttributeWidth) {
	}

	VertexAttributeObject& VertexAttributeObject::operator=(VertexAttributeObject&& other) noexcept {
		if (this == &other)
			return *this;
		m_VAO = other.m_VAO;
		m_LastAttributeWidth = other.m_LastAttributeWidth;
		return *this;
	}

	VertexAttributeObject::~VertexAttributeObject() {
		glDeleteBuffers(1, &m_VAO);
	}

	void VertexAttributeObject::bind() const {
		if (m_BoundObject == this) {
			return;
		}
		glBindVertexArray(m_VAO);
		m_BoundObject = this;
	}

	void VertexAttributeObject::unbind() {
		m_BoundObject = nullptr;
		glBindVertexArray(0);
	}

	void VertexAttributeObject::configureForLayout(VertexShader::LayoutData layoutData) {
		std::vector<Attribute> attributes;
		switch (layoutData.location1.type) {
		case VertexShader::LayoutDataElement::DataType::NONE: 
			break;
		case VertexShader::LayoutDataElement::DataType::VECTOR_3F:
			attributes.push_back(3);
			break;
		case VertexShader::LayoutDataElement::DataType::VECTOR_2F:
			attributes.push_back(2);
			break;
		}

		switch (layoutData.location2.type) {
		case VertexShader::LayoutDataElement::DataType::NONE: 
			break;
		case VertexShader::LayoutDataElement::DataType::VECTOR_3F:
			attributes.push_back(3);
			break;
		case VertexShader::LayoutDataElement::DataType::VECTOR_2F:
			attributes.push_back(2);
			break;
		}

		switch (layoutData.location3.type) {
		case VertexShader::LayoutDataElement::DataType::NONE: 
			break;
		case VertexShader::LayoutDataElement::DataType::VECTOR_3F:
			attributes.push_back(3);
			break;
		case VertexShader::LayoutDataElement::DataType::VECTOR_2F:
			attributes.push_back(2);
			break;
		}

		compileAttributes(attributes);
	}

	void VertexAttributeObject::compileAttributes(const std::vector<Attribute>& attributes) {
		unsigned int stride{ 0 };

		for (const Attribute& attribute : attributes) {
			stride += attribute * sizeof(float);
		}

		unsigned int i = 0;
		for (const Attribute& attribute : attributes) {
			enableAttributePointer(i, attribute, stride);
			i++;
		}
	}

	void VertexAttributeObject::enableAttributePointer(const unsigned index, const Attribute attribute, const unsigned stride) {
		glVertexAttribPointer(index, (GLint)attribute, GL_FLOAT, GL_FALSE, (GLint)stride, (void*)((uint64_t)m_LastAttributeWidth));
		glEnableVertexAttribArray(index);
		m_LastAttributeWidth = attribute * sizeof(float) + m_LastAttributeWidth;
	}
}