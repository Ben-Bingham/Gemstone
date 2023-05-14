#include "pch.h"
#include  "VertexAttributeObject.h"

#include "Core/Engine.h"

namespace Gem {
	VertexAttributeObject::VertexAttributeObject()
		: m_Handle(g_Engine.openGlContext.GenerateVertexAttributeObject()) { }

	VertexAttributeObject::~VertexAttributeObject() {
		g_Engine.openGlContext.DeleteVertexAttributeObject(m_Handle);
	}

	void VertexAttributeObject::Bind() const {
		g_Engine.openGlContext.BindVertexAttributeObject(m_Handle);
	}

	void VertexAttributeObject::SetLayout(const Layout& layout) {
		for (size_t index{ 0 }; index < m_MaxAttribute; index++) {
			g_Engine.openGlContext.DeleteAttributePointer(m_Handle, index);
		}

		size_t stride{ 0 };
		for (auto& [type, name] : layout) {
			stride += type.byteCount;
		}

		size_t index{ 0 };
		size_t offset{ 0 };
		for (auto& [type, name] : layout) {
			g_Engine.openGlContext.CreateAttributePointer(m_Handle, index, type, stride, offset);
			offset += type.byteCount;
			index++;
		}

		m_MaxAttribute = index;
	}

	VertexAttributeObjectHandle VertexAttributeObject::Handle() const {
		return m_Handle;
	}
}