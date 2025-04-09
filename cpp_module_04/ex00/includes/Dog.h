#ifndef DOG_H
#define DOG_H
#include "Animal.h"


class Dog: public Animal {
public:
	Dog(void);
	~Dog(void);
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	void makeSound(void) const;
};

#endif // DOG_H
