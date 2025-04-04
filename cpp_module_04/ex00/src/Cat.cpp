#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << "Cat was constructed" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat was destructed" << std::endl;
}

Cat::Cat(const Cat &d) : Animal(d) {
	std::cout << "Cat was copied" << std::endl;
}

Cat& Cat::operator=(const Cat &d) {
	(void)d;
	std::cout << "Cat was assigned to another Cat" << std::endl;
	return *this;
}
