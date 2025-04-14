#include "Character.h"
#include "AMateria.h"
#include <iostream>

Character::Character() : _name("nobody"), _slots(NULL), _nbrMat() {
    _slots = new AMateria*[MAX_NBR_MATERIA];
    for (int i = 0; i < MAX_NBR_MATERIA; i++)
        _slots[i] = NULL;
    std::cout << _name << "-Character was constructed" << std::endl;
}

Character::Character(std::string name) : _name(name), _slots(NULL), _nbrMat() {
    _slots = new AMateria*[MAX_NBR_MATERIA];
    for (int i = 0; i < MAX_NBR_MATERIA; i++)
        _slots[i] = NULL;
    std::cout << _name << "-Character was constructed" << std::endl;
}

Character::~Character() {
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        if (_slots[i])
            delete _slots[i];
    }
    delete[] _slots;
    std::cout << _name << "-Character was destructed" << std::endl;
}

Character::Character(const Character& c) : _name(c._name), _nbrMat(c._nbrMat) {
    _slots = new AMateria*[MAX_NBR_MATERIA];
    for (int i = 0; i < MAX_NBR_MATERIA; i++)
        _slots[i] = c._slots[i]->clone();

    std::cout << _name << "-Character was copy-constructed" << std::endl;
};

Character& Character::operator=(const Character& c) {
    if (this == &c)
        return *this;

    this->_name = c._name;
    for (int i = 0; i < MAX_NBR_MATERIA; i++) {
        delete this->_slots[i];
        _slots[i] = c._slots[i]->clone();
    }
    this->_nbrMat = c._nbrMat;

    std::cout << _name << "-Character was copy-assigned" << std::endl;
    return *this;
};

const std::string& Character::getName() const { return _name; }

AMateria* Character::getMateria(int idx) {
    if (idx < 0 || idx >= MAX_NBR_MATERIA || _nbrMat == 0 || !_slots[idx])
        return NULL;
    return _slots[idx];
}

void Character::equip(AMateria* m) {
    if (_nbrMat == MAX_NBR_MATERIA)
        return;
    int i = 0;
    while (i < MAX_NBR_MATERIA) {
        if (!_slots[i]) {
            _slots[i] = m;
            break;
        }
        i++;
    }
    _nbrMat++;
    return;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= MAX_NBR_MATERIA || _nbrMat == 0 || !_slots[idx])
        return;
    _slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= MAX_NBR_MATERIA || _nbrMat == 0 || !_slots[idx])
        return;
    _slots[idx]->use(target);
}
