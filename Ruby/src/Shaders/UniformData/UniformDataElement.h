#pragma once

#include <string>

namespace Ruby {
	class UniformDataElement {
	public:
		explicit UniformDataElement(std::string name);

		virtual void upload() const {}
		std::string getName();

	protected:
		std::string m_Name;
	};
}