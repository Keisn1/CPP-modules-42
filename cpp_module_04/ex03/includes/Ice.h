#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria {
public:
  Ice();
  ~Ice();
  Ice(const Ice &);
  Ice &operator=(const Ice &);
  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // ICE_H
