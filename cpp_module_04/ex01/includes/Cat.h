#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "Brain.h"

class Cat: public Animal {
private:
	Brain* _brain;
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	void makeSound(void) const;
};

#endif // CAT_H
