#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat was constructed" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat was destructed" << std::endl;
}

Cat::Cat(const Cat &d) : Animal(d) {
	_brain = new Brain(*d._brain);
	std::cout << "Cat was copy-constructed" << std::endl;
}

Cat& Cat::operator=(const Cat &c) {
	*(this->_brain) = *(c._brain);
	std::cout << "Cat was assigned to another Cat" << std::endl;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Cat makes a Cat sound: Miau" << std::endl;
}
