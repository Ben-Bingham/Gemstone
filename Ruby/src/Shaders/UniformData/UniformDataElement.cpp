#include "UniformDataElement.h"

namespace Ruby {
	UniformDataElement::UniformDataElement(std::string name)
		: m_Name(std::move(name)) {
	}

	std::string UniformDataElement::getName() const {
		return m_Name;
	}

	void UniformDataElement::setName(const std::string& name) {
		m_Name = name;
	}
}
