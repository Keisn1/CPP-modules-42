#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "Brain.h"


class Dog: public AAnimal {
private:
	Brain* _brain;
public:
	Dog(void);
	~Dog(void);
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	void makeSound(void) const;
};

#endif // DOG_H
