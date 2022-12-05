#pragma once

#include "GeometryData.h"

namespace Ruby {
	class RawGeometryData : public GeometryData {
	public:
		explicit RawGeometryData(DrawMode drawMode = DrawMode::TRIANGLES);

		void setData(std::vector<float> positionalData);
		void setData(std::vector<float> positionalData, std::vector<unsigned int> indexData);

		void setData(std::vector<float> positionalData, std::vector<float> normalData, std::vector<float> textureCoordinateData);
		void setData(std::vector<float> positionalData, std::vector<float> normalData, std::vector<float> textureCoordinateData, std::vector<unsigned int> indexData);

		[[nodiscard]] std::vector<float> getVertices() const override;
		[[nodiscard]] std::vector<unsigned int> getIndices() const override;

	private:
		void setIndices(std::vector<float> positionalData);

		std::vector<float> m_PositionalData;
		std::vector<float> m_NormalData;
		std::vector<float> m_TextureCoordinateData;

		std::vector<unsigned int> m_IndexData;
	};
}