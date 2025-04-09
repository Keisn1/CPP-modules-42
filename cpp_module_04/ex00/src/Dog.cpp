#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "Dog was constructed" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog was destructed" << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d) {
	std::cout << "Dog was copied" << std::endl;
}

Dog& Dog::operator=(const Dog &d) {
	(void)d;
	std::cout << "Dog was assigned to another Dog" << std::endl;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Dog makes a Dog sound: Wuff Wuff" << std::endl;
}
