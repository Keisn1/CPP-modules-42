#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal"){
	std::cout << "WrongAnimal was constructed" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal was destructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) : _type(a._type) {
	std::cout << "WrongAnimal was copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a) {
	this->_type = a._type;
	std::cout << "WrongAnimal was assigned to another WrongAnimal"<< std::endl;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal makes an animal sound" << std::endl;
}

void WrongAnimal::printType(void) { std::cout << "type: " << _type << std::endl; }

std::string WrongAnimal::getType(void) const { return _type; }
