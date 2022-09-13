#include <iostream>

#include "Log.h"

namespace Lazuli {
	void log(std::string message) {
		std::cout << message << std::endl;
	}
}