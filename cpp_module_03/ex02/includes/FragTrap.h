#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
	void highFivesGuys(void);
};

#endif // FRAGTRAP_H
