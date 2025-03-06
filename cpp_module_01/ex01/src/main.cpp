#include <iostream>
#include "Zombie.hpp"

int main() {
	int N = 6;
	std::string zombie_name = "Foo";
	Zombie* zombies = zombieHorde(N, zombie_name);

	for (int i = 0; i < N; i++)
		zombies[i].announce();

	delete[] zombies;
	return 0;
}
