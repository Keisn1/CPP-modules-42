#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;
public:
	DiamondTrap(std::string name);
	void whoAmI(void);
};

#endif // DIAMONDTRAP_H
