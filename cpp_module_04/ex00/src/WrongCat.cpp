#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat was constructed" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat was destructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &d) : WrongAnimal(d) {
	std::cout << "WrongCat was copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &d) {
	(void)d;
	std::cout << "WrongCat was assigned to another WrongCat" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat makes a WrongCat sound: Miau" << std::endl;
}
