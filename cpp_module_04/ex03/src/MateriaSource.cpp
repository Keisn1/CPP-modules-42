#include "MateriaSource.h"
#include "Character.h"

MateriaSource::MateriaSource(void) {
    _materias = new AMateria*[MAX_NBR_MATERIA];
    for (int i = 0; i < MAX_NBR_MATERIA; i++)
        _materias[i] = NULL;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        if (_materias[i])
            delete _materias[i];
    }
    delete[] _materias;
}

MateriaSource::MateriaSource(const MateriaSource& ms) {
    _materias = new AMateria*[MAX_NBR_MATERIA];
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        if (ms._materias[i])
            _materias[i] = ms._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms) {
    if (this == &ms)
        return *this;
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        if (ms._materias[i])
            _materias[i] = ms._materias[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        if (!_materias[i]) {
            _materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
