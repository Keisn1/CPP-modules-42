#ifndef CAT_H
#define CAT_H
#include "Animal.h"

class Cat: public Animal {
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	void makeSound(void) const;
};

#endif // CAT_H
