#include "Animal.h"
#include <iostream>

AAnimal::AAnimal(void) : _type("Animal"){
	std::cout << "Animal was constructed" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal was destructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a) : _type(a._type) {
	std::cout << "Animal was copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &a) {
	this->_type = a._type;
	std::cout << "Animal was assigned to another Animal"<< std::endl;
	return *this;
}

void AAnimal::makeSound(void) const {
	std::cout << "Animal makes an animal sound" << std::endl;
}

void AAnimal::printType(void) { std::cout << "type: " << _type << std::endl; }

std::string AAnimal::getType(void) const { return _type; }
