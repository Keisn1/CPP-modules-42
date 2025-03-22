#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClassTrap {
private:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
public:
	ClassTrap(void);
	ClassTrap(std::string);
	ClassTrap(const ClassTrap&);
	ClassTrap& operator=(const ClassTrap&);
	~ClassTrap(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif // CLAPTRAP_H
