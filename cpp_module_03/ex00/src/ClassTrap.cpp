#include "ClapTrap.h"
#include <iostream>

ClassTrap::ClassTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) {}

ClassTrap::ClassTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {}

ClassTrap::ClassTrap(const ClassTrap &ct) : _name(ct._name), _hit_points(ct._hit_points), _energy_points(ct._energy_points), _attack_damage(ct._attack_damage) {}

ClassTrap& ClassTrap::operator=(const ClassTrap &ct) {
    this->_name = ct._name;
    this->_hit_points = ct._hit_points;
    this->_energy_points = ct._energy_points;
    this->_attack_damage = ct._attack_damage;
    return *this;
}

void ClassTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}
