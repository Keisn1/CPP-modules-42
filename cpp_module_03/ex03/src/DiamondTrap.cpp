#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
		_name = name;

		_hit_points=FragTrap::_hit_points ;
		_energy_points=ScavTrap::_energy_points;
		_attack_damage=FragTrap::_attack_damage;
		std::cout << "DiamondTrap " << name << " was constructed!"
				  << " with hp: " << _hit_points
				  << ", ep: " << _energy_points
				  << " and ad: " << _attack_damage << std::endl;
}

void DiamondTrap::whoAmI(void) {
		std::cout << "My DiamondTrap name is: " << _name << std::endl;
		std::cout << "My ClapTrap name is: " <<  ClapTrap::_name << std::endl;
}
