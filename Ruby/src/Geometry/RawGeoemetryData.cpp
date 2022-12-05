#include "RawGeometryData.h"

namespace Ruby {
	RawGeometryData::RawGeometryData(const DrawMode drawMode)
		: GeometryData(drawMode) {
		
	}


	std::vector<float> RawGeometryData::getVertices(VertexShader::LayoutData layoutData) const {
		bool normals = false;
		bool textureCoordinates = false;

		if (layoutData.location1.name == VertexShader::LayoutDataElement::DataName::NORMAL ||
			layoutData.location2.name == VertexShader::LayoutDataElement::DataName::NORMAL ||
			layoutData.location3.name == VertexShader::LayoutDataElement::DataName::NORMAL) {
			normals = true;
		}

		if (layoutData.location1.name == VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES ||
			layoutData.location2.name == VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES ||
			layoutData.location3.name == VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES) {
			textureCoordinates = true;
		}

		std::vector<float> verticies;
		unsigned int numberOfVerticies{ (unsigned int)m_PositionalData.size() / 3u };
		unsigned int j{ 0 };
		unsigned int g{ 0 };
		unsigned int v{ 0 };
		for (unsigned int i = 0; i < numberOfVerticies; i++, j += 3, g += 3, v += 2) {
			verticies.push_back(m_PositionalData[j + 0]);
			verticies.push_back(m_PositionalData[j + 1]);
			verticies.push_back(m_PositionalData[j + 2]);

			if (normals) {
				verticies.push_back(m_NormalData[g + 0]);
				verticies.push_back(m_NormalData[g + 1]);
				verticies.push_back(m_NormalData[g + 2]);
			}

			if (textureCoordinates) {
				verticies.push_back(m_TextureCoordinateData[v + 0]);
				verticies.push_back(m_TextureCoordinateData[v + 1]);
			}
		}

		return verticies;
	}

	std::vector<unsigned int> RawGeometryData::getIndices() const {
		return m_IndexData;
	}

	void RawGeometryData::setIndices(std::vector<float> positionalData) {
		unsigned int numberOfVerticies = positionalData.size() / 3;
		std::vector<unsigned int> indexData;
		for (unsigned int i = 0; i < numberOfVerticies; i++) {
			indexData.push_back(i);
		}

		m_IndexData = std::move(indexData);
	}

	void RawGeometryData::setData(std::vector<float> positionalData) {
		m_PositionalData = std::move(positionalData);

		std::vector<float> normals;
		std::vector<float> textureCoordinates;
		unsigned int numberOfVerticies = m_PositionalData.size() / 3;
		for (unsigned int i = 0; i < numberOfVerticies; i++) {
			normals.push_back(0.0f);
			normals.push_back(1.0f);
			normals.push_back(0.0f);

			if (i % 2 == 0) {
				textureCoordinates.push_back(0.0f);
				textureCoordinates.push_back(0.0f);
			}
			else {
				textureCoordinates.push_back(1.0f);
				textureCoordinates.push_back(1.0f);
			}
		}

		m_NormalData = std::move(normals);
		m_TextureCoordinateData = std::move(textureCoordinates);

		setIndices(m_PositionalData);
	}

	void RawGeometryData::setData(std::vector<float> positionalData, std::vector<unsigned int> indexData) {
		setData(positionalData);

		m_IndexData = std::move(indexData);
	}

	void RawGeometryData::setData(std::vector<float> positionalData, std::vector<float> normalData, std::vector<float> textureCoordinateData) {
		m_PositionalData = std::move(m_PositionalData);
		m_NormalData = std::move(normalData);
		m_TextureCoordinateData = std::move(textureCoordinateData);
		setIndices(positionalData);
	}

	void RawGeometryData::setData(std::vector<float> positionalData, std::vector<float> normalData, std::vector<float> textureCoordinateData, std::vector<unsigned int> indexData) {
		m_PositionalData = std::move(positionalData);
		m_NormalData = std::move(normalData);
		m_TextureCoordinateData = std::move(textureCoordinateData);
		m_IndexData = std::move(m_IndexData);
	}
}