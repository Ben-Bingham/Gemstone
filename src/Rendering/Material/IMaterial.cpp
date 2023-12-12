#include "pch.h"
#include "IMaterial.h"

namespace Gem {
	IMaterial::IMaterial(const Ptr<Shader>& shader, const Ptr<Shader>& instancedShader)
		: shader(shader), instancedShader(instancedShader) {}

	void IMaterial::Apply() {}
	void IMaterial::Remove() {}

	void IMaterial::InstancedApply() {}
	void IMaterial::InstancedRemove() {}
}