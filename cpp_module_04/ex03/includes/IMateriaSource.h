#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include <string>

class AMateria;

class IMateriaSource {
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif // IMATERIASOURCE_H
