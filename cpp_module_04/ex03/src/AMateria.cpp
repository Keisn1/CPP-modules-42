#include "AMateria.h"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << "AMateria of type " << _type << "was constructed" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria of type " << _type << "was destructed" << std::endl;
}

AMateria::AMateria(const AMateria &am) : _type(am._type) {
	std::cout << "AMateria of type " << _type << "was copy-constructed" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &am) {
	if (this == &am)
		return *this;
	this->_type = am._type;
	std::cout << "AMateria of type " << _type << "was copy-assigned" << std::endl;
	return *this;
}

std::string const &AMateria::getType() const { return _type; };
