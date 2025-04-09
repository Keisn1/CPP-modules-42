#include "Animal.h"
#include <iostream>

Animal::Animal(void) : _type("Animal"){
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

void Animal::makeSound(void) const {
	std::cout << "Animal makes an animal sound" << std::endl;
}

void Animal::printType(void) { std::cout << "type: " << _type << std::endl; }

std::string Animal::getType(void) const { return _type; }
