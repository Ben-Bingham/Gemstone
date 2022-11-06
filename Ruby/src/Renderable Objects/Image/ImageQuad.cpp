#include "ImageQuad.h"

namespace Ruby {
	const std::vector<unsigned int> ImageQuad::indices{
			0, 2, 1,
			0, 3, 2,
	};

	const std::vector<float> ImageQuad::verticies{
		-1.0f,  1.0f, 0.0f,   0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,   0.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,   1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,   1.0f, 1.0f
	};
}