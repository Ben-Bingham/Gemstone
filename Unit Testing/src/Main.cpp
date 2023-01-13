#include <iostream>

#include "Log.h"

#include "Esperite/Esperite.h"

int main() {
	esperite();

	LOG("All tests passed.");
	std::cin.get();
}