#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "AMateria.h"

class Character {
private:
	std::string _name;
	AMateria* _slots;
public:
	Character();
	~Character();
	Character(const Character&);
	Character& operator=(const Character&);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, Character &target);
};


#endif // CHARACTER_H
