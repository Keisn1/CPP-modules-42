#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal(void);
	virtual ~Animal(void);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	virtual void makeSound(void) const;
	std::string getType(void) const;
	void printType(void);
};

#endif // ANIMAL_H
