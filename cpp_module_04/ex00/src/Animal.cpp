#include "Animal.h"
#include <iostream>

Animal::Animal(void) {
	std::cout << "Animal of type \"\" was constructed" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal of type \"\" was destructed" << std::endl;
}
