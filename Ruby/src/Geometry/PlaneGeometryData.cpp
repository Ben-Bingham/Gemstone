#include "PlaneGeometryData.h"

namespace Ruby {
	std::vector<float> PlaneGeometryData::getVertices(const VertexShader::LayoutData layoutData) const {
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

		std::vector<float> vertices;
		constexpr unsigned int numberOfVertices{ 4u };
		unsigned int j{ 0 };
		unsigned int g{ 0 };
		unsigned int v{ 0 };
		for (unsigned int i = 0; i < numberOfVertices; i++, j += 3, g += 3, v += 2) {
			vertices.push_back(positionalData[j + 0]);
			vertices.push_back(positionalData[j + 1]);
			vertices.push_back(positionalData[j + 2]);

			if (normals) {
				vertices.push_back(normalData[g + 0]);
				vertices.push_back(normalData[g + 1]);
				vertices.push_back(normalData[g + 2]);
			}

			if (textureCoordinates) {
				vertices.push_back(textureCoordinateData[v + 0]);
				vertices.push_back(textureCoordinateData[v + 1]);
			}
		}

		return vertices;
	}

	std::vector<unsigned int> PlaneGeometryData::getIndices() const {
		return indexData;
	}

	const std::vector<float> PlaneGeometryData::positionalData = {
		-1.0f,  1.0f,  0.0f, 
		-1.0f, -1.0f,  0.0f, 
		 1.0f, -1.0f,  0.0f, 
		 1.0f,  1.0f,  0.0f
	};
	
	const std::vector<float> PlaneGeometryData::normalData = {
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
	};
	
	const std::vector<float> PlaneGeometryData::textureCoordinateData = {
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};
	
	const std::vector<unsigned int> PlaneGeometryData::indexData = {
		2, 1, 0,
		3, 2, 0
	};
}