#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie() {}
Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
     std::cout << _name << " got destroyed" << std::endl;
}

void Zombie::set_name(std::string name) { _name = name; };
void Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
