#include <iostream>

#include "Log.h"

#include "Esperite/Esperite.h"

#include "Ruby/Ruby.h"

int main() {
	esperite();
	ruby();

	LOG("All tests passed.");
	std::cin.get();
}