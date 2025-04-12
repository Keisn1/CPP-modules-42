#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog was constructed" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog was destructed" << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d) {
	_brain = new Brain(*d._brain);
	std::cout << "Dog was copy-constructed" << std::endl;
}

Dog& Dog::operator=(const Dog &d) {
	*(this->_brain) = *(d._brain);
	std::cout << "Dog was assigned to another Dog" << std::endl;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Dog makes a Dog sound: Wuff Wuff" << std::endl;
}
