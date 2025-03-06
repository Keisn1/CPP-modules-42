#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return zombies;
}

Zombie *newZombie(std::string name) {
	Zombie* z = new Zombie(name);
	z->announce();
	return z;
}
