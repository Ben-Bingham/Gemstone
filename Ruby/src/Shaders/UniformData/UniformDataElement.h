#pragma once

#include <string>

namespace Ruby {
	class UniformDataElement {
	public:
		explicit UniformDataElement(std::string name);

		virtual void upload() const {}
		std::string getName() const;
		void setName(const std::string& name);

	protected:
		std::string m_Name;
	};
}