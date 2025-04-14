#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.h"
#include <string>

class AMateria {
protected:
  std::string _type;

public:
  AMateria(void);
  AMateria(std::string const &type); // constructor with a string
  virtual ~AMateria(void);
  AMateria(const AMateria &);
  AMateria &operator=(const AMateria &am);
  std::string const &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif // AMATERIA_H
