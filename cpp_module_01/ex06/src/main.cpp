#include <iostream>
#include "Harl.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "I expect one argument";
		return 0;
	}

	std::string level = argv[1];
	Harl harl;
	harl.filter(level);

	return 0;
}
