#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap " << _name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap " << _name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap(const  ClapTrap &ct) : _name(ct._name), _hit_points(ct._hit_points), _energy_points(ct._energy_points), _attack_damage(ct._attack_damage) {
    std::cout << "Copy of ClapTrap " << _name << " was constructed" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " got destructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ct) {
    this->_name = ct._name;
    this->_hit_points = ct._hit_points;
    this->_energy_points = ct._energy_points;
    this->_attack_damage = ct._attack_damage;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (_energy_points == 0)
        std::cout << "ClapTrap " << _name << " has no energy points left.";
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << " This costs 1 energy point." << std::endl;;
    _energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hit_points = (_hit_points > amount) ? (_hit_points - amount) : 0;

    std::cout << "ClapTrap " << _name << " loses " << amount << " hit points due to an attack." << std::endl;

    if (_hit_points == 0)
        std::cout << "ClapTrap " << _name << " has no more hit points." << std::endl;
    else
        std::cout << "ClapTrap " << _name << " has " << _hit_points << " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energy_points == 0)
        std::cout << "ClapTrap " << _name << " has no energy points left.";
    std::cout << "ClapTrap " << _name << " regains " << amount << " hit points!" << " This costs 1 energy point." << std::endl;
    _energy_points--;
}
