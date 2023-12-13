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

	void VertexAttributeObject::configure() {
		bind();
		std::vector<Attribute> attributes;

		attributes.push_back(3);
		attributes.push_back(3);
		attributes.push_back(2);

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