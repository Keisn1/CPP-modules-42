#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void set_name(std::string name);
};

Zombie* newZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);
void randomChump(std::string name);
#endif // ZOMBIE_H
