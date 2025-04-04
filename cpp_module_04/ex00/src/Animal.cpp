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

void Animal::makeSound(void) {
	if (_type == "Dog") {
		std::cout << "Dog makes a Dog sound: Wuff Wuff" << std::endl;
		return;
	}
	std::cout << "Animal makes an animal sound" << std::endl;
}

void Animal::printType(void) { std::cout << "type: " << _type << std::endl; }
