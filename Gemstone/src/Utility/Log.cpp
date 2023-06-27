#include "pch.h"
#include "Log.h"
#include <iostream>

namespace Gem {
	void Log(const char* filePath, int lineNumber, const std::string& message, LogLevel level) {
		std::string startOfLog{};

		if (Logger::g_LogLevel) {
			switch (level) {
			case LogLevel::INFO:
				startOfLog += "[INFO] ";
				break;
			case LogLevel::WARNING:
				startOfLog += "[WARNING] ";
				break;
			case LogLevel::ERROR:
				startOfLog += "[ERROR] ";
				break;
			case LogLevel::TERMINAL:
				startOfLog += "[TERMINAL] ";
				break;
			}
		}

		const auto filePathString = std::string{ filePath };

		const std::string shortenedPath = filePathString.substr(filePathString.find_last_of('\\') + 1);
		if (Logger::g_FilePath && Logger::g_LineNumber) {
			startOfLog += "(" + shortenedPath + ':' + std::to_string(lineNumber) + ") ";
		}
		else if (!Logger::g_FilePath && Logger::g_LineNumber) {
			startOfLog += "(" + std::to_string(lineNumber) + ") ";
		}
		else if (Logger::g_FilePath && !Logger::g_LineNumber) {
			startOfLog += "(" + shortenedPath + ") ";
		}

		std::cout << startOfLog << message << std::endl;

		if (level == LogLevel::TERMINAL) {
			std::cout << "Press enter to terminate the program." << std::endl;
			std::cin.get();

			exit(EXIT_FAILURE);
		}
	}
} 