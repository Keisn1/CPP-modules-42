#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon *_weapon;
public:
    HumanB(std::string name);
    void attack(void);
    void setWeapon(Weapon &weapon);
};

#endif // HUMANB_H
