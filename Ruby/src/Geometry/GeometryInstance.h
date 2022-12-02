#pragma once

#include "GeometryData.h"

namespace Ruby {
	class GeometryInstance {
	public:
		GeometryInstance(GeometryData& geometryData, const VertexShader::LayoutData& layoutData);

		void use();

	private:
		GeometryData* m_GeoemetryData;

		VertexAttributeObject m_VAO{ };
		VertexBuffer m_VertexBuffer{ };
		IndexBuffer m_IndexBuffer{ };
	};
}