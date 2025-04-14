#include "Character.h"
#include <iostream>

Character::Character() : _name("nobody") {
	std::cout << _name << "-Character was constructed" << std::endl;
}

Character::~Character() {
	std::cout << _name << "-Character was destructed" << std::endl;
}

Character::Character(const Character& c) : _name(c._name) {
	std::cout << _name << "-Character was copy-constructed" << std::endl;
};

Character& Character::operator=(const Character& c)  {
	if (this == &c)
		return *this;
	this->_name = c._name;
	std::cout << _name << "-Character was copy-assigned" << std::endl;
	return *this;
};
