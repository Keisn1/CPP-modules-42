#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie() {}
Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	 std::cout << name << " got destroyed" << std::endl;
}

void Zombie::set_name(std::string name) { this->name = name; };
void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
