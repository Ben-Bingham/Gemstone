#pragma once
#include <string>

namespace Gem {
	class Path {
	public:
		Path(const std::string& localPath);
		Path(const char* localPath);

		std::string path;

		static void SetGemAssets(const std::string& gemAssetsString);

	private:
		static std::string m_GemAssets;
	};
}