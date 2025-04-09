#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
protected:
	std::string _type;
public:
	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(const WrongAnimal&);
	WrongAnimal& operator=(const WrongAnimal&);
	void makeSound(void) const;
	std::string getType(void) const;
	void printType(void);
};

#endif // WRONGANIMAL_H
