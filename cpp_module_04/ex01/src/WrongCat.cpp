#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	_brain = new Brain();
	std::cout << "WrongCat was constructed" << std::endl;
}

WrongCat::~WrongCat() {
	delete _brain;
	std::cout << "WrongCat was destructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &d) : WrongAnimal(d) {
	_brain = new Brain(*d._brain);
	std::cout << "WrongCat was copy-constructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &c) {
	(void)c;
	std::cout << "WrongCat was assigned to another WrongCat" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat makes a WrongCat sound: Miau" << std::endl;
}
