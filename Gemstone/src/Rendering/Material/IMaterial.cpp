#include "pch.h"
#include "IMaterial.h"

namespace Gem {
	IMaterial::IMaterial(const Ptr<Shader>& shader)
		: shader(shader) {}

	void IMaterial::Apply() {}

	void IMaterial::Remove() {}
}