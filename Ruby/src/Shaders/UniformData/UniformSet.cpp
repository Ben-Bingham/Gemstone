#include "UniformSet.h"
#include "UniformDataElement.h"

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	UniformSet::UniformSet(std::initializer_list<UniformDataElement> uniforms) {
		for (auto& uniform : uniforms) {
			m_DataElements.push_back(std::make_unique<UniformDataElement>(uniform));
		}
	}

	bool UniformSet::contains(const std::string& name) const {
		for (const UniformDataElementPtr& elementPtr : m_DataElements) {
			if (elementPtr->getName() == name) {
				return true;
			}
		}
		return false;
	}
}