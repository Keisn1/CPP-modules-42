#include "Brain.h"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain was constructed" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain was destructed" << std::endl;
}

Brain::Brain(const Brain &b) {
	for (int i = 0; i < 100; ++i)
		_ideas[i] = b._ideas[i];
	std::cout << "ideas were copied" << std::endl;
	std::cout << "Brain was copy-constructed" << std::endl;
}

Brain& Brain::operator=(const Brain& b) {

	if (this == &b)
		return *this;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = b._ideas[i];
	std::cout << "ideas were copied" << std::endl;
	std::cout << "Brain was copy-assigned" << std::endl;
	return *this;
}

void Brain::printIdeas(int amount) const {
	if (amount < 0 || amount > 100) {
		std::cout << "you're funny; which brain can handle this amount of ideas?" << std::endl;
		return;
	}
	for (int i = 0; i < amount; i++)
			std::cout << _ideas[i] << std::endl;
}
