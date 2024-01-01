#include  "Rendering/OpenGl Objects/VertexAttributeObject.h"

namespace Gem {
	VertexAttributeObject::VertexAttributeObject()
		: m_Handle(OpenGlContext::Get().GenerateVertexAttributeObject()) { }

	VertexAttributeObject::~VertexAttributeObject() {
		OpenGlContext::Get().DeleteVertexAttributeObject(m_Handle);
	}

	void VertexAttributeObject::Bind() const {
		OpenGlContext::Get().BindVertexAttributeObject(m_Handle);
	}

	void VertexAttributeObject::Unbind() {
		OpenGlContext::Get().BindVertexAttributeObject(0);
	}

	void VertexAttributeObject::SetLayout(const Layout& layout) {
		for (size_t index{ 0 }; index < m_MaxAttribute; index++) {
			OpenGlContext::Get().DeleteAttributePointer(m_Handle, index);
		}

		size_t stride{ 0 };
		for (auto& [type, name] : layout) {
			stride += type.byteCount;
		}

		size_t index{ 0 };
		size_t offset{ 0 };
		for (auto& [type, name] : layout) {
			OpenGlContext::Get().CreateAttributePointer(m_Handle, index, type, stride, offset);
			offset += type.byteCount;
			index++;
		}

		m_MaxAttribute = index;
	}

	VertexAttributeObjectHandle VertexAttributeObject::Handle() const {
		return m_Handle;
	}
}