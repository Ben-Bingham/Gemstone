#pragma once
#include <vector>

#include "New Rendering/OpenGlContext.h"

namespace Gem {
	class VertexAttributeObject {
	public:
		VertexAttributeObject();
		VertexAttributeObject(const VertexAttributeObject& other) = delete;
		VertexAttributeObject(VertexAttributeObject&& other) noexcept = default;
		VertexAttributeObject& operator=(const VertexAttributeObject& other) = delete;
		VertexAttributeObject& operator=(VertexAttributeObject&& other) noexcept = default;
		~VertexAttributeObject();

		void Bind();

		struct DataElement {
			OpenGlContext::GlType type;
			std::string name;
		};

		using Layout = std::vector<DataElement>;

		void SetLayout(const Layout& layout);

		[[nodiscard]] VertexAttributeObjectHandle Handle() const;

	private:
		VertexAttributeObjectHandle m_Handle;
		size_t m_MaxAttribute{ 0 };
	};
}