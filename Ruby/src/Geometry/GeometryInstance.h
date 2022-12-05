#pragma once

#include "GeometryData.h"
#include "Pointer.h"

#include "OpenGL objects/GlBuffer.h"
#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class GeometryInstance {
	public:
		GeometryInstance(Ptr<GeometryData> geometryData);

		void use() const;

		[[nodiscard]] GeometryData& getGeometryData() const;
		[[nodiscard]] size_t getIndexCount() const;

		void setData(const Ptr<GeometryData>& geometryData);

	private:
		Ptr<GeometryData> m_GeometryData{ nullptr };

		VertexAttributeObject m_VAO{ };
		VertexBuffer m_VertexBuffer{ };
		IndexBuffer m_IndexBuffer{ };
	};
}