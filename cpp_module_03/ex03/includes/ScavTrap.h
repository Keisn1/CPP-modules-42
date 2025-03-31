#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap&);
	void attack(const std::string& target);
	ScavTrap& operator=(const ScavTrap&);
	void guardGate(void);
};

#endif // SCAVTRAP_H
