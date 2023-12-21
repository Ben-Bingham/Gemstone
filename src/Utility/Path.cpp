#include <filesystem>
#include "Utility/Path.h"

namespace Gem {
	Path::Path(const std::string& localPath) {
		auto assetFolder = std::filesystem::current_path();
		if (localPath.find("engineAssets") != std::string::npos) {
			assetFolder = m_GemAssets;
		}

		path = (assetFolder / localPath).generic_string();

		while (path.find('/') != std::string::npos) {
			path.replace(path.find('/'), std::string("/").size(), "\\");
		}
	}

	Path::Path(const char* localPath) {
		*this = Path(std::string{ localPath });
	}

	void Path::SetGemAssets(const std::string& gemAssetsString) {
		m_GemAssets = gemAssetsString;
	}

	std::string Path::m_GemAssets{ };
}