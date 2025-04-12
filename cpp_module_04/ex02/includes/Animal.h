#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class AAnimal {
protected:
	std::string _type;
public:
	AAnimal(void);
	virtual ~AAnimal(void);
	AAnimal(const AAnimal&);
	AAnimal& operator=(const AAnimal&);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
	void printType(void);
};

#endif // ANIMAL_H
