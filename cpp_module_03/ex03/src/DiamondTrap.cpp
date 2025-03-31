#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
	_name = name;
	std::cout << "DiamondTrap " << name << " was constructed!" << std::endl;
}
