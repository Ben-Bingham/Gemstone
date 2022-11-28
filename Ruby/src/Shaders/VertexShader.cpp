#include "VertexShader.h"
#include "Log.h"

namespace Ruby {
	VertexShader::VertexShader(const TextFile& shaderSourceFile, const LayoutData layoutData)
		: Shader(glCreateShader(GL_VERTEX_SHADER), shaderSourceFile), m_LayoutData(layoutData) {

		std::string shaderSource = getShaderSourceFile().getContent();
		const char* charShaderSource = shaderSource.c_str();

		glShaderSource(getShader(), 1, &charShaderSource, NULL);
		glCompileShader(getShader());

		int success;
		char infoLog[512];
		glGetShaderiv(getShader(), GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(getShader(), 512, NULL, infoLog);
			LOG("Vertex shader failed to compile.\n" + std::string(infoLog), Lazuli::LogLevel::ERROR);
		}
	}

	VertexShader::LayoutData VertexShader::getLayout() const {
		return m_LayoutData;
	}

	VertexShader::LayoutData::LayoutData(LayoutDataElement location1, LayoutDataElement location2, LayoutDataElement location3)
		: location1(location1), location2(location2), location3(location3){
		
	}

	VertexShader::LayoutDataElement::LayoutDataElement(DataType type, DataName name)
		: type(type), name(name) {
		
	}
}