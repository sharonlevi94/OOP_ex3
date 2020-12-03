#include <iostream>
#include <stdlib.h>

void terminate(const char errorMessage[]) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}