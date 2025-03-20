#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), weapon(weapon) {}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}
