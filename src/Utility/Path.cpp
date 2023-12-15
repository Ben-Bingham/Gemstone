#include <filesystem>
#include "Utility/Path.h"

namespace Gem {
	Path::Path(const std::string& localPath) {
		path = (std::filesystem::current_path() / localPath).generic_string();

		while (path.find('/') != std::string::npos) {
			path.replace(path.find('/'), std::string("/").size(), "\\");
		}
	}

	Path::Path(const char* localPath) {
		*this = Path(std::string{ localPath });
	}
}