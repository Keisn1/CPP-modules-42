#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"
#include <string>

class DiamondTrap :  public ScavTrap, public FragTrap {
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap&);
	DiamondTrap& operator=(const DiamondTrap&);
	~DiamondTrap();
	void whoAmI(void);
};

#endif // DIAMONDTRAP_H
