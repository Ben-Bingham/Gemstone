#include <Windows.h>

#include <stdlib.h>
#include <iostream>

#include "Log.h"

namespace Lazuli {
	void Log::log(int lineNumber, const char* file, const std::string& message, LogLevel messageLevel) {
		if (messageLevel >= m_LogLevel) {
			std::string fileString{ file };
			size_t pos = fileString.find("Gemstone");
			std::string shortendPath = "";
			if (pos != std::string::npos) {
				shortendPath = fileString.erase(0, pos + 9);
			}

			std::string boilerPlate = "";
			boilerPlate += ": " + std::to_string(lineNumber) + ' ' + shortendPath + "] ";

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#undef ERROR

			switch (messageLevel) {
			default:
			case LogLevel::INFO:
				if (m_PrintFilePath) {
					std::cout << "[INFO" << boilerPlate << message << std::endl;
				}
				else {
					std::cout << "[INFO] " << message << std::endl;
				}
				break;
			case LogLevel::WARNING:
				SetConsoleTextAttribute(hConsole, 14);
				if (m_PrintFilePath) {
					std::cout << "[WARNING" << boilerPlate << message << std::endl;
				}
				else {
					std::cout << "[WARNING] " << message << std::endl;
				}

				SetConsoleTextAttribute(hConsole, 7);

				break;
			case LogLevel::ERROR:
				SetConsoleTextAttribute(hConsole, 12);
				if (m_PrintFilePath) {
					std::cout << "[ERROR" << boilerPlate << message << std::endl;
				}
				else {
					std::cout << "[ERROR] " << message << std::endl;
				}

				SetConsoleTextAttribute(hConsole, 7);

				break;
			case LogLevel::TERMINAL:
				SetConsoleTextAttribute(hConsole, 13);
				if (m_PrintFilePath) {
					std::cout << "[TERMINAL" << boilerPlate << message << std::endl;
				}
				else {
					std::cout << "[TERMINAL] " << message << std::endl;
				}

				SetConsoleTextAttribute(hConsole, 7);

				std::cout << "Press enter to terminate the program." << std::endl;
				std::cin.get();

				exit(EXIT_FAILURE);
				break;
			}
		}
	}

	Log LOGGER(LogLevel::INFO, true);
}

