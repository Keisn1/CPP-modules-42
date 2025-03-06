#include "Zombie.hpp"

int main() {
	Zombie* z = newZombie("Foo");
	delete z;
	randomChump("Foo2");
}
