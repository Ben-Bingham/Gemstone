#include <iostream>

#include "vector/Vector.h"

int main() {
	std::cout << "Hello World!" << std::endl;

	Malachite::Vector2f vec1{ 0, 0 };

	Malachite::Vector2f vec2{ 5, 4 };

	vec1 += vec2;

	std::cout << vec1 << vec2;

	std::cin.get();
}