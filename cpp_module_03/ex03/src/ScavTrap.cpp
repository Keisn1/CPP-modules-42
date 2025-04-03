#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    _hit_points=100;
    _energy_points=50;
    _attack_damage=20;
    std::cout << "ScavTrap " << _name << " was constructed"
              << " with hp: " << _hit_points
              << ", ep: " << _energy_points
              << " and ad: " << _attack_damage << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hit_points=100;
    _energy_points=50;
    _attack_damage=20;
    std::cout << "ScavTrap " << _name << " was constructed"
              << " with hp: " << _hit_points
              << ", ep: " << _energy_points
              << " and ad: " << _attack_damage << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " got destructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st) {
    std::cout << "ScavTrap " << _name << " got copied"
              << " with hp: " << _hit_points
              << ", ep: " << _energy_points
              << " and ad: " << _attack_damage << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
    if (this == &st)
        return *this;
    std::cout << "ScavTrap " << _name << " got assigned ScavTrap " << st._name << std::endl;
    _name = st._name;
    _hit_points = st._hit_points;
    _energy_points = st._energy_points;
    _attack_damage = st._attack_damage;
    return *this;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (_energy_points == 0)
        std::cout << "ScavTrap " << _name << " has no energy points left.";
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << " This costs 1 energy point." << std::endl;;
    _energy_points= _energy_points - 1;
}
