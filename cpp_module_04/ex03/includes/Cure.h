#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure : public AMateria {
public:
  Cure();
  ~Cure();
  Cure(const Cure &);
  Cure &operator=(const Cure &);
  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // CURE_H
