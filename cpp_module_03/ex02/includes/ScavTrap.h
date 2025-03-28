#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
	void guardGate(void);
};

#endif // SCAVTRAP_H
