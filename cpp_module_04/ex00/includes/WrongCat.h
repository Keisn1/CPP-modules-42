#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "WrongAnimal.h"

class WrongCat: public WrongAnimal {
public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat&);
	WrongCat& operator=(const WrongCat&);
	void makeSound(void) const;
};

#endif // WRONGCAT_H
