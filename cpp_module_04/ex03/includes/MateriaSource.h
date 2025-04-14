#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
  private:
    AMateria** _materias;

  public:
    MateriaSource(void);
    ~MateriaSource(void);
    MateriaSource(const MateriaSource&);
    MateriaSource& operator=(const MateriaSource&);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const& type);
};

#endif // MATERIASOURCE_H
