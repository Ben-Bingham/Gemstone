#include "UniformDataElement.h"

namespace Ruby {
	UniformDataElement::UniformDataElement(std::string name)
		: m_Name(std::move(name)) {
	}

	std::string UniformDataElement::getName() {
		return m_Name;
	}
}
