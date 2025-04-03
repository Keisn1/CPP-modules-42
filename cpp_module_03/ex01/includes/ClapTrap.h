#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
protected:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
public:
	ClapTrap(void);
	ClapTrap(std::string);
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
	virtual ~ClapTrap(void);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printAttributes(void);
};


#endif // CLAPTRAP_H
