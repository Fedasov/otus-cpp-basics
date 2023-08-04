#include "random.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int random(int max_value) {

	std::srand((unsigned int)std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	// std::cout << random_value << std::endl;

	return random_value;
}