#pragma once
#include <vector>

#include "Shaders/VertexShader.h"

namespace Ruby {
	using Attribute = unsigned int;

	class VertexAttributeObject {
	public:
		VertexAttributeObject();
		VertexAttributeObject(const VertexAttributeObject& other) = delete;
		VertexAttributeObject(VertexAttributeObject&& other) noexcept;
		VertexAttributeObject& operator=(const VertexAttributeObject& other) = delete;
		VertexAttributeObject& operator=(VertexAttributeObject&& other) noexcept;

		~VertexAttributeObject();

		void bind() const;
		static void unbind();

		void configure();

	private:
		void compileAttributes(const std::vector<Attribute>& attributes);

		void enableAttributePointer(unsigned int index, Attribute attribute, unsigned int stride);

		unsigned int m_VAO;
		unsigned int m_LastAttributeWidth{ 0 };

		static inline const VertexAttributeObject* m_BoundObject{ nullptr };
	};
}