#include "ImageQuad.h"

namespace Ruby {
	const std::vector<unsigned int> ImageQuad::indices{
			0, 1, 2,
			0, 2, 3,
	};

	const std::vector<float> ImageQuad::verticies{
		-1.0f,  1.0f, 0.0f,   0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f,   0.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,   1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,   1.0f, 1.0f
	};
}