#include "ClapTrap.h"

ClassTrap::ClassTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) {}

ClassTrap::ClassTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {}
