#include "Animal.h"
#include <iostream>

Animal::Animal(void) {
	std::cout << "Animal was constructed" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal was destructed" << std::endl;
}

Animal::Animal(const Animal &a) : _type(a._type) {
	std::cout << "Animal was copied" << std::endl;
}

Animal& Animal::operator=(const Animal &a) {
	this->_type = a._type;
	std::cout << "Animal was assigned to another Animal"<< std::endl;
	return *this;
}
