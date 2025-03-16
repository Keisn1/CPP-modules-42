#include "Zombie.hpp"

int main() {
	Zombie* zp = newZombie("Foo");
	delete zp;
	randomChump("Foo2");

	Zombie z ("Foo3");
	z.announce();
}
