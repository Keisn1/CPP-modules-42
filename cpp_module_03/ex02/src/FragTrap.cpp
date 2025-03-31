#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("") {

    _hit_points=100;
    _energy_points=100;
    _attack_damage=30;
    std::cout << "FragTrap" << _name << " was constructed"
              << " with hp: " << _hit_points
              << ", ep: " << _energy_points
              << " and ad: " << _attack_damage << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hit_points=100;
    _energy_points=100;
    _attack_damage=30;
    std::cout << "FragTrap" << _name << " was constructed"
              << " with hp: " << _hit_points
              << ", ep: " << _energy_points
              << " and ad: " << _attack_damage << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " got destructed"
              << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft) {
    std::cout << "FragTrap " << _name << " got copied"
              << " with hp: " << _hit_points
              << ", ep: " << _energy_points
              << " and ad: " << _attack_damage << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft) {
    if (this == &ft)
        return *this;
    std::cout << "FragTrap " << _name << " got assigned FragTrap "
              << ft._name << std::endl;
    _name = ft._name;
    _hit_points = ft._hit_points;
    _energy_points = ft._energy_points;
    _attack_damage = ft._attack_damage;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " sagt: High Five" << std::endl;
}
