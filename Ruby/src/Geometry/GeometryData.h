#pragma once

#include <vector>

#include "OpenGL objects/GlBuffer.h"
#include "OpenGL objects/VertexAttributeObject.h"

#include "Shaders/VertexShader.h"

namespace Ruby {
	class GeometryData {
	public:
		GeometryData() = default;

		[[nodiscard]] virtual std::vector<float> getVertices(VertexShader::LayoutData) const = 0;
		[[nodiscard]] virtual std::vector<unsigned int> getIndices() const = 0;
	};
}