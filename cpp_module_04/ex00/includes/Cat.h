#ifndef CAT_H
#define CAT_H
#include "Animal.h"

class Cat: public Animal {
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat&);
	Cat& operator=(const Cat&);
};

#endif // CAT_H
