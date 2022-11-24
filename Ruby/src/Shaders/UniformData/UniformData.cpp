#include "UniformData.h"

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	UniformDataElement::UniformDataElement(std::string name)
		: m_Name(std::move(name)) { }

	std::string UniformDataElement::getName() {
		return m_Name;
	}

	/*void UniformSet::add(const UniformDataElementPtr& uniform) {
		m_DataElements.push_back(uniform);
	}*/

	bool UniformSet::contains(const std::string& name) const {
		for (const UniformDataElementPtr& elementPtr : m_DataElements) {
			if (elementPtr->getName() == name) {
				return true;
			}
		}
		return false;
	}
}