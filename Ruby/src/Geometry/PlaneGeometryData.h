#pragma once

#include "GeometryData.h"

namespace Ruby {
	class PlaneGeometryData : public GeometryData {
	public:
		PlaneGeometryData() = default;

		[[nodiscard]] std::vector<float> getVertices(VertexShader::LayoutData) const override;
		[[nodiscard]] std::vector<unsigned int> getIndices() const override;

	private:
		const static std::vector<float> positionalData;
		const static std::vector<float> normalData;
		const static std::vector<float> textureCoordinateData;

		const static std::vector<unsigned int> indexData;
	};
}