#include "Zombie.hpp"

int main() {
	Zombie* zp = newZombie("Foo");
	zp->announce();
	delete zp;
	randomChump("Foo2");

	Zombie z ("Foo3");
	z.announce();
}
