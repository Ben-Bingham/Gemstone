#pragma once

namespace Gem {
	enum class LogLevel {
		INFO,
		WARNING,
		ERROR,
		TERMINAL
	};

	void Log(const char* filePath, int lineNumber, const std::string& message, LogLevel level = LogLevel::INFO);

	namespace Logger {
		inline bool g_LogLevel{ true };
		inline bool g_FilePath{ true }; // This and shortened path should be mutually exclusive
		inline bool g_LineNumber{ true };
	}
}

#define ENABLE_LOG_ON_RELEASE

#if defined(GEMSTONE_DEBUG)  || defined(ENABLE_LOG_ON_RELEASE)
#define LOG(...) Gem::Log(__FILE__, __LINE__, __VA_ARGS__)
#elif
#define LOG(...)
#endif