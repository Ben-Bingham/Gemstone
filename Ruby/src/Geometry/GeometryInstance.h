#pragma once

#include "GeometryData.h"
#include "Pointer.h"

#include "OpenGL objects/GlBuffer.h"
#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class GeometryInstance {
	public:
		GeometryInstance(Ptr<GeometryData> geometryData, const VertexShader::LayoutData& layoutData);

		void use() const;

		[[nodiscard]] VertexShader::LayoutData getDataLayout() const;
		[[nodiscard]] GeometryData& getGeometryData() const;
		[[nodiscard]] size_t getIndexCount() const;

	private:
		Ptr<GeometryData> m_GeometryData;

		VertexShader::LayoutData m_LayoutData;

		VertexAttributeObject m_VAO{ };
		VertexBuffer m_VertexBuffer{ };
		IndexBuffer m_IndexBuffer{ };
	};
}