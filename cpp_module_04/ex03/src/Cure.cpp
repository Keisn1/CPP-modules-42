#include "Cure.h"
#include "AMateria.h"
#include <iostream>

Cure::Cure() : AMateria("cure") { std::cout << "Cure was constructed" << std::endl; }

Cure::~Cure() { std::cout << "Cure was destructed" << std::endl; }

Cure::Cure(const Cure& c) : AMateria(c._type) { std::cout << "Cure was copy-constructed" << std::endl; }

Cure& Cure::operator=(const Cure& c) {
    if (this == &c)
        return *this;
    this->_type = c._type;
    std::cout << "Cure was copy-assigned" << std::endl;
    return *this;
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
