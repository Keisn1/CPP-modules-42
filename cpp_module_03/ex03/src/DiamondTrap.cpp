#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <iostream>


DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), ScavTrap(), FragTrap() {
	_name = "";
	_hit_points=100;
	_energy_points=50;
	_attack_damage=30;
	std::cout << "DiamondTrap " << _name << " was constructed!"
			  << " with hp: " << _hit_points
			  << ", ep: " << _energy_points
			  << " and ad: " << _attack_damage << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
		_name = name;
		_hit_points=100;
		_energy_points=50;
		_attack_damage=30;
		std::cout << "DiamondTrap " << _name << " was constructed!"
							<< " with hp: " << _hit_points
							<< ", ep: " << _energy_points
							<< " and ad: " << _attack_damage << std::endl;
}

void DiamondTrap::whoAmI(void) {
		std::cout << "My DiamondTrap name is: " << _name << std::endl;
		std::cout << "My ClapTrap name is: " <<  ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap(void) { std::cout << "DiamondTrap " << _name << " got destructed" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt) {
	_name = dt._name;
	std::cout << "DiamondTrap " << _name << " got copied"
			  << " with hp: " << _hit_points
			  << ", ep: " << _energy_points
			  << " and ad: " << _attack_damage << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {
	if (this == &dt)
		return *this;

	std::cout << "DiamondTrap " << _name << " got assigned DiamondTrap " << dt._name << std::endl;
	_name = dt._name;
	_hit_points = dt._hit_points;
	_energy_points = dt._energy_points;
	_attack_damage = dt._attack_damage;
	return *this;
}
