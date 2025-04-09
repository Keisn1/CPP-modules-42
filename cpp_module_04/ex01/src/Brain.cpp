#include "Brain.h"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain was constructed" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain was destructed" << std::endl;
}

Brain::Brain(const Brain &b) {
	(void)b;
	std::cout << "ideas were copied" << std::endl;
	std::cout << "Brain was copy-constructed" << std::endl;
}
