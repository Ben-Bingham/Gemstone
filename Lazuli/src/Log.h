#pragma once
#include <string>
#include <iostream>

namespace Lazuli {
#undef ERROR

	enum class LogLevel {
		INFO,
		WARNING,
		ERROR
	};

	class Log {
	public:
		Log(LogLevel logLevel = LogLevel::INFO, bool printFilePath = true) : m_LogLevel(logLevel), m_PrintFilePath(printFilePath) {}

		void log(int lineNumber, const char* file, const std::string& message, LogLevel messageLevel = LogLevel::INFO);

		void setLogLevel(LogLevel newLevel) { m_LogLevel = newLevel; }
		LogLevel getLogLevel() { return m_LogLevel; }

	private:
		LogLevel m_LogLevel;
		bool m_PrintFilePath;
	};

	extern Log LOGGER;
}


#ifdef LAZULI_DEBUG
#define LOG(...) Lazuli::LOGGER.log(__LINE__, __FILE__, __VA_ARGS__)
#else
#define LOG(...)
#endif // LAZULI_DEBUG