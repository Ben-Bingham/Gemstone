#pragma once

#include <GL/glew.h>

#include "Shader.h"

namespace Ruby {
	class FragmentShader : public Shader {
	public:
		FragmentShader(const TextFile& shaderSourceFile);

		void dispose() override { glDeleteShader(getShader()); }
	};
}