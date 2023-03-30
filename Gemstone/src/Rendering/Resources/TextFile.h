#pragma once
#include <string>

namespace Gem {
	class TextFile {
	public:
		TextFile(const std::string& path);
		TextFile(const std::string& path, const std::string& content);

		std::string getContent() const { return m_Content; }
		std::string getPath() const { return m_Path; }
	private:
		std::string m_Path;
		std::string m_Content;
	};


}