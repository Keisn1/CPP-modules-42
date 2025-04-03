#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal(void);
	~Animal(void);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
};

#endif // ANIMAL_H
