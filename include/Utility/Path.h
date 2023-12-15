#pragma once
#include <string>

namespace Gem {
	class Path {
	public:
		Path(const std::string& localPath);
		Path(const char* localPath);

		std::string path;
	};
}