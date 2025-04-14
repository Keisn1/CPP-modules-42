#include "Ice.h"
#include "AMateria.h"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice was constructed" << std::endl;
}

Ice::~Ice() {
  std::cout << "Ice was destructed" << std::endl;
}

Ice::Ice(const Ice &c) : AMateria(c._type) {
	std::cout << "Ice was copy-constructed" << std::endl;
}

Ice &Ice::operator=(const Ice &c) {
	if (this == &c)
		return *this;
	this->_type = c._type;
	std::cout << "Ice was copy-assigned" << std::endl;
	return *this;
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
