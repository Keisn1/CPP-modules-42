#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "AMateria.h"

#define MAX_NBR_MATERIA 4

class Character : public ICharacter {
  private:
    std::string _name;
    AMateria** _slots;
    unsigned char _nbrMat;

  public:
    Character();
    Character(std::string name);
    ~Character();
    Character(const Character&);
    Character& operator=(const Character&);
    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    AMateria* getMateria(int idx);
};

#endif // CHARACTER_H
