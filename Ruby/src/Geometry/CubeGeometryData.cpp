#include "CubeGeometryData.h"

namespace Ruby {
	CubeGeometryData::CubeGeometryData() { }

	std::vector<float> CubeGeometryData::getVertices(const VertexShader::LayoutData layoutData) const {
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
		unsigned int numberOfVerticies{ 24u };
		unsigned int j{ 0 };
		unsigned int g{ 0 };
		unsigned int v{ 0 };
		for (unsigned int i = 0; i < numberOfVerticies; i++, j += 3, g += 3, v += 2) {
			verticies.push_back(positionalData[j + 0]);
			verticies.push_back(positionalData[j + 1]);
			verticies.push_back(positionalData[j + 2]);

			if (normals) {
				verticies.push_back(normalData[g + 0]);
				verticies.push_back(normalData[g + 1]);
				verticies.push_back(normalData[g + 2]);
			}

			if (textureCoordinates) {
				verticies.push_back(textureCordinateData[v + 0]);
				verticies.push_back(textureCordinateData[v + 1]);
			}
		}

		return verticies;
	}

	std::vector<unsigned int> CubeGeometryData::getIndices() const {
		return indexData;
	}

	const std::vector<float> CubeGeometryData::positionalData = {
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,

		-0.5f, -0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,

		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,

		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f
	};

	const std::vector<float> CubeGeometryData::textureCordinateData = {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	const std::vector<float> CubeGeometryData::normalData = {
		  0.0f,  0.0f,  1.0f,
		  0.0f,  0.0f,  1.0f,
		  0.0f,  0.0f,  1.0f,
		  0.0f,  0.0f,  1.0f,
					 
		  1.0f,  0.0f,  0.0f,
		  1.0f,  0.0f,  0.0f,
		  1.0f,  0.0f,  0.0f,
		  1.0f,  0.0f,  0.0f,
					 
		 -1.0f,  0.0f,  0.0f,
		 -1.0f,  0.0f,  0.0f,
		 -1.0f,  0.0f,  0.0f,
		 -1.0f,  0.0f,  0.0f,

		  0.0f,  1.0f,  0.0f,
		  0.0f,  1.0f,  0.0f,
		  0.0f,  1.0f,  0.0f,
		  0.0f,  1.0f,  0.0f,

		  0.0f,  0.0f, -1.0f,
		  0.0f,  0.0f, -1.0f,
		  0.0f,  0.0f, -1.0f,
		  0.0f,  0.0f, -1.0f,

		  0.0f, -1.0f,  0.0f,
		  0.0f, -1.0f,  0.0f,
		  0.0f, -1.0f,  0.0f,
		  0.0f, -1.0f,  0.0f,
	};

	const std::vector<unsigned int> CubeGeometryData::indexData = {
		0, 1, 2,
		1, 3, 2,
		4, 5, 6,
		5, 7, 6,
		8, 9, 10,
		9, 11, 10,
		12, 13, 14,
		13, 15, 14,
		16, 17, 18,
		17, 19, 18,
		20, 21, 22,
		21, 23, 22
	};
}