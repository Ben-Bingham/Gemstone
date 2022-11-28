#pragma once

#include <vector>

#include "GeometryData.h"

namespace Ruby {
	class CubeGeometryData : public GeometryData {
	public:
		CubeGeometryData();

		[[nodiscard]] std::vector<float> getVertices(VertexShader::LayoutData) const override;
		[[nodiscard]] std::vector<unsigned int> getIndices() const override;

	private:
		const static std::vector<float> positionalData;
		const static std::vector<float> normalData;
		const static std::vector<float> textureCordinateData;

		const static std::vector<unsigned int> indexData;
	};
}