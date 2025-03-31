#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
		_name = name;
		set_hit_points(FragTrap::get_hit_points());
		set_energy_points(ScavTrap::get_energy_points());
		set_attack_damage(FragTrap::get_attack_damage());
		std::cout << "DiamondTrap " << name << " was constructed!"
							<< " with hp: " << this->get_hit_points()
							<< ", ep: " << this->get_energy_points()
							<< " and ad: " << this->get_attack_damage() << std::endl;
}


void DiamondTrap::whoAmI(void) {
		std::cout << "My DiamondTrap name is: " << _name << std::endl;
		std::cout << "My ClapTrap name is: " << get_name() << std::endl;

}
