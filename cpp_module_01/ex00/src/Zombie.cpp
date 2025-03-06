#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {
	announce();
}

Zombie::~Zombie() {
	 std::cout << name << " got destroyed" << std::endl;
}

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
